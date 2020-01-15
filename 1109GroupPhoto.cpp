#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

struct Node
{
	string name;
	int height;
}v[10001];

int N,R,S=0,E=0;

bool cmp(Node x,Node y)
{
	if(x.height!=y.height) return x.height>y.height;
	else return x.name<y.name;
}

int main()
{
	scanf("%d%d",&N,&R);
	for(int i=0;i<N;++i)
	{
		cin>>v[i].name;
		scanf("%d",&v[i].height);
	}
	sort(v,v+N,cmp);
	int t=0,row=R;
	int m,i,j;
	while(row)
	{
		if(row==R)
			m=N-N/R*(R-1);
		else
			m=N/R;
		vector<string> stemp(m);
		stemp[m/2]=v[t].name;
		j=m/2-1;
		for(i=t+1;i<t+m;i=i+2)
			stemp[j--]=v[i].name;
		j=m/2+1;
		for(i=t+2;i<t+m;i=i+2)
			stemp[j++]=v[i].name;
		cout<<stemp[0];
		for(int i=1;i<m;++i) cout<<" "<<stemp[i];
		cout<<endl;
		t=t+m;
		row--;				
	}
	return 0;
} 
