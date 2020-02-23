#include<iostream>
#include<vector>
using namespace std;

const int MaxN=100000;

struct node{
	int data;
	int next;
}L[MaxN];
int Head,N,K;

vector<int> AD[3];

void Travel(int H)
{
	while(H!=-1)
	{
		if(L[H].data<0) AD[0].push_back(H);
		else if(L[H].data>=0&&L[H].data<=K) AD[1].push_back(H);
		else AD[2].push_back(H);
		H=L[H].next;
	}
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&Head,&N,&K);
	for(int i=0;i<N;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		L[a].data=b;
		L[a].next=c;
	}
	Travel(Head);
    bool F=false;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<AD[i].size();++j)
		{
            if(F==0){
                printf("%05d %d",AD[i][j],L[AD[i][j]].data);
                F=true;
            }
            else printf("%05d\n%05d %d ",AD[i][j],AD[i][j],L[AD[i][j]].data);    
		}
	}
	printf("-1");
	return 0;
} 
