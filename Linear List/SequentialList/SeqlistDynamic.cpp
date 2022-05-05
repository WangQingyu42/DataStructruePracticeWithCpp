#include <stdlib.h>
#include <stdio.h>
#define InitSize 10
typedef struct{
    int *data;
    int MaxSize;
    int length;
}SeqList;
void InitList(SeqList &L){
    L.data = (int*)malloc(InitSize*sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}
void IncreaseSize(SeqList &L, int len){
    int *p = L.data;
    L.data=(int *)malloc(InitSize*sizeof(int));
    for(int i=0; i<L.length; i++){
        L.data[i]=p[i];
    }
    L.MaxSize=L.MaxSize+len;
    free (p);
}

//按位查找
int GetElem(SeqList L,int i){
	return L.data[i-1];   //随机存取
}
int main(){
    SeqList L;
    InitList(L);
   // 插入几个数据
	for(int i=0; i<L.MaxSize; i++){
		L.data[i]=i;
		printf("%d\n",L.data[i]);
	}
	IncreaseSize(L,5);
	for(int j=0; j<L.MaxSize; j++){
		L.data[j]=j;
		printf("%d\n",L.data[j]);
	}
    return 0;
}
