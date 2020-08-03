#include <iostream>
#include "CForOffer.h"
#include<vector>

int main()
{
	CForOffer mForOffer;
	//vector<vector<int>> TwoDArray{ {1, 2, 3},{2, 3, 4} };
	//std::cout << TwoDArray.size();
	//std::cout<< mForOffer.ZTwoDArrayLookUp(2,TwoDArray);

	//char test[] = "hello i can stop";
	//mForOffer.ZReplaceSpace(test, strlen(test));
	//std::cout << test[0] << test[5] << test[6] << test[7];
	//std::cout << std::endl;
	
	/**
	测试二叉树重建
	vector<int> zPre = { 1,2,4,7,3,5,6,8 };
	vector<int> zIn = { 4,7,2,1,5,3,8,6 };
	CForOffer::TreeNode* zTestTreeNode;
	zTestTreeNode = mForOffer.ZreConstructBinaryTree(zPre, zIn);
	*/

	/*
	栈生产队列测试
	CForOffer::CStackToQueue mStackToQueue;
	mStackToQueue.push(1);
	mStackToQueue.push(2);
	mStackToQueue.push(3);
	std::cout<<mStackToQueue.pop();
	std::cout << mStackToQueue.pop();
	mStackToQueue.push(4);
	std::cout << mStackToQueue.pop();
	mStackToQueue.push(5);
	std::cout << mStackToQueue.pop();
	std::cout << mStackToQueue.pop();
	*/

	/*第六题测试
	vector<int> zIn = { 4,7,2,1,5,3,8,6 };
	vector<int> zIn2;
	std::cout << mForOffer.ZminNumberInRotateArray(zIn2);
	std::cout << std::endl;
	*/

	
	vector<int> zIn = { 4,7,2,1,5,3,8,6 };
	vector<int>* arr = &zIn;
	mForOffer.reOrderArray(*arr);
	std::cout << *(arr->begin()+4);
	system("pause");
	return 0;
}