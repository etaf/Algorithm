#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int M = 110;
const int N = 10010;
int tab_p[M];
int tab_time[M];
int vip_tab[M];

int hms2s(int hh,int mm,int ss)
{
	return hh*3600+mm*60+ss;
}
typedef struct Pep
{
	int hh,mm,ss;
	int atime;
	int d;
	int vip;

	void get_atime()
	{
		atime = hh*3600+mm*60+ss;
	}
	bool operator<(const Pep& z)const
	{return atime<z.atime;}

}Pep;
Pep ps[N];
queue<int> qvip;
bool vis[N];
int main()
{
	//freopen("in","r",stdin);
	int n,i,j,hh,mm,ss,vip;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d:%d:%d %d %d",&ps[i].hh,&ps[i].mm,&ps[i].ss, &ps[i].d,&ps[i].vip);
		ps[i].d = ps[i].d<120?ps[i].d:120;
		ps[i].d*=60;
		ps[i].get_atime();
	}
	int k,m;
	scanf("%d%d",&m,&k);

	for(i=0;i<k;++i)
	{
		scanf("%d",&vip_tab[i]);
		--vip_tab[i];
	}
	sort(vip_tab,vip_tab+k);
	sort(ps,ps+n);
	int p,q;
	p=0;q=0;
	int st = 8*3600;
	int et = 21*3600;

	for(;q<n && ps[q].atime<st;++q)
	{
		if(ps[q].vip)
		{
			qvip.push(q);
		}
	}
	int u;
	for(int t=st;t<et;++t)
	{

		for(;q<n && ps[q].atime<=t;++q)
		{
			if(ps[q].vip)
			{
				qvip.push(q);
			}
		}
		//viptab find vip
		for(i=0;i<k;++i)
		{
			if(tab_time[vip_tab[i]] == 0 && !qvip.empty())
			{
				u = qvip.front();
				vis[u] = 1;
				qvip.pop();
				tab_time[vip_tab[i]] = ps[u].d;
				++tab_p[vip_tab[i]];
				printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",ps[u].hh,ps[u].mm,ps[u].ss,t/3600,(t%3600)/60,t%60,(t-ps[u].atime+30)/60);
			}
		}
		for(i=0;i<m;++i)
		{
			
			if(tab_time[i]==0)
			{

				while(p<q && vis[p])++p;
				if(p<q)
				{
					tab_time[i] = ps[p].d-1;
					
					tab_p[i]++;
					if(ps[p].vip)
						qvip.pop();
					vis[p] = 1;
					printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",ps[p].hh,ps[p].mm,ps[p].ss,t/3600,(t%3600)/60,t%60,(t-ps[p].atime+30)/60);
					++p;
				}
					
			}else
			{
				--tab_time[i];
			}
		}
	}
	printf("%d",tab_p[0]);
	for(int i=1;i<m;++i)
		printf(" %d",tab_p[i]);
	printf("\n");
	return 0;
}