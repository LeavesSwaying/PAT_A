#include<iostream>
#include<algorithm>
using namespace std;

struct student
{
	int f;
	int Ge;
	int Gi;
	int select[5];
}stu[40000];
int N,K;

int expect[105],real[105]={0},M;
int result[105][7];

bool cmp1(student a,student b)
{
	int sumA=a.Ge+a.Gi;
	int sumB=b.Ge+b.Gi;
	if(sumA!=sumB) return sumA>sumB;
	else return a.Ge>b.Ge;
}

bool cmp2(int x,int y)
{
	return stu[x].f<stu[y].f;
}

bool isSame(int a,int b)
{
	int sumA=stu[a].Ge+stu[a].Gi;
	int sumB=stu[b].Ge+stu[b].Gi;
	if(sumA==sumB&&stu[a].Ge==stu[b].Ge) return true;
	return false;
}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;++i)
		for(int j=0;j<7;++j)
			result[i][j]=-1;
	for(int i=0;i<M;++i){
		scanf("%d",&expect[i]);
	}
	for(int i=0;i<N;++i){
		stu[i].f=i;
		scanf("%d%d",&stu[i].Ge,&stu[i].Gi);
		for(int j=0;j<5;++j)
			if(j<K) scanf("%d",&stu[i].select[j]);
			else stu[i].select[j]=-1;
	}
	sort(stu,stu+N,cmp1);
	for(int x=0;x<N;++x)
	{
		int y=0;
		while(y<K){
			int TheSel=stu[x].select[y];
			if(real[TheSel]<expect[TheSel])
			{
				result[TheSel][real[TheSel]]=x;
				++real[TheSel];
				break;
			}
			else if(isSame(result[TheSel][real[TheSel]-1],x))
			{
				result[TheSel][real[TheSel]]=x;
				++real[TheSel];
				break;
			}
			else ++y;
		}
	}
	for(int i=0;i<M;++i)
	{   
		int x=0;
		while(result[i][x]!=-1)	++x;
		sort(result[i],result[i]+x,cmp2);
		for(int j=0;j<x;++j){
            if(j) printf(" ");
	        printf("%d",stu[result[i][j]].f);
        }
        printf("\n");
	}
	return 0;
}
