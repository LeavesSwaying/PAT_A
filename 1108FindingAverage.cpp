#include<iostream>
#include<string>
using namespace std;

int N;

bool check(string s,double &x)
{
	int dot=0,n1=0,n2=0;
	int i=0;
	if(s[i]=='-') i++;
	for(;i<s.size();++i)
	{
		if(s[i]=='.')
		{
			dot++;
			if(dot>1) return 0;
		}
		else if('0'<=s[i]&&s[i]<='9')
		{
			if(dot) n2++;
			else n1++;
		}
		else return 0;
	}
	if(n2>2) return 0;
	sscanf(s.c_str(),"%lf",&x);
	if(x>=-1000&&x<=1000) return 1;
	return 0;
}

int main()
{
	string Tmps;
	scanf("%d", &N);
	double sum = 0,x;
	int n=0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Tmps;
		if (check(Tmps,x))
		{
			sum+=x;
			++n;
		}
		else
		{
			cout<<"ERROR: "<<Tmps<<" is not a legal number\n";
		}
	}
	sum=sum/(1.0*n);
	if (n>1)
		printf("The average of %d numbers is %.2f", n, sum);
	else if(n==1)
        printf("The average of 1 number is %.2f",sum);
    else
		printf("The average of 0 numbers is Undefined");
	return 0;
}
