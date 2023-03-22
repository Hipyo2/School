#Nicholas Ang
#CS482
#Project 1


# Import libraries
import numpy as np
import pandas as pd
import argparse

#USING string library for string.punctuation, string methods such as replace, isdigit, etc
import string

#USING nltk library for set of stopwords to remove from messages
import nltk

#USING re library to remove http and email from messages
import re

#Downloads stopwords to be able to be accessed
nltk.download('stopwords')

class NaiveBayesFilter:
    def __init__(self, test_set_path):
        self.vocabulary = None
        self.training_set= None
        self.test_set = None
        self.p_spam = None
        self.p_ham = None
        self.test_set_path = test_set_path
        #My own added variables
        self.sdf = None
        self.hdf = None
        self.classifyVector = None
        self.wispam = None
        self.wiham = None


    def read_csv(self):
        self.training_set = pd.read_csv('train.csv', sep=',', header=0, names=['v1', 'v2'], encoding = 'utf-8')
        self.test_set = pd.read_csv(self.test_set_path, sep=',', header=0, names=['v1', 'v2'], encoding = 'utf-8')


    def data_cleaning(self):
        # Normalization
        # Replace addresses (hhtp, email), numbers (plain, phone), money symbols
        # Remove the stop-words

	#nltk library STOP WORDS set of english stop words
        stopWords = set(nltk.corpus.stopwords.words('english'))
        
        #initialization of tokenized list of word lists, vocabulary list of words, dictionary
        tokenized = []
        self.vocabulary = []
        dictionary = {}

	#removes numbers, special punctuation, emails, http, and money symbols
        for i in range(0, len(self.training_set)):
        
        	#make sentence lower case to remove any differences due to either intentional or unintentional capitalizations of letters
        	self.training_set.v2[i] = self.training_set.v2[i].lower()
        	#remove url
        	self.training_set.v2[i] = re.sub(r"http\S+", "", self.training_set.v2[i])
        	self.training_set.v2[i] = re.sub(r"\S+@\S+.\S+", "", self.training_set.v2[i])
        	
        	#Looks at each character - checks if digit to remove, if char is money symbol to remove, if char is a punctuation character to remove
        	for char in self.training_set.v2[i]:
        		#remove digits
        		if char.isdigit():
        			self.training_set.v2[i] = self.training_set.v2[i].replace(char, "")
        		#remove money symbols
        		elif char == "$" or char == "€" or char == "£" :
        			self.training_set.v2[i] = self.training_set.v2[i].replace(char, "")
        		#remove punctuation
        		elif char in string.punctuation:
        			self.training_set.v2[i] = self.training_set.v2[i].replace(char, "")
        			
        	#Splits the sentence into individual words to check for stop words
        	sentence = self.training_set.v2[i].split()
        	notRemoved = []

        	#iterates through each word in sentence
        	for sentenceWords in sentence:
        			#checks if word is not a word in the stopWords set, if not in stopWords, dont add to cleaned sentence
        			if sentenceWords not in stopWords:
        				notRemoved.append(sentenceWords)

		#Add words of each sentence into vocabulary
        	for words in notRemoved:
        		self.vocabulary.append(words)
        	#Add sentence to tokenized list, tokenized is list of sentences 
        	tokenized.append(notRemoved)
        	

        
        # Lemmatization - Graduate Students

        # Stemming - Gradutate Students

        # Tokenization

        # Vectorization

        # Remove duplicates - Can you think of any data structure that can help you remove duplicates?
	#ie sets ###
	#Make vocabulary a set to get rid of duplicates and then turn it into a list so its easier to maintain relative order and indexing
        self.vocabulary = list(set(self.vocabulary))
        
	#Create a dictionary with every word in vocab as a key and value is empty list to append to
        dictionary = {key: [] for key in self.vocabulary}

	#for each sentence, count how many times each word shows up and add to key(word) : value (count of words in each sentence)
        for word in self.vocabulary:
        	for i in range(0, len(tokenized)):
        		count = tokenized[i].count(word)
        		dictionary[word].append(count)
        		
        # Convert to dataframe 
        df = pd.DataFrame(dictionary)
        print(df)
        
        # Separate the spam and ham dataframes
        self.sdf = pd.DataFrame()
        self.hdf = pd.DataFrame()
        for j in range(0, len(df)):
        	#if spam sentence, add row to spam dataframe, otherwise add to ham dataframe
        	if self.training_set.v1[j] == "spam":
        		self.sdf = pd.concat([self.sdf, df.iloc[[j]]])
        	else:
        		self.hdf = pd.concat([self.hdf, df.iloc[[j]]])

    def fit_bayes(self):
        # Calculate P(Spam) and P(Ham)
        #initialized lists and values
        p_wispam = []
        Nwspam = []
        Nwham = []
        p_wiham = []
        spamCount = 0
        hamCount = 0
        
        #Count # of spam and # of ham in training set
        for i in range(0, len(self.training_set)):
        	if self.training_set.v1[i] == "spam":
        		spamCount += 1
        	else:
        		hamCount += 1
        #Calculate probability of spam and ham respectively
        self.p_spam = spamCount/len(self.training_set)
        self.p_ham = hamCount/len(self.training_set)
        
        # Calculate Nspam, Nham and Nvocabulary
        Nvocab = len(self.vocabulary)
        
        #calculate the number of times a word appears in spam messages and ham messages
        for word in self.vocabulary:
        	Nwspam.append(self.sdf[word].sum())
        	Nwham.append(self.hdf[word].sum())
        	
        # Laplace smoothing parameter
        #Smoothing prevents 0 probability words
        alpha = 1
        
        # Calculate P(wi|Spam) and P(wi|Ham)
        # P(wi|S) = (num of word in spam messages + alpha )/ (total number of words*alpha + number of spam messages)
        for i in range(0, len(self.vocabulary)):
        	p_wispam.append(((Nwspam[i]+alpha)/(spamCount + (alpha*Nvocab))))
        	p_wiham.append(((Nwham[i]+alpha)/(hamCount + (alpha*Nvocab))))
        self.wispam = p_wispam
        self.wiham = p_wiham

    def train(self):
        self.read_csv()
        self.data_cleaning()
        self.fit_bayes()
    
    def sms_classify(self, message):
        '''
        classifies a single message as spam or ham
        Takes in as input a new sms (w1, w2, ..., wn),
        performs the same data cleaning steps as in the training set,
        calculates P(Spam|w1, w2, ..., wn) and P(Ham|w1, w2, ..., wn),
        compares them and outcomes whether the message is spam or not.
        '''
        #SAME DATA CLEANING AS IN DATA CLEANING FUNCTION BUT FOR 1 SENTENCE
        #nltk stop words set
        stopWords = set(nltk.corpus.stopwords.words('english'))
        #make all lower case
        message = message.lower()
        
	#remove url and emails
        message = re.sub(r"http\S+", "", message)
        message = re.sub(r"\S+@\S+.\S+", "", message)
        
	#remove numbers, money symbols, punctuation
        for char in message:
        	#remove digits
        	if char.isdigit():
        		message = message.replace(char, "")
        	#remove money symbols
        	elif char == "$" or char == "€" or char == "£" :
        		message = message.replace(char, "")
        	#remove punctuation
        	elif char in string.punctuation:
        		message = message.replace(char, "")
        		
        #Split message into individual words
        sentence = message.split()
        notRemoved = []
        
        #Add words in sentence that are not stop words into notRemoved list
        for sentenceWords in sentence:
        		if sentenceWords not in stopWords:
        			notRemoved.append(sentenceWords)
        
        
        #Bayes theorem: P(S|W) = P(S) * P(W|S)/P(W)
        #P(W|S) = P(wi|S) * P(w(i+1)|S) * ...
        PWS = self.p_spam
        PWH = self.p_ham
        for word in notRemoved:
        	#only look at words in vocabulary since you calculated their probabilities
        	if word in self.vocabulary:
        		PWS = PWS * self.wispam[self.vocabulary.index(word)]
        		PWH = PWH * self.wiham[self.vocabulary.index(word)]
        Pwords = PWS + PWH
        PWSF = PWS/Pwords
        PWHF = PWH/Pwords
        
        #if P(H|W) > P(S|W) return as ham message
        #if P(S|W) > P(H|W) return as spam message
        #otherwise cant classify
        if PWHF > PWSF:
        	return "ham"
        elif PWSF > PWHF:
        	return "spam"
        else:
        	return "nhc"

        # if p_ham_given_message > p_spam_given_message:
        #     return 'ham'
        # elif p_spam_given_message > p_ham_given_message:
        #     return 'spam'
        # else:
        #     return 'needs human classification'

    def classify_test(self):
        '''
        Calculate the accuracy of the algorithm on the test set and returns 
        the accuracy as a percentage.
        '''
        #Call train so that it reads the training file and the test file, setting test and training set
        self.train()
        self.classifyVector = []
        sumCorrect = 0
        
        #Classify each message in test set and add to classifyVector, compare result of classification to actual label
        #If correct, +1, otherwise +0.
        for i in range(0, len(self.test_set)):
        	self.classifyVector.append(self.sms_classify(self.test_set.v2[i]))
        
        	if self.test_set.v1[i] == self.classifyVector[i]:
        		sumCorrect += 1
        		
        #Accuracy is (total correct/test set length) * 100 for percentage
        accuracy = (sumCorrect / len(self.test_set.v1))*100
        return accuracy

#Main
if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Naive Bayes Classifier')
    parser.add_argument('--test_dataset', type=str, default = "test.csv", help='path to test dataset')
    args = parser.parse_args()
    classifier = NaiveBayesFilter(args.test_dataset)
    acc = classifier.classify_test()
    print("Accuracy: ", acc, "%")
