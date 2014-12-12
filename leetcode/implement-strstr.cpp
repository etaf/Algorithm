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
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) { //KMP
        int n = strlen(haystack);
        int m = strlen(needle);
        int *next = new int[m];
        get_next(needle,next,m);
        int i=0,j=0;
        while(i<n && j<m)
        {
            if( j == -1 || haystack[i] == needle[j])++i,++j;
            else j = next[j];
        }
        if( j == m) return i-m;
        else return -1;
    }
    void get_next(char* pattern, int* next, int m){
        int i=0,j=-1;
        next[0] = -1;
        while(i<m-1){
            if(j == -1 || pattern[i] == pattern[j]) {
                ++j,++i;
                if(pattern[i] != pattern[j]) next[i] = j;
                else next[i] = next[j];
            }
            else j = next[j];
        }

    }

};
void test(){
    //char str[] = "abcdabaabetffsdafdsa";
    //char p[] = "abet";
    //char str[] = "bbbbababbbaabbba";
    //char p[] = "abb";
    char str[] = "abab";
    char p[] = "ab";
    Solution sol;
    cout<<sol.strStr(str,p)<<endl;
}
int main()
{
    test();
	return 0;
}


