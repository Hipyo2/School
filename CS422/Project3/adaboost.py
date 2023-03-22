#Nicholas Ang
#CS422 Project 3 adaboost.py

#libraries
from sklearn import tree as t
import numpy as np
import math as m

def adaboost_train(X, Y, max_iter):
	#initialize f, alpha, weights, training Xp, training Yp
	f = []
	Xp = []
	Yp = []
	#Copy X and Y values to respective lists
	for x in range(0,len(X)):
		Xp.append(X[x])
		Yp.append(Y[x])

	alpha = []
	weights = []
	
	Z = 1
	
	#Set weights to 1/N
	for i in range(0, len(X)):
		weights.append(1/len(X))
		
	#Loop through multiple iterations
	for k in range(0,max_iter):
		#instantiate error, fraction weights, and lowest for each f classifier
		lowest = 100000
		error = 0
		
		#create decision trees and predict values
		dt = t.DecisionTreeClassifier(max_depth = 1)
		dt = dt.fit(Xp,Yp)
		f.append(dt)
		yHat = dt.predict(X)

		#Add weighted error if not matching
		for j in range(0,len(Y)):
			if yHat[j] != Y[j]:
				error += weights[j]
					
		#Calculate alpha given that there is some error, otherwise 1	
		if(error != 0):
			alpha.append((0.5)*m.log(((1-error)/error)))
		else:
			alpha.append(1)
		
		
		#Calculate new weights
		for b in range(0, len(X)):
			weights[b] = weights[b] * m.exp(-alpha[k] * Y[b] * yHat[b])
			
		#Calculate normalizing value Z
		Z = sum(weights)
		
		#normalize every weight
		#also get lowest value to see what the baseline is for the ratios ie 1/(some value)
		for b in range(0, len(X)):
			weights[b] = weights[b]/Z
			if weights[b] < lowest:
				lowest = weights[b]
				
		#Clear Xp and Yp
		Xp = []
		Yp = []
				
		#Add correct ratios of samples to Xp and Yp
		for j in range(0,len(X)):
			rangeV = int(round((weights[j]/lowest),0))
			for k in range(0,rangeV):
				Xp.append(X[j])
				Yp.append(Y[j])
	print("Alpha:", alpha)	
	return f, alpha
	
def adaboost_test(X, Y, f, alpha):
	#Initialize sum, accuracy, yhat list
	sumC = 0
	accuracy = 0
	yHat = []
	
	for i in range(0,len(Y)):
		sumF = 0
		#sum up alpha*prediction at each sample for each classifier and alpha
		for j in range (0,len(f)):
			sumF += alpha[j] * f[j].predict([X[i]])

		#Voted on prediction, positive or negative
		if(sumF >= 0):
			yHat.append(1)
		else:
			yHat.append(-1)
	
	#Check which values are correct
	for i in range(0,len(Y)):
		if(yHat[i] == Y[i]):
			sumC += 1
	
	#Calculate accuracy
	accuracy = sumC/len(Y)
	return accuracy
