#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MaxN=105;

struct node{
	int layer;
	vector<int> child;
}Node[MaxN];

int N,M;

void levelTravel(int s)
{
	int u;
	Node[s].layer=1;
	queue<int> q;
	q.push(s);
	int nowlevel=1,nowNum=0;
	int anslevel=1,ansNum=0;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		if(nowlevel<Node[u].layer)
		{
			if(ansNum<nowNum)
			{
				anslevel=nowlevel;
				ansNum=nowNum;
			}
			nowlevel++;
			nowNum=0;
		}
		nowNum++;
		for(int i=0;i<Node[u].child.size();++i)
		{
			Node[Node[u].child[i]].layer=Node[u].layer+1;
			q.push(Node[u].child[i]);
		}
		//printf("%d %d\n",anslevel,ansNum);
	}
	if(ansNum<nowNum)
	{
		anslevel=nowlevel;
		ansNum=nowNum;
	}
	printf("%d %d",ansNum,anslevel);
}

int main()
{
	int a,b,k;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;++i)
	{
		scanf("%d%d",&a,&k);
		for(int j=0;j<k;++j)
		{
			scanf("%d",&b);
			Node[a].child.push_back(b);	
		}
	}
	levelTravel(1);
	return 0;
}
