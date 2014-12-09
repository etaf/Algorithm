#include<iostream>
using namespace std;
template<typename T>
bool Input(T &x)
{
	cout<<"Please input a nonnegative number.\n";
	cin>>x;
	if(x<0)
	{
		cout<<"Please input a nonnegative number.\n";
		cin>>x;
		if(x<0)
		{
			cout<<"Please input a nonnegative number.\n";
			cin>>x;
			if(x<0)
				return false;
		}
	
	}
	return true;

}
int main()
{
	int x;
	if(Input(x))
		cout<<x<<endl;
	else
		cout<<"The input is  failled ! \n";
return 0;
}