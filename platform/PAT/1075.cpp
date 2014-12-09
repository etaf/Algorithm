#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 0x3fffffff
const int N = 10010;

typedef struct Pep
{
	int id,sc[8],sum,pn;
	bool exit;
	bool operator < (const Pep& z)const 
	{
		if(sum == z.sum)
		{
			if(pn == z.pn)
			{
				return id<z.id;
			}else
			{
				return pn>z.pn;
			}
		}else
		{return sum>z.sum;}
	}
}Pep;
Pep peps[N];
Pep ps[N];
int fm[8];
int n,k,m;
void output(int r,Pep pep)
{
	printf("%d %05d %d",r,pep.id,pep.sum);
	for(int i=0;i<k;++i)
	{
		if(pep.sc[i]==-2)printf(" -");
		else if(pep.sc[i] == -1)printf(" 0");
		else printf(" %d",pep.sc[i]);
	}
	printf("\n");
}
int main()
{

	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<k;++i)
	{
		scanf("%d",&fm[i]);
	}

	int uid,pid,score;

	for(int i=0;i<10001;++i)
	{
		peps[i].exit = false;
		peps[i].id = i;
		peps[i].pn = 0;
		for(int j=0;j<k;++j)
		{
			peps[i].sc[j] = -2;
		}
		peps[i].sum = 0;
	}
	while(m--)
	{
		scanf("%d%d%d",&uid,&pid,&score);
		--pid;
		peps[uid].sc[pid] = peps[uid].sc[pid] > score?peps[uid].sc[pid] : score;
		if(score>=0)
			peps[uid].exit = true;
	}
	int cnt = 0;
	for(int i=0;i<10001;++i)
	{
		if(peps[i].exit)
		{
			for(int j=0;j<k;++j)
			{
				if(peps[i].sc[j] == fm[j])++peps[i].pn;
				if(peps[i].sc[j]>=0)
					peps[i].sum += peps[i].sc[j];
			}
			ps[cnt++] = peps[i];
		}
	}
	sort(ps,ps+cnt);
	int r= 1,rt;
	for(int i=0;i<cnt;++i,++r)
	{
		output(r,ps[i]);rt = r;
		while(i+1<cnt && ps[i+1].sum == ps[i].sum)
		{
			output(r,ps[i+1]);
			++i;
			++rt;
		}
		r = rt;
	}
}