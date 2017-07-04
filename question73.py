class Solution(object):
    def setZeroes(self, matrix):
        if len(matrix)==0 or len(matrix[0])==0:
            return
        row,col=self.getRowCol(matrix)
        if row==-1:
            return
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                if matrix[i][j]==0:
                    matrix[row][j]=0
                    matrix[i][col]=0
        print(matrix)
        for i in xrange(len(matrix)):
            if matrix[i][col]==0 and i!=row:
                for j in xrange(len(matrix[0])):
                    matrix[i][j]=0
        for j in xrange(len(matrix[0])):
            if matrix[row][j]==0 and j!=col:
                for i in xrange(len(matrix)):
                    matrix[i][j]=0
        for i in xrange(len(matrix)):
            matrix[i][col]=0
        for j in xrange(len(matrix[0])):
            matrix[row][j]=0
        #return
    def getRowCol(self,matrix):
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                if matrix[i][j]==0:
                    return i,j
        return -1,-1
        #return i,j
        
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """