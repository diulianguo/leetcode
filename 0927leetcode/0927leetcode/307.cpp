#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class NumArray {
//private:
//    vector<int> acc;
//public:
//    NumArray(vector<int> &nums)
//    {
//        acc.resize(nums.size() + 1);
//        for (int i = 0; i < nums.size(); i++)
//            add(i + 1, nums[i]);
//    }
//
//    void add(int pos, int val)
//    {
//        while (pos < acc.size()){
//            acc[pos] += val;
//            pos += lowbit(pos);
//        }
//    }
//
//    int lowbit(int pos)
//    {
//        return pos&(-pos);
//    }
//
//    void update(int i, int val)
//    {
//        int temp = acc[i + 1] - acc[i];
//        for (int j = i + 1; j < acc.size(); j++)
//            acc[j] += val - temp;
//    }
//
//    int sumRange(int i, int j)
//    {
//        return acc[j + 1] - acc[i];
//    }
private:
    vector<int> c;
    vector<int> m_nums;
public:
    NumArray(vector<int> &nums)
    {
        c.resize(nums.size() + 1);
        m_nums = nums;
        for (int i = 0; i < nums.size(); i++){
            add(i + 1, nums[i]);
        }
    }

    int lowbit(int pos)
    {
        return pos&(-pos);//这个节点管辖的区间为2^k（其中k为x二进制末尾0的个数）个元素
    }
    void add(int pos, int value)
    {
        while (pos < c.size()){
            c[pos] += value;
            pos += lowbit(pos);//每个value的管辖区间是2的k次方，用这种方法来计算
        }
    }
    int sum(int pos)
    {
        int res = 0;
        while (pos > 0){
            res += c[pos];
            pos -= lowbit(pos);//将pos的二进制最后一个1减去
        }
        return res;
    }

    void update(int i, int val)
    {
        int ori = m_nums[i];
        int delta = val - ori;
        m_nums[i] = val;
        add(i + 1, delta);
    }

    int sumRange(int i, int j)
    {
        return sum(j + 1) - sum(i);
    }
};

//int main()
//{
//    vector<int> nums = { 1, 3, 5 };
//    NumArray numArray(nums);
//    cout << numArray.sumRange(0, 2) << endl;
//    numArray.update(0, 10);
//    cout << numArray.sumRange(0, 2) << endl;
//    system("pause");
//    return 0;
//}