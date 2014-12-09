#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
using namespace std;

const int N = 1048586;

char s[N];
bool isok(char c)
{
	return  ('0'<=c && c<='9') || ('a'<=c && c<='z') ;
}

void get_lower()
{
	for(int i=0;s[i];++i)
	{
		if('A'<=s[i] && s[i]<='Z')
			s[i]  += 'a' - 'A';
	}
}
int main()
{
	while (gets(s))
	{
		get_lower();
		map<string,int> M;
		
		for(int i=0;s[i];++i)
		{
			while(s[i] && !isok(s[i]))++i;
			if(s[i] == 0)break;

			string word;
			while(s[i] && isok(s[i]))word+=s[i++];
			M[word]++;
			if(s[i] == 0)break;

		}

		map<string,int>::iterator it;
		string ans_s;
		int ans_n=0;

		for(it=M.begin();it!=M.end();++it)
		{
	//		cout<<it->first<<" "<<it->second<<endl;
			if(it->second > ans_n)
			{
				ans_n = it->second;
				ans_s = it->first;
			}
		}
		cout<<ans_s<<" "<<ans_n<<endl;

	}
	return 0;
}