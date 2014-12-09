/**************************************
*                                     *
*            离线等价类               *
*    DataStructure：Stack（Linked）   *
*                   Chain             *
*                                     *
*                                     *
**************************************/

/*

//------------------------
#include"LinkedStack.h"
#include"Chain.h"
#include"ChainIterator.h"

//------------------------

int main()
{
//--------InPut-------------
	int n,r;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	if(n<2)
	{
		cerr<<"Too few elements"<<endl;exit(1);
	}
	cout<<"Enter the number of relations"<<endl;
	cin>>r;
	if(r<1)
	{
		cerr<<"Too few relations"<<endl;

	}
	Chain<int> *chain;
	try{
		chain=new Chain<int>[n+1];
	}catch(NoMem){cerr<<"Out of Memory"<<endl;exit(1);}
	int a,b;
	for(int i=1;i<=r;i++)
	{
		cout<<"Enter the Next Pairs:"<<endl;
		cin>>a>>b;
		chain[a].Insert(0,b);
		chain[b].Insert(0,a);
		
	}
//------------Output---------------
	LinkedStack<int> stack;
	bool *out;
	try
	{
		out=new bool[n+1]; 
	}catch(NoMem){cerr<<"No enough memory for array out"<<endl;}
	for(int i=0;i<=n;i++)
		out[i]=false;

	for(int i=1;i<=n;i++)
	{
		if(!out[i])
		{
			cout<<"the  class is: "<<i<<" ";
			stack.Add(i);
			out[i]=true;
			while(!stack.IsEmpty())
			{
				int *q,j;
				stack.Delete(j);
				ChainIterator<int> c;
				q=c.Initialize(chain[j]);
				while(q)
				{
					if(!out[*q])
					{
						out[*q]=true;
						cout<<*q<<" ";
					    stack.Add(*q);
					}
					q=c.Next();
				}
			}
			cout<<endl;
		}
		
	}

	return 0;
}



*/