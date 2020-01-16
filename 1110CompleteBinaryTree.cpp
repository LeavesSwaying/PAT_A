#include<iostream>
#include<string> 
#include<queue> 
using namespace std;
//输入的数据有可能是两位数的，不能用%c接收
struct Node{
 int fa;
 int lc,rc;	
}Tree[25];
int N;

void init(int num)
{
	for(int i=0;i<num;++i)
	{
		Tree[i].fa=-1;
		Tree[i].lc=-1;
		Tree[i].rc=-1;
	}
}

int findRoot(int start)
{
	int i=start;
	while(Tree[i].fa!=-1) i=Tree[i].fa;
	return i;
}

int main()
{
	scanf("%d",&N);
	init(N);
	string a,b;
	for(int i=0;i<N;++i)
	{
		cin>>a>>b;
		if(a!="-")
		{
			int Tm=0;
			for(int j=0;j<a.size();++j)
			{
				Tm=Tm*10+(a[j]-'0');
			}
			Tree[i].lc=Tm;
			Tree[Tm].fa=i;
		}
		if(b!="-")
		{
			int Tm=0;
			for(int j=0;j<b.size();++j)
			{
				Tm=Tm*10+(b[j]-'0');
			}
			Tree[i].rc=Tm;
			Tree[Tm].fa=i;
		}
	}
	int root=findRoot(0);
	//Travel
	int s;
	bool F=false;
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		s=q.front();q.pop();
		if(F&&(Tree[s].lc!=-1||Tree[s].rc!=-1))
		{
			printf("NO %d",root);
			return 0;
		}
		if(Tree[s].lc!=-1)
		{
			q.push(Tree[s].lc);
		} 
		if(Tree[s].rc!=-1)
		{
			if(Tree[s].lc==-1)
			{
				printf("NO %d",root);
				return 0;
			}
			q.push(Tree[s].rc);
		}
		else F=true; 	
	}
	printf("YES %d",s);
	return 0;
} 
