#pragma once
#include<vector>
#include<stack>

using namespace std;

class CForOffer
{
public:
	//剑指offer第一题，二位数组查找
	bool ZTwoDArrayLookUp(int target,vector<vector<int>> TwoDArray);
	//剑指offer第二题，字符串替换空格
	void ZReplaceSpace(char *str,int length);
	//剑指offer第三题，链表反向输出
	struct ListNode {
		int val;
		struct ListNode* next;
		ListNode(int x) :
			val(x), next(NULL) {
			
		}
	};
	vector<int> ZprintListFromTailToHead(ListNode *head);
	//剑指offer第四题，输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	TreeNode* ZreConstructBinaryTree(vector<int> pre, vector<int> vin);
	//剑指offer第五题，栈实现队列。
	class CStackToQueue
	{
	public:
		void push(int node);
		int	pop();
	private:
		stack<int> zPushStack;//作为存储数据得栈
		stack<int> zPopStack;//作为输出数据时得中间栈
	};
	//剑指offer第六题，输出旋转数组得最小值
	int ZminNumberInRotateArray(vector<int> rotateArray);
	//剑指offer第七题，斐波那契数列问题
	int ZFibonacci(int n);
	//剑指offer第八题，青蛙跳台阶(1,2跳)问题
	int ZjumpFloor(int number);
	//剑指offer第九题，青蛙跳台阶(1,2...n跳)问题
	int ZjumpFloorII(int number);
	//剑指offer第十题，矩阵折叠问题
	int ZrectCover(int number);
	//剑指offer第十一题，二进制表示中1的个数
	int  ZNumberOf1(int n);
	//剑指offer第十二题，给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。 
	double ZPower(double base, int exponent);
	//剑指offer第十三题，数组调整奇数和偶数顺序
	void ZreOrderArray(vector<int>& array);
	//剑指offer第十四题，链表返回指定值
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);


};

