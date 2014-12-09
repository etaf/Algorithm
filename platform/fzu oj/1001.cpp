#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n;
	getchar();
	while(n--)
	{
		getline(s);
		for(i=s.length()-1;i>=0;i--)
		{
			cout<<s[i];
		}
		cout<<endl;

	}
	return 0;
}