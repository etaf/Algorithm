#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @return a string
    def intToRoman(self, num):
        dict = {"M":1000, "CM":900,"D":500,"CD":400,"C":100,"XC":90,"L":50,"XL":40,"X":10,"IX":9,"V":5,"IV":4,"I":1}
        symbols = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        result = ""
        for symbol in symbols:
            if num == 0:
                break
            count = num/dict[symbol]
            num = num%dict[symbol]
            while count > 0:
                result += symbol
                count -= 1
        return result

