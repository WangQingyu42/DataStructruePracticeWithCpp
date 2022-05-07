#include<stddef.h>
#include<stdlib.h>
#include<stdio.h> 
//队列是只允许在一端进行插入，在另一端删除的线性表
//先进先出First In First Out (FIFO)

//用顺序存储实现队列
# define MaxSize 10

//若不许浪费存储空间,则加入size
//初始化时rear = front =0; size=0
//插入成功size++ 删除成功size--
//队满条件size==MaxSize,队空size==0
//或者 加入tag 
//每次删除成功时令tag=0 每次插入操作成功时令tag=1
//只有删除操作才可能导致队空 front==rear && tag==1
//只有插入操作才可能导致队满

typedef struct{
	int data[MaxSize];
	int front,rear;  //队头指针和队尾指针
	// int size;  //队列当前长度
	// int tag;    //最近进行的是插入/删除操作 
} SqQueue;

void InitSqQueue(SqQueue &Q){
	Q.rear=Q.front=0;
}
bool SqEmpty(SqQueue Q){
	if(Q.rear=Q.front)
		return true;
	else
		return false;
}
//入队（循环队列）
bool SqEnQueue(SqQueue &Q,int x){
	if((Q.rear+1)%MaxSize==Q.front) //判断队满 ,牺牲一个存储单元
		return false;
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize; //队尾指针加1取模，将储存空间在逻辑上变成了“环状”
}
//出队(删除一个队头元素，并用x返回)
bool SqDeEnQueue(SqQueue &Q,int &x){
	if(Q.front==Q.rear)
		return false;
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true;
}
//获得队头元素的值，用x返回
bool GetHead(SqQueue Q,int &x){
	if(Q.front==Q.rear)
		return false;
	x=Q.data[Q.front];
	return true;
}
//队列元素个数：(rear+MaxSize-front)% MaxSize




void testSqQueue(){
	SqQueue Q;
}

