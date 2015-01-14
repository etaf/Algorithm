#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
        fx = []
        fy = []
        for i in range(9):
            fx.append([0]*9)
            fy.append([0]*9)
        ft = []
        for i in range(3):
            ft.append([])
            for j in range(3):
                ft[i].append([0]*9)
        for i in range(9):
            for j in range(9):
                if  board[i][j].isdigit() == False:
                    continue
                v = int(board[i][j])-1
                if fx[i][v] :
                    return False
                fx[i][v] = 1
                if fy[j][v]:
                    return False
                fy[j][v] = 1
                if ft[int(i/3)][int(j/3)][v]:
                    return False
                ft[int(i/3)][int(j/3)][v] = 1
        return True

if __name__ == "__main__":
    board = [".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]
    sol = Solution()
    sol.isValidSudoku(board)

