#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int MaxN=1005;

int N,M;
int num[MaxN];

bool JudgeMax()
{
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(2*u+1<N)
		{
			if(num[u]<num[2*u+1])
				return false;
			q.push(2*u+1);
			if(2*u+2<N)
			{
				if(num[u]<num[2*u+2])
					return false;
				q.push(2*u+2);		
			}	
		}
	}
	return true;
}

bool JudgeMin()
{
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(2*u+1<N)
		{
			if(num[u]>num[2*u+1])
				return false;
			q.push(2*u+1);
			if(2*u+2<N)
			{
				if(num[u]>num[2*u+2])
					return false;
				q.push(2*u+2);		
			}	
		}
	}
	return true;
}
bool F;
void postTravel(int x)
{	
	if(x>=N) return;
	postTravel(2*x+1);
	postTravel(2*x+2);
    if(F==false) F=true;
    else printf(" ");
	printf("%d",num[x]); 
} 
 
int main()
{
	scanf("%d%d",&M,&N);
	for(int i=0;i<M;++i)
	{
		fill(num,num+MaxN,-1);
		for(int j=0;j<N;++j)
		{
			scanf("%d",&num[j]);
		}
		if(JudgeMax())
			printf("Max Heap\n");
		else if(JudgeMin())
			printf("Min Heap\n");
		else
			printf("Not Heap\n");
        F=false;	
		postTravel(0);
		printf("\n");
	}
	return 0;	
} 
