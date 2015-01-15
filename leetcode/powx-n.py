#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @param x, a float
    # @param n, a integer
    # @return a float
    def pow(self, x, n):
        res = 1
        if n <0:
            x = 1/x
            n = -n
        while n:
            if n&1:
                res *= x
            n >>= 1
            x = x*x
        return res
if __name__ == "__main__":
    sol = Solution()
    print sol.pow(2.0,-5)
