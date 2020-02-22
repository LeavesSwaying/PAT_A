#include<iostream>
#include<string>
using namespace std;

typedef long long LL;

LL N;

void process(string str,LL &a,LL &b,LL &c)
{
	a=0;b=0;c=0;
	for(int i=0;i<str.size();++i)
	{
		a=a*10+(str[i]-'0');
		if(i<str.size()/2)
		{
			b=b*10+(str[i]-'0');
		}
		else
		{
			c=c*10+(str[i]-'0');
		}
	}
}

int main()
{
	string str;
	scanf("%lld",&N);
	for(int i=0;i<N;++i)
	{
		cin>>str;
		LL a,b,c;
		process(str,a,b,c);
		LL m=b*c;
		if(m==0) printf("No\n");
		else if(a%m==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;	
} 
