#include<iostream>
#include<vector>
using namespace std;

class NumArray {
private:
    vector<int> acc;
public:
    NumArray(vector<int> &nums)
    {
        acc.push_back(0);
        for (int i = 0; i < nums.size(); i++)
            acc.push_back(acc.back() + nums[i]);
    }

    int sumRange(int i, int j)
    {
        return acc[j + 1] - acc[i];
    }
};

//int main()
//{
//    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
//    NumArray numArray(nums);
//}
