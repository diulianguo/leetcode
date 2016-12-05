#include<iostream>
#include<vector>
using namespace std;

int findMinDup(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return -1;
    if (n == 1)
        return nums[0];

    int i = 0, j = n - 1;
    while (i!=j && nums[i] >= nums[j]){
        int mid = (i + j) / 2;
        if (nums[mid] > nums[j])
            i = mid + 1;
        else if (nums[mid]<nums[j])
            j = mid;
        else{
            j--;
        }
    }
    return nums[i];
}

//int main()
//{
//    vector<int> nums = { 1,1 };
//    cout << findMinDup(nums);
//    system("pause");
//    return 0;
//}