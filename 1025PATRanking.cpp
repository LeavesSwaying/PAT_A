#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std; 
/*cannot use typedef here*/
struct student
{
	char id[14];
	int score;
	int location_number;
	int local_rank;
}stu[30005];

bool cmp(student a,student b)
{
	if(a.score!=b.score) return a.score>b.score;
	else return strcmp(a.id,b.id)<0;
}

int main()
{
	int M,N,score,count=0;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&M);
		for(int j=1;j<=M;++j)
		{
			scanf("%s %d",stu[count].id,&score);
			stu[count].score=score;
			stu[count++].location_number=i;
		}
		sort(stu+count-M,stu+count,cmp);
		stu[count-M].local_rank=1;
		for(int j=count-M+1;j<count;++j){
			if(stu[j].score==stu[j-1].score)
				stu[j].local_rank=stu[j-1].local_rank;
			else
				stu[j].local_rank=j+1-(count-M);
		}
	}
	printf("%d\n",count);
	sort(stu,stu+count,cmp);
	int r=1;
	for(int i=0;i<count;++i)
	{
		if(i>0&&stu[i].score!=stu[i-1].score) r=i+1;
		printf("%s ",stu[i].id);
		printf("%d %d %d\n",r,stu[i].location_number,stu[i].local_rank);
	}
	return 0;
}
