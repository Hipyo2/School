#Nicholas Ang
#CS461
#Project 1

#Q1

#get path to working directory to pull file from
project.path <- getwd()
data.file <- "GSE9782.RData"

full.data.file.path <- paste0(project.path,"/",data.file)

#load data and get indexes of treated and control group
load(full.data.file.path)

is.treated <- group == "treated"
is.control <- group == "control"

dataGSE9782.treated = which(is.treated)
dataGSE9782.control = which(is.control)


#Q2
#function to calculate mean of treated and control values, subtract means from each other for difference
meanSub <- function(x)
{
  treated.value <- x[dataGSE9782.treated]
  control.value <- x[dataGSE9782.control]
  treated.mean <- mean(treated.value)
  control.mean <- mean(control.value)
  mean.diff <- treated.mean - control.mean
}
#log 2 data, logFC (log fold change) calculated with meanSub function
data.log2 = log(dataGSE9782,2)
logFC <- apply(data.log2, MARGIN = 1, FUN = meanSub)



#Q3
#perform t test on treated values and control values
#extract p value and place in t.PValue vector
t.PValue = apply(dataGSE9782,MARGIN = 1, function(row){
  treated.value <- row[dataGSE9782.treated]
  control.value <- row[dataGSE9782.control]
  t.result = t.test(treated.value,control.value)
  t.result$p.value
})
#extract tscore and place in t.TScore vector
t.TScore = apply(dataGSE9782, MARGIN = 1, function(row){
  treated.value <- row[dataGSE9782.treated]
  control.value <- row[dataGSE9782.control]
  t.result = t.test(treated.value,control.value)
  t.result$statistic
})
#create data frame with gene ids, pvalue, tscore, and logFC and write to file
gene.ids = rownames(dataGSE9782)
df = data.frame(gene.ids,t.PValue, t.TScore, logFC)
write.table(df, file = "DE-results.rds",row.names = F)

#Q4
#create pdf for volcano.pdf
pdf(file = "volcano.pdf")
logFC = logFC
t.PValue.log10 = -log(t.PValue,10)
#if absolute value of logFC is greater than 1 and t.Pvalue is less than 0.05, color red, otherwise black
colors = ifelse(abs(logFC) > 1 & t.PValue < 0.05, "red", "black")
#x axis is log fc, y axis is t.PValue.log10 which is -log(t.Pvalue,10)
#colors based on value of t.Pvalue and absolute value of logFC
plot(x = logFC, y = t.PValue.log10, ylab = "-t.PValue.log10", col = colors)
dev.off()

#Q5
#perform wilcox.test on treated values and control values
#extract pvalue and place in vector w.PValue
w.PValue = apply(dataGSE9782,MARGIN = 1, function(row){
  treated.value <- row[dataGSE9782.treated]
  control.value <- row[dataGSE9782.control]
  w.result = wilcox.test(treated.value,control.value)
  w.result$p.value
})

#extract gene ids where pvalues are less than 0.05 for each test
t.gene.ids = gene.ids[t.PValue < 0.05]
w.gene.ids = gene.ids[w.PValue < 0.05]

#set tw.gene.ids to gene.ids where both t.gene.ids and w.gene.ids have and write tw.gene.ids to file
tw.gene.ids = intersect(t.gene.ids, w.gene.ids)
write.table(tw.gene.ids, file = "wilcoxon-results.rds", row.names = FALSE, col.names = "tw.gene.ids")

#Q6
#Histogram of Log 2 of the data
pdf(file = "hist.pdf")
hist(data.log2)
dev.off()

#Q7
#Generate boxplot pdf file
pdf(file = "boxplot.pdf")

#calculate the maximum value of the absolute value of logFC
logFC = logFC
logFC.abs = abs(logFC)
logFC.abs.max = max(logFC.abs)

#find row index where absolute value logFc matches with logFC.abs.max
gene.index.with.max.absolute.logFC = which(logFC.abs == logFC.abs.max)
#extract data at where the gene has maximum absolute expression change and split it based on treated and control
expression.values = data.log2[gene.index.with.max.absolute.logFC,]
treated.values = expression.values[dataGSE9782.treated]
control.values = expression.values[dataGSE9782.control]

#create boxplot with treated values and control values from row gene with max absolute logFC
boxplot(list(treated = treated.values, control = control.values))
dev.off()