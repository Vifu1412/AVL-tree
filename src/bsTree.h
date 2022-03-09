/*
 * bsTree.h
 *
 *  Created on: 2017年4月8日
 *      Author: lsn
 */

#ifndef SRC_BSTREE_H_
#define SRC_BSTREE_H_
#include "dictionary.h"
template<class K, class E>
class bsTree: public dictionary<K, E> //继承抽象类dictionary
{
   public:
      virtual void ascend() = 0;
	// 按key的升序输出
      virtual ~bsTree(){};
};
#endif /* SRC_BSTREE_H_ */
