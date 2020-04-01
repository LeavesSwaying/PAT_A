#include<iostream>
#include<algorithm>
using namespace std;

const int MaxN=100005;

int A[MaxN],N;

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&A[i]);
	}
	sort(A,A+N);
	int ans=1;
	for(int i=0;i<N;++i)
	{
		if(A[i]==ans)
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
} 
