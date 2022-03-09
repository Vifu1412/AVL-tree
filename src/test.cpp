/*
 * test.cpp
 *
 *  Created on: 2019年7月15日
 *      Author: orang
 */
#include "AVLTree.cpp"
#include <iostream>
using std::cout;
using std::endl;
using namespace std;



int main(void)
{
	int a = 8;
	char v[9] = { 'v', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	AVLTree<int, char> x;
	//测试insert
	if(a>0){
		cout<<"请输入key-value ："<<endl;
		for (int i = 1; i <= a; ++i) {

			x.insert(std::pair<int, char>(i, v[i]));
		}
	}
	cout<<"创建完成"<<endl;
	//测试empty
	if(x.empty())
		cout<<"AVL树为空"<<endl;
	else
		cout<<"AVL树不为空"<<endl;
	//测试ascend
	cout<<"升序输出："<<endl;
	x.ascend();
	cout<<"层次遍历："<<endl;
	x.levelOrderOutput();
	//测试size
	cout<<"AVL树节点个数为："<<x.size()<<endl;
	//测试find
	cout<<"请输入查找节点的key"<<endl;
	std::pair<const int, char> *s = x.find(6);
	if(s)
	   cout <<"查找节点为："<< s->first << ' ' << s->second << endl;
	else
		cout<<"无此节点"<<endl;
	//测试erase
	cout<<"请输入删除节点的key"<<endl;
	x.erase(6);
	cout<<"节点已删除"<<endl;
	cout<<"升序输出："<<endl;
	x.ascend();
	cout<<"层次遍历："<<endl;
	x.levelOrderOutput();
	x.erase(1);
	cout << "节点已删除" << endl;
	cout << "升序输出：" << endl;
	x.ascend();
	cout << "层次遍历：" << endl;
	x.levelOrderOutput();
	x.erase(3);
	cout << "节点已删除" << endl;
	cout << "升序输出：" << endl;
	x.ascend();
	cout << "层次遍历：" << endl;
	x.levelOrderOutput();
	x.erase(2);
	cout << "节点已删除" << endl;
	cout << "升序输出：" << endl;
	x.ascend();
	cout << "层次遍历：" << endl;
	x.levelOrderOutput();
}
