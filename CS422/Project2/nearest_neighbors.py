#Nicholas Ang
#CS422 Project 2 nearest_neighbors.py

import numpy as np
import scipy.spatial as sc

def KNN_test(X_train, Y_train, X_test, Y_test, K):
	sumCorrect = 0
	accuracy = 0
	labels = []
	#for every test sample
	for i in range (0, len(X_test)):
		distance = []
		distanceIndex = []
		sumPos = 0
		sumNeg = 0
		#for every training sample, calculate distance from test point to each training point
		for j in range(0,len(X_train)):
			distance.append(sc.distance.euclidean(X_test[i], X_train[j]))
		#sort distances
		distanceIndex = np.argsort(distance)
		#based on the sorted distances, check label of closest K neighbor points
		for k in range(0,K):
			if Y_train[distanceIndex[k]] == 1:
				sumPos += 1
			else:
				sumNeg += 1
		#Majority is label
		if sumPos > sumNeg:
			labels.append(1)
		else:
			labels.append(-1)
	
	#Check if predicted label is correctly predicted compared to Y_test
	for b in range(0,len(labels)):
		if labels[b] == Y_test[b]:
			sumCorrect += 1
		else:
			sumCorrect += 0
	
	print("Nearest Neighbors K:",K)
	#print("Labels:",labels)
	#print("Correct Labels:", Y_test)
	accuracy = sumCorrect/len(labels)
	return accuracy

