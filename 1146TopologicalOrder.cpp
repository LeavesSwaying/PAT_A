#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MaxN=10005;

int M,N,K;
bool vis[MaxN];

vector<int> G[MaxN];

int main()
{
	int a,b;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i)
	{
		scanf("%d%d",&a,&b);
		G[b].push_back(a);
	}
	scanf("%d",&K);
	bool S=false;
	for(int i=0;i<K;++i)
	{
		bool F=false;
		fill(vis,vis+MaxN,false);
		for(int j=1;j<=N;++j)
		{
			scanf("%d",&a);
			for(int k=0;k<G[a].size();++k)
			{
				if(vis[G[a][k]]==false)
				{
					if(F==false)
                    {
                        if(S==false)
					    {
						    S=true;
				    	}
				    	else printf(" ");
                        printf("%d",i);
                    }
					F=true;
				}
			}
			vis[a]=true;
		}
	}
	return 0;
}
