#include "CForOffer.h"

bool CForOffer::ZTwoDArrayLookUp(int target, vector<vector<int>> TwoDArray)
{
	//###########################
	//part 1
	if (false) 
	{
		for (int i = 0; i < TwoDArray.size(); ++i)
		{
			for (int j = 0; j < TwoDArray[i].size(); ++j)
			{
				if (TwoDArray[i][j]==target)
				{
					return true;
				}
			}
		}
		return false;

	}
	//###########################
	//part 2 
	/*
	以二维数组的左下角或者右上角为起点，进行判断。以下以左下角为起点举例，当当前值大于target时，上移；当
	当前值小于target时，右移。
	*/
	if (true)
	{
		int weight =TwoDArray[0].size();
		int height = TwoDArray.size();
		int i = height-1;
		int j = 0;
		while (true)
		{
			
			if (i < 0 || j < 0||i>height-1||j>weight-1) return false;
			if (TwoDArray[i][j] == target)
			{
				return true;
			}
			else if (TwoDArray[i][j] < target)
			{
				j++;
			}
			else if (TwoDArray[i][j] > target)
			{
				i--;
			}
		}
	}
	//###########################
}

/*
首先获取空格的个数，计算出新字符串的大小，然后替换就可以了。
*/
void CForOffer::ZReplaceSpace(char* str, int length)
{
	
	if (str == NULL || length == 0) return;
	int z_space_num = 0;
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
		{
			z_space_num++;
		}
	}
	for (int i= length-1;i>=0;--i)
	{
		if (str[i] == ' ')
		{
			z_space_num--;
			str[i + 2 * z_space_num] = '%';
			str[i + 2 * z_space_num+1] = '2';
			str[i + 2 * z_space_num+2] ='0';
		}
		else
		{
			str[i + 2 * z_space_num] = str[i];
		}
	}
}

vector<int> CForOffer::ZprintListFromTailToHead(ListNode* head)
{
	vector<int> zList;
	if (NULL == head) return zList;
	ListNode *p = head;
	zList.push_back(0);//为了能够使用zList.begin()迭代器，不然这个迭代器等于end（），无法进行循环内的操作。
	while (p!=NULL)
	{	
		zList.insert(zList.begin(),p->val);
		p = p->next;
	}
	zList.pop_back();//删除之前的加进去的“0”；
	return zList;
}


CForOffer::TreeNode* CForOffer::ZreConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	int inlen = vin.size();
	if (inlen == 0) return NULL;

	vector<int> left_pre, right_pre, left_in, right_in;

	//创建根节点，根节点肯定是前序遍历的第一个数

	TreeNode* head = new TreeNode(pre[0]);

	//找到中序遍历根节点所在位置,存放于变量gen中

	int gen = 0;

	for (int i = 0; i < inlen; i++)
	{
		if (vin[i] == pre[0])
		{
			gen = i;
			break;
		}
	}

	//对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
	//利用上述这点，对二叉树节点进行归并

	for (int i = 0; i < gen; i++)//zzy,实际上就是以根节点作为分界，分出了左右两个子树。下面这两个处理就是对这两个子树，分别取出中序遍历和前序遍历得值。
	{
		left_in.push_back(vin[i]);//左子树得中序遍历
		left_pre.push_back(pre[i + 1]);//左子树得前序遍历
	}

	for (int i = gen + 1; i < inlen; i++)

	{
		right_in.push_back(vin[i]);//右
		right_pre.push_back(pre[i]);
	}

	//递归，再对其进行上述所有步骤，继续细分子树的左、右子子数，直到叶节点

	head->left = ZreConstructBinaryTree(left_pre, left_in);
	head->right = ZreConstructBinaryTree(right_pre, right_in);

	return head;
}

void CForOffer::CStackToQueue::push(int node)
{
	zPushStack.push(node);
}

int CForOffer::CStackToQueue::pop()
{
	if (zPushStack.empty()) return -1;
	while (!zPopStack.empty())
	{
		zPopStack.pop();
	}
	//将zPushStack倒过来写进zPopStack
	while (!zPushStack.empty())
	{
		zPopStack.push(zPushStack.top());
		zPushStack.pop();
	}
	//去除zPopStack顶，也就是zPushStack底得值
	int tmp = zPopStack.top();
	zPopStack.pop();
	//将剩下得数据恢复到zPushStack中
	while (!zPopStack.empty())
	{
		zPushStack.push(zPopStack.top());
		zPopStack.pop();
	}
	return tmp;
}


int CForOffer::ZminNumberInRotateArray(vector<int> rotateArray)
{
	if (rotateArray.size() == 0) return 0;
	int tmp = rotateArray[0];
	for (auto i = rotateArray.begin(); i != rotateArray.end(); ++i)
	{

		if (tmp > * i)
		{
			tmp = *i;
		}
	}
	return tmp;
}

