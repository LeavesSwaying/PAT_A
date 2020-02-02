#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MaxN=550;
const int INF=1000;

struct Node{
	int v;
	int t;
	int l;
};

vector<Node> G[MaxN];
int N,M,s,e;
/*Dijkstra算法部分*/
int pre[MaxN];//路径向量 
int dis[MaxN],ime[MaxN];//距离和时间向量 
bool vis[MaxN];//是否遍历向量 
void Dijkstra1(int s)
{
	fill(dis,dis+N,INF);
	fill(ime,ime+N,INF);
	fill(vis,vis+N,false);
	dis[s]=0;ime[s]=0;
	for(int i=0;i<N;++i)
	{
		int u=-1,min=INF;
		for(int j=0;j<N;++j)
			if(vis[j]==false&&dis[j]<min)
			{
				u=j;min=dis[j];
			} 
		if(u==-1) return;
		vis[u]=true;
		for(int j=0;j<G[u].size();++j)
		{
			int v=G[u][j].v;
			if(vis[v]==false&&dis[u]+G[u][j].l<dis[v])
			{
				dis[v]=dis[u]+G[u][j].l;
				ime[v]=ime[u]+G[u][j].t;
				pre[v]=u;	
			}
			else if(vis[v]==false&&dis[u]+G[u][j].l==dis[v]&&ime[u]+G[u][j].t<ime[v])
			{
				ime[v]=ime[u]+G[u][j].t;
				pre[v]=u;
			}
		}
	}
}
int wei[MaxN];
void Dijkstra2(int s)
{
	fill(ime,ime+N,INF);
	fill(wei,wei+N,INF);
	fill(vis,vis+N,false);
	ime[s]=0;wei[s]=0;
	for(int i=0;i<N;++i)
	{
		int u=-1,min=INF;
		for(int j=0;j<N;++j)
			if(vis[j]==false&&ime[j]<min)
			{
				u=j;min=ime[j];
			} 
		if(u==-1) return;
		vis[u]=true;
		for(int j=0;j<G[u].size();++j)
		{
			int v=G[u][j].v;
			if(vis[v]==false&&ime[u]+G[u][j].t<ime[v])
			{
				ime[v]=ime[u]+G[u][j].t;
				wei[v]=wei[u]+1;
				pre[v]=u;	
			}
			else if(vis[v]==false&&ime[u]+G[u][j].t==ime[v]&&wei[u]+1<wei[v])
			{
				wei[v]=wei[u]+1;
				pre[v]=u;
			}
		}
	}
}
/*此部分结束*/ 
/*打印路径部分*/

int dist[MaxN],d=0,dmin;
int sime[MaxN],t=0,tmin;

void PrinR1(int s,int e)
{
	if(s==e)
	{
		dist[d++]=s;
		return;
	}
	PrinR1(s,pre[e]);
	dist[d++]=e;
	return;	
} 
void PrinR2(int s,int e)
{
	if(s==e)
	{
		sime[t++]=s;
		return;
	}
	PrinR2(s,pre[e]);
	sime[t++]=e;
	return;	
} 
/*此部分结束*/ 
int main()
{
	scanf("%d%d",&N,&M);
	Node A,B;
	int F;
	for(int i=0;i<M;++i)
	{
		scanf("%d%d%d%d%d",&A.v,&B.v,&F,&A.l,&A.t);
		B.l=A.l;
		B.t=A.t;
		G[A.v].push_back(B);
		if(!F) G[B.v].push_back(A);
	}
	scanf("%d%d",&s,&e);
	Dijkstra1(s);
	dmin=dis[e];
	PrinR1(s,e);
	Dijkstra2(s);
	tmin=ime[e];
	PrinR2(s,e);
	int FL=1;
	if(d==t)
		for(int i=0;i<d;++i)
		{
			if(dist[i]!=sime[i]) FL=0;
		}
	else FL=0;
	if(FL==1)
	{
		printf("Distance = %d; Time = %d:",dmin,tmin);
		for(int i=0;i<d;++i)
		{
			if(!i) printf(" %d",dist[i]);
			else printf(" -> %d",dist[i]);
		}
	}
	else
	{	
		printf("Distance = %d:",dmin);
		for(int i=0;i<d;++i)
		{
			if(!i) printf(" %d",dist[i]);
			else printf(" -> %d",dist[i]);
		}
		printf("\nTime = %d:",tmin);
		for(int i=0;i<t;++i)
		{
			if(!i) printf(" %d",sime[i]);
			else printf(" -> %d",sime[i]);
		}					
	}	
	return 0;
}
