#include<iostream>
using namespace std;
template<typename T>
void ChangeSize2D(T **& a,int row,int col,int torow,int tocol)
{
	int i,j;
	T** b=new T*[torow];
	for(i=0;i<torow;i++)
	{
		b[i]=new T[tocol];
	}
	for( i=0;i<(row<torow?row:torow);i++)
		for(j=0;j<(col<tocol?col:tocol);j++)
			b[i][j]=a[i][j];
	for(i=0;i<row;i++)
		delete[] a[i];
	delete[] a;
	a=b;

}
int main()
{
	int i,j,row,col,torow,tocol;
	while(cin>>row>>col)
	{
		char **a=new char*[row];
		for(i=0;i<row;i++)
		{
			a[i]=new char[col];
			for(j=0;j<col;j++)
				cin>>a[i][j];
		}
		cin>>torow>>tocol;
		ChangeSize2D(a,row,col,torow,tocol);
		for(i=0;i<torow;i++)
		{
			for(j=0;j<tocol;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}

	return 0;
}