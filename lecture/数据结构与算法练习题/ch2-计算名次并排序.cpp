#include<iostream>
using namespace std;
//计算名次
template<typename T>
void Rank(T *a,int n,int *r)
{
	int i,j;
	for( i=1;i<=n;i++)
	r[i]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<i;j++)//经过n（n-1）/2 次比较
			if(a[j]>a[i])
				r[i]++;
			else
				r[j]++;
}
template<typename T>
//原地重排
void Rearrange(T *a,int n,int *r)// 数组r为已存有名次
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(r[i]!=i)
		{
			Swap(a[r[i]],a[i]);
			Swap(r[r[i]],r[i]);//2n 次交换
		}
	}
}
template<typename T>
void Swap(T& a,T& b)
{
	T t;
	t=a;a=b;b=t;
}
// 附加数组重排
template<typename T>
void Rearrange1(T *&a,int n,int* r)
{
	T* u=new T[n+1];
	int i;
	for(i=1;i<=n;i++)
	{
		u[r[i]]=a[i];
	}
	T*b=a;
	a=u;
	delete[] b;
	b=0;
	u=0;

}
int main()
{
	int n,i;
	cin>>n;
	int *a=new int[n+1];
	int *r=new int[n+1];
	for(i=1;i<=n;i++)
		cin>>a[i];
	Rank(a,n,r);
	for(i=1;i<=n;i++)
		cout<<r[i]<<" ";
	cout<<endl;
	Rearrange(a,n,r);
	for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;


	return 0;
}
