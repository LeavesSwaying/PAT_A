#include<iostream>
using namespace std;

const int MaxN=100000;

int N;
double A[MaxN];
//ע��Ϊһ����֪��Ϊ�εĴ���
int findFactor(int i)
{
	//return N+i*(N-i-1);
    return (i+1)*(N-i);
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%lf",&A[i]);
	double sum=0;
	for(int i=0;i<N;++i)
	{
        //sum+=A[i]*findFactor(i);
		sum+=A[i]*(i+1)*(N-i);
	}
	printf("%.2lf\n",sum);
	return 0;	
} 
