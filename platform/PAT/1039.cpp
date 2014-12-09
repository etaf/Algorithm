#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

vector<int>* hashtab[26*26*26*26];

int hashf(char* s)
{
	int h = s[0] - 'A';
	h = h*26+s[1] - 'A';
	h = h*26+s[2] - 'A';
	h = h*26+s[3] - '0';
	return h;
}

int main()
{
	int n,k,id,m,h;
	scanf("%d%d",&n,&k);
	char stn[8];
	for(int i=0;i<k;++i)
	{
		scanf("%d %d",&id,&m);
		for(int j=0;j<m;++j)
		{
			scanf(" %s",stn);
			h = hashf(stn);
			if(hashtab[h] == 0)
			{
				hashtab[h] = new vector<int>;
			}
			hashtab[h]->push_back(id);
		}

	}
	vector<int> ans;

	for(int i=0;i<n;++i)
	{
		scanf(" %s",stn);
		printf("%s ",stn);
		h = hashf(stn);
		if(hashtab[h] == 0){printf("0\n");continue;}
		ans = * (hashtab[h] );
		sort(ans.begin(),ans.end());
		printf("%d %d",ans.size(),ans[0]);
		
		for(int i=1;i<ans.size();++i)
			printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}