#include<iostream>
using namespace std;

const int MaxSize=105;
int A[MaxSize],A2[MaxSize],B[MaxSize],N;

bool same()
{
	for(int i=1;i<=N;++i)
		if(A[i]!=B[i]) return false;
	return true;
}

bool insertSort()
{
	int i,j,temp;
	bool flag=false;
	for(i=2;i<=N;++i){
		temp=A[i];
		for(j=i;j>1&&A[j-1]>temp;--j)
			A[j]=A[j-1];
		A[j]=temp;
		if(same()){
			flag=true;
			break;
		}
	}
	if(flag){
		++i;
		temp=A[i];
		for(j=i;j>1&&A[j-1]>temp;--j)
			A[j]=A[j-1];
		A[j]=temp;
		return true;
	}
	return false;
}

void downAdjust(int low,int high)
{
	int temp;
	int i=low,j=2*i;
	while(j<=high){
		if(j+1<=high&&A[j+1]>A[j])
			j=j+1;
		if(A[j]>A[i]){
			temp=A[i];A[i]=A[j];A[j]=temp;
			i=j;j=2*i;
		}
		else break;
	}
}

void heapSort()
{
	int temp;
	for(int i=N/2;i>=1;--i)
		downAdjust(i,N);
	for(int i=N;i>1;--i){
		temp=A[i];A[i]=A[1];A[1]=temp;
		downAdjust(1,i-1);
		if(same()){
			--i;
			temp=A[i];A[i]=A[1];A[1]=temp;
			downAdjust(1,i-1);
			return;
		}
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		scanf("%d",&A[i]);
		A2[i]=A[i];
	}
	for(int i=1;i<=N;++i){
		scanf("%d",&B[i]);
	}
	if(insertSort()){
		printf("Insertion Sort\n");
	} 
	else{
		for(int i=1;i<=N;++i){
			A[i]=A2[i];
		}
		printf("Heap Sort\n");
		heapSort();
	} 
	for(int i=1;i<N;++i)
			printf("%d ",A[i]);
	printf("%d",A[N]);
	return 0;	
} 
