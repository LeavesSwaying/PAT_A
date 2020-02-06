#include<iostream>
#include<cmath>
#include<set>
using namespace std;

const int MaxN=10000;

int N,M,champion;
set<int> s;
set<int> prim;
set<int> check;

bool isPrime(int n)
{
	if(n<=1) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;++i)
	{
		if(n%i==0) return false;
	}
	return true;
}

int main()
{
	int Tmp;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&Tmp);
		s.insert(Tmp);
		if(i==1) champion=Tmp;
		if(isPrime(i)) prim.insert(Tmp);
	}
	
	scanf("%d",&M);
	for(int i=1;i<=M;++i)
	{
		scanf("%d",&Tmp);
		if(s.find(Tmp)==s.end()) printf("%04d: Are you kidding?\n",Tmp);
		else if(check.find(Tmp)!=check.end())
			printf("%04d: Checked\n",Tmp);
		else if(Tmp==champion) printf("%04d: Mystery Award\n",Tmp);
		else if(prim.find(Tmp)!=prim.end())
		{
			printf("%04d: Minion\n",Tmp);
		}
		else printf("%04d: Chocolate\n",Tmp);
		check.insert(Tmp);
	}
	return 0;
} 
