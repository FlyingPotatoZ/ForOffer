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
	�Զ�ά��������½ǻ������Ͻ�Ϊ��㣬�����жϡ����������½�Ϊ������������ǰֵ����targetʱ�����ƣ���
	��ǰֵС��targetʱ�����ơ�
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
���Ȼ�ȡ�ո�ĸ�������������ַ����Ĵ�С��Ȼ���滻�Ϳ����ˡ�
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
	zList.push_back(0);//Ϊ���ܹ�ʹ��zList.begin()����������Ȼ�������������end�������޷�����ѭ���ڵĲ�����
	while (p!=NULL)
	{	
		zList.insert(zList.begin(),p->val);
		p = p->next;
	}
	zList.pop_back();//ɾ��֮ǰ�ļӽ�ȥ�ġ�0����
	return zList;
}


CForOffer::TreeNode* CForOffer::ZreConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	int inlen = vin.size();
	if (inlen == 0) return NULL;

	vector<int> left_pre, right_pre, left_in, right_in;

	//�������ڵ㣬���ڵ�϶���ǰ������ĵ�һ����

	TreeNode* head = new TreeNode(pre[0]);

	//�ҵ�����������ڵ�����λ��,����ڱ���gen��

	int gen = 0;

	for (int i = 0; i < inlen; i++)
	{
		if (vin[i] == pre[0])
		{
			gen = i;
			break;
		}
	}

	//����������������ڵ���ߵĽڵ�λ�ڶ���������ߣ����ڵ��ұߵĽڵ�λ�ڶ��������ұ�
	//����������㣬�Զ������ڵ���й鲢

	for (int i = 0; i < gen; i++)//zzy,ʵ���Ͼ����Ը��ڵ���Ϊ�ֽ磬�ֳ���������������������������������Ƕ��������������ֱ�ȡ�����������ǰ�������ֵ��
	{
		left_in.push_back(vin[i]);//���������������
		left_pre.push_back(pre[i + 1]);//��������ǰ�����
	}

	for (int i = gen + 1; i < inlen; i++)

	{
		right_in.push_back(vin[i]);//��
		right_pre.push_back(pre[i]);
	}

	//�ݹ飬�ٶ�������������в��裬����ϸ��������������������ֱ��Ҷ�ڵ�

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
	//��zPushStack������д��zPopStack
	while (!zPushStack.empty())
	{
		zPopStack.push(zPushStack.top());
		zPushStack.pop();
	}
	//ȥ��zPopStack����Ҳ����zPushStack�׵�ֵ
	int tmp = zPopStack.top();
	zPopStack.pop();
	//��ʣ�µ����ݻָ���zPushStack��
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
		ʹ�÷ǵݹ鷽���������ǰ����ÿһ�׵�ֵ��
		*/
		int zpre = 0;//����ֵ��ǰһ��ֵ
		int znow = 1;//��Ҫ���ص�ֵ
		while (n--)
		{
			znow = znow + zpre;//���·���ֵ=��һ������ֵ+��һ������ֵ��ǰֵ
			zpre = znow - zpre;//���·���ֵ��ǰֵ��Ҳ������һ������ֵ��=���·���ֵ-����һ��ֵ
		}
		return zpre;
	}

	if (true)
	{
		/*part2
		ʹ�õݹ鷽�����ݹ鵽����ײ��ǵ�һ��Ԫ��1�͵ڶ���Ԫ��2���ɴ˿�����΢���ݹ�˼�롣
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
	/*˼·��
	������n��̨�ף�����Ϊf��n����
	��ʱ����һ��������ѡ��
	������1������滹��n-1��̨�ף�Ҳ���Ǻ���Ļ�ʣ�Ĵ�����f(n-1)
	������2������滹��n-2��̨�ף�Ҳ���Ǻ���Ļ�ʣ�Ĵ�����f(n-2)
	��ô��֪��f��n��=f(n-1)+f(n-2)
	̽���Ϳ�֪��������һ��쳲��������У�ֻ������һ���ڶ���Ԫ����1��2.
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
	/*˼·����ν̰���㷨
	�������ϵ�i��̨�ף�����Ϊf��i����
	��ô�����ϵ�i+1��̨�ף������ǣ�f(i+1)=f��i��+f��i-1��+f��i-2)+.....+f(1)+1
	��Ϊ������i+1��̨�׿���ѡ�񵽵�i��̨�׺��ٰ�1��̨����1�������߿���ѡ�񵽵�i-1��̨�׺��ٰ�2��̨����1��.���������������ߵ���1��̨�׺��ٰ�i��̨����1��;���ߴ�0ֱ������i+1��;
	Ҳ����˵��������ǰ̨�׵Ĵ�����������֮ǰ̨�״������ܺ��ټ���ֱ��������ǰ��1��
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
	˼·����n�����ȵľ��Σ�������ϵķ�ʽֻ�������֣������������š��������š��������ż�һ�����š�
	ǰ�����־�����n-2���Ⱦ��εĻ����Ͻ������ӣ�����һ�־�����n-3���Ⱦ��������ӡ�
	����fn=f��n-2��*2+f(n-3)
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

	//ʵ���ϣ�����������л���쳲��������С�
}


int  CForOffer::ZNumberOf1(int n)
{
	unsigned int target = 1;//֮������unsigned int���ͣ���Ϊ�������Ƴ����ĸ��ֽں�target����0�����ڳ����˳���
	int count = 0;
	while (target)
	{
		if (n & target)//�������ƣ��ȶ��Ƿ����1.
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
	���ڵ��Զ��ԣ�ָ���������������ˡ���ָ��ת��Ϊ��������ʽ��Ȼ�����ƣ���1������Σ���0���һ�Ρ�
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