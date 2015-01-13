#!/usr/bin/env python
# encoding: utf-8
import re
class Solution:
    # @return a string
    def countAndSay(self, n):
        s1 = s2= '1'
        for i in range(n-1):
            len1 = len(s1)
            s2 = ""
            j=0
            while j<len1:
                cnt = 1
                while j+1<len1 and s1[j] == s1[j+1]:
                    j+=1
                    cnt+=1
                s2 += str(cnt) + str(s1[j])
                j+=1
            s1 = s2
        return s1;
class Solution_REGEX:
    # @return a string
    def countAndSay(self,n):
        p = re.compile(r'(.)\1*')
        now = '1'
        for i in xrange(n-1):
            prev = now
            now = "".join( str(m.end()-m.start())+prev[m.start()] for m in re.finditer(p, prev)  )
            #now = "".join( iter(str(m.end()-m.start())+prev[m.start()] for m in re.finditer(p, prev)  ))
        return now
if __name__ == '__main__':
    sol = Solution_REGEX()
    print sol.countAndSay(4)
