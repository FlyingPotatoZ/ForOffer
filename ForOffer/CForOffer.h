#pragma once
#include<vector>
#include<stack>

using namespace std;

class CForOffer
{
public:
	//��ָoffer��һ�⣬��λ�������
	bool ZTwoDArrayLookUp(int target,vector<vector<int>> TwoDArray);
	//��ָoffer�ڶ��⣬�ַ����滻�ո�
	void ZReplaceSpace(char *str,int length);
	//��ָoffer�����⣬���������
	struct ListNode {
		int val;
		struct ListNode* next;
		ListNode(int x) :
			val(x), next(NULL) {
			
		}
	};
	vector<int> ZprintListFromTailToHead(ListNode *head);
	//��ָoffer�����⣬����ĳ��������ǰ���������������Ľ�������ؽ����ö�����
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	TreeNode* ZreConstructBinaryTree(vector<int> pre, vector<int> vin);
	//��ָoffer�����⣬ջʵ�ֶ��С�
	class CStackToQueue
	{
	public:
		void push(int node);
		int	pop();
	private:
		stack<int> zPushStack;//��Ϊ�洢���ݵ�ջ
		stack<int> zPopStack;//��Ϊ�������ʱ���м�ջ
	};
	//��ָoffer�����⣬�����ת�������Сֵ
	int ZminNumberInRotateArray(vector<int> rotateArray);
	//��ָoffer�����⣬쳲�������������
	int ZFibonacci(int n);
	//��ָoffer�ڰ��⣬������̨��(1,2��)����
	int ZjumpFloor(int number);
	//��ָoffer�ھ��⣬������̨��(1,2...n��)����
	int ZjumpFloorII(int number);
	//��ָoffer��ʮ�⣬�����۵�����
	int ZrectCover(int number);
	//��ָoffer��ʮһ�⣬�����Ʊ�ʾ��1�ĸ���
	int  ZNumberOf1(int n);
	//��ָoffer��ʮ���⣬����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η��� 
	double ZPower(double base, int exponent);
	//��ָoffer��ʮ���⣬�������������ż��˳��
	void ZreOrderArray(vector<int>& array);
	//��ָoffer��ʮ���⣬������ָ��ֵ
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);


};

