#include<iostream>
#include<vector>
using namespace std;

vector<int> save;
void insert(bool &F)
{
	int emp;
	scanf("%d",&emp);
	for(int i=0;i<save.size();++i)
	{
		int len=save.size()-i;
		if(save[i]==emp||save[i]-len==emp||save[i]+len==emp)
		{
			F=true;
		}
	}
	save.push_back(emp);
}

int N,M;	
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		bool F=false;
		save.clear();
		scanf("%d",&M);
		for(int j=0;j<M;++j)
		{
			insert(F);		
		}
		if(F) printf("NO\n");
		else printf("YES\n");	
	}
	return 0;
} 
