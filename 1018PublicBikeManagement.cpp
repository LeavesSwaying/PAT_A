#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MaxN=600;
const int INF=1000;

struct node{
	int v;
	int len;
};

vector<node> G[MaxN];

int Cmax,N,Sp,M;
int num[MaxN];


int  dis[MaxN];
bool vis[MaxN];
vector<int> pre[MaxN];

void Dijkstra(int s)
{
	fill(dis,dis+N,INF);
	fill(vis,vis+N,false);
	dis[s]=0;
	for(int i=0;i<N;++i)
	{
		int u=-1,min=INF;
		for(int j=0;j<N;++j)
			if(vis[j]==false&&dis[j]<min){
				u=j;min=dis[j];
			}
		if(u==-1) cout<<"Aror";
		vis[u]=true;
		for(int j=0;j<G[u].size();++j)
		{
			int v=G[u][j].v;
			if(vis[v]==false&&dis[u]+G[u][j].len<dis[v])
			{
				dis[v]=dis[u]+G[u][j].len;
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if(vis[v]==false&&dis[u]+G[u][j].len==dis[v])
			{
				pre[v].push_back(u);
			}
		}
	}	
}

vector<int> ans,emp;
int minNeed=INF,minRemain;
void DFS(int e)
{
	if(e==0)
	{
		emp.push_back(e);
		int need=0,remain=0;
		for(int i=emp.size()-1;i>=0;--i)
		{
			int v=emp[i];
			if(num[v]>0)
			{
				remain+=num[v];
			}
			else
			{
				if(remain>abs(num[v]))
				{
					remain-=abs(num[v]);
				}
				else
				{
					need+=abs(num[v])-remain;
					remain=0;
				}
			}
		}
		if(need<minNeed)
		{
			minNeed=need;
			minRemain=remain;
			ans=emp;
		}
		else if(need==minNeed&&remain<minRemain)
		{
			minRemain=remain;
			ans=emp;
		}
		emp.pop_back();
		return;
	}
	emp.push_back(e);
	for(int i=0;i<pre[e].size();++i)
	{
		DFS(pre[e][i]);
	}
	emp.pop_back();
}

int main()
{
	int a,b,len;
	scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
	N++;
	for(int i=1;i<N;++i)
	{
		scanf("%d",&num[i]);
		num[i]-=Cmax/2;
	}
	for(int i=0;i<M;++i)
	{
		scanf("%d%d%d",&a,&b,&len);
		node x,y;
		x.v=b;x.len=len;
		y.v=a;y.len=len;
		G[a].push_back(x);
		G[b].push_back(y);
	}
	Dijkstra(0);
	DFS(Sp);
	printf("%d ",minNeed);
	for(int i=ans.size()-1;i>=0;--i)
	{
		if(i==0) printf("%d",ans[i]);
		else printf("%d->",ans[i]);
	}
	printf(" %d",minRemain);	
	return 0;
} 
