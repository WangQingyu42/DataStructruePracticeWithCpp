#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
//����˳��洢
	#define MAXLEN 255
	typedef struct{
		char ch[MAXLEN];
		int length;
	}SString;//��̬����ʵ�֣�����˳��洢��

	//���Ӵ�����sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
	bool SubString(SString &Sub,SString S,int pos,int len){
		//�Ӵ���ΧԽ��
		if (pos+len-1<S.length)
			return false;
		for(int i=pos;i<pos+len;i++){
			Sub.ch[i-pos+1]=S.ch[i];
		}
		Sub.length = len;
		return true;
	}
	//�Ƚϲ�������S>T �򷵻�>0����S=T���򷵻�ֵ=0; ��S<T,�򷵻�ֵ<0
	StrCompare(SString S, SString T) {
		for(int i=1; i<= S.length && i<= T.length;i++){
			if(S.ch[i] != T.ch[i])
				return S.ch[i] - T.ch[i];			
		}
		return S.length-T.length;
	}
	//��λ������������S�д����봮Tֵ��ͬ���Ӵ����򷵻���������S�е�һ�γ��ֵ�λ�ã�������ֵΪ0
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
	}HString; //��̬����ʵ�֣��ѷ���洢��

	//HString S;
	//S.ch = (char *)malloc(MAXLEN*sizeof(char));  ������Ҫ�ֶ�free
	//S.length = 0;


//������ʽ�洢
	typedef struct StringNode{
		char ch;  //ÿ���ڵ��һ���ַ�
		struct StringNode *next;
	}StringNode,*String;

	typedef struct StringNode1{
		char ch[4];  //ÿ���ڵ�����ַ�,�洢�ܶ����
		struct StringNode *next;
	}StringNode1,*String1;