#include<iostream>
#include<algorithm>
using namespace std;

const int N=1005;

int father[N];
int isRoot[N];
int course[N];

int find(int x)
{
	while(x!=father[x])
		x=father[x];
	return x;
}

void Union(int x,int y)
{
	int faX=find(x);
	int faY=find(y);
	if(faX==faY) return;
	else
		father[faX]=faY;
}

void init(int n)
{
	for(int i=1;i<=n;++i)
		father[i]=i;
}

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	int n,m,h;
	scanf("%d",&n);
	init(n);
	for(int i=1;i<=n;++i){
		scanf("%d:",&m);
		for(int j=0;j<m;++j){
			scanf("%d",&h);
			if(course[h]==0)
				course[h]=i;
			Union(i,find(course[h]));
		}
	}
	for(int i=1;i<=n;++i)
		++isRoot[find(i)];	
	int ans=0;
	for(int i=1;i<=n;++i)
		if(isRoot[i]!=0)
			++ans;
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+n+1,cmp);
	for(int i=1;i<=ans;++i){
		printf("%d",isRoot[i]);
		if(i<ans) printf(" ");
	}
	return 0;
} 
