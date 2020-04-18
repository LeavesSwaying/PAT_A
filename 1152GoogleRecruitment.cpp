#include<iostream>
#include<cmath>
using namespace std;

const int MaxL=1005;

int L,K;
int A[MaxL];
char B[MaxL];

bool isPrime(int x)
{
	if(x<=1) return false;
	int sqr=(int)sqrt(1.0*x);
	for(int i=2;i<=sqr;++i)
		if(x%i==0) return false;
	return true; 
}

bool Judge(int c)
{
	int ans=0;
	for(int i=c;i<c+K;i++)
	{
		ans=10*ans+A[i];
	}
	if(isPrime(ans))
	{
		for(int i=c;i<c+K;++i)
		{
			printf("%d",A[i]);
		}
	}
	return isPrime(ans); 
}

int main()
{
	scanf("%d%d",&L,&K);
	scanf("%s",B);
	for(int i=0;i<L;++i)
	{
		A[i]=B[i]-'0';
	}
	bool F=false; 
	for(int i=0;i<=L-K;++i)
	{
		if(Judge(i))
		{
			F=true;
			break;
		} 
	}
	if(F==false) printf("404");
	return 0;
}
