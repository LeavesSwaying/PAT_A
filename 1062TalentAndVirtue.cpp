#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct man{
	char num[9];
	int VirGrad;
	int TalGrad;
	int sum;
	int rank;
}man;

man G[100000];
int N,low,hig;

int JudgeRank(int vir,int tal)
{
	if(tal<low||vir<low) return 0;
	if(tal>=hig&&vir>=hig) return 4;
	if(vir>=hig) return 3;
	if(vir>=tal) return 2;
	return 1;
}

bool cmp(man a,man b)
{
	if(a.rank!=b.rank) return a.rank>b.rank;
	else if(a.sum!=b.sum) return a.sum>b.sum;
	else if(a.VirGrad!=b.VirGrad) return a.VirGrad>b.VirGrad;
	else return strcmp(a.num,b.num)<0;
}

int main()
{
	//freopen("data.in","r",stdin); 
	cin>>N>>low>>hig;
	int vir,tal;
	char nmm[9];
	for(int i=0;i<N;++i)
	{
		scanf("%s",G[i].num);
		cin>>vir>>tal;
		G[i].VirGrad=vir;
		G[i].TalGrad=tal;
		G[i].sum=vir+tal;
		G[i].rank=JudgeRank(vir,tal);
	}
	sort(G,G+N,cmp);
	int i;
	for(i=N-1;i>=0;--i)
	{
		if(G[i].TalGrad>=low&&G[i].VirGrad>=low) break;
	}
	++i;
	printf("%d\n",i);
	for(int j=0;j<i;++j){
		printf("%s %d %d\n",G[j].num,G[j].VirGrad,G[j].TalGrad);
	}
	return 0;
} 
