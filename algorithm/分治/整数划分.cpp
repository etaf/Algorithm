#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

#define INF 0x3fffffff

/*整数划分问题
	
	 6
     5+1

     4+2   4+1+1

     3+3   3+2+1  3+1+1

     2+2+2 2+2+1+1 2+1+1+1+1

     1+1+1+1+1+1
	
	输出划分数
*/

int dfs(int n,int m)
{
	if(m==1)return 1;
	if(n<m)return dfs(n,n);
	if(n==m)return 1+dfs(n,n-1);
	return dfs(n,m-1)+dfs(n-m,m);
}


void num_div(int n)
{
	printf("%d\n",dfs(n,n));
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		num_div(n);

	}
}