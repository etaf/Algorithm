#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int dec(int* c)
{
	sort(c,c+4);

	int res = 0;

	for(int i=3;i>=0;--i)
	{
		res = res*10+c[i];
	}
	return res;
}
int inc(int* c)
{
	sort(c,c+4);
	int res = 0;
	for(int i=0;i<4;++i)
	{
		res = res*10+c[i];
	}
	return res;
}

void get_c(int* c,int x)
{
	for(int i=0;i<4;++i)c[i] = 0;
	int ccnt=0;
	while(x)
	{
		c[ccnt++] = x%10;
		x/=10;
	}
}
int main()
{
	char s[64];
	int a[64],b[64],c[64]={0};
	int x,d1,i1;
	while(~scanf("%s",s))
	{
//		if(strcmp(s,"6174") == 0)continue;
		int ccnt=3;
		for(int i=0;s[i];++i)
		{
			c[ccnt--]=s[i]-'0';
		}

		d1 = dec(c);
		i1 = inc(c);
		x = d1-i1;
			
		printf("%04d - %04d = %04d\n",d1,i1,x);	

		while(x!=0 && x!=6174)
		{
			get_c(c,x);
			d1 = dec(c);
			i1 = inc(c);
			x = d1-i1;
			printf("%04d - %04d = %04d\n",d1,i1,x);
		}

	}


	return 0;
}