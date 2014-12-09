#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N,K;
	int i,j;
	int count;
	int num[10000];
	while (scanf("%d%d",&N,&K)!=EOF)
	{
		int date[10000];
		count = 1;
		for (i=0;i<N;i++)
			scanf("%d",&date[i]);
		sort(date,date+N);
		num[0] = date[N-1];
		j=1;
		for(i=N-1;i>0;i--)
		{
			if (count == K)
				break;
			if (date[i-1]!=date[i])
			{
				count++;
				num[j] = date[i-1];
				j++;
			}
		}
		if (count<K)
			printf("-1\n");
		else
		{
			for (i=count-1;i>=1;i--)
				printf("%d ",num[i]);
			printf("%d\n",num[0]);
		}
	}
	return 0;
}