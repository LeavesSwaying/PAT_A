#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int MaxN=100;

struct node{
	int data;
	int lchild,rchild;
}Tree[MaxN];
int a[MaxN],N;

void inOrder(int root)
{
	static int k=0;
	if(Tree[root].lchild!=-1)
		inOrder(Tree[root].lchild);
	Tree[root].data=a[k++];
	if(Tree[root].rchild!=-1)
		inOrder(Tree[root].rchild);
}

void layerOrder(int root)
{
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(now==root) printf("%d",Tree[now].data);
		else printf(" %d",Tree[now].data);
		if(Tree[now].lchild!=-1)
			q.push(Tree[now].lchild);
		if(Tree[now].rchild!=-1)
			q.push(Tree[now].rchild);
	}
}

int main()
{
	int l,r,d;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d%d",&l,&r);
		Tree[i].lchild=l;
		Tree[i].rchild=r;
	}
	for(int i=0;i<N;++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+N);
	inOrder(0);
	layerOrder(0);
	return 0;	
} 
