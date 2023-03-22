#!/usr/bin/python3
#Nicholas Ang
#Project 0
#CS482


import numpy as np
import argparse

class TicTacToe:
	def __init__(self, board=None, player=1) -> None:
		if board is None:
			self.board = self.init_board()
		else:
			self.board = board
		self.player = player

	def init_board(self):
		return np.array([[0,0,0],[0,0,0],[0,0,0]])

	def print_board(self):
		print (self.board)

	def eval_win(self):
		# TODO: Implement how to evaluate a win
		#Check columns and rows for equal values
		for i in range(0,3):
			if (self.board[i][0] == self.board[i][1] == self.board[i][2]) and self.board[i][0] != 0:
				return self.board[i][0]
			elif (self.board[0][i] == self.board[1][i] == self.board[2][i]) and self.board[0][i] != 0:
				return self.board[0][i]
		#Check diagonals for equal values
		if (self.board[0][0] == self.board[1][1] == self.board[2][2]) and self.board[0][0] != 0:
				return self.board[0][0]
		elif (self.board[2][0] == self.board[1][1] == self.board[0][2]) and self.board[2][0] != 0:
				return self.board[2][0]
		#Otherwise draw
		else:
			return 0

	def play_game(self):
		# some while loop 
		#Loop until no moves left
		#self.player = -1
		while self.checkMoves() != 0:	
			#if win found, exit loop
			if self.eval_win() != 0:
				break	
			
			#minimax and make optimal move
			val,row,col = self.minimax()
			
			if row != -1 and col != -1:
				self.board[row][col] = self.player
			#swap player
			print(self.board)
			self.player = -self.player
		return self.board, self.eval_win()
		
	def checkMoves(self):
		#add up all 0 in numpy array
		sum = 0
		for i in range(0,3):
			for j in range(0,3):
				if self.board[i][j] == 0:
					#print("+1")
					sum += 1
				else:
					sum += 0
		return sum
		
	def changePlayer(self):
		#set player to opponent
		self.player = -self.player
		
	def minimax(self):
		#start with max if player is 1, start with min if player is -1
		if self.player == 1:
			return self.max()
		else:
			return self.min()
		
	def min(self):
		#check if win, lose, or draw
		value = self.eval_win()
		#if any winning move, send back who wins
		if value == -1:
			return value, -1,-1
		elif value == 1:
			return value, -1, -1
		#check if any more moves can be made and is not equal to a player value
		elif self.checkMoves() == 0 and value != -1:
			return 0, -1, -1
		
		#start min high
		bestMin = 1000
		bestRow = -1
		bestCol = -1
		#iterate through every row and column
		for i in range(0,3):
			for j in range(0,3):
				#if available space to make moves
				if self.board[i][j] == 0:
					#do the move
					self.board[i][j] = self.player
					
					#check opponents moves
					self.changePlayer()
					tempMin, tempRow,tempCol = self.max()
					#multiply by decision factor
					tempMin = tempMin * 0.9
					self.changePlayer()
					
					#if temp min value is less than best min, set the bestMin, bestRow, bestCol
					if bestMin > tempMin:
						bestMin = tempMin
						bestRow = i
						bestCol = j
					
					#undo move to be able to check other moves	
					self.board[i][j] = 0
		return bestMin,bestRow,bestCol
		
	def max(self):	
		#check if win, lose, or draw
		value = self.eval_win()
		#if any winning move, send back who wins
		if value == 1:
			return value, -1,-1
		elif value == -1:
			return value ,-1,-1
		#check if any more moves can be made and is not equal to a player value
		elif self.checkMoves() == 0 and value != 1:
			return 0, -1, -1
			
		#start max low		
		bestMax = -1000
		bestRow = -1
		bestCol = -1
		
		#iterate through every row and column
		for i in range(0,3):
			for j in range(0,3):
				#if available space to make move
				if self.board[i][j] == 0:
					#do the move
					self.board[i][j] = self.player
					
					#check moves of opponent
					self.changePlayer()
					#find optimal opponent move and try to minimize
					tempMax, tempRow,tempCol = self.min()
					#multiply by decision factor
					tempMax = tempMax * 0.9
					self.changePlayer()
					
					#if tempMax is bigger than best max, set bestMax to tempMax, bestRow to i, bestCol to j
					if bestMax < tempMax:
						bestMax = tempMax
						bestRow = i
						bestCol = j
					
					#undo move to be able to check other moves
					self.board[i][j] = 0
					
					
		return bestMax, bestRow, bestCol
		

def load_board( filename ):
	return np.loadtxt( filename)

# def save_board( self, filename ):
# 	np.savetxt( filename, self.board, fmt='%d')

def main():
	parser = argparse.ArgumentParser(description='Play tic tac toe')
	parser.add_argument('-f', '--file', default=None, type=str ,help='load board from file')
	parser.add_argument('-p', '--player', default=1, type=int, choices=[1,-1] ,help='player that playes first, 1 or -1')
	args = parser.parse_args()

	board = load_board(args.file) if args.file else None
	testcase = np.array([[ 0,0,0],
                             [-1,1,0],
                             [-1,0,0]])
	ttt = TicTacToe(testcase, args.player)
	# ttt.print_board()
	b,p = ttt.play_game()
	print("final board: \n{}".format(b))
	print("winner: player {}".format(p))

if __name__ == '__main__':
	main()
