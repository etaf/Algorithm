/*
二分
2014年1月06日 星期一 19:12:32 HKT	 答案正确	25	1044	C++ (g++)	40	3480	kite

题意： 给定一个数组，一个整数k 求 所有 和为k 的子序列，<begin,end> 若不存在和为k 求大于k且最近k 的所有子序列。
解：
枚举起点，二分终点，找最接近k且大于k的终点。
*/

#include<stdio.h>
#define INF 0x3fffffff
int n,k;
const int N = 100010;
int sum[N];

typedef struct Seg{
	
	int l,r,v;
	Seg(){}
	Seg(int _l,int _r,int _v):l(_l),r(_r),v(_v){}
	bool operator<(const Seg& z)const
	{
		return v<z.v;
	}
}Seg;
Seg seg[N+N];
int sct;
int bsearch(int st,int l,int r)
{//find first larger than k
	while(l<r)
	{
		int mid = (l+r) >> 1;
		if(sum[mid]-st>= k)
			r = mid;
		else
			l = mid+1;
	}
	return r;
}
int main()
{

	scanf("%d%d",&n,&k);
		
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}

	int minn = INF;
	sct = 0;
	int tmp;
	for(int i=1,j;i<=n;++i)
	{
		j = bsearch(sum[i-1],i,n);
		tmp = sum[j]-sum[i-1];
		if(tmp>=k)
		{
			minn = minn<tmp?minn:tmp;
			seg[sct++] = Seg(i,j,tmp);
		}
	}

	for(int i=0;i<sct;++i)
	{
		if(seg[i].v == minn)
			printf("%d-%d\n",seg[i].l,seg[i].r);
	}

	return 0;
}