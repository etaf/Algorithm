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

    int climbStairs(int n) {

        int a = 1,b=1,c;



        for(int i=2;i<=n;++i){

            c = a+b;

            b = a;

            a = c;

        }

        return a;

    }

};
int main()
{
	return 0;
}


