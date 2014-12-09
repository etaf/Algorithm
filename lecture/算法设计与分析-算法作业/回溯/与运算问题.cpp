/*ËÑË÷ +¼ôÖ¦*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef __int64 llong;

llong minn;
int n,m;
llong a[40];
llong c[40];

void dfs(int cnt,int p,llong v)
{
	minn = minn<v?minn:v;
	if(cnt == m )return;
	if(p<n)
	{

		for(int i=p;i<n;++i)
		{
			if( (v & c[i]) < minn)
			{
				dfs(cnt+1,i+1,v&a[i]);
			}
		}
	}
}
int main()
{

	scanf("%d%d",&n,&m);
	int i;
	for(i=0;i<n;++i)scanf("%I64d",a+i);

	sort(a,a+n);

	c[n-1]=a[n-1];
	for(i=n-2;i>=0;--i)
		c[i] = a[i]&c[i+1];

	minn = 1;
	minn = minn << 62;
	dfs(0,0,minn-1);
	printf("%I64d\n",minn);


	return 0;
}


        