#Nicholas Ang
#CS422 Project 1 decision_trees.py

import numpy as np
import math as m

def DT_train_binary(X, Y, max_depth):
	DT = []
	leftSide = []
	leftSideValues = []
	leftE = 0
	rightE = 0
	rightSide = []
	rightSideValues = []
	igIndex = 0
	highestIG = -1
	
	#calculate entropy for everything
	if(len(X) != 0):
		onesCount = np.count_nonzero(Y)
		probYes = float(onesCount/len(X))
		probNo = float((len(X) - onesCount)/len(X))
	else:
		probYes = 0
		probNo = 0
	if(probNo!= 0 and probYes != 0):
		entropy = -probNo * m.log(probNo,2) - probYes*m.log(probYes,2)
	else:
		entropy = 0

	if(len(X) != 0):
		#as long as its not max depth
		if max_depth != 0:
			max_depth -= 1

			#For every column
			for z in range(0, len(X[0])):
				
				L = X[:,z]

				onesCountYF = 0
				onesCountNF = 0
				L1 = []
				L2 = []
				#at the row and column, check if 1 or 0 for left side and right side
				for i in range(0, len(X)):
					if L[i] == 1:
						L1.append(i)
					else:
						L2.append(i)

				#Count left side labels for 1 and calculate entropy for (YES)
				for j in range(0, len(L1)):
					if Y[L1[j]] == 1:
						onesCountYF += 1
				if len(L1) != 0:
					probYesYF = float(onesCountYF/len(L1))
					probNoYF = float((len(L1) - onesCountYF)/len(L1))
				else:
					probYesYF = 0
					probNoYF = 0	
				if probNoYF == 0 or probYesYF == 0:
					entropyYF = 0
				else: 
					entropyYF = -probNoYF * m.log(probNoYF,2) - probYesYF*m.log(probYesYF,2)
					
				#Count right side labels for 1 and calculate entropy for (NO)
				for j in range(0, len(L2)):		
					if Y[L2[j]] == 1:
						onesCountNF += 1
				if len(L2) != 0:
					probYesNF = float(onesCountNF/len(L2))
					probNoNF = float((len(L2) - onesCountNF)/len(L2))
				else:
					probYesNF = 0
					probNoNF = 0
				if probNoNF == 0 or probYesNF == 0:
					entropyNF = 0
				else:
					entropyNF = -probNoNF * m.log(probNoNF,2) - probYesNF*m.log(probYesNF,2)

				#calculate information gain
				iG = entropy - float((len(L1)/len(X)))*entropyYF - float((len(L2)/len(X)))*entropyNF

				#take highest information gain out of all the preliminary DTs
				if(highestIG < iG):
					igIndex = int(z)
					highestIG = iG
					leftE = entropyYF
					rightE = entropyNF

					if L1 != []:
						leftSide = L1
						leftSideValues = []
						leftSideValues.append(int(Y[L1[0]]))
						for i in range(0, len(L1)):
							leftSideValues.append(L1[i])
					if L2 != []:
						rightSide = L2
						rightSideValues = []
						rightSideValues.append(int(Y[L2[0]]))
						for j in range(0, len(L2)):
							rightSideValues.append(L2[j])

			#delete the looked at column
			X = np.delete(X, igIndex, 1)
			#add index to DT
			DT.append(igIndex)
			#add left side first
			if leftE == 0:
				DT.append(leftSideValues)
				#delete rows from being added again
				X = np.delete(X, leftSide, 0)
				Y = np.delete(Y, leftSide)
			elif max_depth == 0:
				DT.append(leftSideValues)
			elif leftE != 0:
				#if there still information to be gained, go deeper
				DT.append(DT_train_binary(X,Y, max_depth))

			#add right side after
			if rightE == 0:
				DT.append(rightSideValues)
			elif max_depth == 0:
				DT.append(rightSideValues)
			elif rightE != 0:
				#if there still information to be gained, go deeper
				DT.append(DT_train_binary(X,Y, max_depth))
		else:
			DT = []
	return DT

def DT_test_binary(X, Y, DT):
	if(DT != []):
		accuracy = 0
		index = DT[0]
		sumDT = 0
		i = 0
		L1 = []
		L2 = []
		
		#for every x sample, make a prediction and compare it to the Y value at its index
		for i in range(0, len(X)):
			value = DT_make_prediction(X[i],DT)
			if value == Y[i]:
				sumDT += 1
			else:
				sumDT += 0
		#accuracy is sum of correct values divided by the length
		accuracy = sumDT / len(X)
		return accuracy
	else:
		return 0

def DT_make_prediction(x, DT):
	if(DT != []):
		value = 0
		index = DT[0]
			
		#checks if the inside of a list contains only integer values
		if(all([isinstance(listCheck,int) for listCheck in DT]) == 1):
			#first number in a leaf should be the label of values inside the leaf
			value = DT[0]
			return value

		#Checks if the x sample should go to the left side of the tree
		elif x[index] == 1 and [isinstance(DT[1],list) == 1]:
			x = np.delete(x,index)
			value = DT_make_prediction(x, DT[1])

		#Checks if the x sample should go to the right side of the tree	
		elif x[index] == 0 and [isinstance(DT[2],list) == 1]:
			x = np.delete(x,index)
			value = DT_make_prediction(x, DT[2])
		
		return value
	
def RF_build_random_forest(X, Y, max_depth, num_of_trees):
	RF_list = []
	#create as many trees as num_of_trees
	for i in range(0, num_of_trees):
		randSample = []
		randLabel = []
		#for the number of samples
		for j in range(0, len(X)):
			#select around 10% of them to add to a DT
			if np.random.random_integers(1,10) == 1:
				randSample.append(list(X[j]))
				randLabel.append(Y[j])
		randSample = np.array(randSample)	
		DT = DT_train_binary(randSample, randLabel,max_depth)
		
		#print accuracy of each DT and add to RF
		print("DT",i,": ",DT_test_binary(X,Y,DT))
		RF_list.append(DT)
	return RF_list
	


def RF_test_random_forest(X, Y, RF):
	sumRF = 0
	RF_value = 0
	storePred = []
	#for every sample for each tree, get a prediction and then add it to listMajority 
	for j in range(0, len(X)):
		listMajority = []
		for i in range(0, len(RF)):
			DT_make_prediction(X[j], RF[i])
			if DT_make_prediction(X[j], RF[i]) == 1:
				listMajority.append(1)
		#check if 1 is majority. if yes add 1 to storePred list. if no add 0 to storePred
		if len(listMajority) >= (len(RF) // 2) + 1:
			storePred.append(1)
		else:
			storePred.append(0)
	#for every label in y, compare it to the stored prediction at the corresponding index, if correct add to sum		
	for k in range(0, len(Y)):
		if storePred[k] == Y[k]:
			sumRF += 1
		else:
			sumRF += 0
	#calculate accuracy of stored majority prediction
	RF_value = sumRF/len(Y)
	return RF_value
	
