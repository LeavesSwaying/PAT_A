#include<iostream>
#include<queue>
using namespace std;

int sum[1000],maxlayer;

struct node{
	int data;
	int layer;
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

void insert(node* &root,int x)
{
	if(root==NULL)
	{
		root=newNode(x);
		return;
	}
	if(x<root->data)
		insert(root->left,x);
	else
		insert(root->right,x);	
}

int layerOrder(node* root)
{
	root->layer=0;
	sum[root->layer]++;
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* now=q.front();
		q.pop();
		sum[now->layer]++;
		if(maxlayer<now->layer) maxlayer=now->layer;
		if(now->left)
		{
			now->left->layer=now->layer+1;
			q.push(now->left);	
		}
		if(now->right)
		{
			now->right->layer=now->layer+1;
			q.push(now->right);	
		}	
	}
	return maxlayer;
}

int main()
{
	int N,Tmp;
	node* Tree=NULL;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&Tmp);
		insert(Tree,Tmp);
	}
	maxlayer=layerOrder(Tree);
	printf("%d + %d = %d",sum[maxlayer],sum[maxlayer-1],sum[maxlayer]+sum[maxlayer-1]);
	return 0;	
} 
