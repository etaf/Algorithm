#include<iostream>
#include<string>
using namespace std;
int main()
{
	int m,n,i;
	cin>>m>>n;
	string *dic=new string[m];
	int *sal=new int[m];
	for(i=0;i<m;i++)
		cin>>dic[i]>>sal[i];
	string word;
	while(n--)
	{
		cin>>word;
		int sum=0;
		while(word!=".")
		{
			for(i=0;i<m;i++)
				if(word==dic[i])
				{sum+=sal[i];break;}
			cin>>word;

		}
		cout<<sum<<endl;
	}
	return 0;
}
