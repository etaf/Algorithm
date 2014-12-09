//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//#define INF 0x3fffffff
//
//typedef struct Pep
//{
//	int age, v;
//	char name[10];
//	
//	bool operator < (const Pep& z)const 
//	{
//		return age<z.age;
//	}
//}Pep;
//Pep ps[100010];
//
//
//bool cmp(Pep x, Pep y)
//{
//	return (x.v>y.v || (x.v == y.v && x.age<y.age) || ( x.v == y.v && x.age == y.age && strcmp(x.name,y.name)<0));
//}
//int main()
//{
//	int n,m;
//	scanf("%d%d",&n,&m);
//	for(int i=0;i<n;++i)
//	{
//		scanf("%s%d%d",&ps[i].name,&ps[i].age,&ps[i].v);
//	}
//	sort(ps,ps+n);
//
//	int anst = 0;
//	int mp,l,r;
//	Pep ll;
//	Pep rr;
//	for(int ca = 1;ca<=m;++ca)
//	{
//		printf("Case #%d:\n",ca);
//		scanf("%d%d%d",&mp,&ll.age,&rr.age);
//
//		l = lower_bound(ps,ps+n,ll)-ps;
//		r = upper_bound(ps,ps+n,rr)-ps-1;
//
//		if(l == n || r<l)
//		{
//			printf("None\n");
//			continue;
//		}
//		for(int i=l;i<=r;++i)
//		{
//			ansp[i-l] = ps[i];
//		}
//		sort(ansp,ansp+r-l+1,cmp);
//		for(int i=0;i<mp && i<r-l+1;++i)
//		{
//			printf("%s %d %d\n",ansp[i].name,ansp[i].age,ansp[i].v);
//		}
//	}
//
//}
//



#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 0x3fffffff

typedef struct Pep
{
	int age, v;
	char name[10];

	bool operator < (const Pep& z)const 
	{
		return age<z.age;
	}
}Pep;
Pep ps[100010];
Pep ansp[100010];
Pep ps2[100010];
bool cmp(Pep x, Pep y)
{
	return (x.v>y.v || (x.v == y.v && x.age<y.age) || ( x.v == y.v && x.age == y.age && strcmp(x.name,y.name)<0));
}
int main()
{
	int n,m;

	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	{
		scanf("%s%d%d",&ps[i].name,&ps[i].age,&ps[i].v);

		ps2[i] = ps[i];
	}

	sort(ps,ps+n,cmp);
	sort(ps2,ps2+n);

	int anst = 0;
	int mp,l,r,cnt,xl,xr;
	Pep ll;
	Pep rr;
	for(int ca = 1;ca<=m;++ca)
	{
	
		scanf("%d%d%d",&mp,&l,&r);
		printf("Case #%d:\n",ca);
		ll.age = l;
		rr.age = r;
		xl = lower_bound(ps2,ps2+n,ll)-ps2;
		xr = upper_bound(ps2,ps2+n,rr)-ps2-1;

		if(xl == n || xr<xl)
		{
			printf("None\n");
			continue;
		}

		if(xr-xl<10000)
		{
			for(int i=xl;i<=xr;++i)
			{
				ansp[i-xl] = ps2[i];
			}
			sort(ansp,ansp+xr-xl+1,cmp);
			for(int i=0;i<mp && i<xr-xl+1;++i)
			{
				printf("%s %d %d\n",ansp[i].name,ansp[i].age,ansp[i].v);
			}
		}

		else
		{
			cnt=0;
			for(int i=0;i<n && cnt<mp;++i)
			{
				if(l<=ps[i].age && ps[i].age<=r)
				{
					++cnt;
					printf("%s %d %d\n",ps[i].name,ps[i].age,ps[i].v);
				}
			}
			if(cnt==0)printf("None\n");
		}
	}

}
