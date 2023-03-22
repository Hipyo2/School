#Nicholas Ang
#CS422 Project 2 clustering.py

import numpy as np
import scipy.spatial as sc

def K_Means(X,K,mu):
	clusters = []
	counter = 0
	for k in range(0,K):
		clusters.append([])
	cluster = []
	prevmu = np.array([]);
	
	#random mu initialization
	if mu.size == 0:
		L1 = list(np.random.choice(len(X), K, replace = False))
		for k in range(0,K):
			L1[k] = [L1[k]]
		print("Mu:", L1)
		mu = np.array(L1)
	#random + given mu initialization, up to K mu values
	elif mu.size != K:
		L = []
		listChoices = []
		for c in range(0, len(X)):
			listChoices.append(c)
		print(listChoices)
		for j in range(0, mu.size):
			L.append(list(mu[j]))
			value = list(mu[j])
			listChoices.remove(value[0])
		L1 = list(np.random.choice(listChoices, (K-mu.size), replace = False))
		for k in range(0,(K-mu.size)):
			L1[k] = [L1[k]]
			L.append(L1[k])
		print("Mu:", L)
		mu = np.array(L)
	#Given mu
	else:
		print("Mu:", mu)

	#Go until convergence when break happens
	while True:
		clusters = []
		for k in range(0,K):
			clusters.append([])	
			
		calcmu = []
		#calculate new mu
		for j in range(0, len(X)):
			distance = []
			for i in range(0, K):
				#given sample point indexes starting. always needs to start with index
				if counter == 0:
					if not isinstance(X[j],np.ndarray):
						distance.append(sc.distance.euclidean([X[j]], [X[mu[i][0]]]))
					else:
						distance.append(sc.distance.euclidean(X[j], X[mu[i][0]]))
			
				else:
					#For 1D
					if len(mu[i]) == 1:
						if not isinstance(X[j],np.ndarray):
							distance.append(sc.distance.euclidean([X[j]], [mu[i][0]]))
						else:
							distance.append(sc.distance.euclidean(X[j], mu[i][0]))
					#For 2D
					else:
						if not isinstance(X[j],np.ndarray):
							distance.append(sc.distance.euclidean([X[j]], [mu[i]]))
						else:
							distance.append(sc.distance.euclidean(X[j], mu[i]))
			
			#sort distances
			distanceIndex = np.argsort(distance)

			for k in range(0,K):
				if distanceIndex[0] == k:
					if not isinstance(X[j],np.ndarray):
						#print(X[j])
						clusters[k].append(X[j])
					else:
						#print(X[j])
						clusters[k].append(list(X[j]))

		#loop through each cluster
		for l in range(0,K):
			#if two points are same, one cluster will be empty, set calculated mu of the cluster to the point
			if clusters[l] == []:
				if counter == 0:
					clusters[l].append(list(X[mu[l][0]]))
					if not isinstance(clusters[l][0],list) and clusters[l] != []:
						calcmu.append([np.mean(clusters[l], axis = 0)])
					else:
						calcmu.append(list(np.mean(clusters[l], axis = 0)))
				else:
					clusters[l].append(mu[l])
					if not isinstance(clusters[l][0],list) and clusters[l] != []:
						calcmu.append([np.mean(clusters[l], axis = 0)])
					else:
						calcmu.append(list(np.mean(clusters[l], axis = 0)))
			#calculate mean as normal
			else:
				if not isinstance(clusters[l][0],list) and clusters[l] != []: #*******# CHECK THIS THING AGAIN LATER FOR OTHER CASES
					calcmu.append([np.mean(clusters[l], axis = 0)])
				else:
					calcmu.append(list(np.mean(clusters[l], axis = 0)))
		counter += 1
		
		#check if previous mu is equal to calculated mu
		if np.array_equal(calcmu,mu) == False:
			mu = calcmu
		else:
			break

	return mu
