#include<iostream>
#include<cstdio>
using namespace std;
typedef struct Node* Tree;
typedef struct Node* Node_t;
typedef int Type;
struct Node
{
	Node_t left;
	Node_t right;
	int height;
	Type data;
};
int Height(Node_t node)
{
	if (node)
		return node->height;
	return 0;
}
int Max(int n, int m)
{
	if (n > m)
		return n;
	return m;
}
//ÓÒÐý
Node_t RightRotate(Node_t a)
{
	Node_t b = a->left;
	a->left = b->right;
	b->right = a;
	a->height = Max(Height(a->left), Height(a->right))+1;
	b->height = Max(Height(b->left), Height(b->right))+1;
	return b;
}
//×óÐý
Node_t LeftRotate(Node_t a)
{
	Node_t b = a->right;
	a->right = b->left;
	b->left = a;
	a->height = Max(Height(a->left), Height(a->right))+1;
	b->height = Max(Height(b->left), Height(b->right))+1;
	return b;
}
//×óÓÒÐý
Node_t LeftRightRotate(Node_t a)
{
	a->left = LeftRotate(a->left);
	return RightRotate(a);
}
//ÓÒ×óÐý
Node_t RightLeftRotate(Node_t a)
{
	a->right = RightRotate(a->right);
	return LeftRotate(a);
}
Node_t NewNode(Type t)
{
	Node_t pn = (Node_t) malloc(sizeof(Node));
	if (!pn)
		return NULL;
	pn->left = pn->right = NULL;
	pn->data = t;
	pn->height = 1;
	return pn;
}
//²åÈë½Úµã
Node_t Insert(Type x, Tree t)
{
	if (t == NULL)
	{
		t = NewNode(x);
	}
	else if (x <t->data)
	{
		t->left = Insert(x, t->left);
		if ( Height(t->left) - Height( t->right) == 2)
		{
			if (x < t->left->data)
			{
				t = RightRotate(t);
			}
			else
			{
				t = LeftRightRotate(t);
			}
		}
	}
	else
	{
		t->right = Insert(x, t->right);
		if (Height(t->right) - Height(t->left) == 2)
		{
			if (x > t->right->data)
			{
				t = LeftRotate(t);
			}
			else
			{
				t = RightLeftRotate(t);
			}
		}
	}
	t->height = Max(Height(t->left), Height(t->right)) + 1;
	return t;
}

int main()
{
	Tree t=NULL;
	int i,j,n,x;
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%d",&x);
		t=Insert(x,t);
	}
	printf("%d\n",t->data);
}