#include<iostream>
using namespace std;

const int MaxN=50005;

int pre[MaxN],in[MaxN],N;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* BuildTree(int preL,int preR,int inL,int inR)
{
	if(preL>preR) return NULL;
	int i;
	for(i=inL;i<=inR;++i)
		if(in[i]==pre[preL]) break;
	int numLeft=i-inL;	
	node* Tmp=new node;
	Tmp->data=pre[preL];
	Tmp->lchild=BuildTree(preL+1,preL+numLeft,inL,i-1);
	Tmp->rchild=BuildTree(preL+numLeft+1,preR,i+1,inR);
	return Tmp;
}

int pos[MaxN],pf=0;
void postOrder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	pos[pf++]=root->data;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<N;++i)
	{
		scanf("%d",&in[i]);
	}
	node* R=NULL;
	R=BuildTree(0,N-1,0,N-1);
	postOrder(R);
	printf("%d",pos[0]);
	return 0;	
} 
