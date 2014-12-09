#include<stdio.h>

char get_c(int x)
{
	int t = x/13;
	if(t ==0)return 'S';
	if(t == 1) return 'H';
	if(t == 2) return 'C';
	if(t == 3) return 'D';
	if (t==4) return 'J';
}
int main()
{
	int st[64];
	int k;
	int n=54;
	scanf("%d",&k);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&st[i]);
		--st[i];
	}
	int a[64],b[64];
	for(int i=0;i<54;++i)
		a[i]=i;
	int *p = a;
	int *q = b;
	int *t;
	while(k--)
	{
		for(int i=0;i<n;++i)
			q[st[i]]=p[i];
		t=p;
		p=q;
		q=t;
	}
	
	char c = get_c(p[0]);
	printf("%c%d",c,p[0]%13 + 1);
	for(int i=1;i<n;++i)
	{
		printf(" %c%d",get_c(p[i]),p[i]%13 + 1);
	}
	printf("\n");
	return 0;
}