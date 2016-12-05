#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int findMin(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int mid;
    if (n == 1)
        return nums[0];
    else if (n == 2)
        return min(nums[0], nums[1]);

    /*int i = 0, j = n - 1;
    while (i < j){
        if (j - i == 1)
            return min(nums[i], nums[j]);
        mid = (i + j) / 2;
        if (nums[i] < nums[mid] && nums[mid]<nums[j])
            return nums[i];

        if (nums[mid]>nums[i])
            i = mid;
        else
            j = mid;
    } 
    return nums[i];*/
    int i = 0, j = n - 1;
    while (nums[i] > nums[j]){
        int mid = (i + j) / 2;
        if (nums[mid]>nums[j])
            i = mid + 1;
        else
            j = mid;
    }
}

//int main()
//{
//    vector<int> nums = { 3, 1, 2 };
//    cout << findMin(nums);
//    system("pause");
//    return 0;
//}