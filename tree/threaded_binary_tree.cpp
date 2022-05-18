typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;     //左右线索标志，为0表示l/rchild真的表示左右孩子
}ThreadNode,*ThreadTree;

//找中序前驱
	//辅助全局变量，用于查找结点p的前驱
	BiTNode *p;   //p指向目标结点
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

//中序遍历二叉树，一边遍历一边线索化

	ThreadNode *pre=NULL; //全局变量pre,指向当前访问结点的前驱
	void CreateInThread(ThreadTree T){
		pre=NULL;
		if(T!=NULL){
			InThread(T);
			if (pre->rchild==NULL)
				pre->rtag=1;   //处理遍历的最后一个节点
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

//先序
//当ltag==0时才能对左子树进行先序线索化
	void InThread(ThreadTree T){
		if (T!=NULL){
			visit(T);
			if(T->ltag==0) //lchild不是前驱线索
				PreThread(T->lchild);  //和InThread一致
			findPre(T->rchild);
		}
	}
//后序和中序类似


//中序线索二叉树找中序后继
	//找到以P为根的子树中，第一个被中序遍历的结点
	ThreadNode *FirstNode(ThreadNode *p){
		//循环找到最左下结点（不一定是叶子结点）
		while(p->ltag==0)
			p=p->lchild;
		return p;
	}
	//在中序线索二叉树中找到结点p的后继结点
	ThreadNode *Nextnode(ThreadNode *p){
		//右子树中最左下结点
		if(p->ltag == 0)
			return FirstNode(p->rchild);
		else
			return p->rchild;

	}
	//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
	//空间复杂度O(1)
	void Inorder(ThreadNode *T){
		for(TreadNode *p=FirstNode(T);P!=NULL;p=NextNode(p)){
			visit(p);
		}
	}

//中序线索二叉树找中序前驱
	ThreadNode *LastNode(ThreadNode *p){
		while(p->rtag==0)
			p=p->rchild;
		return p;
	}

	ThreadNode *Prenode(ThreadNode *p){
		//左子树中最右下结点
		if(p->ltag == 0)
			return PreNode(p->lchild);
		else
			return p->lchild;
	}
	void RevInorder(ThreadNode *T){
		for(ThreadNode *p=Lastnode(T);p!=NULL;p=PreNode(p))
			visit(p);
	}

