#include<iostream>
#include<vector>
using namespace std;

const int MaxN=100005;

struct node{
	double price;
	vector<int> child;
}Tree[MaxN];
int N,Root;
double P,r,sum=0;
int num=0;

void DFS(int Root,int level)
{
	if(Tree[Root].child.size()==0)
	{
		if(sum<Tree[Root].price)
		{
			sum=Tree[Root].price;
			num=1;
		}
		else if(sum==Tree[Root].price)
		{
			num++;	
		} 
		return;
	}
	for(int i=0;i<Tree[Root].child.size();++i)
	{
		Tree[Tree[Root].child[i]].price=Tree[Root].price*(1+r);
		DFS(Tree[Root].child[i],level+1);
	}
}

int main()
{
	int Tmp;
	scanf("%d%lf%lf",&N,&P,&r);
	r=r/100;
	for(int i=0;i<N;++i)
	{
		scanf("%d",&Tmp);
		if(Tmp==-1) Root=i;
		else
		{
			Tree[Tmp].child.push_back(i);
		}
	}
	Tree[Root].price=P;
	DFS(Root,0);
	printf("%.2lf %d",sum,num);
	return 0;
} 
