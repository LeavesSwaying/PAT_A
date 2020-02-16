#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF=1000;
const int MaxN=510;

struct node{
	int v;
	int len;
};

vector<node> G[MaxN];
int N,M,S,E,W[MaxN];

int  wei[MaxN];
int  num[MaxN];
int  dis[MaxN];
bool vis[MaxN];
void Dijkstra(int s)
{
	fill(wei,wei+MaxN,0);
	fill(num,num+MaxN,0);
	fill(dis,dis+MaxN,INF);
	fill(vis,vis+MaxN,false);
	dis[s]=0;num[s]=1;wei[s]=W[s];
	for(int i=0;i<N;++i)
	{
		int u=-1,min=INF;
		for(int j=0;j<N;++j)
			if(vis[j]==false&&dis[j]<min){
				u=j;min=dis[j];
			}
		if(u==-1) cout<<"error";
		vis[u]=true;
		for(int j=0;j<G[u].size();++j)
		{
			int v=G[u][j].v;
			if(vis[v]==false&&dis[u]+G[u][j].len<dis[v])
			{
				dis[v]=dis[u]+G[u][j].len;
				num[v]=num[u];	
				wei[v]=wei[u]+W[v];
			}
			else if(vis[v]==false&&dis[u]+G[u][j].len==dis[v])
			{	
				if(wei[v]<wei[u]+W[v])
					wei[v]=wei[u]+W[v];
				num[v]+=num[u];
			}	
		}	
	}
	printf("%d %d",num[E],wei[E]);
}

int main()
{
	scanf("%d%d%d%d",&N,&M,&S,&E);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&W[i]);
	}
	int a,b,l;
	for(int i=0;i<M;++i)
	{
		scanf("%d%d%d",&a,&b,&l);
		node Tmp;
		Tmp.len=l;
		Tmp.v=b;
		G[a].push_back(Tmp);
		Tmp.v=a;
		G[b].push_back(Tmp);
	}
	Dijkstra(S);
	return 0;	
} 
