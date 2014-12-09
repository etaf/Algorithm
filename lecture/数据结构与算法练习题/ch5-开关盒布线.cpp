/***********************************
*                                  *
*         开关盒布线               *
*	DataStruce	Stack（Linked）    *
*							       *
***********************************/






#include"LinkedStack.h"
bool CheckBox(int p[],int n)
{
	LinkedStack<int> s;
	int c;
	for(int i=0;i<n;i++)
	{
		if(!s.IsEmpty())
		{
			if(s.Top()==p[i])
				s.Delete(c);
			else
				s.Add(p[i]);
			
		}
		else
		{
			s.Add(p[i]);
		}
	}
	if(s.IsEmpty())
		return true;
	else 
		return false;

}
//---------------------------------
int main()
{
	int n;
	cout<<"enter the number of the foot."<<endl;
	cin>>n;
	cout<<"enter the series."<<endl;
	int *p=new int[n];
	for(int i=0;i<n;i++)
		cin>>p[i];
	if(CheckBox(p,n))
		cout<<"The box is routable."<<endl;
	else
		cout<<"The box is unroutable"<<endl;
	return 0;
}
//---------------------------------
//---------------------------------