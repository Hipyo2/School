#Nicholas Ang
#CS422
#Project 4 PCA.py

#Libraries
import numpy as np
import matplotlib.pyplot as plt

#Compute Covariance Matrix
def compute_covariance_matrix(Z):
	#transpose and multiple Zt with Z
	zt = Z.transpose()
	cov = np.matmul(zt,Z)
	return cov
	
#Calculate Principal components	
def find_pcs(cov):
	#Calculate eigenvalues and eigenvectors
	L, pcs = np.linalg.eig(cov)
	return pcs, L
	
#Project the data onto principal component
def project_data(Z, PCS, L):
	#project onto most important principal component
	maxEigenIndex = np.argmax(L)
	zstar = np.matmul(Z, PCS[:,maxEigenIndex])
	return zstar

#Show as plot	
def show_plot(Z, Z_star):
	zx = []
	zy = []
	Z_stary = [0] * len(Z_star)
	#Split Z into x and y vectors
	for i in range(0,len(Z)):
		zx.append(Z[i][0])
		zy.append(Z[i][1])
	#Plot original data
	plt.scatter(zx,zy)
	#Plot projected data with x values as projected and y values as 0
	plt.scatter(Z_star,Z_stary)
	
	plt.show()
	return None

