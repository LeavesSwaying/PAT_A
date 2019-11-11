#include<iostream>
#include<cmath>
using namespace std;

const int N=10001;

bool isPrime(int s)
{
	if(s<=1) return false;
	int sqr=(int)sqrt(1.0*s);
	for(int i=2;i<=sqr;++i){
		if(s%i==0) return false;
	}
	return true;
}

bool hashTable[N]={false};

int main()
{
	int Tsize,n,a;
	scanf("%d%d",&Tsize,&n);
	while(isPrime(Tsize)==false) ++Tsize;
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		int M=a%Tsize;
		if(hashTable[M]==false){
			hashTable[M]=true;
			if(i==0) printf("%d",M);
			else printf(" %d",M);
		}
		else{
			int step;
			for(step=1;step<Tsize;++step){
				M=(a+step*step)%Tsize;
				if(hashTable[M]==false){
					hashTable[M]=true;
					printf(" %d",M);
					break;
				}
			}
			if(step>=Tsize) printf(" -");	
		}
	}
	return 0;
}
