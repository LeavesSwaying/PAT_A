#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

struct node{
	int index,num;
	bool operator < (const node& x) const
	{
		return num==x.num?index<x.index:num>x.num;
	}
	node(int _x,int _y):index(_x),num(_y){}
};
const int MaxN=500005;

int N,K,T[MaxN];
set<node> s;

int main()
{
	int a;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&a);
		if(i==0)
		{
			T[a]++;
			s.insert(node(a,T[a]));
			continue;
		}
		printf("%d:",a);
		int cnt=0;
		for(auto it=s.begin();cnt<K&&it!=s.end();++it,++cnt) 
			printf(" %d",it->index);
		printf("\n");
		auto it=s.find(node(a,T[a]));
		if(it!=s.end()) s.erase(it);
		T[a]++;
		s.insert(node(a,T[a]));	
	}
	return 0;	
} 
