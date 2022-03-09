/*
 * dictionary.h
 *
 *  Created on: 2017年3月28日
 *      Author: lsn
 */

#ifndef DICTIONARY_H_   //判断某个宏是否未被定义，若未定义则执行下面语句
//1、防止头文件的重复包含和编译；
//2、便于程序的调试和移植；
#define DICTIONARY_H_
#include <iostream>
#include <functional>
#include <utility> 		//调用pair类型
#include <iterator>

template<typename K, typename E>
class dictionary {
public:
	virtual ~dictionary() {};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual std::pair<const K, E>* find(const K&) const = 0;  //返回匹配数对的指针
	virtual void erase(const K&) = 0;
	virtual void insert(const std::pair<const K,E>&) = 0;
};

#endif /* DICTIONARY_H_ */

