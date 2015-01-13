#!/usr/bin/env python
# encoding: utf-8

class Solution:
    # @return a boolean
    def isValid(self, s):
        stack = []
        for c in s:
            if(len(stack) == 0 and (c ==')' or c == ']' or c == '}')):
                return False
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
                continue
            if (c == ')' and stack[-1] == '(') or (c == ']' and stack[-1] == '[') or (c == '}' and stack[-1] == '{'):
                stack.pop()
            else:
                stack.append(c)
        return len(stack) == 0
if __name__ == '__main__':
    sol = Solution()
    print sol.isValid("(])")
