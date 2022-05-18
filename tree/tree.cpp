#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#define MaxSize 100
//Binary Tree representation(sequential)
//only suit for full binary tree
struct TreeNode{
	int value;
	bool isEmpty;
};
void testTree(){
	TreeNode t[MaxSize];
	for(int i=0;i<MaxSize;i++){
		t[i].isEmpty=true;
	}
}
// left child of i    --2i
// right child of i   --2i+1 
// parent node of i   --floor(i/2)


////Binary Tree representation(link) || binary linked list

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


void testBiTree(){
	BiTree root = NULL;
	//insert root
	root = (BiTree)malloc(sizeof(BiTNode));
	root->data=1;
	root->lchild=NULL;
	root->rchild=NULL;
	//insert a new node
	BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
	p->data=2;
	p->lchild=NULL;
	p->rchild=NULL;
	root->lchild=p;
}

//Trifurcate linked list
typedef struct BiTNode1{
	int data;
	struct BiTNode *lchild,*rchild,*parent;
}BiTNode1,*BiTree1;





   