#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int MaxN=10;

struct node{
	int data;
	int lchild;
	int rchild;
}Tree[MaxN];
int N;

bool findRoot[MaxN];

void layerOrder(int root)
{
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
        if(now==root) printf("%d",now);
		else printf(" %d",now);
		if(Tree[now].lchild!=-1)
		{
			q.push(Tree[now].lchild);
		}
		if(Tree[now].rchild!=-1)
		{
			q.push(Tree[now].rchild);
		}
	}
	printf("\n");
}

void inOrder(int root)
{
	static bool F=false;
	if(Tree[root].lchild!=-1)
		inOrder(Tree[root].lchild);
	if(F) printf(" %d",root);
	else
	{
		printf("%d",root);
		F=true;
	}
	if(Tree[root].rchild!=-1)
		inOrder(Tree[root].rchild);	
}

int main()
{
	fill(findRoot,findRoot+MaxN,false);
	scanf("%d\n",&N);
	char l,r;
	for(int i=0;i<N;++i)
	{
		scanf("%c %c\n",&l,&r);
		if(l!='-')
		{
			Tree[i].rchild=l-'0';
			findRoot[l-'0']=true;
		}
		else Tree[i].rchild=-1;
		if(r!='-')
		{
			Tree[i].lchild=r-'0';
			findRoot[r-'0']=true;
		}
		else Tree[i].lchild=-1;
		Tree[i].data=i;
	}
	int root;
	for(root=0;root<N;++root)
		if(findRoot[root]==false) break;
	layerOrder(root);
	inOrder(root);
	return 0;	
} 
