// 在线等价：
输入n，代表n行等式
当n==-1时结束运行。
输出与a相等的所有字母。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Find(int* p,int e)
{
	while(p[e])
		e=p[e];
	return e;
}
int main()
{
	int n;
	
	while(cin>>n)
	{
		char c[4];
		int parent[27]={0};
		if(n==-1)break;
		while(n--)
		{
			cin>>c;
			int x,y;
			x=c[0]-'a'+1;
			y=c[2]-'a'+1;
			x=Find(parent,x);
			y=Find(parent,y);
			if(x>y)
				parent[y]=x;
			else
				parent[x]=y;


		}
		int e=1;
		vector<int> selected;
		while(parent[e])
		{
			e=parent[e];
		}
		for(int i=1;i<27;i++)
			if(Find(parent,i)==e)
				selected.push_back(i);
		sort(selected.begin(),selected.end());
		for(int i=0;i<selected.size();i++)
			cout<<(char)(selected[i]+'a'-1)<<" ";
		cout<<endl;

	}
	return 0;
}