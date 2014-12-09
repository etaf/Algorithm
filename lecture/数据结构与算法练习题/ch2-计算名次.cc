#include<iostream>
using namespace std;
//¼ÆËãÃû´Î
template<typename T>
void Rank(T *a,int n,int *r)
{
	int i,j;
	for( i=0;i<n;i++)
	r[i]=1;
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(a[j]>a[i])
				r[i]++;
			else
				r[j]++;
}
int main()
{
	int n,i;
	cin>>n;
	int *a=new int[n];
	int *r=new int[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	Rank(a,n,r);
	for(i=0;i<n;i++)
		cout<<r[i]<<" ";
	cout<<endl;

	return 0;
}