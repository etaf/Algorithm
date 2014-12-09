#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int m;
void preprocess(char* s,int& k)
{

	
	char t[1024];
	int i,j;
	
	int cnt= 0;
	int len=strlen(s);
	int pp = len;
	for(i=0;i<len;++i)
	{
		if(s[i] != '0' && s[i]!='.')break;
	}
	if(i==len)
	{
		s[0] = '0';
		s[1] = '.';
		for(j=0;j<m;++j)s[j+2]='0';
		s[j+2]=0;
		k=0;
		return;
	}

	for(i=0;s[i]=='0';++i);

		//i---strlen(i)	
		for(j=i;j<len;++j)
		{	if(s[j] == '.')
			{
				pp = j;
				break;
			}
		}
		k = pp-i;
		if(pp == i)
		{
			for(j=pp+1;j<len && s[j] == '0' ;++j)--k;
			
			i=j;	
		}
		
		t[0] = '0';t[1]='.';
		int cntt=2;
		for(j=0;cntt-2<m && j+i<len;++j)
		{
			if(s[j+i]=='.')continue;
			t[cntt++] = s[j+i];
		}
		while(cntt-2<m)
			t[cntt++]='0';
		t[cntt++]=0;
		strcpy(s,t);



}
int main()
{
	char s1[1024],s2[1024];
	int k1,k2;
	scanf("%d %s %s",&m,s1,s2);
	preprocess(s1,k1);
	preprocess(s2,k2);

	if(strcmp(s1,s2)==0 && k1 == k2)
	{
		printf("YES %s*10^%d\n",s1,k1);
	}else
	{
		printf("NO %s*10^%d %s*10^%d\n",s1,k1,s2,k2);
	}

}

/*
3 0.1 0.001 
3 0.00 00.00 
3 0.0000 00.0
*/