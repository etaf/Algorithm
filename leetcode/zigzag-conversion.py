#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @return a string
    def convert(self, s, nRows):
        s_len  = len(s)
        i = 0
        mt = []
        nowx = 0
        nowy = 0
        if nRows == 1:
            return s
        while i < s_len:
            print nowx , nowy
            if nowy == 0:
                mt.append([' ']*nRows)
                dx = 0
                dy = 1
            elif nowy == nRows-1:
                dx = 1
                dy = -1
            if dx == 1:
                mt.append([' ']*nRows)
            mt[nowx][nowy] = s[i]
            i+=1
            nowx+=dx
            nowy+=dy

        res = ""
#        for i in mt:
            #print i
        for j in range(nRows):
            for i in range(len(mt)):
                if mt[i][j] != ' ':
                    res+= mt[i][j]
        return res
if __name__ == "__main__":
    sol = Solution()
    #print sol.convert("PAYPALISHIRING",3)
    #print sol.convert("ABCDEFGHIJKLMN",4)
    print sol.convert("AB",1)
