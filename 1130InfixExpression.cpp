#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int MaxN=30;

bool isRoot[MaxN];

struct node{
	string str;
	int lchild;
	int rchild;
}Tree[MaxN];

void inOrder(int R,int layer)
{
	if(R==-1)
	{
		return;
	}
	bool F=Tree[R].lchild==-1&&Tree[R].rchild==-1;
	if(layer==0||F) ;
	else printf("(");
	inOrder(Tree[R].lchild,layer+1);
	cout<<Tree[R].str;
	inOrder(Tree[R].rchild,layer+1);
	if(layer==0||F) ;
	else printf(")");
}

int N;
int main()
{
	fill(isRoot,isRoot+MaxN,false);
	node Tmp;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	{
		cin>>Tree[i].str>>Tree[i].lchild>>Tree[i].rchild;
		if(Tree[i].lchild!=-1) isRoot[Tree[i].lchild]=true;
		if(Tree[i].rchild!=-1) isRoot[Tree[i].rchild]=true;
	}
	int r;
	for(r=1;r<=N;r++)
		if(isRoot[r]==false) break;
	inOrder(r,0);
	return 0;
}
