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

//��ʼ������ͷ���ĵ�����
bool InitList1(LinkList &L){
	L = NULL;//�ձ���ʱû���κν��
	return true;
}

//�жϵ������Ƿ�Ϊ��
bool Empty1(LinkList L){
	if (L == NULL)
		return true;
	else
		return false;
}


//��ʼ����ͷ���ĵ�����
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
//��λ�����
bool ListInsert(LinkList &L, int i, int e){
	if(i<1)
		return false;
	LNode *p;  //ָ��pָ��ǰɨ�赽�Ľ��
	int j=0;    //��ǰpָ����ǵڼ����ڵ�
	p = L;       //Lָ��ͷ��㣬ͷ����ǵ�0���ڵ�
	while(p != NULL && j<i-1){ //ѭ���ҵ���i-1�����
		p->next;
		j++;
	}//���ʱ�临�Ӷ�O(1)�0(n)
	if(p == NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//ָ���ڵ�ĺ���������p�ڵ�֮�����Ԫ��e
bool InsertNextNode(LNode *p,int e){
	if (p=NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
//ǰ���������p�ڵ�֮ǰ����Ԫ��e
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
//��λ��ɾ��
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
//��λ���� ʱ�临�Ӷ�O(n)
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

//��ֵ���� ʱ�临�Ӷ�O(n)
LNode * LocateElem(LinkList L, int e){
	LNode *p = L->next;
	while(p != NULL && p->data != e){
		p = p->next;
	}
	return p;
}
//���ĳ��� ʱ�临�Ӷ�O(n)
int Length(LinkList L){
	int len=0;
	LNode *p = L;
	while(p != NULL){
		p=p->next;
		len++;
	}
	return len;
}

//������Ľ���
//β�巨���������� ʱ�临�Ӷ�O(n)
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
//ͷ�巨����������
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