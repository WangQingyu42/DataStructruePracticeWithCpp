typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;     //����������־��Ϊ0��ʾl/rchild��ı�ʾ���Һ���
}ThreadNode,*ThreadTree;

//������ǰ��
	//����ȫ�ֱ��������ڲ��ҽ��p��ǰ��
	BiTNode *p;   //pָ��Ŀ����
	BiTNode *pre=NULL;
	BiTNode *final=NULL;

	void findPre(BiTree T){
		if (T!=NULL){
			findPre(T->lchild);
			visit(T);
			findPre(T->rchild);
		}
	}

	void visit(BiTNode *q){
		if(q==p)
			final = pre;
		else
			pre=q;		
	}

//���������������һ�߱���һ��������

	ThreadNode *pre=NULL; //ȫ�ֱ���pre,ָ��ǰ���ʽ���ǰ��
	void CreateInThread(ThreadTree T){
		pre=NULL;
		if(T!=NULL){
			InThread(T);
			if (pre->rchild==NULL)
				pre->rtag=1;   //������������һ���ڵ�
		}
	}

	void InThread(ThreadTree T){
		if (T!=NULL){
			findPre(T->lchild);
			visit(T);
			findPre(T->rchild);
		}
	}
	void visit(ThreadNode *q){
		if(q->lchild==NULL){
			q->lchild=pre;
			q->ltag=1;
		}
		if(pre!=NULL && pre->rchild==NULL){
			pre->rchild=q;
			pre->rtag=1;
		}
		pre=q;
	}

//����
//��ltag==0ʱ���ܶ���������������������
	void InThread(ThreadTree T){
		if (T!=NULL){
			visit(T);
			if(T->ltag==0) //lchild����ǰ������
				PreThread(T->lchild);  //��InThreadһ��
			findPre(T->rchild);
		}
	}
//�������������


//����������������������
	//�ҵ���PΪ���������У���һ������������Ľ��
	ThreadNode *FirstNode(ThreadNode *p){
		//ѭ���ҵ������½�㣨��һ����Ҷ�ӽ�㣩
		while(p->ltag==0)
			p=p->lchild;
		return p;
	}
	//�������������������ҵ����p�ĺ�̽��
	ThreadNode *Nextnode(ThreadNode *p){
		//�������������½��
		if(p->ltag == 0)
			return FirstNode(p->rchild);
		else
			return p->rchild;

	}
	//�������������������������������������ʵ�ֵķǵݹ��㷨��
	//�ռ临�Ӷ�O(1)
	void Inorder(ThreadNode *T){
		for(TreadNode *p=FirstNode(T);P!=NULL;p=NextNode(p)){
			visit(p);
		}
	}

//��������������������ǰ��
	ThreadNode *LastNode(ThreadNode *p){
		while(p->rtag==0)
			p=p->rchild;
		return p;
	}

	ThreadNode *Prenode(ThreadNode *p){
		//�������������½��
		if(p->ltag == 0)
			return PreNode(p->lchild);
		else
			return p->lchild;
	}
	void RevInorder(ThreadNode *T){
		for(ThreadNode *p=Lastnode(T);p!=NULL;p=PreNode(p))
			visit(p);
	}

