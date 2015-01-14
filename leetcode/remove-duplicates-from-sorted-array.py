#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        len_A = len(A)
        ans = 0
        for i in range(len_A):
            if (i+1<len_A and A[i+1] != A[i]) or (i+1 == len_A):
                A[ans] = A[i]
                ans +=1
        return ans;
if __name__ == '__main__':
    sol =  Solution()
    print sol.removeDuplicates([1,2,2,3])

