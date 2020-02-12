#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int MaxN=10005;

priority_queue<double,vector<double>,greater<double>> q;

int main()
{
	int Tmp,N;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&Tmp);
		q.push(1.0*Tmp);
	}
	double a,b,ans;
	while(q.size()!=1)
	{
		a=q.top();q.pop();
		b=q.top();q.pop();
		ans=(a+b)/2.0;
		q.push(ans);
	}
    printf("%.0lf",q.top());
	return 0;
} 
