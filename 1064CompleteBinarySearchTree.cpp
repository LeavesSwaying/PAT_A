#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010;

int num[N],CBT[N],n,index=0;

void inOrder(int root)
{
	if(root>n) return;
	inOrder(root*2);
	CBT[root]=num[index++];
	inOrder(root*2+1);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&num[i]);
	sort(num,num+n);
	inOrder(1);
	for(int i=1;i<=n;++i){
		printf("%d",CBT[i]);
		if(i<n) printf(" ");	
	}
	return 0;
} 
