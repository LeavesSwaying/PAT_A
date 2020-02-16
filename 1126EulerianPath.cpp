#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MaxN=510;

vector<int> G[MaxN];
int N,M;
//Travel
bool vis[MaxN];
void DFS(int s)
{
	vis[s]=true;
	for(int i=0;i<G[s].size();++i)
		if(vis[G[s][i]]==false)
			DFS(G[s][i]);
}

bool JudgeConn()
{
	int branch=0;
	fill(vis,vis+MaxN,false);
	for(int i=1;i<=N;++i)
	{
		if(vis[i]==false)
		{
			++branch;
			DFS(i);
		}
	}
	if(branch==1) return true;
	else return false;
}
//Travel End

int main()
{
	int a,b;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;++i)
	{
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int numOfOdd=0;
	bool allEven=true;
	for(int i=1;i<=N;++i)
	{
		if(i!=1) printf(" ");
		printf("%d",G[i].size());
		if(G[i].size()%2==1)
		{
			allEven=false;
			numOfOdd++;
		} 
	}
	printf("\n");
	if(JudgeConn())
	{
		if(allEven) printf("Eulerian");
		else if(numOfOdd==2) printf("Semi-Eulerian");
		else printf("Non-Eulerian");
	}
	else
	{
		printf("Non-Eulerian");
	}
	return 0;
}
