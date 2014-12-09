#include<iostream>
#include<cstdio>
using namespace std;


void solve(int ca)
{
	double c,f,x;
	scanf("%lf%lf%lf",&c,&f,&x);
	double need1=x,need2=x,dt = 2;
	printf("Case #%d: ",ca);
	
	
	double ans=0;
	while(1)
	{
		need1 = x/dt;
		need2 = c/dt+x/(dt+f);
		if(need1>need2)
		{
			ans+=c/dt;
			dt+=f;
		}else
		{
			ans+=need1;
			break;
		}
	}
	printf("%.7lf\n",ans);

}
int main()
{
	int T;
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;++i)
	{
		solve(i);
	}
	return 0;
}