#include<iostream>
#include<vector>
using namespace std;

//vector<int> searchRange(vector<int>& nums, int target)
//{
//    vector<int> res;
//    int i = 0, j = nums.size() - 1;
//    while (i <= j){
//        int mid = (i + j) / 2;
//        if (nums[mid] >= target)
//            j = mid - 1;
//        else if (nums[mid] < target)
//            i = mid + 1;
//    }
//    int left = i;
//    i = 0; j = nums.size() - 1;
//    while (i <= j){
//        int mid = (i + j) / 2;
//        if (nums[mid] > target)
//            j = mid - 1;
//        else if (nums[mid] <= target)
//            i = mid + 1;
//    }
//    int right = j;
//    if (nums[left] != target || nums[right] != target)
//        left = right = -1;
//    res.push_back(left);
//    res.push_back(right);
//    return res;
//}

int searchInsert(vector<int>& nums, int target)
{
    int i = 0, j = nums.size() - 1;
    while (i <= j){
        int mid = (i + j) / 2;
        if (nums[mid]<target)
            i = mid + 1;
        else if (nums[mid]>target)
            j = mid - 1;
        else
            return mid;
    }
    return i;
}

//int main()
//{
//    vector<int> nums = { 1 };
//    //vector<int> range = searchRange(nums, 8);
//    cout << searchInsert(nums, 2) << endl;
//    system("pause");
//    return 0;
//}
//