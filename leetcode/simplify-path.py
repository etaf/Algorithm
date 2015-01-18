#!/usr/bin/env python
# encoding: utf-8
class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        dis = path.split('/')
        st = ['']
        for dir_name in dis:
            if dir_name == "..":
                if len(st)>1:
                    st.pop()
            elif dir_name != "." and dir_name!='':
                st.append(dir_name)

        return '/'.join(st) or '/'


if __name__ == "__main__":
    sol = Solution()
    print sol.simplifyPath("/")
