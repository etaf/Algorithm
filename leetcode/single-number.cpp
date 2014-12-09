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
using namespace std;

class Solution {

public:

    int singleNumber(int A[], int n) {
        int ans = 0;
        for(int i=0;i<n;++i){
           ans ^= A[i]; 
        }
        return ans;
    }

};
int main()
{
	return 0;
}


