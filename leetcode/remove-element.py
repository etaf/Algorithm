#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        if A == [] :
            return 0
        l = 0
        r = len(A)-1
        while l<r:
            if A[l] == elem:
                while l<r and  A[r] == elem:
                    r = r-1
                if l == r:
                    return l
                else:
                    A[l],A[r] = A[r],A[l]
            l = l+1
        return l if A[l] == elem else l+1
if __name__ == '__main__':
    sol = Solution()
    #A = [1,2,1,2,3]
    A = []
    n = sol.removeElement(A,1)
    print A[0:n]

