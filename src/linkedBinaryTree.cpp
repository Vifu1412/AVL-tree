/*
 * linkedBinaryTree.cpp
 *
 *  Created on: 2017年4月8日
 *      Author: lsn
 */
#ifndef SRC_LINKEDBINARYTREE_CPP_
#define SRC_LINKEDBINARYTREE_CPP_

#include "linkedBinaryTree.h"



template<class E>
void linkedBinaryTree<E>::output(binaryTreeNode<E> *t){
    std::cout << t->element << ':';
}



template<class E>
void linkedBinaryTree<E>::preOrder(binaryTreeNode<E> *t){
   if (t){//t!=NULL
      visit(t);
      preOrder(t->leftChild);
      preOrder(t->rightChild);
   }
}


template<class E>
void linkedBinaryTree<E>::inOrder(binaryTreeNode<E> *t){
   if (t){//t!=NULL
      inOrder(t->leftChild);
      visit(t);
      inOrder(t->rightChild);
   }
}

template<class E>
void linkedBinaryTree<E>::postOrder(binaryTreeNode<E> *t){
   if (t){//t!=NULL
      postOrder(t->leftChild);
      postOrder(t->rightChild);
      visit(t);
   }
}

template <class E>
void linkedBinaryTree<E>::levelOrder(binaryTreeNode<E> *t){
   if(!t) return;
   std::queue<binaryTreeNode<E>*> q;
   q.push(t);
   while (!q.empty()){
	   t = q.front();
		visit(t);
	   q.pop();

		//将t的左右子树放入队列
      if (t->leftChild != NULL)
         q.push(t->leftChild);
      if (t->rightChild != NULL)
         q.push(t->rightChild);
   }
}
//template<class E>
//binaryTreeNode<E> * linkedBinaryTree<E>::copy(binaryTreeNode<E> *t){
//	if(!t) return NULL;
//	binaryTreeNode<E> * left,*right;
//	left = copy(t->leftChild);
//	right = copy(t->rightChild);
//	return new binaryTreeNode<E>(t->element, left,right);
//}

template<class E>
void linkedBinaryTree<E>::deleteNodes(binaryTreeNode<E> *t){
	if(!t) return;
	deleteNodes(t->leftChild);
	deleteNodes(t->rightChild);
	delete t;
}

template<class E>
linkedBinaryTree<E>& linkedBinaryTree<E>::operator=(const linkedBinaryTree<E> & rightHand){
	if(this == & rightHand) return *this;//自己赋值到自己，但是现在的编译器对自己赋值给自己会提示错误
	deleteNodes(this->root);
	root = copy(rightHand.root);
	treeSize = rightHand.treeSize;//
	return *this;
}

//template<class E>
//void linkedBinaryTree<E>::makeTree(const E& element,
//           linkedBinaryTree<E>& left, linkedBinaryTree<E>& right)
//{//左右子树与新元素合成新的树，左右子树必须是不同的树
//   root = new binaryTreeNode<E> (element, left.root, right.root);
//   treeSize = left.treeSize + right.treeSize + 1;
//
//   // 拒绝左树和右树的访问
//   left.root = right.root = NULL;
//   left.treeSize = right.treeSize = 0;
//}

//template<class E>
//int linkedBinaryTree<E> ::getHeight(binaryTreeNode<E>*t){
//
//	if(t==NULL){
//		return 0;
//	}
//	int leftHeight = getHeight(t->leftChild)+1;
//	int rightHeight = getHeight(t->rightChild)+1;
//	return leftHeight<rightHeight?rightHeight:leftHeight;
//}
//template<class E>
//bool linkedBinaryTree<E>::isHBLT(){
//	return isHBLT(this->root);
//}
//
//template<class E>
//bool linkedBinaryTree<E>::isHBLT(binaryTreeNode<E> *t){
//	if(!t){
//		return true;
//	}
//	else if(t->leftChild==NULL&&t->rightChild==NULL){
//		return true;
//	}
//	else if(getHeight(t->leftChild)>=getHeight(t->rightChild)){
//		return isHBLT(t->leftChild)&&isHBLT(t->rightChild);
//	}
//	else
//		return false;
//
//
//}


//注意模版静态类初始化的语法


template<class E>
void (*linkedBinaryTree<E>::visit)(binaryTreeNode<E>*)=0;



#endif
