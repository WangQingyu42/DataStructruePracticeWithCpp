#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
//struct Lnode{
//	int data;
//	struct Lnode *next;
//}
//typedef struct LNode Lnode;
//typedef struct LNode *LinkList;
//struct Lnode *p = (struct LNode*)malloc(sizeof(struct Lnode));

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

//初始化不带头结点的单链表
bool InitList1(LinkList &L){
	L = NULL;//空表，暂时没有任何结点
	return true;
}

//判断单链表是否为空
bool Empty1(LinkList L){
	if (L == NULL)
		return true;
	else
		return false;
}


//初始化带头结点的单链表
bool InitList(LinkList &L){
	L = (LNode*) malloc(sizeof(LNode));
	if (L==NULL)
		return false;
	L->next = NULL;
	return true;
}
bool Empty(LinkList L){
	if (L->data == NULL)
		return true;
	else
		return false;
}
//按位序插入
bool ListInsert(LinkList &L, int i, int e){
	if(i<1)
		return false;
	LNode *p;  //指针p指向当前扫描到的结点
	int j=0;    //当前p指向的是第几个节点
	p = L;       //L指向头结点，头结点是第0个节点
	while(p != NULL && j<i-1){ //循环找到第i-1个结点
		p->next;
		j++;
	}//最好时间复杂度O(1)最坏0(n)
	if(p == NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//指定节点的后插操作，在p节点之后插入元素e
bool InsertNextNode(LNode *p,int e){
	if (p=NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//前插操作，在p节点之前插入元素e
bool InsertPriorNode(LNode *p, int e){
	if(p=NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data=p->data;
	p->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
//按位序删除
bool ListDelete(LinkList &L,int i, int &e){
	if(i<1)
		return false;
	LNode *p;
	int j=0;
	p = L;
	while(p != NULL && j<i-1){
		p=p->next;
		j++;
	}
	if(p==NULL)
		return false;
	LNode *q = p->next;
	e=q->data;
	p->next=q->next;
	free(q);
	return true;
} 
//按位查找 时间复杂度O(n)
LNode * GetElem(LinkList L, int i){
	if(i<0)
		return NULL;
	LNode *p;
	int j=0;
	p=L;
	while(p != NULL && j<i){
		p = p->next;
		j++;
	}
	return p;
}

//按值查找 时间复杂度O(n)
LNode * LocateElem(LinkList L, int e){
	LNode *p = L->next;
	while(p != NULL && p->data != e){
		p = p->next;
	}
	return p;
}
//求表的长度 时间复杂度O(n)
int Length(LinkList L){
	int len=0;
	LNode *p = L;
	while(p != NULL){
		p=p->next;
		len++;
	}
	return len;
}

//单链表的建立
//尾插法建立单链表 时间复杂度O(n)
LinkList List_TailInsert(LinkList &L){
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s,*r = L;
	scanf("%d",&x);
	while(x !=9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return L;
}
//头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->data = NULL;
	scanf("%d",&x);
	while(x !=9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
	return L;
}


void main(){
	LinkList L;
	InitList(L);
}