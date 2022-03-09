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

	AVLTree<int, char> x;
	//RR
	cout << "测试RR旋转，依次插入：10:a|30:b|50:c" << endl;
	x.insert(std::pair<int, char>(10, 'a'));
	x.insert(std::pair<int, char>(30, 'b'));
	x.insert(std::pair<int, char>(50, 'c'));
	cout << "升序输出：" << endl;
	x.ascend();
	cout << "先根遍历：" << endl;
	x.preOrderOutput();
	cout << "中根遍历：" << endl;
	x.inOrderOutput();
	//LL
	cout << "测试LL旋转,依次插入：5:d|3:e" << endl;
	x.insert(std::pair<int, char>(5, 'd'));
	x.insert(std::pair<int, char>(3, 'e'));
	cout<<"升序输出："<<endl;
	x.ascend();
	cout << "先根遍历：" << endl;
	x.preOrderOutput();
	cout << "中根遍历：" << endl;
	x.inOrderOutput();
	//LR
	cout << "测试LR旋转,插入：20:f" << endl;
	x.insert(std::pair<int, char>(20, 'f'));
	cout << "升序输出：" << endl;
	x.ascend();
	cout << "先根遍历：" << endl;
	x.preOrderOutput();
	cout << "中根遍历：" << endl;
	x.inOrderOutput();
	//删除节点左右孩子至少有一个为空
	cout << "测试删除，删除：3:e" << endl;
	x.erase(3);
	cout << "升序输出：" << endl;
	x.ascend();
	cout << "先根遍历：" << endl;
	x.preOrderOutput();
	cout << "中根遍历：" << endl;
	x.inOrderOutput();
	//RL
	cout << "测试RL旋转，插入：15:g" << endl;
	x.insert(std::pair<int, char>(15, 'g'));
	cout << "升序输出：" << endl;
	x.ascend();
	cout << "先根遍历：" << endl;
	x.preOrderOutput();
	cout << "中根遍历：" << endl;
	x.inOrderOutput();
	//删除节点有左右孩子
	x.insert(std::pair<int, char>(18, 'h'));
	cout << "测试删除，插入：18:h，删除：10:a" << endl;
	x.erase(10);
	cout << "升序输出：" << endl;
	x.ascend();
	cout << "先根遍历：" << endl;
	x.preOrderOutput();
	cout << "中根遍历：" << endl;
	x.inOrderOutput();
	cout << "测试查找,5:d" << endl;
	std::pair<const int, char> *s = x.find(5);
	if (s)
		cout << "查找节点为：" << s->first << ' ' << s->second << endl;
	else
		cout << "无此节点" << endl;

}
