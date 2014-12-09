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

vector<string> co[2510];
int main()
{
	int n,k,m,cid;
	string stn;
	char tmp[5];
	//cin>>n>>k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i)
	{
		//cin>>stn>>m;
		scanf("%s%d",tmp,&m);
		stn = tmp;
		while(m--)
		{
			//cin>>cid;
			scanf("%d",&cid);
			co[cid].push_back(stn);
		}
	}
	for(int i=1;i<=k;++i)
	{
		//cout<<i<<" "<<co[i].size()<<endl;
		printf("%d %d\n",i,co[i].size());
		sort(co[i].begin(),co[i].end());
		for(int j=0;j<co[i].size();++j)
		{
			//cout<<co[i][j]<<endl;
			printf("%s\n",co[i][j].c_str());
		}
	}
	return 0;
}
