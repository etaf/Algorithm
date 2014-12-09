#include<iostream>
using namespace std;
void Subset(bool* a,char* b,int i,int n)
{
	if(i==n-1)
	{
		a[n-1]=0;
		cout<<"{ ";
		for(int j=0;j<n;j++)
		{
			if(a[j])cout<<b[j]<<" ";
		}
		cout<<"}"<<endl;
		a[n-1]=1;
		cout<<"{ ";
		for(j=0;j<n;j++)
			if(a[j])cout<<b[j]<<" ";
		cout<<"}"<<endl;
		return;
	}
	a[i]=0;Subset(a,b,i+1,n);
	a[i]=1;Subset(a,b,i+1,n);

}

int main()
{
	int i,n;
	while(cin>>n)
	{
		bool* a=new bool[n];
		char* b=new char[n];
		for(i=0;i<n;i++)
			cin>>b[i];
		Subset(a,b,0,n);
		
	}
	
	return 0;
}