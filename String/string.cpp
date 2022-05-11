#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
//串的顺序存储
	#define MAXLEN 255
	typedef struct{
		char ch[MAXLEN];
		int length;
	}SString;//静态数组实现（定长顺序存储）

	//求子串，用sub返回串S的第pos个字符起长度为len的子串
	bool SubString(SString &Sub,SString S,int pos,int len){
		//子串范围越界
		if (pos+len-1<S.length)
			return false;
		for(int i=pos;i<pos+len;i++){
			Sub.ch[i-pos+1]=S.ch[i];
		}
		Sub.length = len;
		return true;
	}
	//比较操作，若S>T 则返回>0；若S=T，则返回值=0; 若S<T,则返回值<0
	StrCompare(SString S, SString T) {
		for(int i=1; i<= S.length && i<= T.length;i++){
			if(S.ch[i] != T.ch[i])
				return S.ch[i] - T.ch[i];			
		}
		return S.length-T.length;
	}
	//定位操作，若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置；否则函数值为0
	Index(SString S,SString T){
		int i=1,n=S.length,m=T.length;
		SString Sub;
		while(i<n-m+1){
			SubString(Sub,S,i,m);
			if(StrCompare(Sub,S) !=0)
				++i;
			else return i;
		}
		return 0;
	}


	typedef struct{
		char *ch;
		int length;
	}HString; //动态数组实现（堆分配存储）

	//HString S;
	//S.ch = (char *)malloc(MAXLEN*sizeof(char));  用完需要手动free
	//S.length = 0;


//串的链式存储
	typedef struct StringNode{
		char ch;  //每个节点存一个字符
		struct StringNode *next;
	}StringNode,*String;

	typedef struct StringNode1{
		char ch[4];  //每个节点存多个字符,存储密度提高
		struct StringNode *next;
	}StringNode1,*String1;