#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int M,N,K;
queue<int> s;

bool JudgeSeq()
{
	stack<int> m;
	int tag;
	int n=1;
	for(int i=0;i<N;++i){
		tag=s.front();s.pop();
		while(m.empty()||tag!=m.top()){
			if(n==N+1) break;
			if(m.size()==M)
			{
				while(!s.empty()) s.pop();
				return false;
			} 
			m.push(n++);	
		} 
		if(tag==m.top()) m.pop();
		else break;
	}
	while(!s.empty()) s.pop();
	if(m.empty()) return true;
	else return false;
}

int main() 
{
	freopen("data.in","r",stdin);
	scanf("%d%d%d",&M,&N,&K);
	int a;
	while(K--){
		for(int i=0;i<N;++i){
			scanf("%d",&a);
			s.push(a);
		}
		if(JudgeSeq()) printf("YES");
		else printf("NO");
		printf("\n");
	}
	return 0;
}
