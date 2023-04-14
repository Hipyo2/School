#Nicholas Ang
#CS461
#Project 2

#Q1

#Data Setup
library(GEOquery)
eset<-getGEO("GSE19804", filename="GSE19804_series_matrix.txt")

data <- exprs(eset)

pdata <- pData(eset)
control<-rownames(pdata[grep("Lung Normal",pdata$title),])

cancer<-rownames(pdata[grep("Lung Cancer",pdata$title),])

is.control = which(colnames(data) %in% control)
is.cancer = which(colnames(data) %in% cancer)

#Q2
#meanSub Function that calculates the mean control and cancer of a row and their difference
meanSub <- function(x)
{
  control.value <- x[is.control]
  cancer.value <- x[is.cancer]
  control.mean <- mean(control.value)
  cancer.mean <- mean(cancer.value)
  mean.diff <- control.mean - cancer.mean
}

#Perform t test to get p value and t score on each row
PValue = apply(data,MARGIN = 1, function(row){
  control.value <- row[is.control]
  cancer.value <- row[is.cancer]
  t.result = t.test(control.value,cancer.value)
  t.result$p.value
})
TScore = apply(data, MARGIN = 1, function(row){
  control.value <- row[is.control]
  cancer.value <- row[is.cancer]
  t.result = t.test(control.value,cancer.value)
  t.result$statistic
})

#Calculate log fold change using meanSub function
logFC <- apply(data, MARGIN = 1, FUN = meanSub)
gene.ids = rownames(data)
df = data.frame(gene.ids, PValue, TScore, logFC)
saveRDS(df, file = "DE-results.rds")

#Q3
#From the P value and log fold change, create a volcano plot.
#Differentially expressed genes are red, rest are black
pdf(file = "volcano.pdf")
PValue.log10 = -log(PValue, 10)
colors = ifelse(abs(logFC) > 1 & PValue < 0.05, "red", "black")
plot(x = logFC, y = PValue.log10, ylab = "-PValue.log10", col = colors)
dev.off()

#Q4
#Perform t test on control and cancer data and save as dataframe
t.OBSERVED = apply(data, 1, function(r){
  t.test(r[is.control], r[is.cancer])$statistic
})
t.OBSERVED = data.frame(t.OBSERVED)
saveRDS(t.OBSERVED, file = "t-observed.rds")

#Q5
#Instantiate t.NULL.DISTRIBUTION
t.NULL.DISTRIBUTION = NULL

#Permute the data 100 times
for (i in 1:100)
{
  #Create random permutation of indexes from 1 to ncol(data)
  random.index = sample(1:ncol(data))
  #Get permuted data from random index
  data.permuted = data[,random.index]
  #Apply t test and get tscore on each row in data.permuted
  tscore.NULL = apply(data.permuted, 1, function(r){
    t.test(r[is.control], r[is.cancer])$statistic
  })
  
  #Add column of tscores to t.NULL.DISTRIBUTION Data frame
  t.NULL.DISTRIBUTION = cbind(t.NULL.DISTRIBUTION, tscore.NULL)
}

#Instantiate p.T vector as NULL
p.T = NULL
#For every row in the data
for(i in 1:nrow(data))
{
  #row i value of t.OBSERVED
  t.observed.i = t.OBSERVED[i,]
  #all values in row i of t.NULL.DISTRIBUTION
  t.NULL.DIST.i = t.NULL.DISTRIBUTION[i,]
  
  #compare t.observed.i value to each value in row t.NULL.DIST.i
  #For two tailed, more extreme is when NULL > OBSERVED
  #Count extreme values in a row and divide by 100 for empirical pvalue p.T
  p.T[i] = (sum((abs(t.observed.i) < abs(t.NULL.DIST.i))))/100
}
#Save p.T vector as rds file
saveRDS(p.T, file = "p-empirical-t-score.rds")

#Q6
#Calculate Euclidean distance between control mean and cancer mean of each row
e.OBSERVED = apply(data, 1, function(r){
  control.mean <- mean(r[is.control])
  cancer.mean <- mean(r[is.cancer])
  e.SCORE = sqrt(((control.mean - cancer.mean)^2))
})

#Store as data frame
e.OBSERVED = data.frame(e.OBSERVED)

#Instantiate e.NULL.DISTRIBUTION
e.NULL.DISTRIBUTION = NULL

#Permute the data 100 times
for (i in 1:100)
{
  #gets permuted data 
  random.index = sample(1:ncol(data))
  data.permuted = data[,random.index]
  #Calculate Euclidean distance between means 
  escore.NULL = apply(data.permuted, 1, function(r){
    control.mean <- mean(r[is.control])
    cancer.mean <- mean(r[is.cancer])
    e.SCORE = sqrt(((control.mean - cancer.mean)^2))
  })
  e.NULL.DISTRIBUTION = cbind(e.NULL.DISTRIBUTION, escore.NULL)
}

#Instantiate p.E as NULL
p.E = NULL
#Count the number where the abs of e.observed.i is less than the abs of e.NULL.DIST.i and divide by 100
#counts where e.OBSERVED is more extreme than e.NULL.DISTRIBUTION
for(i in 1:nrow(data))
{
  e.observed.i = e.OBSERVED[i,]
  e.NULL.DIST.i = e.NULL.DISTRIBUTION[i,]
  p.E[i] = (sum((abs(e.observed.i) < abs(e.NULL.DIST.i))))/100
}
#p.E is saved as rds file
saveRDS(p.E, file = "p-empirical-euclidean.rds")

#Q7
#Create histograms using p.T and p.E and save as pdfs
pdf(file = "hist-pT.pdf")
hist(p.T)
dev.off()
pdf(file = "hist-pE.pdf")
hist(p.E)
dev.off()

#Q8
#Calculate the correlation between p.E and p.T
cor(p.T,p.E)