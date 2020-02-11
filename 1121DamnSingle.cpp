#include<iostream>
#include<map>
#include<set>
using namespace std;

map<int,int> couple;

set<int> ans;

int main()
{
	int N,M,a,b,Tmp;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d%d",&a,&b);
		couple[a]=b;
		couple[b]=a;
	}
	scanf("%d",&M);
	for(int i=0;i<M;++i)
	{
		scanf("%d",&Tmp);
		if(couple.find(Tmp)==couple.end())
		{
			ans.insert(Tmp);
		}
		else if(ans.find(couple[Tmp])==ans.end())
		{
			ans.insert(Tmp);
		}
		else
		{
			ans.erase(ans.find(couple[Tmp]));
		}
	}
	printf("%d\n",ans.size());
	set<int>::iterator it;
	for(it=ans.begin();it!=ans.end();++it)
	{
		printf("%05d",*it);
		if(it!=--ans.end()) printf(" ");
	}
	return 0;
} 
