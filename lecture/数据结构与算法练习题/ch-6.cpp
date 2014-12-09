#include<iostream>
using namespace std;
template<typename T>
bool Find(const T *a,const T &x,int begin,int end)
{
	if(begin==end)
	return false;
	if(a[begin]!=x)
		return Find(a,x,begin+1,end);
	else
	{
		cout<<x<<" is the "<<begin+1<<"th element."<<endl;
		return true;
	}
}
int main()
{
	int n,i;
	while(cin>>n){

	char *a=new char[n];
	char x;
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>x;
	if(!Find(a,x,0,n))
		cout<<"no" <<x<<" can be found!\n";
	
	}
	return 0;
}