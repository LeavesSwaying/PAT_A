#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(char a,char b)
{
	return a>b;
}

string sub(string a,string b)
{
	char c;
	string ans;
	for(int i=0;i<4;++i)
	{
		c=a[i]-b[i]+'0';
		ans.push_back(c);
	}
	for(int i=3;i>=0;--i)
	{
		if(ans[i]<'0')
		{
			ans[i]+=10;
			ans[i-1]--;
		}
		
	}
	return ans;
}

int main()
{
	string num,numB,numS;
	cin>>num;
	if(num=="6174")
	{
		printf("7641-1467=6174");
		return 0;
	}
	while(num.size()!=4)
	{
		num.push_back('0');
	}
	while(num!="6174"&&num!="0000")
	{
		sort(num.begin(),num.end());
		numS=num;
		sort(num.begin(),num.end(),cmp);
		numB=num;
		num=sub(numB,numS);
		cout<<numB<<" - "<<numS<<" = "<<num<<endl;
	}
	return 0;
} 
