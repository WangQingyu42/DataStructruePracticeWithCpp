#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#define MAXLEN 255
//最坏时间复杂度=O(m+n)
typedef struct{
	char ch[MAXLEN];
	int length;
}SString;

int Index_KMP(SString S,SString T,int next[]){
	int i=1,j=1;
	while(i<=S.length && j<=T.length){
		if(j=0 || S.ch[i] == T.ch[j]){
			++i;
			++j;    //继续比较后继字母
		}else{
			j=next[j];  //模式串向右移动,匹配失败时指针i不回溯
		}
		if(j>T.length)
			return i-T.length;  //匹配成功
		else
			return 0;

	}

}




