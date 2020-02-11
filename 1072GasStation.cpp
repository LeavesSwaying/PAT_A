#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int MaxN=1020;
const int INF=10000;

int N,M,K,D,L;

struct node{
	int v;
	int dis;
};

vector<node> G[MaxN];

int findNum(string str)
{
	if('0'<=str[0]&&str[0]<='9')
	{
		int num=0;
		for(int i=0;i<str.size();++i)
			num=num*10+(str[i]-'0');
		return num;	
	}
	if(str.size()==2)
	{
		int k=str[1]-'0';
		return N+k;
	}
	if(str.size()==3) return N+10;
}
/*最短路径算法开始*/
bool vis[MaxN];
int  dis[MaxN]; 
void Dijkstra(int s,int& minL,int& maxL,double& aveL)
{
	fill(dis,dis+L+1,INF);
	fill(vis,vis+L+1,false);
	dis[s]=0;
	for(int i=1;i<=L;++i)
	{
		int u=0,min=INF;
		for(int j=1;j<=L;++j)
			if(vis[j]==false&&dis[j]<min)
			{
				u=j;
				min=dis[j];
			}
		if(u==0) return;
		vis[u]=true;
		for(int k=0;k<G[u].size();++k)
		{
			int v=G[u][k].v;
			if(vis[v]==false&&dis[u]+G[u][k].dis<dis[v])
			{
				dis[v]=dis[u]+G[u][k].dis;
			}
		}	
	}
	int sum=0;
	minL=INF;
	maxL=-1;
	for(int i=1;i<=N;++i)
	{
		sum+=dis[i];
		if(maxL<dis[i]) maxL=dis[i];
		if(dis[i]<minL) minL=dis[i];
	}
	aveL=(1.0*sum)/(1.0*N);
}
/*最短路径算法结束*/
int main()
{
	string str1,str2;
	int dist;
	scanf("%d%d%d%d",&N,&M,&K,&D);
	L=N+M;
	for(int i=0;i<K;++i)
	{
		//这道题要注意，如果输入数据选择字符串，那么数字是可以变为多位的 
		cin>>str1>>str2>>dist;
		int x1=findNum(str1);
		int x2=findNum(str2);
		node Tmp1,Tmp2;
		Tmp1.dis=dist;
		Tmp2.dis=dist;
		Tmp1.v=x2;
		Tmp2.v=x1;
		G[x1].push_back(Tmp1);
		G[x2].push_back(Tmp2);
	}
	int ansMin=0,index=0;
	double ansAve=INF;
	for(int i=1;i<=M;++i)
	{
		int min,max;
		double ave;
		Dijkstra(N+i,min,max,ave);
		if(max>D) continue;
		if(ansMin<min)
		{
			ansMin=min;
			ansAve=ave;
			index=i;
		}
		if(ansMin==min&&ave<ansAve)
		{
			ansAve=ave;
			index=i;
		}
	}
	if(index==0) printf("No Solution");
	else
	{
		printf("G%d\n",index);
		printf("%.1lf %.1lf",1.0*ansMin,ansAve);
	} 
	return 0;
} 
