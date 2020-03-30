#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MaxN=205;

int G[MaxN][MaxN];

int Nv,Ne,M;

void Judge(vector<int> T)
{
	sort(T.begin(),T.end());
	for(int i=0;i<T.size()-1;++i)
	{
		for(int j=i+1;j<T.size();++j)
		{
			int a=T[i],b=T[j];
			if(G[a][b]!=1)
			{
				printf("Not a Clique\n");	
				return;
			} 
		}
	}
	for(int i=1;i<=Nv;++i)
	{
		bool F=true;
		for(int j=0;j<T.size();++j)
		{
			if(G[i][T[j]]!=1)
			{
				F=false;
				break;
			}	
		}
		if(F==true)
		{
			printf("Not Maximal\n");
			return;
		} 
	}
	printf("Yes\n");
}

int main()
{
	int a,b;
	scanf("%d%d",&Nv,&Ne);
	for(int i=0;i<Ne;++i)
	{
		scanf("%d%d",&a,&b);
		G[a][b]=1;
		G[b][a]=1;
	}
	int n;
	vector<int> Tmp;
	scanf("%d",&M);
	for(int i=0;i<M;++i)
	{
		Tmp.clear();
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a);
			Tmp.push_back(a);
		}
		Judge(Tmp);
	}
	return 0;
} 
