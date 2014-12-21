#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<cstdlib>
using namespace std;
/*
 * 1 -> A
 * 2 -> B
 * 3 -> C
 * ...
 * 26 -> Z
 * 27 -> AA
 * 28 -> AB
 * ...
 * 52 -> AZ
 * 53 -> BA
 * ...
 * 26*26 -> YZ
 * 
 * 26 based, when n%26 == 0 , we borrow the higher position a 1 to make it Z,not zero.
 */
class Solution {
public:
    string convertToTitle(int n) { 
        string ans;
        while(n){
            if(n%26)
            {
                ans.push_back(n%26 -1 + 'A');
                n/=26;
            }
            else
            {
                ans.push_back('Z');
                n/=26;
                --n;
            }
        }
        int l =0,r= ans.size()-1;
        while(l<r)swap(ans[l++],ans[r--]);
        return ans;
    }
};
int main()
{
    Solution sol;
    cout<<sol.convertToTitle(53)<<endl;
	return 0;
}


