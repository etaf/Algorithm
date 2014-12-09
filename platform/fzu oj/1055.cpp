#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==-1)break;
		if(n==0){cout<<"a"<<endl;continue;}
		bool used[26]={0};
		used[0]=true;
		char x,y,t;
		bool flag=false;
		while(n--)
		{
			cin>>x>>t>>y;
			if(y<'a' || y>'z'){used[x-'a']=true;continue;}
			if(used[x-'a']==1 && used[y-'a']==0)
				used[x-'a']=false;
			for(int i=0;i<26;i++)
				if(used[y-'a'])
				{
					used[x-'a']=true;
					flag++;
				}

		}
		if(flag)
		{
			int i;
			for(i=0;!used[i];i++);
			cout<<(char)(i+'a');
			for(++i;i<26;i++)
				if(used[i])
					cout<<" "<<(char)(i+'a');

		}
		else
			cout<<"none";
		cout<<endl;

	}
	return 0;

}