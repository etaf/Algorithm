 //递归函数生成排列
#include<iostream>
using namespace std;
template<typename T>
void Perm(T a[],int begin,int end)
{
	int i;
	if(begin==end-1)
	{
		for( i=0;i<end;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		return ;
	}
	for(i=begin;i<end;i++)
	{
		Swap(a[i],a[begin]);
		Perm(a,begin+1,end);
		Swap(a[i],a[begin]);
	}

}
template<typename T>
void Swap(T &a,T &b)
{
	T temp=a;a=b;b=temp;
}
int main()
{
	int n,i;
	
	while(cin>>n)
	{
		char *a=new char[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		Perm(a,0,n);
	}

	return 0;
}