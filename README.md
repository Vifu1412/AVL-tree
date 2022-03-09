# 1.概述
在链式存储结构实现二叉树的基础上实现AVL树功能进而实现字典功能

# 2.dictionary.h
该文件定义了抽象类dictionary，是字典数据结构的抽象数据类型规范，所有方法都是纯虚函数，K是键类型，E是值类型。
## 1.有关字典的操作有：
- 确定字典是否为空
- 确定字典有多少数对
- 寻找一个指定了关键字的数对
- 插入一个数对
- 删除一个指定了关键字的数对
## 2.关于插入
p.first和p.second分别表示数对p的关键字和值。当字典没有与关键字p.first对应的数对时，插入操作insert(p)把数对p插入字典；当字典已经具有与关键字p.first对应的数对时，用新的值取代旧的值。操作方式与STL容器类hash_map的方法insert一致。
## 3.关于查找
查找函数的返回值是指针，指向与给定的关键字相匹配的数对。与STL的容器类hash_map的函数find一致。

# 3.bsTree.h
该文件定义了抽象类bsTree，是二叉搜索树的抽象数据类型规范，所有方法都是纯虚函数，K是键类型，E是值类型。

# 4.binaryTree.h
该文件定义了链式存储的节点结构binaryTreeNode和二叉树抽象类binaryTree，抽象类binaryTree所有方法都是纯虚函数。

# 5.linkedBinaryTree.h
类linkedBinaryTree是抽象类binaryTree的派生类，节点的类型是binaryTreeNode。类linkedBinaryTree有两个数据成员实例root和treeSize。root是指向二叉树节点的指针，treeSize是二叉树节点个数。类linkedBinaryTree有个静态数据程序成员visit,它是一个函数指针，这个函数返回值类型是void,参数是binaryTreeNode类型的指针。

公有遍历方法preOrder先给静态数据成员visit赋值，得到访问节点的函数，然后调用私有递归方法preOrder,它是实际上执行前序遍历的函数。相应的中序和后序方法类似。

# 6.linkedBinaryTree.cpp
该文件是对linkedBinaryTree类函数的实现。

# 7.AVLTree.h
该文件定义了二叉树数据成员element的结构，包括键值对和节点高度。类AVLTree继承bsTree类和
linkedBinaryTree类。实现了dictionary和bsTree的方法。

# 8.AVLTree.cpp
该文件是对AVLTree类函数的实现。
## 1.插入
插入新的节点可能会导致AVL树失衡，平衡因子(某一节点左右子树高度差)为2表示失衡。
## 2.失衡种类
原理不做描述，仅描述实现方法
### 1.LL型
失衡节点左孩子左子树增加新节点导致失衡

**方法：**
1.设失衡节点为T，其左孩子为L
2.将L右孩子给T左孩子
3.T作为L的右孩子
4.由下到上更改高度，除L、T外其他节点高度均未改变
### 2.LR型
失衡节点左孩子右子树增加新节点导致失衡

**方法：**
1.设失衡节点为T，其左孩子为L
2.对L进行RR旋转
3.对T进行LL旋转

**RR和RL型与上面两种相反**

## 2.删除
### 1.删除情况
#### 1.待删除节点左右非空
- 左子树比右子树高时，找出左子树最大节点与待删除节点交换，删除带删除节点
- 右子树比左子树高时，找出右子树最小节点与待删除节点交换，删除带删除节点
#### 2.待删除节点左右孩子至少一个为空
待删除节点与非空一侧交换，删除待删除节点

**删除后调整节点高度**
### 2.判断失衡
#### 1.待删除节点在t的左子树中
1.删除后判断t右子树是否比左子树高2（是否失衡）
2.若右子树的左子树比右子树高为RL变换否则为RR
#### 1.待删除节点在t的右子树中
与第一种情况相反

# 9.test.cpp
该文件为测试文件，对AVL树插入失衡后四种调整方式和删除后导致失衡的两种情况进行了测试。
