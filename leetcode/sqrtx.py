#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @param x, an integer
    # @return an integer
    def sqrt(self, x):
        l = 0.0
        r = float(x)
        while(int(l)!=int(r)):
            mid = (l+r)/2
            if mid * mid <= x:
                l = mid
            else:
                r = mid
        return int(l)
if __name__ == "__main__":
    sol = Solution()
    print sol.sqrt(15)

