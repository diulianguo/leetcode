#include<iostream>
#include<vector>
using namespace std;

void swapArray(vector<int>& temp, int i, int j)
{
    //����i��j����λ�õ��ַ�
    int cur = temp[i];
    temp[i] = temp[j];
    temp[j] = cur;
}

void perm(vector<vector<int>>& res, vector<int>& temp, int index)
{
    //��temp�д�indexλ�ÿ�ʼ��������Ԫ�أ������Լ����ֱ𽻻�,�������е�Ҷ�ڵ����ȫ���Ľ�
    if (index == temp.size()){
        res.push_back(temp);
        return;
    }
    for (int i = index; i < temp.size(); i++){
        swapArray(temp, index, i);//index��iλ�õ�Ԫ�ؽ����������Ժ����������½���
        perm(res, temp, index + 1);
        swapArray(temp, index, i);//�ָ�ԭ״������
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<int> temp = nums;
    vector<vector<int>> res;
    perm(res, temp, 0);
    return res;
}

//int main()
//{
//    vector<int> nums = { 1, 2, 3 };
//    vector<vector<int>> res = permute(nums);
//}