/*
 * AVLTree.h
 *
 *  Created on: 2019年7月13日
 *      Author: orang
 */

#ifndef SRC_INDEXEDBINARYSEARCHTREE_H_
#define SRC_INDEXEDBINARYSEARCHTREE_H_

#include "bsTree.h"
#include "linkedBinaryTree.cpp"

//element结构定义，键值对和节点高度
template<class K,class E>
struct AVLTreeElement{
	K key;
	E value;
	int height;
};

template<class K,class E>
std::ostream& operator<<(std::ostream& out,const AVLTreeElement<K,E>& x){
	out <<x.key<<":"<<x.value<<":"<<x.height<<"|";
	return out;
}


template<class K,class E>
class AVLTree :public bsTree<K,E>,
			public linkedBinaryTree<AVLTreeElement<K,E>>{
public:
	//dictionary 的方法
	bool empty() const;
	int size() const;
	std::pair<const K,E>* find(const K& theKey) const;
	void insert(const std::pair<const K,E>& thePair);
	void erase(const K& theKey);
	//bsTree 的方法
	void ascend();

//	int height();

private:
	int max(int a,int b);
	int height(binaryTreeNode<AVLTreeElement<K,E>>*t);
	binaryTreeNode<AVLTreeElement<K,E>>* erase(binaryTreeNode<AVLTreeElement<K,E>>*t,binaryTreeNode<AVLTreeElement<K,E>>*p);
	binaryTreeNode<AVLTreeElement<K,E>>* insert(binaryTreeNode<AVLTreeElement<K,E>>*t,const std::pair<const K,E>& thePair);
	binaryTreeNode<AVLTreeElement<K,E>>* LL_Rotation(binaryTreeNode<AVLTreeElement<K,E>>*t);
	binaryTreeNode<AVLTreeElement<K,E>>* RR_Rotation(binaryTreeNode<AVLTreeElement<K,E>>*t);
	binaryTreeNode<AVLTreeElement<K,E>>* LR_Rotation(binaryTreeNode<AVLTreeElement<K,E>>*t);
	binaryTreeNode<AVLTreeElement<K,E>>* RL_Rotation(binaryTreeNode<AVLTreeElement<K,E>>*t);

};

#endif /* AVLTREE_H_ */
