#include<iostream>
#include<string>
using namespace std;

bool HashTable[30]={false};

int findID(string s)
{
	int ans=0;
	for(int i=0;i<s.size();++i)
		ans+=s[i]-'0';
	return ans;	
}

int main()
{
	int N;
	scanf("%d",&N);
	string str;
	for(int i=0;i<N;++i)
	{
		cin>>str;
		int ID=findID(str);
		HashTable[ID]=true;	
	}
	int ans[30],af=0;
	for(int i=0;i<30;++i)
	{
		if(HashTable[i])
		{
			ans[af++]=i;
		}
	}
	printf("%d\n",af);
	for(int i=0;i<af;++i)
	{
		if(i>0) printf(" ");
		printf("%d",ans[i]);
	}	
}
