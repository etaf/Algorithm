#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        dic = dict()
        ans = []
        for st in strs:
            hash_val = [0]*26
            for c in st:
                hash_val[ord(c)-ord('a')]+=1
            hash_val = ''.join([str(c) for c in hash_val])
            if not hash_val in dic :
                dic[hash_val] = []
            dic[hash_val].append(st)
        for ls in dic.values():
            if len(ls)>1:
                for s in ls:
                    ans.append(s)
        return ans


if __name__ == "__main__":
    sol = Solution()
    print sol.anagrams(["aeiou","ouiea","abc","cab"])

