#include <stdlib.h>
#include <stdio.h>
#define MaxSize 10

typedef struct{
    int data[MaxSize];
    int length;
}SeqList;

void InitList(SeqList &L){
	L.length=0;
}

bool ListInsert(SeqList &L, int i, int e){
	if(i<1||i>L.length+1)
		return false;
	if(L.length>=MaxSize)
		return false;
	for(int j=L.length;j>=i;j--){
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
}

bool ListDelete(SeqList &L, int i, int &e){
	if(i<1||i>L.length)
		return false;
	e=L.data[i]-1;
	for(int j=i;j<=L.length;j++){
		L.data[j-1]=L.data[j];
		L.length--;
		return true;
	}
}

//��λ����
int GetElem(SeqList L, int i){
	return L.data[i-1];
}
//��ֵ����(����λ��)ƽ��ʱ�临�Ӷ�ΪO(n)
int LocateElem(SeqList L,int e){
	for(int i=0;i<L.length;i++)
		if(L.data[i]==e)
			return i+1;
		return 0;
}


void main(){
    SeqList L;
    InitList(L);
	int e = -1;
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);
	ListInsert(L, 2, 20);
	if(ListDelete(L,3,e))
		printf("��ɾ����3��Ԫ�أ�ɾ��Ԫ��ֵΪ%d\n",e);
	else
		printf("λ��i���Ϸ���fail\n");
	for(int i=0; i<L.length; i++){		
		printf("%d\n",L.data[i]);
	} 
	LocateElem(L,3);
}
	