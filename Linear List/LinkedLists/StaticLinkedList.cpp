<<<<<<< HEAD
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#define MaxSize 10
//静态链表：用数组的方式实现的链表
//优点：增删操作不需要移动大量的元素
//缺点：不能随机存取，只能从头结点开始依次往后查，容量固定不可变

struct Node{
	int data; 
	int next;
};
typedef struct{
	int data;
	int next;       //下一个元素的数组下标
}SLinkList[MaxSize];


void main(){
	struct Node x;
	printf("sizeX=%d\n",sizeof(x));

	struct Node a[MaxSize];
	printf("sizeA=%d\n",sizeof(a));

	SLinkList b;
	printf("sizeB=%d\n",sizeof(b));
=======
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#define MaxSize 10
//静态链表：用数组的方式实现的链表
//优点：增删操作不需要移动大量的元素
//缺点：不能随机存取，只能从头结点开始依次往后查，容量固定不可变

struct Node{
	int data; 
	int next;
};
typedef struct{
	int data;
	int next;       //下一个元素的数组下标
}SLinkList[MaxSize];


void main(){
	struct Node x;
	printf("sizeX=%d\n",sizeof(x));

	struct Node a[MaxSize];
	printf("sizeA=%d\n",sizeof(a));

	SLinkList b;
	printf("sizeB=%d\n",sizeof(b));
>>>>>>> 38075cfc48c960f57341d1c4bf78fbaa4072812b
}