/*
用gcc 提交 否则超时
*/
#include<stdio.h>
int f[10001];
int a[100001];
int main()
{
	int n,i;
	scanf("%d",&n);

	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		f[a[i] ]+=1;
	}
	
	for(i=0;i<n;++i)
	{
		if(f[a[i]] == 1)
		{
			printf("%d\n",a[i]);
			return 0;
		}
	}

	printf("None\n");
	return 0;
}