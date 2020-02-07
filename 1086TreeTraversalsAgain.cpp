#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

const int MaxN=50;

int pre[MaxN],in[MaxN],post[MaxN],N;
int rf=0,nf=0,of=0;

struct node{
	int data;
	node* lchild;
	node* rchild;
};

node* BuildTree(int preL,int preR,int inL,int inR)
{
	if(preL>preR) return NULL;
	node* root=new node;
	root->data=pre[preL];
	int k;
	for(k=inL;k<=inR;k++)
		if(in[k]==pre[preL]) break;
	int numLeft=k-inL;
	//左侧的区间为[preL+1,preL+numLeft],[inL,k-1];
	//右侧的区间为[preL+numLeft+1,preR],[k+1,inR];
	root->lchild=BuildTree(preL+1,preL+numLeft,inL,k-1);
	root->rchild=BuildTree(preL+numLeft+1,preR,k+1,inR);
	return root;		
}

void postOrder(node* root)
{
	if(root==NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	post[of++]=root->data;
}

int main()
{
	stack<int> s;
	char Tmp[5];
	int TNode;
	scanf("%d",&N);
	for(int i=0;i<2*N;++i)
	{
		scanf("%s",Tmp);
		if(strcmp(Tmp,"Push")==0)
		{
			scanf("%d",&TNode);
			s.push(TNode);
			pre[rf++]=TNode;
		}
		if(strcmp(Tmp,"Pop")==0)
		{
			TNode=s.top();
			s.pop();
			in[nf++]=TNode;
		}
	}
	node* Root=BuildTree(0,N-1,0,N-1);
	postOrder(Root);
	for(int i=0;i<N;++i)
	{
		if(i==0) printf("%d",post[i]);
		else printf(" %d",post[i]);
	}
	return 0;
}
