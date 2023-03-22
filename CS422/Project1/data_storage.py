#Nicholas Ang
#CS422 Project 1 data_storage.py

import numpy as np
import math as m

def build_nparray(data):
	array = np.array(data)
	#delete header row 
	a1 = np.delete(array, 0,0)
	a2 = np.delete(array, 0,0)
	
	#a1 is features, a2 is labels
	a1 = a1.astype('float64')
	a2 = a2.astype('int32')
	a1 = np.delete(a1, len(a1[0]) - 1, 1)
	a2 = np.delete(a2, slice(len(a2[0])-1),1)
	a2 = np.concatenate(a2)
	return a1, a2
	

def build_list(data):
	listData = np.array(data)
	#list1 is features, list 2 is labels
	list1 = []
	list2 = [int(listData[i][(len(listData[0])-1)]) for i in range(1,len(listData))]
	
	#deleting labels column and headers from list features
	listData = np.delete(listData, 0, 0)
	listData = np.delete(listData, len(listData[0]) - 1, 1)
	listData = listData.astype('float64')
	list1 = listData.tolist()

	
	return list1,list2;
	
	
def build_dict(data):
	dictData = np.array(data)
	keys = []
	values = []
	values2 = []
	dictKeys = dict({})
	dict1 = dict({})
	dict2 = dict({})
	#create list of keys
	for i in range(0, len(dictData[0])-1):
		keys.append(dictData[0][i])
	
	#Create lists of feature values(values) and label values(values2)
	for i in range(1, len(dictData)):
		values.append([])
		values2.append(int(dictData[i][len(dictData[0])-1]))
		for j in range(0, len(dictData[0])-1):
			values[i-1].append(float(dictData[i][j]))
	
	#Link values to keys in dict1
	for i in range (0, len(dictData)-1):
		dict1[i] = dict({})
		for j in range(0, len(dictData[0])-1):
			dictKeys[keys[j]] = values[i][j]
		dict1[i] = dict(dictKeys)

	#Link values2 to row index in dict2	
	for i in range (0, len(dictData)-1):
		dict2[i] = values2[i]

	return dict1, dict2;
