#include<iostream>
#include<string>
using namespace std;

const int MaxN=40;

int main()
{
	int N;
	string D,str;
	cin>>D;
	scanf("%d",&N);
	for(int i=0;i<N-1;++i)
	{
		int cnt=0;
		char G=D[0];
		for(int j=0;j<D.size();++j)
		{
			if(D[j]!=G)
			{
				str.push_back(G);
				str.push_back(cnt+'0');
				G=D[j];
				cnt=1;
				continue;	
			}
			cnt++; 
		}
		str.push_back(G);
		str.push_back(cnt+'0');
		//cout<<str<<endl;
		D=str;
		str.clear();
	}
	cout<<D<<endl;
	return 0;
} 
