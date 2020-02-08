#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> seq,ans;
int seqL,ansL=0;

int main()
{
	int N;
	scanf("%d",&N);
	int sqr=(int)sqrt(1.0*N);
	for(int i=2;i<=sqr;++i)
	{
		if(N%i==0)
		{
			seq.clear();
			seq.push_back(i);
			seqL=1;
			int M=N/i;
			for(int j=i+1;M%j==0;++j)
			{
				seq.push_back(j);
				seqL++;
				M/=j;
			}
			if(ansL<seqL)
			{
				ans=seq;
				ansL=seqL;
			}
		}
	}
	if(ansL==0)
	{
		printf("1\n%d",N);
		return 0;
	}
	printf("%d\n",ansL);
	for(int i=0;i<ans.size();++i)
	{
		if(i==0) printf("%d",ans[i]);
		else printf("*%d",ans[i]);
	}
	return 0;
}
