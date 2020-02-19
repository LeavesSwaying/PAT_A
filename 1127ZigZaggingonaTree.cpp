#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int MaxN=50;

struct node{
	int data,layer;
	node* lchild;
	node* rchild;
};

int in[MaxN],pos[MaxN],pre[MaxN],N;

node* BuildTree(int inL,int inR,int posL,int posR)
{
	if(inL>inR) return NULL;
	int i,ans=pos[posR];
	for(i=inL;i<=inR;++i)
		if(ans==in[i]) break;
	int numLeft=i-inL;	
	node* k=new node;
	k->data=ans;
	k->lchild=BuildTree(inL,i-1,posL,posL+numLeft-1);
	k->rchild=BuildTree(i+1,inR,posL+numLeft,posR-1);
	return k;	
}

vector<int> dps,fps;
int L;
void BFS(node* r)
{
	L=0;
	r->layer=0;
	queue<node*> q;
	q.push(r);
	while(!q.empty())
	{
		node* now=q.front();
		q.pop();
		if(now->layer==L)
			dps.push_back(now->data);
		else
		{
			if(L%2==0)
				for(int i=dps.size()-1;i>=0;--i)
					fps.push_back(dps[i]);
			else
				for(int i=0;i<dps.size();++i)
					fps.push_back(dps[i]);
			L++;
			dps.clear();
			dps.push_back(now->data);				
		}		
		if(now->lchild)
		{
			now->lchild->layer=now->layer+1;
			q.push(now->lchild);
		}
		if(now->rchild)
		{
			now->rchild->layer=now->layer+1;
			q.push(now->rchild);
		}
	}
	if(L%2==0)
		for(int i=dps.size()-1;i>=0;--i)
			fps.push_back(dps[i]);			
	else
		for(int i=0;i<dps.size();++i)
			fps.push_back(dps[i]);
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&in[i]);
	}
	for(int i=0;i<N;++i)
	{
		scanf("%d",&pos[i]);
	}
	node* R=BuildTree(0,N-1,0,N-1);
	BFS(R);
	for(int i=0;i<fps.size();++i)
	{
		if(i!=0) printf(" ");
		printf("%d",fps[i]);
	}
	return 0;
} 
