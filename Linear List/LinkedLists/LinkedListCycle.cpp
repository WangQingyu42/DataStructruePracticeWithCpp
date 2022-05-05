#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

typedef struct DNode{
	int data;
	struct DNode *prior,*next;
}DNode,*DLinklist;

//初始化带头结点的单链表
bool InitList(LinkList &L){
	L = (LNode*) malloc(sizeof(LNode));
	if (L==NULL)
		return false;
	L->next = L;
	return true;
}

bool Empty(LinkList L){
	if (L->next == L)
		return true;
	else
		return false;
}

bool isTail(LinkList L, LNode *p){
	if (p->next == L)
		return true;
	else
		return false;
}



bool InitDLinkList(DLinklist &L){
	L = (DNode *)malloc(sizeof(DNode));
	if(L==NULL)
		return false;
	L->prior=L;
	L->next=L;
	return true;
}
bool Empty(DLinklist L){
	if (L->next=NULL)
		return true;
	else
		return false;
}
bool isTail2(DLinklist L,DNode *p){
	if(p->next==L)
		return true;
	else
		return false;
}