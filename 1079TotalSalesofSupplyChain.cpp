#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

const int MaxN=100001;

struct node{
	double num,price;
	vector<int> child;
}Tree[MaxN];

int N;
double r,P;


double sum=0;

void BFS(int Root)
{
	Tree[Root].price=P;
	queue<int> q;
	q.push(Root);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		if(Tree[now].num>0) 
			sum=sum+Tree[now].num*Tree[now].price;
		for(int i=0;i<Tree[now].child.size();++i)
		{
			Tree[Tree[now].child[i]].price=(1+r/100.0)*Tree[now].price;
			q.push(Tree[now].child[i]);
		}
	}
}

void DFS(int Root,int depth)
{
	if(Tree[Root].child.size()==0)
	{
		sum+=Tree[Root].num*pow(1+r,depth);
		return;
	} 
	for(int i=0;i<Tree[Root].child.size();++i)
	{
		DFS(Tree[Root].child[i],depth+1);
	}
}
int main()
{
	int k,Tmp;
	scanf("%d%lf%lf",&N,&P,&r);
	r/=100;
	for(int i=0;i<N;++i)
	{
		scanf("%d",&k);
		if(k==0)
		{
			scanf("%lf",&Tree[i].num);
		}
		else
		{
			Tree[i].num=0;
			for(int j=0;j<k;++j)
			{
				scanf("%d",&Tmp);	
				Tree[i].child.push_back(Tmp);
			}	
		} 
		
	}
	BFS(0);
	printf("%.1lf",sum);
	return 0;
} 
