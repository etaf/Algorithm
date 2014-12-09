#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
		while(n--)
		{
			bool judge[13];
			int a[13]={0};
			for(i=0;i<12;i++)
				judge[i]=1;
			string l,r,p;
			int c=3;
			while(c--)
			{
				cin>>l>>r>>p;
				if(p[0]=='e')
				{
					for(i=0;i<l.length();i++)
					{
						judge[l[i]-'A']=0;
						
					}
					for(i=0;i<r.length();i++)
					{
						judge[r[i]-'A']=0;
					}
				}
				else
					if(p[0]=='u')
					{
						for(i=0;i<l.length();i++)
							if(judge[l[i]-'A'])
								a[l[i]-'A']+=1;
								
						for(i=0;i<r.length();i++)
							if(judge[r[i]-'A'])
								a[r[i]-'A']-=1;
							
					}
						else
						{
							for(i=0;i<l.length();i++)
								if(judge[l[i]-'A'])
									a[l[i]-'A']-=1;
							for(i=0;i<r.length();i++)
								if(judge[r[i]-'A'])
									a[r[i]-'A']+=1;
						}

			}
					int max=0,min=0;
					int maxi=0,mini=0;
					for(i=0;i<12;i++)
					{
						if(judge[i])
						{
							if(max<a[i])
							{	maxi=i;max=a[i];}
							if(min>a[i])
							{	mini=i;min=a[i];}
						}
					}
					if(max+min>0)
						cout<<(char)(maxi+'A')<<" is the counterfeit coin and it is heavy.";
					else
						cout<<(char)(mini+'A')<<" is the counterfeit coin and it is light.";
					cout<<endl;

			
		}
	return 0;

}