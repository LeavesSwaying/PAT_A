#include<iostream>
#include<cmath>
using namespace std;

const int MaxN=20005;

int HashTable[MaxN];
int MSize,M,N;

bool isPrime(int n)
{
	/*判断素数的函数*/
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
	/*初始化哈希表*/ 
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
		/*理论上j<=MSize/2即可满足所有要求，但这里探测到了j<=MSize*/ 
		for(int j=0;j<=MSize;++j)
		{
			int y=(a+j*j)%MSize;
			num++;
			/*要注意发现空元素也表示元素不存在于哈希表中*/
			if(HashTable[y]==-1||HashTable[y]==a)
				break;
		}
	}
	/*这里可以看出浮点保留进制是四舍五入*/
	printf("%0.1lf\n",1.0*num/M);
	return 0;
} 
