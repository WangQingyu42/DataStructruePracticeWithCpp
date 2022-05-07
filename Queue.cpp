#include<stddef.h>
#include<stdlib.h>
#include<stdio.h> 
//������ֻ������һ�˽��в��룬����һ��ɾ�������Ա�
//�Ƚ��ȳ�First In First Out (FIFO)

//��˳��洢ʵ�ֶ���
# define MaxSize 10

//�������˷Ѵ洢�ռ�,�����size
//��ʼ��ʱrear = front =0; size=0
//����ɹ�size++ ɾ���ɹ�size--
//��������size==MaxSize,�ӿ�size==0
//���� ����tag 
//ÿ��ɾ���ɹ�ʱ��tag=0 ÿ�β�������ɹ�ʱ��tag=1
//ֻ��ɾ�������ſ��ܵ��¶ӿ� front==rear && tag==1
//ֻ�в�������ſ��ܵ��¶���

typedef struct{
	int data[MaxSize];
	int front,rear;  //��ͷָ��Ͷ�βָ��
	// int size;  //���е�ǰ����
	// int tag;    //������е��ǲ���/ɾ������ 
} SqQueue;

void InitSqQueue(SqQueue &Q){
	Q.rear=Q.front=0;
}
bool SqEmpty(SqQueue Q){
	if(Q.rear=Q.front)
		return true;
	else
		return false;
}
//��ӣ�ѭ�����У�
bool SqEnQueue(SqQueue &Q,int x){
	if((Q.rear+1)%MaxSize==Q.front) //�ж϶��� ,����һ���洢��Ԫ
		return false;
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize; //��βָ���1ȡģ��������ռ����߼��ϱ���ˡ���״��
}
//����(ɾ��һ����ͷԪ�أ�����x����)
bool SqDeEnQueue(SqQueue &Q,int &x){
	if(Q.front==Q.rear)
		return false;
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true;
}
//��ö�ͷԪ�ص�ֵ����x����
bool GetHead(SqQueue Q,int &x){
	if(Q.front==Q.rear)
		return false;
	x=Q.data[Q.front];
	return true;
}
//����Ԫ�ظ�����(rear+MaxSize-front)% MaxSize




void testSqQueue(){
	SqQueue Q;
}

