#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		double sum=0;
		for(int i=n;i>=1;i--)
			sum+=(double)(1.0/i);
		printf("%.12lf\n",sum);

	}
	return 0;
}