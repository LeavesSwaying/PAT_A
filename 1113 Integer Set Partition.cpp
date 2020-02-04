#include<iostream>
#include<algorithm>
using namespace std;

const int MaxN=100001;

int a[MaxN],N;

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+N);
	int sum=0,sum1=0;
	for(int i=0;i<N;++i)
	{
		if(i<N/2) sum1+=a[i];
		sum+=a[i];
	}
	printf("%d %d",N-N/2-N/2,sum-sum1-sum1);
	return 0;	
} 
