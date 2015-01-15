#!/usr/bin/env python
# encoding: utf-8
import sys
class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
        dp = [sys.maxint]*len(grid[0])
        dp[0] = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                dp[j] = grid[i][j] + (min(dp[j],dp[j-1]) if j>0 else dp[j])
        return dp[len(grid[0])-1]

if __name__ == "__main__":
    sol = Solution()
    grid = [[1,2,3],[3,2,1],[1,0,1]]
    print sol.minPathSum(grid)
