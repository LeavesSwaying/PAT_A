#include<iostream>
#include<string>
#include<set>
using namespace std;

int N,M,index;
set<string> ifSave;
int main()
{
	string str;
	bool F=false;
	scanf("%d%d%d",&M,&N,&index);
	for(int i=1;i<=M;++i)
	{
		cin>>str;
		if(index==i)
		{
		
			if(ifSave.find(str)==ifSave.end())
			{
				cout<<str<<endl;
				F=true;
				index+=N;		
			}
			else ++index;
		ifSave.insert(str);
		}
	}
	if(F==false) printf("Keep going...");
	return 0;
}
