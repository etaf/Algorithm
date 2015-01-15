#!/usr/bin/env python
# encoding: utf-8

class Solution:
# rotate matrix in place
# @param matrix, a list of lists of integers
# @return a list of lists of integers
    def rotate(self, matrix):
        n = len(matrix)
        for i in range( n/2):
            for j in range((n+1)/2):
                now = matrix[i][j]
                for k in range(4):
                    matrix[j][n-1-i],now = now,matrix[j][n-1-i]
                    i,j = j,n-1-i
        return matrix

if __name__ == "__main__":
    sol = Solution()
    matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    for row in matrix:
        print ' '.join(str(x) for x in row)
    print "=============="
    matrix = sol.rotate(matrix)
    print "=============="
    for row in matrix:
        print ' '.join(str(x) for x in row)

