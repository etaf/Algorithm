#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        len_A = len(A)
        ans = 0
        for i in range(len_A):
            if (i+2<len_A and A[i+2] != A[i]) or (i+2 >= len_A):
                A[ans] = A[i]
                ans +=1
        #print A[0:ans]
        return ans;
if __name__ == '__main__':
    sol =  Solution()
    print sol.removeDuplicates([1,2,3])

