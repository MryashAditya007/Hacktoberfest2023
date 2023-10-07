# NQueen Problem

# Problem Statement: How can N queens be placed on an NxN chessboard so that no two of them attack each other?

# Problem Link: https://developers.google.com/optimization/cp/queens#:~:text=In%20chess%2C%20a%20queen%20can,of%20them%20attack%20each%20other%3F

# Solution:

N = int(input("enter the size of board: "))

board = [[0] * N for i in range(N)] # makes a matrix of NxX size.

# for j in range(N): # Alternative way of creating board of NxN size
#     temp = []
#     for i in range(N):
#         temp.append(0)
#     board.append(temp)

# print(board)

def isSafe(i, j):
    for p in range(N):
        if board[i][p] == 1 or board[p][j] == 1:
            return False
    
    for n in range(N):
        for m in range(N):
            if i+j == n+m or i-j == n-m:
                if board[n][m] == 1: 
                    return False
    return True

def nqueen(noq):
    if noq == 0:
        return True

    for i in range(N):
        for j in range(N):
            if board[i][j] != 1 and isSafe(i, j):
                board[i][j] = 1
                if nqueen(noq-1) == True:
                    return True
                board[i][j] = 0
    return False

def printboard(board):
    for i in board:
        print(i)

if nqueen(N):
    printboard(board)
else:
    print("Can't place.")