#include<iostream>
using namespace std;
int main()
{
	int selc[200];
	int x=1,y,r,s;
	for(int i=1;i<=100;i++)
	{	
		while(1)
		{
			y=x;
			int r1=1,s1=0;
			do
			{
				r=y%10;
				s=r;
				r1*=r;
				s1+=s;
				
			
			}while(y/=10);
			if(s1==r1)
			{
				
				selc[i]=x;			
			//	cout<<selc[i]<<" ";
				x++;
				break;
			}
			x++;
			
		}
		
	
			
	}
//	cout<<endl<<endl;//
	bool ext[1000000]={0};
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j*selc[i]<1000000;j*=2)
		{
			ext[j*selc[i]]=1;

		}
	}
	int fin[501];
	for(int i=1,j=1;i<=500;i++)
	{
		while(!ext[j])
		{j++;}
		
		fin[i]=j;
	//	cout<<fin[i]<<" ";
		j++;
	}
	int n;
	cin>>n;
	while(n--)
	{
		int k;
		cin>>k;
		cout<<fin[k]<<endl;
	}
	/*int count=0;
	for(int i=1;i<1000000;i++)
		if(ext[i])
		{
			cout<<i<<" ";
			count++;
		}
	cout<<endl<<count<<endl;
	*/


	
	return 0;
}