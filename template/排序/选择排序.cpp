#include<iostream>
using namespace std;
void select_sort(int a[],int n)
{
	int min,minp;
	for(int i=0;i<n-1;i++)
	{
		min=a[i];
		minp=i;
		for(int j=i+1;j<n;j++)
		{
			if(min>a[j])
			{
				min=a[j];
				minp=j;
			}
		}
		a[i]^=a[minp];
		a[minp]^=a[i];
		a[i]^=a[minp];
	}
}
int main()
{
	int n,i,a[10000];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		select_sort(a,n);
		printf("select_sort:\n");
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}