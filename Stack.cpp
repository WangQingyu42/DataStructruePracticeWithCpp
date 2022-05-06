#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>

//栈是只允许在一端进行插入或删除操作的线性表
//特点 后进先出 Last In First Out (LIFO)

#define MaxSize 10
typedef struct{
	int data[MaxSize]; //静态数组存放栈中元素
	int top;                 //栈顶指针  
}SqStack;

//初始化栈
void InitStack(SqStack &S){
	S.top = -1;
}

//判断栈空
bool StackEmpty(SqStack &S){
	if(S.top == -1)
		return true;
	else
		return false;
}

//新元素入栈
bool Push(SqStack &S,int x){
	if(S.top == MaxSize-1)
		return false;
	S.top=S.top+1;
	S.data[S.top+1] = x;
	//S.data[++S.top] = x;
	return true;	
}

//出栈操作
bool Pop(SqStack &S,int &x){
	if(S.top == -1)
		return false;
	x=S.data[S.top];
	S.top=S.top-1;
	return true;	
}
//读取栈顶元素
bool GetTop(SqStack &S,int &x){
	if(S.top == -1)
		return false;
	x=S.data[S.top];
	return true;	
}

//共享栈
typedef struct{
	int data[MaxSize]; //静态数组存放栈中元素
	int top0;                 //0号栈栈顶指针 
	int top1;                 //1号栈栈顶指针
}ShStack;
//初始化共享栈
void InitShStack(ShStack &S){
	S.top0=-1;
	S.top1=MaxSize;
}
//共享栈栈满的条件：top0+1==top1

//链栈的定义
typedef struct Linknode{
	int data;
	struct Linknode *next;
} *LiStack;


void testStack(){
	SqStack S;    //声明一个顺序栈（分配空间）
}