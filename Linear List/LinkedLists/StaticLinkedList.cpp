<<<<<<< HEAD
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#define MaxSize 10
//��̬����������ķ�ʽʵ�ֵ�����
//�ŵ㣺��ɾ��������Ҫ�ƶ�������Ԫ��
//ȱ�㣺���������ȡ��ֻ�ܴ�ͷ��㿪ʼ��������飬�����̶����ɱ�

struct Node{
	int data; 
	int next;
};
typedef struct{
	int data;
	int next;       //��һ��Ԫ�ص������±�
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
//��̬����������ķ�ʽʵ�ֵ�����
//�ŵ㣺��ɾ��������Ҫ�ƶ�������Ԫ��
//ȱ�㣺���������ȡ��ֻ�ܴ�ͷ��㿪ʼ��������飬�����̶����ɱ�

struct Node{
	int data; 
	int next;
};
typedef struct{
	int data;
	int next;       //��һ��Ԫ�ص������±�
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