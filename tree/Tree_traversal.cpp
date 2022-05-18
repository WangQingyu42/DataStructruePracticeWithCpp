#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//Space complexity O(h)
void PreOrder(BiTree T){
	if(T!=NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void PostOrder(BiTree T){
	if(T!=NULL){
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		visit(T);
	}
}

int treeDepth(BiTree T){
	if (T == NULL){
		return 0;
	}
	else{
		int l=treeDepth(T->lchild);
		int r=treeDepth(T->rchild);
		return l>r ? l+1 : r+1;
	}
}

//Implementation of Queue using Linked List
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct LinkNode{
	BiTNode * data;    //保存指针而不是结点
	struct LinkNode *next;
}LinkNode;

typedef struct{
	LinkNode *front,*rear;
}LinkQueue;

void LevelOrder(BiTree T){
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q,T);
	while(!IsEmpty){
		DeQueue(Q,p);
		visit(p);
		if(p->lchild!=NULL)
			EnQueue(Q,p->lchild);
		if(p->rchild!=NULL)
			EnQueue(Q,p->rchild);
	}
}


