#include<iostream>
#include<cmath>
using namespace std;

bool IsPrime(int s)
{
	/*判断是否为素数的函数*/
	if(s<=1) return false;
	int sqr=(int)sqrt(1.0*s);
	for(int i=2;i<=sqr;++i){
		if(s%i==0) return false;
	}
	return true;
}

int Reverse(int s,int radix)
{
	int z[100],tail=0;
	int sum=0,pro=1;
	do{
		z[tail++]=s%radix;
		s=s/radix;
	}while(s);
	for(int i=tail-1;i>=0;--i){
		sum+=z[i]*pro;
		pro*=radix;
	}
	return sum;
}

int main()
{
	int a,b,c;
	while(1){
		scanf("%d",&a);
		if(a<0) break;
		scanf("%d",&b);
		if(IsPrime(a)){
			c=Reverse(a,b);
			if(IsPrime(c)) printf("Yes\n");
			else printf("No\n");
		}
		else printf("No\n");
	}
	return 0;
}
