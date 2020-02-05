#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MaxN=100;

struct node{
	int weight;
	vector<int> child;
}Tree[MaxN];
int N,M,S;


vector<int> Road[MaxN];
int index=0;
void DFS(int Root,int sum,vector<int> pa)
{
	sum=sum+Tree[Root].weight;
	pa.push_back(Root);
	if(Tree[Root].child.size()==0)
	{	
		if(sum==S)
		{
			for(int i=0;i<pa.size();++i)
			{
				Road[index].push_back(Tree[pa[i]].weight);
			}
			index++;
		} 
		return;
	}
	for(int i=0;i<Tree[Root].child.size();++i)
	{
		DFS(Tree[Root].child[i],sum,pa);
	}
}

bool cmp(int a,int b)
{
	return Tree[a].weight>Tree[b].weight;
}

int main()
{
	int k,id,Tmp;
	scanf("%d%d%d",&N,&M,&S);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&Tree[i].weight);
	}	
	for(int i=0;i<M;++i)
	{
		scanf("%d%d",&id,&k);
		for(int i=0;i<k;++i)
		{
			scanf("%d",&Tmp);
			Tree[id].child.push_back(Tmp);
		}
		sort(Tree[id].child.begin(),Tree[id].child.end(),cmp);
	}
	vector<int> ans;
	DFS(0,0,ans);
	for(int i=0;i<index;++i)
	{
		for(int j=0;j<Road[i].size();++j)
		{
			if(j==0) printf("%d",Road[i][j]);
			else printf(" %d",Road[i][j]);
		}
		printf("\n");
	}
	return 0;	
} 
