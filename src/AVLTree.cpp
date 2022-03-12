/*
 * AVLTree.cpp
 *
 *  Created on: 2019年7月13日
 *      Author: orang
 */

#include "AVLTree.h"


//判断是否为空树
template<class K,class E>
bool AVLTree<K,E>::empty() const{
	return (0 == this->treeSize);
}
//返回树节点个数
template<class K,class E>
int AVLTree<K,E>::size() const{
	return this->treeSize;
}
// 按key的升序输出
template<class K,class E>
void AVLTree<K,E>::ascend(){
	this->inOrderOutput();
}

//查找函数，返回key为theKey的键值对
template<class K,class E>
std::pair<const K,E>* AVLTree<K,E>::find(const K& theKey) const{
	binaryTreeNode<AVLTreeElement<K,E>> *p = this->root;
	while(p){
		if(theKey == p->element.key){
			return new std::pair<const K,E>(p->element.key,p->element.value);
		}
		if(theKey < p->element.key)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	return NULL;
}
//比较两值大小，用于辅助计算节点高度
template<class K,class E>
int AVLTree<K,E>::max(int a,int b){
	return a>b ? a : b;
}
//获取节点高度函数
template<class K, class E>
int AVLTree<K, E>::getHeight(binaryTreeNode<AVLTreeElement<K, E>> *t) {

	if (t == NULL) {
		return 0;
	}
	int leftHeight = getHeight(t->leftChild) + 1;
	int rightHeight = getHeight(t->rightChild) + 1;
	return leftHeight < rightHeight ? rightHeight : leftHeight;
}
//LL型调整函数
template<class K,class E>
binaryTreeNode<AVLTreeElement<K,E>>* AVLTree<K,E>::LL_Rotation(binaryTreeNode<AVLTreeElement<K,E>> *t){
	binaryTreeNode<AVLTreeElement<K, E>> *p = t->leftChild;  //设失衡节点为T左孩子为L
	t->leftChild = p->rightChild;							//L右孩子改为T左孩子
	p->rightChild = t;										//T改为L右孩子

	return p;
}
template<class K,class E>
binaryTreeNode<AVLTreeElement<K,E>>* AVLTree<K,E>::RR_Rotation(binaryTreeNode<AVLTreeElement<K,E>> *t){
	binaryTreeNode<AVLTreeElement<K,E>> *p = t->rightChild;
	t->rightChild = p->leftChild;
	p->leftChild = t;

	return p;
}

template<class K,class E>
binaryTreeNode<AVLTreeElement<K,E>>* AVLTree<K,E>::LR_Rotation(binaryTreeNode<AVLTreeElement<K,E>> *t){
	t->leftChild = RR_Rotation(t->leftChild); //先对失衡节点左孩子进行RR旋转，再对失衡节点进行LL旋转
	return LL_Rotation(t);
}

template<class K,class E>
binaryTreeNode<AVLTreeElement<K,E>>* AVLTree<K,E>::RL_Rotation(binaryTreeNode<AVLTreeElement<K,E>> *t){
	t->rightChild = LL_Rotation(t->rightChild);
	return RR_Rotation(t);
}

template<class K,class E>
void AVLTree<K,E>::insert(const std::pair<const K,E>& theDate){
	this->root = insert(this->root,theDate);

}


template<class K,class E>
binaryTreeNode<AVLTreeElement<K,E>>* AVLTree<K,E>::insert(binaryTreeNode<AVLTreeElement<K,E>>*t,const std::pair<const K,E>& theDate){
	if(t == NULL){//插入前是空树，新建一个节点
		AVLTreeElement<K,E> newElement;
		newElement.key = theDate.first;
		newElement.value = theDate.second;
		t = new binaryTreeNode<AVLTreeElement<K,E>> (newElement);
		this->treeSize++;
	}
	else if (theDate.first < t->element.key) { //插入到t的左子树
		t->leftChild = insert(t->leftChild,theDate);
		if (getHeight(t->leftChild) - getHeight(t->rightChild) == 2) { //设最先失衡结点为T，失衡方向结点为t，新插入结点为n，
			if (theDate.first < t->leftChild->element.key)//若T与t大小关系和t与n大小关系一致，则为失衡方向单旋转，否则为双旋转。
				t = LL_Rotation(t);
			else
				t = LR_Rotation(t);
		}
	}
	else if(theDate.first > t->element.key){//插入到t的右子树
		t->rightChild = insert(t->rightChild,theDate);
		if (getHeight(t->rightChild) - getHeight(t->leftChild) == 2) {
			if(theDate.first > t->rightChild->element.key)
				t = RR_Rotation(t);
			else
				t = RL_Rotation(t);
		}
	}
	else { //该key-value已有，更新value
		t->element.value = theDate.second;

	}

	return t;
}

template<class K,class E>
void AVLTree<K,E>::erase(const K& theKey){
	if(!this->root) return;//空树，不作处理

	binaryTreeNode<AVLTreeElement<K,E>>* p = this->root;
	while (p){//找到待删除节点
			if(theKey == p->element.key) break;
			if(theKey < p->element.key)
				p = p ->leftChild;
			else
				p = p->rightChild;
	}
	if(p) this->root = erase(this->root,p);//待删除节点存在，删除
}

template<class K,class E>
binaryTreeNode<AVLTreeElement<K,E>>* AVLTree<K,E>::erase(binaryTreeNode<AVLTreeElement<K,E>>*t,binaryTreeNode<AVLTreeElement<K,E>>*p){
	if(!t)//根为空，直接返回NULL
		return NULL;
	if(p->element.key < t->element.key){//待删除节点在t的左子树中
		t->leftChild = erase(t->leftChild,p);
		if (getHeight(t->rightChild) - getHeight(t->leftChild) == 2) {
			binaryTreeNode<AVLTreeElement<K,E>>* tr = t->rightChild;
			if (getHeight(tr->leftChild) > getHeight(tr->rightChild))
				t = RL_Rotation(t);
			else
				t = RR_Rotation(t);
		}

	}
	else if(p->element.key > t->element.key){//待删除节点在t的右子树中
		t->rightChild = erase(t->rightChild,p);
		if (getHeight(t->leftChild) - getHeight(t->rightChild) == 2) {
			binaryTreeNode<AVLTreeElement<K,E>>* tl = t->leftChild;
			if (getHeight(tl->rightChild) > getHeight(tl->leftChild))
				t = LR_Rotation(t);
			else
				t = LL_Rotation(t);
		}
	}
	else{//t为待删除节点
		if(t->leftChild && t->rightChild){//t左右孩子非空
			if (getHeight(t->leftChild) > getHeight(t->rightChild)) { //t左子树比右子树高
				binaryTreeNode<AVLTreeElement<K,E>>* max = t->leftChild;
				while(max->rightChild)//找出t左子树的最大节点
					max = max->rightChild;
				t->element = max->element; //将t左子树最大节点赋给根节点

				t->leftChild = erase(t->leftChild,max);//删除t左子树的最大节点
			}
			else{
				binaryTreeNode<AVLTreeElement<K,E>>* min = t->rightChild;
				while (min->leftChild) //找出t右子树最小节点
					min = min->leftChild;
				t->element = min->element;

				t->rightChild = erase(t->rightChild,min);
			}
		}
		else{//t左右孩子至少有一个为空
			binaryTreeNode<AVLTreeElement<K,E>>* tmp = t;
			t = (t->leftChild) ? t->leftChild : t->rightChild;
			delete tmp;
		}
	}

	return t;
}



