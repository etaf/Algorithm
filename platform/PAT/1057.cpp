/*
38
Push 10
Push 8
Peek
Push 7
Push 6
Peek
Push 5
Pop
Push 5
Peek
Pop
Push 6
Push 1
Pop
Peek
Push 1
Push 2
Peek
Pop
Peek
Push 2
Peek
Push 3
Peek
Pop
Peek
Push 3
Pop
Pop
Pop
Pop
Pop
Pop
Pop
Pop
Pop
Pop

*/

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<set>
using namespace std;
const int N = 100010;

typedef struct Node
{
	int v,id;
	Node(){}
	Node(int _v,int _id):v(_v),id(_id){}
	bool operator<(const Node& z)const
	{
		return v>z.v || (v==z.v && id>z.id);
	}
	bool operator == (const Node& z)const
	{
		return v==z.v && id == z.id;
	}
}Node;

struct mincmp
{
	bool operator()(const Node& x,const Node& y)
	{
		return x.v>y.v;
	}
};
typedef struct Mstack
{
	Node st[N];
	bool in_st[N];
	int top;
	int id;
	int ln;
	set<Node> lq;
	priority_queue<Node,vector<Node>, mincmp>rq;

	Mstack()
	{
		top = 0;
		id = 0;
		ln = 0;
		memset(in_st,0,sizeof(in_st));

	}
	bool isempty()
	{
		return top == 0;
	}

	void push(int x)
	{
		in_st[id] = 1;
		st[top++] = Node(x,id++);
		
		if(top==1)
		{
			rq.push(st[top-1]);
			return;
		}
		if(x<rq.top().v)
		{
			lq.insert(st[top-1]);
			++ln;
		}else
		{
			rq.push(st[top-1]);
		}

		int k= (top+1)/2 - 1;

		while(ln>k)
		{
			while(!in_st[lq.begin()->id])lq.erase(lq.begin());
			rq.push(*lq.begin());
			lq.erase(lq.begin());
			--ln;
		}
		// left num should be k
		while(ln<k)
		{
			// rq -> lq
			while(!in_st[rq.top().id] ) rq.pop();
			lq.insert(rq.top());
			rq.pop();
			++ln;
		}
	}

	int pop()
	{
		--top;
		in_st[st[top].id] = 0;
		
		if(lq.find(st[top])!=lq.end())--ln;
		if(top == 0)
		{return st[top].v;}

		int k=(top+1)/2-1;
		
		while(ln>k)
		{
			while(!in_st[lq.begin()->id])lq.erase(lq.begin());
			rq.push(*lq.begin());
			lq.erase(lq.begin());
			--ln;
		}
		while(ln<k)
		{
			// rq -> lq
			while(!in_st[rq.top().id] ) rq.pop();
			lq.insert(rq.top());
			rq.pop();
			++ln;
		}
		return st[top].v;
	}
	int get_mid()
	{
		while(!in_st[rq.top().id])rq.pop();
		return rq.top().v;
	}
}Mstack;

Mstack mst;

int main()
{
	freopen("in","r",stdin);
	int n,x;
	char s[64];
	scanf("%d",&n);
	
	while(n--)
	{
		scanf(" %s",s);
		if(s[1] == 'o')
		{
			if(mst.isempty())
			{
				printf("Invalid\n");
			}else
			{
				printf("%d\n",mst.pop());
			}
		}
		else if(s[1] == 'u')
		{
			scanf("%d",&x);
			mst.push(x);
		}
		else 
		{
			if(mst.isempty())
			{
				printf("Invalid\n");
			}else
			{
				printf("%d\n",mst.get_mid());
			}
		}
	}
	return 0;
}