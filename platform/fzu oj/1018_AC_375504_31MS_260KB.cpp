/*
  Welcome to Fuzhou University Online Judge - Fasast
  http://acm.fzu.edu.cn
*/


#include<iostream>
using namespace std; 
int cube[20][20][20];
int MaxSubArray(int a[],int n)
{
	int i,max=-500,tmp=0;
	for(i=0;i<n;i++)
	{
		if(tmp>0)
			tmp+=a[i];
		else
			tmp=a[i];
		if(tmp>max)
			max=tmp;
	}
	return max;
}
int MaxSubMatrix(int a[][100],int m,int n)
{
	int i,j,k,sum=0,max=-500;
	int b[100];
	for(i=0;i<m;i++)
	{
		for(k=0;k<n;k++)
			b[k]=0;
		for(j=i;j<m;j++)
		{
			for(k=0;k<n;k++)
				b[k]+=a[j][k];
			sum=MaxSubArray(b,n);
			if(sum>max)
				max=sum;


		}
	}
	
	return max;
}
int MaxSubCube(int z,int x,int y)
{
	int i,j,k, a[100][100],sum=0,max=-500;
	for(k=0;k<z;k++)
	{
		memset(a,0,sizeof(a));
		for(int k1=k;k1<z;k1++)
		{
			for(i=0;i<x;i++)
				for(j=0;j<y;j++)
					a[i][j]+=cube[i][j][k1];
			sum=MaxSubMatrix(a,x,y);
			if(max<sum)
				max=sum;
		}
	}
	return max;

}
int main()
{
	int n,i,j,k;
	while(cin>>n && n)
	{
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					cin>>cube[i][j][k];
	cout<<MaxSubCube(n,n,n)<<endl;
	}
	return 0;
}

 

