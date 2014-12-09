/*
µü´ú¼ÓÉîËÑË÷
*/

#include<iostream>
using namespace std;
#define inf 0x3fffffff
int a[32];

int max_depth;
int pos[8][7] = {
	{0,2,6,11,15,20,22},
	{1,3,8,12,17,21,23},
	{10,9,8,7,6,5,4,},
	{19,18,17,16,15,14,13},
	{23,21,17,12,8,3,1},
	{22,20,15,11,6,2,0},
	{13,14,15,16,17,18,19},
	{4,5,6,7,8,9,10}
};


int opposite[8] = {5,4,7,6,1,0,3,2};

int mid[8] = {6,7,8,11,12,15,16,17};
int rdir[8] = {5,4,7,6,1,0,3,2};
char cpath[9] = "ABCDEFGH";
int path[1000000];
bool suc;

inline int max(int x,int y)
{
	return x>y?x:y;
}

int get_h()
{
	int cnt[4]={0,0,0,0};

	for(int i=0;i<8;++i)
	{
		++cnt[a[mid[i]]];
	}
	return 8-max(max(cnt[1],cnt[2]),cnt[3]);
}

void roate(int d)
{
	int tmp = a[pos[d][0]];
	for(int i=0;i<6;++i)
	{
		a[pos[d][i]] =a[pos[d][i+1]]; 
	}
	a[pos[d][6]] = tmp;
}
int dfs(int depth,int dir)
{
	
	int h,t,minn=inf;
	
	h = get_h(); 
	if(h == 0)
	{
		suc = true;
		return depth;
	}
	if(depth+h>max_depth)return depth+h;

	for(int i=0;i<8;++i)
	{
		if(i == dir)continue;
		roate(i);
		path[depth]=i;
		t = dfs(depth+1,rdir[i]);
		if(suc)return t;
		minn = minn<t?minn:t;
		roate(opposite[i]);

	}
	return minn;
}

int main()
{
	//freopen("in","r",stdin);

	int i,T;
	scanf("%d",&T);
	while(T--)
	{
		for(i=0;i<24;++i)scanf("%d",a+i);
		max_depth = get_h();
		if(max_depth == 0)
		{
			printf("it is OK!\n%d\n",a[mid[0]]);  
			continue;
		}
		suc = false;
		
		while(!suc)
		{
			max_depth = dfs(0,-1);
		}
		for(i=0;i<max_depth;++i)
		{
			printf("%c",cpath[path[i]]);
		}
		printf("\n%d\n",a[mid[0]]);
	}
	return 0;
}

        