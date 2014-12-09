/*
  Welcome to Fuzhou University Online Judge - Fasast
  http://acm.fzu.edu.cn
*/


#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	int n,k,i,j,t,Case=0,temp;
	int mid[201][201],//mid[i][j] 表示从i到j放一个所需要的时间
		d[201],
		ans[201][31];//ans[i][j]表示1到n放j个的最优解（最短路程）。
	
	while(cin>>n>>k)
	{
		memset(mid,0,sizeof(mid));
		if(n==0 && k==0)break;
		for(i=1;i<=n;i++)
			cin>>d[i];
		//--------------------------------------
		for(i=1;i<=n;i++)
			for(j=i;j<=n;j++)
				for(t=i;t<=j;t++)
					mid[i][j]+=abs(d[t]-d[(i+j)/2]);
		//----------------------------------------
		for(i=1;i<=n;i++)           //求1到n放j=1个的ans值
		{
			ans[i][1]=mid[1][i];
			ans[i][i]=0;
		}
		for(j=2;j<=k;j++)          //从j=2个开始求1到n放j个的ans值
			for(i=j;i<=n;i++)      //注意此处i>=j;（才能放得下j个）求1———i放j个的ans值。
			{
				temp=mid[j][i];    //注意t的初始化：在1-i中放j个，最初的状况是1-——（j-1）放j个，之后在i到j中放一个
									//总共路程即为0+mid[i][j];下面的循环也是从这个情况开始的，t从j-1到i-1.遍历所有子序列，找出最优解。
				for(t=j-1;t<i;t++)
				{
					if(temp>ans[t][j-1]+mid[t+1][i])
						temp=ans[t][j-1]+mid[t+1][i];
				}
				ans[i][j]=temp;
			}


		cout<<"Chain "<<++Case<<endl;
		cout<<"Total distance sum = "<<ans[n][k]<<endl<<endl;
	}
	return 0;
}

 

