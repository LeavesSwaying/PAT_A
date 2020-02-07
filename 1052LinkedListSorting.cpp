#include<iostream>
#include<algorithm>
using namespace std;

const int MaxN=100005;

struct Link{
	bool F;
	int add,key,next;
}link[MaxN];

int N,S;

bool cmp(Link a,Link b)
{
	if(a.F==false||b.F==false)
		return a.F>b.F;
	else 
		return a.key<b.key;	
}

int main()
{
	int a,b,c;
	scanf("%d%d",&N,&S);
	for(int i=0;i<N;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		link[a].add=a;
		link[a].key=b;
		link[a].next=c;
	}
	//初始化 
	for(int i=0;i<MaxN;++i)
	{
		link[i].F=false;
	}
	//寻找有效节点
	int now=S,num=0;
	while(now!=-1)
	{
		link[now].F=true;
		num++;
		now=link[now].next;	
	}
	sort(link,link+MaxN,cmp);
	printf("%d %05d\n",num,link[0].add);
	if(num==0)
	{
		printf("0 -1");
		return 0;
	}
	for(int i=0;i<num;++i)
	{
		if(i!=num-1) printf("%05d %d %05d\n",link[i].add,link[i].key,link[i+1].add);
		else printf("%05d %d -1",link[i].add,link[i].key);	
	} 
	return 0;
} 
