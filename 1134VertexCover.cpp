#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int MaxN=10005;

int N,M,K,Nv;

vector<int> G[MaxN];

struct node{
	int a,b;
	bool operator < (const node &x) const{
		if(a!=x.a) return a<x.a;
		else return b<x.b;
	}
};
set<node> s;

node newNode(int a,int b)
{
	node Node;
	if(a<=b)
	{
		Node.a=a;
		Node.b=b;
	}
	else
	{
		Node.b=a;
		Node.a=b;
	}
	return Node;
}

int main()
{
	int a,b;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i)
	{
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	scanf("%d",&K);
	for(int i=0;i<K;++i)
	{
		s.clear();
		scanf("%d",&Nv);
		for(int j=0;j<Nv;++j)
		{
			scanf("%d",&a);
			for(int k=0;k<G[a].size();++k)
			{
				b=G[a][k];
				node Tmp=newNode(a,b);
				s.insert(Tmp);
			}
		}
		if(s.size()==M) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
