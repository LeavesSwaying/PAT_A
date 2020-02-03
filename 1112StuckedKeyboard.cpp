#include<iostream>
#include<string>
#include<set>
using namespace std;

bool HashTable[37]={false};
set<char> s;


int transform(char c)
{
	if('0'<=c&&c<='9')
		return c-'0';
	else if('a'<=c&&c<='z')
		return c-'a'+10;
	else
		return 36;		
}

int main()
{
	string str,result;
	int k;
	cin>>k>>str;
	int j=0;
	char ic,jc;
	for(int i=0;i<str.size();++i)
	{
		ic=str[i];jc=str[j];
		if(ic!=jc)
		{
			if((i-j)%k!=0) HashTable[transform(jc)]=true; 
			j=i;
		}
	}
	int i=0;
	while(i<str.size())
	{
		if(HashTable[transform(str[i])])
			result.push_back(str[i]);
		else
		{
			if(s.find(str[i])==s.end()) cout<<str[i];
			s.insert(str[i]);
			result.push_back(str[i]);
			i+=k;
			continue;
		}
		++i;
	}
	printf("\n");
	cout<<result;
	return 0;
} 