int CForOffer::ZFibonacci(int n)
{
	if (false)
	{
		/*part1
		使用非递归方法，逐次向前计算每一阶的值。
		*/
		int zpre = 0;//返回值的前一个值
		int znow = 1;//需要返回的值
		while (n--)
		{
			znow = znow + zpre;//最新返回值=上一个返回值+上一个返回值的前值
			zpre = znow - zpre;//最新返回值的前值（也就是上一个返回值）=最新返回值-上上一个值
		}
		return zpre;
	}

	if (true)
	{
		/*part2
		使用递归方法，递归到的最底层是第一个元素1和第二个元素2，由此可以稍微理解递归思想。
		*/
		if (n <= 0) return 0;
		else if (n == 1) return 1;
		else if (n == 2) return 1;
		else
		{
			return ZFibonacci(n - 1) + ZFibonacci(n - 2);
		}
	}
	
}

int CForOffer::ZjumpFloor(int number)
{
	/*思路：
	假设有n个台阶，次数为f（n）。
	此时，下一步有两种选择
	往上跳1格，则后面还有n-1个台阶，也就是后面的还剩的次数是f(n-1)
	往上跳2格，则后面还有n-2个台阶，也就是后面的还剩的次数是f(n-2)
	那么可知，f（n）=f(n-1)+f(n-2)
	探索就可知，这又是一个斐波那契数列，只不过第一个第二个元素是1和2.
	*/
	if (number <= 0) return 0;
	else if (number == 1) return 1;
	else if (number == 2) return 2;
	else
	{
		return ZjumpFloor(number - 1) + ZjumpFloor(number - 2);
	}

}


int CForOffer::ZjumpFloorII(int number)
{
	/*思路：所谓贪心算法
	假设跳上第i个台阶，次数为f（i）。
	那么，跳上第i+1个台阶，次数是：f(i+1)=f（i）+f（i-1）+f（i-2)+.....+f(1)+1
	因为：到第i+1个台阶可以选择到第i个台阶后，再按1个台阶跳1步；或者可以选择到第i-1个台阶后，再按2个台阶跳1步.。。。。。；或者到第1个台阶后，再按i个台阶跳1步;或者从0直接跳到i+1阶;
	也就是说，跳到当前台阶的次数等于所有之前台阶次数的总和再加上直接跳到当前的1次
	*/
	if (number <= 0) return 0;
	vector<int> zCountPool;
	zCountPool.push_back(0);
	zCountPool.push_back(1);
	zCountPool.push_back(2);
	for (int i = 3; i <= number; ++i)
	{
		int tmp = 0;
		for (int j = 0; j < i; ++j)
		{
			tmp+=zCountPool[j];
		}
		zCountPool.push_back(tmp+1);
	}
	return zCountPool[number];

}


int  CForOffer::ZrectCover(int number)
{
	/*
	思路：第n个长度的矩形，最后的组合的方式只会有三种，即：两个竖着、两个横着、两个横着加一个竖着。
	前面两种就是在n-2长度矩形的基础上进行增加，后面一种就是在n-3长度矩形上增加。
	所有fn=f（n-2）*2+f(n-3)
	*/
	if (number <= 0) return 0;
	vector<int> zCountPool;
	zCountPool.push_back(1);
	zCountPool.push_back(1);
	zCountPool.push_back(2);
	for (int i = 3; i <= number; ++i)
	{
		int tmp = 0;
		tmp = tmp+zCountPool[i-2]*2+ zCountPool[i-3];
		zCountPool.push_back(tmp);
	}
	return zCountPool[number];

	//实际上，算出来的数列还是斐波那契数列。
}


int  CForOffer::ZNumberOf1(int n)
{
	unsigned int target = 1;//之所以用unsigned int类型，是为了在右移超过四个字节后target等于0，便于程序退出。
	int count = 0;
	while (target)
	{
		if (n & target)//依次右移，比对是否包含1.
		{
			count++;
		}
		target=target << 1;
	}
	return count;
}


double  CForOffer::ZPower(double base, int exponent)
{
	/*
	对于电脑而言，指数运算就是连续相乘。将指数转换为二进制形式，然后右移，逢1相乘两次，逢0相乘一次。
	*/
	long long zAbsExp = abs((long long)exponent);
	double zTarget = 1.0;
	while (zAbsExp)
	{
		if (zAbsExp & 1) zTarget *= base;
		base *= base;
		zAbsExp = zAbsExp >> 1;
	}
	return (exponent > 0) ? zTarget:1/zTarget;
}

void CForOffer::ZreOrderArray(vector<int>& array)
{
	vector<int> tmp_OddNum;
	vector<int> tmp_EvenNum;
	for (auto i = array.begin(); i != array.end(); ++i)
	{
		if (*i % 2)
		{
			tmp_OddNum.push_back(*i);
		}
		else
		{
			tmp_EvenNum.push_back(*i);
		}
	}
	vector<int> tmp_R;
	
	tmp_R.insert(tmp_R.end(), tmp_OddNum.begin(), tmp_OddNum.end());
	tmp_R.insert(tmp_R.end(), tmp_EvenNum.begin(), tmp_EvenNum.end());
	array = tmp_R;
}

CForOffer::ListNode* CForOffer::FindKthToTail(ListNode* pListHead, unsigned int k)
{

}