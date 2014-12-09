#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef struct Node
{
	double num;
	double money;
	double price;

	Node(){}
	Node(double num1,double money1):num(num1),money(money1){}
	bool operator<(const Node& z)const
	{return price>z.price;}
}Node;
int main ()
{
	int n;
	
	double tot;
	Node products[1010];
	while(~scanf("%d%lf",&n,&tot))
	{
		for(int i=0;i<n;++i)
			scanf("%lf",&products[i].num);
		for(int i=0;i<n;++i)
		{
			scanf("%lf",&products[i].money);
			products[i].price = products[i].money/products[i].num;
		}
		sort(products,products+n);
		double ans= 0;
		for(int i =0;i<n && tot>0;++i)
		{
			if(tot>=products[i].num)
			{
				tot-=products[i].num;
				ans += products[i].money;
			}else
			{
				ans+=tot*products[i].price;
				tot=0;
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}