#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct student
{
	char id[11];
	char name[11];
	int grade;
}stu[1000];

bool cmp(student a,student b)
{
	return a.grade>b.grade;
}

int main()
{
	int N,Gmin,Gmax;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%s%s%d",stu[i].name,stu[i].id,&stu[i].grade);
	}
	sort(stu,stu+N,cmp);
	scanf("%d%d",&Gmin,&Gmax);
	bool flag=false;
	for(int i=0;i<N;++i){
		if(stu[i].grade<=Gmax&&Gmin<=stu[i].grade)
		{
			flag=true;
			printf("%s %s\n",stu[i].name,stu[i].id);
		}
	}
	if(!flag) printf("NONE");
	return 0;
} 
