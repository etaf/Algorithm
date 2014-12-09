 
/*
dp[i] 表示以第i个数结尾的序列的最长递增子序列长度
dp[i] = max( dp[ t= 1:i-1 ] )+1				where a[t]<a[i]
复杂度O(n^2)

非dp算法 O(nlog(n))：

维护一个 有序数组，st[]，st[i] 为 长度为i的递增子序列的最末数的最小值。

对于a[i] , if(a[i]>st[len-1]) st[len++] = a[i]; else 二分查找 st 中 第一个 st[k] >= a[i] 的数，替换之。

4 5 6 3 1 2 3 5 6
*/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 100001;

int st[N];
int main()
{
	int n,x,p;
	while(~scanf("%d",&n))
	{
	int len = 1;
	scanf("%d",&st[0]);
	for(int i=1;i<n;++i)
	{
		scanf("%d",&x);
		if(st[len-1]<x)
			st[len++]=x;
		else
		{
			p = lower_bound(st,st+len,x)-st;
			st[p] = x;
		}
	}
	printf("%d\n",len);
	}
	return 0;
}
        