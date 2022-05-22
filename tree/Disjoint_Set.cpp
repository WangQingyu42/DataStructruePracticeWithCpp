#define SIZE 13
int UFSets[SIZE];

//初始化并查集
void Initial(int S[]){
	for(int i=0;i<SIZE;i++)
		S[i]=-1;
}
//核心思想:尽可能让树的高度变矮

//Find,返回x所属根节点 最坏时间复杂度O(n)
int Find(int S[],int x){
	while (S[x]>=0)
		x=S[x];
	return x;
}
//Find操作的优化(压缩路径Path Compression)
//先找到根节点,再将查找路径上所有结点都挂到根节点下
int Find(int S[],int x){
	int root=x;
	while (S[root]>=0){
		root=S[root];   //循环找到根节点
	}
	while(x!=root){    //压缩路径
		int t = S[x];  //t指向x的父节点
		S[x]=root;     //x直接挂到根节点下
		x=t;
	}
	return root;
}



//Union,将两个集合合并为一个,时间复杂度O(1)
void Union(int S[],int root1,int root2){
	if(root1==root2) return;
	S[root2]=root1;
}

//Union操作的优化,小树合并到大树(Union By Rank)
//用根节点的绝对值表示数的结点总数
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