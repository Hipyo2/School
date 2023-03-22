#Nicholas Ang
#CS422 Project 2 perceptron.py

import numpy as np
import scipy.spatial as sc

def perceptron_train(X,Y):
	epochNum = 0
	prevwb = [[],]
	wb = [[],]
	#initialize weights and bias
	for i in range(0, len(X[0])):
		wb[0].append(0)
	wb.append(0)
	
	#initialize previous weight and bias as different than wb
	for i in range(0, len(X[0])):
		prevwb[0].append(1)
	prevwb.append(1)
	
	#set epoch limit to 100000 or until convergence when prevwb == wb
	while epochNum != 100000 and prevwb != wb:
		#set prevwb to wb
		for i in range(0,len(X[0])):
			prevwb[0][i] = wb[0][i]
		prevwb[1] = wb[1]
		
		#for every point
		for j in range(0,len(X)):
			act = 0
			yact = 0
			#calculate activation
			for k in range(0, len(X[0])):
				#print(wb[0][k])
				act += wb[0][k]*X[j][k]
			act += wb[1]
			
			#calculate activation * Y
			yact = act*Y[j]
			
			#if less than 0, update weights and bias
			if yact <= 0:
				for k in range(0, len(X[0])):
					wb[0][k] = (wb[0][k] + (Y[j]*X[j][k]))
				wb[1] = wb[1] + Y[j]
		epochNum += 1
	print("Final epoch:" , epochNum)
	print(wb)
	return wb


def perceptron_test(X_test, Y_test, w, b):
	accuracy = 0
	sumCorrect = 0
	#for every test sample
	for j in range(0,len(X_test)):
			act = 0
			yact = 0
			#calculate w*x + b
			for k in range(0, len(X_test[0])):
				act += w[k]*X_test[j][k]
			act += b
			#if positive, check if Y_test is equal to 1
			if act >= 0:
				if Y_test[j] == 1:
					sumCorrect += 1
			#if negative, check if Y_test is equal to 1
			else:
				if Y_test[j] == -1:
					sumCorrect += 1
	#calculate accuracy with total correct divided by total number of test samples
	accuracy = sumCorrect/len(Y_test)
	return accuracy
