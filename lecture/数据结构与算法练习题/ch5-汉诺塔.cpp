/************************************
*                                   *
*     递归求汉诺塔的搬运步骤        *
*  Data Structure：Stack（Linked）  *
*                                   *
************************************/


/*



#include<iostream>
#include<xcept.h>
#include"LinkedStack.h"
#include<time.h>
using namespace std;
LinkedStack<int> x,y,z;
int d;
int count=0;
void ShowState()
{
	cout<<++count<<endl;
	cout<<x<<endl<<y<<endl<<z<<endl;

}
void Hanoi(int n,LinkedStack<int>& x,LinkedStack<int>& y,LinkedStack<int>& z)
{
	if(n>0)
	{
		Hanoi(n-1,x,z,y);
		x.Delete(d);
		y.Add(d);
		ShowState();
		cout<<endl;
		Hanoi(n-1,z,y,x);
	}



}
int main()
{
	int n;
	cout<<"enter the size of hanoi ."<<endl;
	cin>>n;
	for(int i=n;i>0;i--)
		x.Add(i);
	clock_t start=clock();
	Hanoi(n,x,y,z);
	cout<<"the time used is: "<<(clock()-start)/CLK_TCK<<endl;
	return 0;
}


*/