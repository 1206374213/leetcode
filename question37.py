# Write a program to solve a Sudoku puzzle by filling the empty cells.

# Empty cells are indicated by the character '.'.

# You may assume that there will be only one unique solution.


# A sudoku puzzle...


# ...and its solution numbers marked in red.

class Solution(object):
    def solveSudoku(self, board):
        self.solution(board)
    def findUnsolved(self,board):
        for i in range(9):
            for j in range(9):
                if board[i][j]=='.':
                    return i,j
        return -1,-1
    def solution(self,board):
        row,col=self.findUnsolved(board)
        if row!=-1:
            for num in range(1,10):
                if self.checkRow(board,row,str(num)) and self.checkCol(board,col,str(num))and self.checkBox(board,row,col,str(num)):
                    board[row][col]=str(num)
                    if self.solution(board):
                        return True
                    board[row][col]='.'
            return False
        return True
    def checkRow(self,board,row,ch):
        for i in range(9):
            if board[row][i]==ch:
                return False
        return True
    def checkCol(self,board,col,ch):
        for i in range(9):
            if board[i][col]==ch:
                return False
        return True
    def checkBox(self,board,row,col,ch):
        x=col-col%3
        y=row-row%3
        for i in range(y,y+3):
            for j in range(x,x+3):
                if board[i][j]==ch:
                    return False
        return True
    
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modifify board in-place instead.
        """
        