#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct node{
	int data,height;
	node* lchild;
	node* rchild;
};

//
node* newNode(int v)
{
	node* Node=new node;
	Node->data=v;
	Node->height=1;
	Node->lchild=Node->rchild=NULL;
	return Node;
}
int getHeight(node* root)
{
	if(root==NULL) return 0;
	return root->height;
}
int getBF(node* root)
{
	return getHeight(root->lchild)-getHeight(root->rchild);
}
void updateHeight(node* &root)
{
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
//
void R(node* &root)
{
	node* Tmp=root->lchild;
	root->lchild=Tmp->rchild;
	Tmp->rchild=root;
	updateHeight(root);
	updateHeight(Tmp);
	root=Tmp;
}
void L(node* &root)
{
	node* Tmp=root->rchild;
	root->rchild=Tmp->lchild;
	Tmp->lchild=root;
	updateHeight(root);
	updateHeight(Tmp);
	root=Tmp;
}
//
void insert(node* &root,int v)
{
	if(root==NULL)
	{
		root=newNode(v);
		return;
	}
	if(v<root->data)
	{
		insert(root->lchild,v);
		updateHeight(root);
		if(getBF(root)==2)
			if(getBF(root->lchild)==1)
				R(root);
			else if(getBF(root->lchild)==-1)
			{
				L(root->lchild);
				R(root);	
			}	
	}
	else
	{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBF(root)==-2)
			if(getBF(root->rchild)==-1)
				L(root);
			else if(getBF(root->rchild)==1)
			{
				R(root->rchild);
				L(root);	
			}	
	}
}
bool ans=true;
void levelTravel(node* root)
{
	bool F=false,S=false;
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* now=q.front();
		q.pop();
		if(F==true) printf(" ");
		printf("%d",now->data);
		F=true;
		if(now->lchild!=NULL)
		{
			if(S==true) ans=false;
			q.push(now->lchild);
		}
		else S=true;
		if(now->rchild!=NULL)
		{
			if(S==true) ans=false;
			q.push(now->rchild);
		}
		else S=true;
	}
}
int main()
{
	int N,Tmp;
	node* root=NULL;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&Tmp);
		insert(root,Tmp);
	}
	levelTravel(root);
	printf("\n");
	if(ans) printf("YES");
	else printf("NO");
	return 0;
} 
