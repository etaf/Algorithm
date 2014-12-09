#include<iostream>
using namespace std;
int main()
{
	double n,sum;
	int i;
	while(cin>>n && n!=0.00)
	{
		sum=0;
		for(i=1;sum<n;i++)
		{
			sum+=1.0/(i+1);
		}
		cout<<i-1<<" card(s)"<<endl;
		
	}
	return 0;
}