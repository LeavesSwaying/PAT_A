#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

typedef struct BinNode{
	int data;
	BinNode *Left,*Right;
}BinNode;

int post[30],inor[30],N;

BinNode* CreatNode()
{
	BinNode* NewNode=(BinNode*)malloc(sizeof(struct BinNode));
	NewNode->data=0;
	NewNode->Left=NULL;
	NewNode->Right=NULL;
	return NewNode;
}

BinNode* BuildTree(int PS,int PE,int IS,int IE)
{
	if(PS>PE) return NULL;
	BinNode* Child=CreatNode();
	Child->data=post[PE];
	int i;
	for(i=IS;i<=IE&&post[PE]!=inor[i];++i);
	int NumLeft=i-IS;
	Child->Left=BuildTree(PS,PS+NumLeft-1,IS,i-1);
	Child->Right=BuildTree(PS+NumLeft,PE-1,i+1,IE);
	return Child;
}

void PrintTree(BinNode* Node)
{
	static bool flag=false;
	if(flag) printf(" %d",Node->data);
	else{
		flag=true;
		printf("%d",Node->data);
	}
}

void Travel(BinNode* Head)
{
	queue<BinNode*> s;
	s.push(Head);
	BinNode* temp;
	while(!s.empty()){
		temp=s.front();s.pop();
		if(temp->Left) s.push(temp->Left);
		if(temp->Right) s.push(temp->Right);
		PrintTree(temp);
		free(temp);
	}
}

int main()
{
	freopen("data.in","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<N;++i){
		scanf("%d",&inor[i]);
	}
	BinNode* Tree=BuildTree(0,N-1,0,N-1);
	Travel(Tree);
	return 0;
}
