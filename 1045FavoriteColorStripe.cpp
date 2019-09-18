#include<iostream>
#include<algorithm>
using namespace std;

int M[201],MN;
int L[10001],LN;
int dp[201][10001];

int main()
{
	int N;
	scanf("%d%d",&N,&MN);
	for(int i=1;i<=MN;++i)
		scanf("%d",&M[i]);
	scanf("%d",&LN);
	for(int i=1;i<=LN;++i)
		scanf("%d",&L[i]);
	for(int i=1;i<=MN;++i)
		dp[i][0]=0;
	for(int j=1;j<=LN;++j)
		dp[0][j]=0;
	for(int i=1;i<=MN;++i)
		for(int j=1;j<=LN;++j)
			if(M[i]==L[j])
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	printf("%d",dp[MN][LN]);
	return 0;
} 
