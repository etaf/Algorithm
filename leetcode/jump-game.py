#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        last_index = len(A)-1
        r = A[0]
        l = 0
        while l<=r:
            if r>=last_index:
                return True
            r = max(r,l+A[l])
            l+=1
        return False

if __name__ == "__main__":
    A = [2,3,1,1,4]
    B = [3,2,1,0,4]
    sol = Solution()
    print sol.canJump(A)
    print sol.canJump(B)
