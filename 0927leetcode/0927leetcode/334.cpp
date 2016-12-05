#include<iostream>
#include<vector>
using namespace std;

bool increasingTriplet(vector<int>& nums)
{
    if (nums.size() <= 2)
        return false;
    int fmin = INT_MAX;
    int smin = INT_MAX;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] <= fmin){
            fmin = nums[i];
        } else if (nums[i] <= smin){
            smin = nums[i];
        } else
            return true;
    }
    return false;
}

//int main()
//{
//    vector<int> nums = { 1, 1, 1, 1 };
//    cout << increasingTriplet(nums) << endl;
//    system("pause");
//    return 0;
//}