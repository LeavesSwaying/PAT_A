#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
//图的定义部分 
const int MaxN=10005;
int G[MaxN][MaxN],N=0;
bool vis[MaxN]={false};
//映射部分 
map<int,string> its;
map<string,int> sti;
int M,K;
int findNum(string str)
{
	if(sti.find(str)!=sti.end())
	{
		return sti[str];
	}
	else
	{
		sti[str]=N;
		its[N]=str;
		return N++;
	}
}
//图的遍历部分
int HashTable[MaxN]={0};
map<string,int> ans;
void DFS(int now,int& head,int& num,int& sum)
{
	num++;
	vis[now]=true;
	if(HashTable[head]<HashTable[now]) head=now;
	for(int i=0;i<N;++i)
	{
		if(G[now][i]>0)
		{
			sum=sum+G[now][i];
			G[now][i]=0;
			G[i][now]=0;
			if(vis[i]==false) DFS(i,head,num,sum);
		}
	}
}
void DFSTravel()
{
	for(int i=0;i<N;++i)
	{
		if(vis[i]==false)
		{
			int head=i,num=0,sum=0;
			DFS(i,head,num,sum);
			if(num>=3&&sum>K)
			{
				ans[its[head]]=num;
			}	
		}	
	}	
} 
int main()
{
	string str1,str2;
	int len;
	scanf("%d%d",&M,&K);
	for(int i=0;i<M;++i)
	{
		cin>>str1>>str2>>len;
		int n1=findNum(str1);
		int n2=findNum(str2);
		G[n1][n2]+=len;
		G[n2][n1]+=len;
		HashTable[n1]+=len;
		HashTable[n2]+=len;
	}
	DFSTravel();
	map<string,int>::iterator it;
	printf("%d\n",ans.size());
	for(it=ans.begin();it!=ans.end();++it)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
