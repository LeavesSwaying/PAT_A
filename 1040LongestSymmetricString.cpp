#include<cstdio>
#include<cstring>
using namespace std;

char S[1005];
int dp[1005][1005];

int main()
{
    int i=0;
    char c;
    while(c!='\n')
    {
        scanf("%c",&c);
        S[i++]=c;
    }
    S[i]='\0';
	int len=strlen(S),ans=1;
	for(int i=0;i<len;++i)
	{
		dp[i][i]=1;
		if(i<len-1&&S[i]==S[i+1]){
			dp[i][i+1]=1;
			ans=2;
		}
	}
	for(int L=3;L<=len;L++)
		for(int i=0;i+L-1<len;++i){
			int j=i+L-1;
			if(S[i]==S[j]&&dp[i+1][j-1]==1){
				dp[i][j]=1;
				ans=L;
			}
		}
	printf("%d",ans);
	return 0;	
} 
