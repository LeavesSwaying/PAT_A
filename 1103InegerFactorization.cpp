#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int N,K,P,MaxFacSum;
vector<int> fac,ans,temp;
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
	fac.push_back(0);
	int i=1,Tmp;
	while(1)
	{
		Tmp=(int)pow(i++,P);
		if(Tmp<N) fac.push_back(Tmp);
		else break;
	}
	DFS(fac.size()-1,0,0,0);
	if(MaxFacSum==-1) printf("Impossible\n");
	else{
		printf("%d=%d^%d",N,ans[0],P);
		for(i=1;i<ans.size();++i)
			printf("+%d^%d",ans[i],P);
	}
	return 0;
} 
