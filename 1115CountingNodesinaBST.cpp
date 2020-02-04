#include<iostream>
#include<queue>
using namespace std;

int maxlevel,n1,n2;

struct node{
	int data;
	int level;
	node* left;
	node* right;
};

node* newNode(int v)
{
	node* Node=new node;
	Node->data=v;
	Node->left=Node->right=NULL;
	return Node;
}

void insert(node* &root,int x,int level)
{
	if(root==NULL)
	{
		root=newNode(x);
		root->level=level;
		if(maxlevel<level) maxlevel=level;
		return;
	}
	if(x<=root->data)
		insert(root->left,x,level+1);
	else
		insert(root->right,x,level+1);	
}

void layerOrder(node* root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* now=q.front();
		q.pop();
		if(now->level==maxlevel) ++n1;
		else if(now->level==maxlevel-1) ++n2;
		if(now->left)
		{
			q.push(now->left);	
		}
		if(now->right)
		{
			q.push(now->right);	
		}	
	}
}

int main()
{
	int N,Tmp;
	node* Tree=NULL;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&Tmp);
		insert(Tree,Tmp,0);
	}
	layerOrder(Tree);
	printf("%d + %d = %d",n1,n2,n1+n2);
	return 0;	
} 
