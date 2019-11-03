#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct student
{
	int id;
	char name[9];
	int grade;
}stu[100000]; 

bool cmp1(student a,student b)
{
	return a.id<b.id;
}
bool cmp2(student a,student b)
{
    
    int s=strcmp(a.name,b.name);
    //if(a.name!=b.name) return strcmp(a.name,b.name);
    if(s!=0) return s<0;
	else return a.id<b.id; 
}
bool cmp3(student a,student b)
{
	if(a.grade!=b.grade) return a.grade<b.grade;
	else return a.id<b.id; 
}
int main()
{
	int N,Mod;
	scanf("%d%d",&N,&Mod);
	for(int i=0;i<N;++i)
	{
		scanf("%d%s%d",&stu[i].id,stu[i].name,&stu[i].grade);
	}
	if(Mod==1)
		sort(stu,stu+N,cmp1);
	else if(Mod==2)
		sort(stu,stu+N,cmp2);
	else 
		sort(stu,stu+N,cmp3);
	for(int i=0;i<N;++i)
	{
		printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
	}
	return 0;
}
