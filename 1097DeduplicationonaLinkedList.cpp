#include<iostream>
#include<set>
#include<vector>
using namespace std;

const int MaxN=100000;

struct node{
	int key;
	int next;
}link[MaxN];
int N,Head;

set<int> s;

vector<int> ans[2];

void Travel(int head)
{
	while(head!=-1)
	{
		if(s.find(link[head].key)==s.end())
		{
			ans[0].push_back(head);
			s.insert( link[head].key);
			s.insert(-link[head].key);
		}
		else ans[1].push_back(head);
		head=link[head].next;
	}
}

int main()
{
	int a,b,c;
	scanf("%d%d",&Head,&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		link[a].key=b;
		link[a].next=c;
	}
	Travel(Head);
	for(int i=0;i<ans[0].size();++i)
	{
		if(i<ans[0].size()-1) printf("%05d %d %05d\n",ans[0][i],link[ans[0][i]].key,ans[0][i+1]);
		else printf("%05d %d -1\n",ans[0][i],link[ans[0][i]].key);
	}
	for(int i=0;i<ans[1].size();++i)
	{
		if(i<ans[1].size()-1)
			printf("%05d %d %05d\n",ans[1][i],link[ans[1][i]].key,ans[1][i+1]);
		else	printf("%05d %d -1\n",ans[1][i],link[ans[1][i]].key); 	
	}
	return 0;
} 
