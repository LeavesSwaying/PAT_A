#include<iostream>
using namespace std;

const int MaxN=54+1;

int rule[MaxN],s[MaxN],e[MaxN];

void outPut(int s)
{
	if(s<=13) printf("S%d",s);
	else if(s<=26) printf("H%d",s-13);
	else if(s<=39) printf("C%d",s-26);
	else if(s<=52) printf("D%d",s-39);
	else printf("J%d",s-52);
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<MaxN;++i)
	{
		scanf("%d",&rule[i]);
		s[i]=i;
	}
	for(int i=0;i<N;++i)
	{
		for(int j=1;j<MaxN;++j)
		{
			e[rule[j]]=s[j];
		}
		for(int j=1;j<MaxN;++j)
		{
			s[j]=e[j];
		}
	}
	for(int i=1;i<MaxN;++i)
	{
		outPut(s[i]);
		if(i!=MaxN-1) printf(" ");
	}
	return 0;
} 
