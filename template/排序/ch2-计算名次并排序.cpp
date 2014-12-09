#include<iostream>
using namespace std;
//��������
template<typename T>
void Rank(T *a,int n,int *r)
{
	int i,j;
	for( i=1;i<=n;i++)
	r[i]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<i;j++)//����n��n-1��/2 �αȽ�
			if(a[j]>a[i])
				r[i]++;
			else
				r[j]++;
}
template<typename T>
//ԭ������
void Rearrange(T *a,int n,int *r)// ����rΪ�Ѵ�������
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(r[i]!=i)
		{
			Swap(a[r[i]],a[i]);
			Swap(r[r[i]],r[i]);//2n �ν���
		}
	}
}
template<typename T>
void Swap(T& a,T& b)
{
	T t;
	t=a;a=b;b=t;
}
// ������������
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
