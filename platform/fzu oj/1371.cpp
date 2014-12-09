#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	string sn,sm;
	int n,m;
	getline(cin,sn);        
	while(getline(cin,sn))
	{
		istringstream sin1(sn);
		sin1>>n;				//读入n
		string a[20];
		string b[20];
		int c[20]={0};
		int i;
		for( i=0;i<n;i++)		//读入人名及其党派
		{
			getline(cin,a[i]);		
			getline(cin,b[i]);
		}	
	    getline(cin,sm);		
		istringstream sin2(sm);	//读入m
		sin2>>m;
		string d;
		for(i=0;i<m;i++)		//读入得票人的姓名
		{
			getline(cin,d);
			for(int j=0;j<n;j++) //计票
			{
				if(a[j]==d)
					c[j]++;
			}
		}
		int max=c[0],k=0,flag=0;//找出最大票数
		for(i=1;i<n;i++)
		{
			 if(max<c[i])
				{
					max=c[i];
					k=i;
				}
		}
		for(i=0;i<n && i!=k;i++)//检查是否存在相同票数。
			if(max==c[i])
				flag=1;
		if(flag)cout<<"tie"<<endl;
		else
			cout<<b[k]<<"\n";		
	}
	return 0;

}