#include<iostream>
#include<vector>
using namespace std;

int thirdMax(vector<int>& nums)
{
    long long int min = LLONG_MIN, max = LLONG_MIN, mid = LLONG_MIN;
    int k = 0;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] == min || nums[i] == mid || nums[i] == max)
            continue;
        k++;
        if (nums[i]>max){
            min = mid;
            mid = max;
            max = nums[i];
        } else if (nums[i] > mid){
            min = mid;
            mid = nums[i];
        } else if (nums[i] > min){
            min = nums[i];
        }
    }
    if (k >= 3)
        return min;
    else if (k < 3)
        return max;
}

//int main()
//{
//    vector<int> nums = { 1, 1, 1 };
//    cout << thirdMax(nums) << endl;
//    return 0;
//}