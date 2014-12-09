#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

void count(const char* s,int& a,int & b,int& c)
{
	a=0;b=0;c=0;
	int i=0;
	for(;s[i]!='+';++i,++a);
	for(++i;s[i]!='=';++i,++b);
	for(++i;s[i];++i,++c);
}
void output(const char* s,int a,int b,int c)
{
	int i=0;
	for(i=0;i<a;++i)putchar('|');
	putchar('+');
	for(i=0;i<b;++i)putchar('|');
	putchar('=');
	for(i=0;i<c;++i)putchar('|');
	putchar('\n');
}
int main()
{
	char s[1024];
	while(~scanf("%s",s))
	{
		int a,b,c;
		count(s,a,b,c);

		if(a+b == c)
		{
			output(s,a,b,c);
		}
		else if(a+b -1  == c+1)
		{
			output(s,a-1,b,c+1);
		}else if(a+b+1 == c-1)
		{
			output(s,a+1,b,c-1);
		}else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}