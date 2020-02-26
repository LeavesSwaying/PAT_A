#include<iostream>
#include<string>
using namespace std;

string reverse(string s)
{
	string ans;
	for(int i=s.size()-1;i>=0;--i)
	{
		ans.push_back(s[i]);
	}
	return ans;
}

string ADD(string str1,string str2)
{
	cout<<str1<<" + "<<str2;
	string sum;
	bool F=false;
	for(int i=str1.size()-1;i>=0;--i)
	{
		if(F==true)
		{
			++str1[i];
		}
		F=false;
		char s;
		if(str1[i]-'0'+str2[i]-'0'>=10)
		{
			s=str1[i]+str2[i]-'0'-10;
			F=true;
		}
		else s=str1[i]+str2[i]-'0';
		sum.push_back(s);	
	}
	if(F==true) sum.push_back('1');
	cout<<" = ";
	return reverse(sum);
}



bool Judge(string s)
{
	for(int i=0,j=s.size()-1;i<j;++i,--j)
	{
		if(s[i]!=s[j]) return false;
	}
	return true;
}

int main(){
	string str1;
	cin>>str1;
    if(Judge(str1))
	{
		printf("%s is a palindromic number.",str1.c_str());
		return 0;
	}
	string str2=reverse(str1);
	for(int i=0;i<10;++i)
	{
		string sum=ADD(str1,str2);
		cout<<sum<<endl;
		if(Judge(sum))
		{
			printf("%s is a palindromic number.",sum.c_str());
			return 0;
		}
		str1=sum;
		str2=reverse(str1);
	}
	printf("Not found in 10 iterations.");
	return 0;
} 
