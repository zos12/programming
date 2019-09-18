/*
二叉树用链表定义，因为每个结点有两个出边，指针域变成了两个，
分别指向左子树根结点地址和右子树根结点地址。
何时需要加引用，如果函数中需要新建结点，即对二叉树的结构做出修改，就需要加引用，如果
只是修改当前已有结点的内容，或仅仅是遍历树，就不用加引用。
必须将新结点的左右指针域为NULL，表示这个新结点暂时没有左右子树
*/

#include<iostream>
using namespace std;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
/*
	创建结点，v为权值
node* newNode(int v){
	node* Node = new node;
	Node -> data = v;
	Node -> lchild = Node -> rchild = NULL;
	return Node;
}*/

/*
	二叉树结点查找、修改
	主要找到递归式和递归边界，递归边界是当前结点为空时到达死胡同。
void search(node* root, int x, int newdata){
	if(root == NULL){
		return;
	}
	if(root -> data == x){
		root -> data = newdata;
	}
	search(root -> lchild, x, newdata); 
	search(root -> rchild, x, newdata);
}*/

/*
	root用了引用，即在函数中修改root会直接修改原变量。 search函数修改的是root指向的内容，
	而不是root本身。

void insert(node* &root, int x){
	if(root == NULL){
		root = newNode(x);
		return;
	}
	if(x应该插入左子树){
		insert(root -> lchild, x);
	}else{
		insert(root -> rchild, x);
	}
}*/

/*
	创建二叉树
node* Create(int data[], int n){
	node* root = NULL;  //空结点地址为NULL，结点不存在
	for(int i = 0; i < n; i++){
		insert(root, data[i]);
	}
	return root;
}*/

/*
	先序遍历，先根结点->左子树->右子树,递归边界为根结点为空值
void preorder(node* root){
	if(root == NULL){
		return;
	}
	printf("%d",root -> data);
    preorder(root -> lchild);
    preorder(root -> rchild);
}*/

/*
	中序遍历
void inorder(node* root){
	if(root == NULL){
		return;
	}
	inorder(root -> lchild);
	printf("%d\n", root -> data);
	inorder(root -> rchild);
}*/

/*
	后序遍历
void postorder(node* root){
	if(root == NULL){
		return;
	}
	postorder(root -> lchild);
	postorder(root -> rchild);
	printf("%d\n", root -> data);
}*/

/*
	层次遍历，BFS广度优先搜索
	1、将根结点入队q
	2、取出队首元素
	3、访问队首元素，有左孩子让左孩子入队
	4、有右孩子让右孩子入队
	5、返回2，直到队列为空
	入队的是结点地址
void LayerOrder(node* root){
	queue<node*> q;
	root -> layer = 1;
	q.push(root);
	while(!q.empty()){
		node* now = q.front();
		q.pop();
		printf("%d ", now -> data);
		if(now -> lchild != NULL) {
			now -> lchild -> layer = now -> layer + 1;
			q.push(now -> lchild);
		}
		if(now -> rchild != NULL) {
			now -> rchild -> layer = now -> layer + 1;
			q.push(now -> rchild);
		}
	}

	如果需要计算结点所处的层次
	struct node{
		int layer;
	};

}*/

已知先序序列和中序序列，重构二叉树
先序序列  pre(preL)  pre(preL+1) ... pre(preL+numLeft) pre(preL+numLeft+1) ... pre(preR)
中序序列  in(inL)    in(inL+1)  ...  in(K) in(k+1) ... in(inR)
pre(preL)为根结点 in(k)为root
numLeft = k-inL  //左子树结点数
左子树的先序序列区间[preL+1,preL+numLeft] 中序序列区间[inL,k-1]
右子树的先序序列区间[preL+numLeft+1,preR] 中序序列区间[k+1,inR]
递归边界即先序序列长度小于等于0 preL > preR
node* create(int preL, int preR, int inL, int inR){
	if(preL > preR){
		return NULL;
	}
	node* root = new node; //新建根结点，存放当前二叉树的根结点
	root -> data = pre[preL];
	int k;
	for(k = inL; k <= inR; k++){
		if(in[k] == pre[preL]){
			break;
		}
	}
	int numLeft = k-inL;
	root -> lchild = create(preL+1,preL+numLeft,inL,k-1);
	root -> rchild = create(preL+numLeft+1,preR,k+1,inR);
	return root;
}