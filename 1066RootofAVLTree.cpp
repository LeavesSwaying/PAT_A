#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int data,height;
	node* lchild;
	node* rchild;
};
//创建节点，求树高，求平衡因子，更新树高函数 
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
void updateHeight(node* root)
{
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
//左右旋函数
void L(node* &root)
{
	node* Tmp=root->rchild;
	root->rchild=Tmp->lchild;
	Tmp->lchild=root;
	updateHeight(root);
	updateHeight(Tmp);	
	root=Tmp;
} 
void R(node* &root)
{
	node* Tmp=root->lchild;
	root->lchild=Tmp->rchild;
	Tmp->rchild=root;
	updateHeight(root);
	updateHeight(Tmp);	
	root=Tmp;
}
//插入函数
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
		{
			if(getBF(root->lchild)==1)
				R(root);
			else if(getBF(root->lchild)==-1)
			{
				L(root->lchild);
				R(root);	
			}	
		}
	}
	else
	{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBF(root)==-2)
		{
			if(getBF(root->rchild)==-1)
				L(root);
			else if(getBF(root->rchild)==1)
			{
				R(root->rchild);
				L(root);
			}
		}
	}
}

int main()
{
	int N,v;
	node* root=NULL;
	cin>>N;
	for(int i=0;i<N;++i)
	{
		cin>>v;
		insert(root,v);
	}
	cout<<root->data;
	return 0;
} 
