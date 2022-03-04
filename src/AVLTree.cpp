/*
 * AVLTree.cpp
 *
 *  Created on: 2019年7月13日
 *      Author: orang
 */

#include "AVLTree.h"



template<class K,class E>
bool AVLTree<K,E>::empty() const{
	return (0 == this->treeSize);
}

template<class K,class E>
int AVLTree<K,E>::size() const{
	return this->treeSize;
}

template<class K,class E>
void AVLTree<K,E>::ascend(){
	this->inOrderOutput();
}

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

template<class K,class E>
int AVLTree<K,E>::max(int a,int b){
	return a>b ? a : b;
}



template<class K,class E>
int AVLTree<K,E>::height(binaryTreeNode<AVLTreeElement<K,E>> *t){
	if(t)
		return t->element.height;
	return 0;
}

template<class K,class E>
binaryTreeNode<AVLTreeElement<K,E>>* AVLTree<K,E>::LL_Rotation(binaryTreeNode<AVLTreeElement<K,E>> *t){
	binaryTreeNode<AVLTreeElement<K,E>> *p = t->leftChild;
	t->leftChild = p->rightChild;
	p->rightChild = t;

	t->element.height = max(height(t->leftChild),height(t->rightChild)) + 1;
	p->element.height = max(height(p->leftChild),t->element.height) + 1;

	return p;
}
template<class K,class E>
binaryTreeNode<AVLTreeElement<K,E>>* AVLTree<K,E>::RR_Rotation(binaryTreeNode<AVLTreeElement<K,E>> *t){
	binaryTreeNode<AVLTreeElement<K,E>> *p = t->rightChild;
	t->rightChild = p->leftChild;
	p->leftChild = t;

	t->element.height = max(height(t->leftChild),height(t->rightChild)) + 1;
	p->element.height = max(height(p->leftChild),t->element.height) + 1;

	return p;
}

template<class K,class E>
binaryTreeNode<AVLTreeElement<K,E>>* AVLTree<K,E>::LR_Rotation(binaryTreeNode<AVLTreeElement<K,E>> *t){
	t->leftChild = RR_Rotation(t->leftChild);
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
		newElement.height = 0;
		t = new binaryTreeNode<AVLTreeElement<K,E>> (newElement);
		this->treeSize++;
	}
	else if(theDate.first < t->element.key){//插入到t的左子树
		t->leftChild = insert(t->leftChild,theDate);
		if(height(t->leftChild) - height(t->rightChild) == 2){
			if(theDate.first < t->leftChild->element.key)
				t = LL_Rotation(t);
			else
				t = LR_Rotation(t);
		}
	}
	else if(theDate.first > t->element.key){//插入到t的右子树
		t->rightChild = insert(t->rightChild,theDate);
		if(height(t->rightChild) - height(t->leftChild) == 2){
			if(theDate.first > t->rightChild->element.key)
				t = RR_Rotation(t);
			else
				t = RL_Rotation(t);
		}
	}
	else{//该key-value已有，更新value
		t->element.value = theDate.second;

	}

	t->element.height = max( height(t->leftChild), height(t->rightChild)) + 1;

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
		if(height(t->rightChild) - height(t->leftChild) == 2){
			binaryTreeNode<AVLTreeElement<K,E>>* tr = t->rightChild;
			if(height(tr->leftChild) > height(tr->rightChild))
				t = RL_Rotation(t);
			else
				t = RR_Rotation(t);
		}

	}
	else if(p->element.key > t->element.key){//待删除节点在t的右子树中
		t->rightChild = erase(t->rightChild,p);
		if(height(t->leftChild) - height(t->rightChild) == 2){
			binaryTreeNode<AVLTreeElement<K,E>>* tl = t->leftChild;
			if(height(tl->rightChild) > height(tl->leftChild))
				t = LR_Rotation(t);
			else
				t = LL_Rotation(t);
		}
	}
	else{//t为待删除节点
		if(t->leftChild && t->rightChild){//t左右孩子非空
			if(height(t->leftChild) > height(t->rightChild)){//t左子树比右子树高
				binaryTreeNode<AVLTreeElement<K,E>>* max = t->leftChild;
				while(max->rightChild)//找出t左子树的最大节点
					max = max->rightChild;
				t->element.key = max->element.key;//将t左子树最大节点赋给根节点

				t->leftChild = erase(t->leftChild,max);//删除t左子树的最大节点
			}
			else{
				binaryTreeNode<AVLTreeElement<K,E>>* min = t->rightChild;
				while(min->leftChild)//找出t右子树最大节点
					min = min->leftChild;
				t->element.key = min->element.key;

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



