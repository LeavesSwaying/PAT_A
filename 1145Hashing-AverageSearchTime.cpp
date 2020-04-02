#include<iostream>
#include<cmath>
using namespace std;

const int MaxN=20005;

int HashTable[MaxN];
int MSize,M,N;

bool isPrime(int n)
{
	/*�ж������ĺ���*/
	if(n<=1) return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;++i)
		if(n%i==0) return false;
	return true;
} 

bool F=false;
void insert(int x)
{
	for(int i=0;i<=MSize/2;++i)
	{
		int y=(x+i*i)%MSize;
		if(HashTable[y]==-1)
		{
			HashTable[y]=x;
			return;
		}
	}
	printf("%d cannot be inserted.\n",x);
}

int main()
{	
	/*��ʼ����ϣ��*/ 
	fill(HashTable,HashTable+MaxN,-1); 
	
	scanf("%d%d%d",&MSize,&N,&M);
	while(isPrime(MSize)==false)
		MSize++;
	int a;
	for(int i=0;i<N;++i)
	{
		scanf("%d",&a);
		insert(a);
	}
	int num=0;
	for(int i=0;i<M;++i)
	{
		scanf("%d",&a);
		/*������j<=MSize/2������������Ҫ�󣬵�����̽�⵽��j<=MSize*/ 
		for(int j=0;j<=MSize;++j)
		{
			int y=(a+j*j)%MSize;
			num++;
			/*Ҫע�ⷢ�ֿ�Ԫ��Ҳ��ʾԪ�ز������ڹ�ϣ����*/
			if(HashTable[y]==-1||HashTable[y]==a)
				break;
		}
	}
	/*������Կ������㱣����������������*/
	printf("%0.1lf\n",1.0*num/M);
	return 0;
} 
