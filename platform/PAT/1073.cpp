#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<queue>
using namespace std;
#define INF 0x3fffffff
char s[20010];
char p0,p1,p2[10010],e1,e2;
int main()
{
	scanf("%s",s);
	p0 = s[0];
	if(p0=='-')printf("-");
	p1 = s[1];
	int cntp2=0;
	int i=3;
	for(;s[i]!='E';++i)
	{
		p2[cntp2++]=s[i];
	}
	p2[cntp2] = 0;
	++i;
	e1 = s[i++];
	int en = 0;
	for(;s[i];++i)
	{
		en =  en*10+s[i]-'0';
	}
	int p2_len = strlen(p2);
	if(e1 == '+')
	{
		printf("%c",p1);
		for(i=0;i<p2_len && i<en;++i)
		{
			printf("%c",p2[i]);
		}
		if(i<p2_len)
		{
			printf(".");
			while(i<p2_len)printf("%c",p2[i++]);
		}
		while(i<en)
		{
			printf("0");
			++i;
		}
		printf("\n");
	}else
	{
		if(en ==0)
		{
			printf("%c.",p1);
			for(i=0;p2[i];++i)printf("%c",p2[i]);
			printf("\n");
		}
		else 
		{
			printf("0.");
			for(i=1;i<en;++i)
			{
				printf("0");
			}
			printf("%c",p1);
			for(i=0;p2[i];++i)printf("%c",p2[i]);
			printf("\n");
		}

	}
}
