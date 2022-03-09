/*
 * binaryTree.h
 *
 *  Created on: 2017年4月8日
 *      Author: lsn
 */

#ifndef SRC_BINARYTREE_H_
#define SRC_BINARYTREE_H_
#include <iostream>
template <class T>
//节点结构定义
struct binaryTreeNode{
	//数据成员
	T element;
	binaryTreeNode<T> *leftChild,   // 左子树
			*rightChild;  // 右子树
	binaryTreeNode() :
			element(T()) {
		leftChild = rightChild = NULL;
	}  //构造函数
	//两个复制构造函数
   binaryTreeNode(const T& theElement):element(theElement){
      leftChild = rightChild = NULL;
   }
   binaryTreeNode(const T& theElement,binaryTreeNode *theLeftChild,binaryTreeNode *theRightChild)
                  :element(theElement){
      leftChild = theLeftChild;
      rightChild = theRightChild;
   }
};


template<class T>
class binaryTree{
   public:
      virtual ~binaryTree() {}
      virtual bool empty() const = 0;
      virtual int size() const = 0;
      virtual void preOrder(void (*) (T *)) = 0;
	// void (*) (T *)是一种函数类型，这种函数的返回值类型是void，参数类型是T*
      virtual void inOrder(void (*) (T *)) = 0;
      virtual void postOrder(void (*) (T *)) = 0;
      virtual void levelOrder(void (*) (T *)) = 0;
};

#endif /* SRC_BINARYTREE_H_ */
