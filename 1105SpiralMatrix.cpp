#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

const int MaxN=10005;

int d[MaxN];
int N;

bool cmp(int a,int b)
{
	return a>b;
}

int res[500][500];

int main()
{
	scanf("%d",&N);
	int m=(int)ceil(sqrt(1.0*N));
	while(N%m!=0)
	{
		m++;
	}
	int n=N/m;
	for(int i=0;i<N;++i)
	{
		scanf("%d",&d[i]);
	}
	sort(d,d+N,cmp);
	int df=0,mf=1,nf=0;
	int x=0,y=0;
	while(df<N)
	{
		for(int i=0;i<n-nf&&df<N;++i)
		{
			res[y][++x]=d[df++];
		}
		nf++;
		for(int i=0;i<m-mf&&df<N;++i)
		{
			res[++y][x]=d[df++];
		}
		mf++;
		for(int i=0;i<n-nf&&df<N;++i)
		{
			res[y][--x]=d[df++];
		}
		nf++;
		for(int i=0;i<m-mf&&df<N;++i)
		{
			res[--y][x]=d[df++];
		}
		mf++;
	}
	for(int i=0;i<m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(j!=1) printf(" ");
			printf("%d",res[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
