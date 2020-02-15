#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int MaxN=10005;

string s[MaxN];

bool cmp(string a,string b)
{
	return a+b<b+a;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		cin>>s[i];
	}
	sort(s,s+N,cmp);
	string ans;
	for(int i=0;i<N;++i)
	{
		ans+=s[i];
	}
	while(ans.size()!=0&&ans[0]=='0')
	{
		ans.erase(ans.begin());
	}
	if(ans.size()==0) cout<<0;
	else cout<<ans;
	return 0;
}
