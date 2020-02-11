#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MaxN=1000;

vector<int> G[MaxN];

bool vis[MaxN];

bool Judge(int a[],int n)
{
	fill(vis,vis+MaxN,false);
	int b,e;
	for(int i=0;i<n-1;++i)
	{
		b=a[i];
		if(vis[b]==true) return false;
		vis[b]=true;
		e=a[i+1];
		bool F=false;
		for(int j=0;j<G[b].size();++j)
			if(G[b][j]==e) F=true;
		if(F==false) return false;	
	}
	return true;
}

int N,M;
int main()
{
	int v1,v2;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i)
	{
		scanf("%d%d",&v1,&v2);
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	int P,Q,Tmp[MaxN];
	scanf("%d",&P);
	for(int i=0;i<P;++i)
	{
		scanf("%d",&Q);
		for(int j=0;j<Q;++j)
		{
			scanf("%d",&Tmp[j]);
		}
		if(Q!=N+1)
		{
			printf("NO\n");
			continue;	
		} 
		if(Tmp[0]!=Tmp[Q-1])
		{
			printf("NO\n");
			continue;
		} 
		if(Judge(Tmp,Q)) printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
} 
