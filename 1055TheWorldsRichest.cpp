#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct person
{
	char name[9];
	int age;
	int worth;
}per[100000];

bool cmp(person a,person b)
{
	if(a.worth!=b.worth) return a.worth>b.worth;
	else if(a.age!=b.age) return a.age<b.age; 
	else return strcmp(a.name,b.name)<0;
}

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;++i)
		scanf("%s%d%d",per[i].name,&per[i].age,&per[i].worth);
	sort(per,per+N,cmp);
	int M,Amin,Amax,count;
	for(int i=1;i<=K;++i)
	{
		count=0;
		scanf("%d%d%d",&M,&Amin,&Amax);
		printf("Case #%d:\n",i);
		for(int j=0;j<N&&M!=count;++j)
		{
			if(per[j].age<=Amax&&Amin<=per[j].age)
			{
				printf("%s %d %d\n",per[j].name,per[j].age,per[j].worth);
				++count;
			}	
		}
		if(count==0) printf("None\n");
	}
	return 0;
} 
