#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @param num, a list of integers
    # @return a string
    def largestNumber(self, num):
        s = [str(x) for x in num]
        s.sort(lambda a,b : cmp(b+a,a+b))
        s = "".join(s).lstrip("0")
        return s or "0"

if __name__ == '__main__':
    sol = Solution()
    print sol.largestNumber([0,00,0])

