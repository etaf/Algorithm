 
/*
dp[i] ��ʾ�Ե�i������β�����е�����������г���
dp[i] = max( dp[ t= 1:i-1 ] )+1				where a[t]<a[i]
���Ӷ�O(n^2)

��dp�㷨 O(nlog(n))��

ά��һ�� �������飬st[]��st[i] Ϊ ����Ϊi�ĵ��������е���ĩ������Сֵ��

����a[i] , if(a[i]>st[len-1]) st[len++] = a[i]; else ���ֲ��� st �� ��һ�� st[k] >= a[i] �������滻֮��

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
        