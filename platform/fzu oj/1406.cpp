#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s ;
	int i;
	while(getline(cin,s))
	{
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]>='A' && s[i]<='z')
			{
				s[i]-=3;
				if(s[i]<'a' && s[i]>'Z') 
					s[i]='z'-('a'-s[i])+1;
				if(s[i]<'A')
					s[i]='Z'-('A'-s[i])+1;
			}

		}
		cout<<s<<endl;
	}
	
	return 0;
}