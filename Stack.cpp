#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>

//ջ��ֻ������һ�˽��в����ɾ�����������Ա�
//�ص� ����ȳ� Last In First Out (LIFO)

#define MaxSize 10
typedef struct{
	int data[MaxSize]; //��̬������ջ��Ԫ��
	int top;                 //ջ��ָ��  
}SqStack;

//��ʼ��ջ
void InitStack(SqStack &S){
	S.top = -1;
}

//�ж�ջ��
bool StackEmpty(SqStack &S){
	if(S.top == -1)
		return true;
	else
		return false;
}

//��Ԫ����ջ
bool Push(SqStack &S,int x){
	if(S.top == MaxSize-1)
		return false;
	S.top=S.top+1;
	S.data[S.top+1] = x;
	//S.data[++S.top] = x;
	return true;	
}

//��ջ����
bool Pop(SqStack &S,int &x){
	if(S.top == -1)
		return false;
	x=S.data[S.top];
	S.top=S.top-1;
	return true;	
}
//��ȡջ��Ԫ��
bool GetTop(SqStack &S,int &x){
	if(S.top == -1)
		return false;
	x=S.data[S.top];
	return true;	
}

//����ջ
typedef struct{
	int data[MaxSize]; //��̬������ջ��Ԫ��
	int top0;                 //0��ջջ��ָ�� 
	int top1;                 //1��ջջ��ָ��
}ShStack;
//��ʼ������ջ
void InitShStack(ShStack &S){
	S.top0=-1;
	S.top1=MaxSize;
}
//����ջջ����������top0+1==top1

//��ջ�Ķ���
typedef struct Linknode{
	int data;
	struct Linknode *next;
} *LiStack;


void testStack(){
	SqStack S;    //����һ��˳��ջ������ռ䣩
}