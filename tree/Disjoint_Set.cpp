#define SIZE 13
int UFSets[SIZE];

//��ʼ�����鼯
void Initial(int S[]){
	for(int i=0;i<SIZE;i++)
		S[i]=-1;
}
//����˼��:�����������ĸ߶ȱ䰫

//Find,����x�������ڵ� �ʱ�临�Ӷ�O(n)
int Find(int S[],int x){
	while (S[x]>=0)
		x=S[x];
	return x;
}
//Find�������Ż�(ѹ��·��Path Compression)
//���ҵ����ڵ�,�ٽ�����·�������н�㶼�ҵ����ڵ���
int Find(int S[],int x){
	int root=x;
	while (S[root]>=0){
		root=S[root];   //ѭ���ҵ����ڵ�
	}
	while(x!=root){    //ѹ��·��
		int t = S[x];  //tָ��x�ĸ��ڵ�
		S[x]=root;     //xֱ�ӹҵ����ڵ���
		x=t;
	}
	return root;
}



//Union,���������Ϻϲ�Ϊһ��,ʱ�临�Ӷ�O(1)
void Union(int S[],int root1,int root2){
	if(root1==root2) return;
	S[root2]=root1;
}

//Union�������Ż�,С���ϲ�������(Union By Rank)
//�ø��ڵ�ľ���ֵ��ʾ���Ľ������
void Union(int S[],int root1,int root2){
	if(root1==root2) return;
	if(S[roo1]<S[root2]){
		S[root1] += S[root2];
		S[root2]=root1;
	}else{
		S[root2] += S[root1];
		S[root1]=root2;
	}
	
}