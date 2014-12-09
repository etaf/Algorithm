#include<iostream>
#include<cmath>
#define PI 3.1415926535897932384626433832795
using namespace std;
int main()
{
	double D,V;
	while(cin>>D>>V)
	{
		if(D==0 && V==0)
			break;
		printf("%.3lf\n",pow((D*D*D-6*V/PI),(double)1/3));
	}

	return 0;
}