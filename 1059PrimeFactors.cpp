#include<cstdio>
#include<cmath>

const int maxn=100001;

bool isPrime(int s)
{
	if(s<=1) return false;
	int sqr=(int)sqrt(1.0*s);
	for(int i=2;i<=sqr;++i)
		if(s%i==0) return false;
	return true;
} 

int prime[maxn],pNum=0;
void findPrime()
{
	for(int i=1;i<maxn;++i)
		if(isPrime(i)==true)
			prime[pNum++]=i;
}

int num=0;
struct factor{
	int x,cnt;
}fac[10];

int main()
{
	findPrime();
	int N;
	scanf("%d",&N);
	printf("%d=",N);
	if(N==1) printf("1");
	else
	{
		int sqr=(int)sqrt(1.0*N);
		for(int i=0;i<pNum&&prime[i]<sqr;++i){
			if(N%prime[i]==0){
				fac[num].x=prime[i];
				fac[num].cnt=0;
				while(N%prime[i]==0){
					fac[num].cnt++;
					N/=prime[i];
				}
				++num;
			}
			if(N==1) break;
		}
		if(N!=1){
			fac[num].x=N;
			fac[num++].cnt=1;
		}
		for(int i=0;i<num;++i){
			if(i>0) printf("*");
			printf("%d",fac[i].x);
			if(fac[i].cnt>1)
				printf("^%d",fac[i].cnt);
		}
	}
	return 0;	
}
