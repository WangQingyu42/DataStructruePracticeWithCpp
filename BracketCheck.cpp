#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>


#define MaxSize 10
typedef struct{
	char data[MaxSize];
	int top;                  
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
bool Push(SqStack &S,char x){
	if(S.top == MaxSize-1)
		return false;
	S.top=S.top+1;
	S.data[S.top+1] = x;
	//S.data[++S.top] = x;
	return true;	
}

//��ջ����
bool Pop(SqStack &S,char &x){
	if(S.top == -1)
		return false;
	x=S.data[S.top];
	S.top=S.top-1;
	return true;	
}

bool bracketCheck(char str[],int length){
	SqStack S;
	InitStack(S);
	for(int i=0;i<length;i++){
		if (str[i]=='(' || str[i]=='[' || str[i]=='{'){
			Push(S,str[i]);
		}else{
			if(StackEmpty(S))
				return false;
		}
		char topElem;
		Pop(S,topElem);
		if(str[i]=='(' && topElem !=')')
			return false;
		if(str[i]=='[' && topElem !=']')
			return false;
		if(str[i]=='{' && topElem !='}')
			return false;
	}
	return StackEmpty(S);
}