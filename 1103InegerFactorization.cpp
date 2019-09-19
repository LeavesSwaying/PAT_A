#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

const int inf=0x3f3f3f3f;
int N,K,P,MaxFacSum=-inf;
vector<int> fac,ans,temp;
int power(int x) {
    int ans = 1;
    for (int i = 0; i < P; i++) {
        ans *= x;
    }
    return ans;
}
void DFS(int index,int NowK,int sum,int FacSum)
{
	if(sum==N&&NowK==K){
		if(FacSum>MaxFacSum){
			ans=temp;
			MaxFacSum=FacSum;
		}
		return;
	}
	if(sum>N||NowK>K) return;
	if(index-1>=0){
		temp.push_back(index);
		DFS(index,NowK+1,sum+fac[index],FacSum+index);
		temp.pop_back();
		DFS(index-1,NowK,sum,FacSum);
	}
}

int main()
{
	scanf("%d%d%d",&N,&K,&P);
	int i=0,Tmp=0;
	while(Tmp<=N)
	{
        fac.push_back(Tmp);
		Tmp=power(++i);
	}
	DFS(fac.size()-1,0,0,0);
	if(MaxFacSum==-inf) printf("Impossible\n");
	else{
		printf("%d = %d^%d",N,ans[0],P);
		for(i=1;i<ans.size();++i)
			printf(" + %d^%d",ans[i],P);
	}
	return 0;
} 
