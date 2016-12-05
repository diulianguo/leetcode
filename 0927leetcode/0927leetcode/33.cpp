#include<iostream>
#include<vector>
using namespace std;

//int search(vector<int>& nums, int target)
//{
//    /*int n = nums.size();
//    if (n == 0)
//        return -1;
//    if (n == 1)
//        return target == nums[0] ? 0 : -1;
//    int i = 0, j = n - 1;
//    while (nums[i] > nums[j]){
//        int mid = (i + j) / 2;
//        if (nums[mid]>nums[j])
//            i = mid + 1;
//        else
//            j = mid;
//    }
//
//    if (i == 0){
//        j = n - 1;
//    } else{
//        if (nums[0] > target){
//            j = n - 1;
//        } else{
//            j = i - 1;
//            i = 0;
//        }
//    }
//    while (i < j){
//        if (j - i == 1){
//            if (nums[i] == target)
//                return i;
//            else if (nums[j] == target)
//                return j;
//            else
//                return -1;
//        }
//        int mid = (i + j) / 2;
//        if (nums[mid] < target)
//            i = mid + 1;
//        else if (nums[mid]>target)
//            j = mid - 1;
//        else
//            return mid;
//    }
//    if (nums[i] == target)
//        return i;
//    else
//        return -1;*/
//    int n = nums.size();
//    if (n == 0)
//        return -1;
//    if (n == 1)
//        return target == nums[0] ? 0 : -1;
//    int i = 0, j = n - 1;
//    while (i<j){
//        if (j - i == 1){
//            if (nums[i] == target)
//                return i;
//            else if (nums[j] == target)
//                return j;
//            else
//                return -1;
//        }
//        int mid = (i + j) / 2;
//        if (target == nums[mid])
//            return mid;
//        if (nums[mid] < nums[j]){
//            //右边数组有序
//            if (target>nums[mid] && target <= nums[j])
//                i = mid + 1;
//            else
//                j = mid - 1;
//        } else if (nums[mid] > nums[j]){
//            //左边数组有序
//            if (target >= nums[i] && target < nums[mid])
//                j = mid - 1;
//            else
//                i = mid + 1;
//        }
//    }
//    if (nums[i] == target)
//        return i;
//    else
//        return -1;
//}

int search(vector<int>& nums, int target)
{
    int i = 0, j = nums.size() - 1;
    while (i <= j){
        int mid = (i + j) / 2;
        if (target == nums[mid])
            return mid;
        if (nums[mid]<nums[j]){
            //右边数组有序
            if (target>nums[mid] && target <= nums[j])
                i = mid + 1;
            else
                j = mid - 1;
        } else if (nums[mid]>nums[j]){//左边数组有序
            if (target<nums[mid] && target >= nums[i])
                j = mid - 1;
            else
                i = mid + 1;
        } else
            break;
    }
    if (nums[i] == target)
        return i;
    else
        return -1;
}

//int main()
//{
//    vector<int> nums = { 1,3,5 };
//    int target = 0;
//    cout << search(nums, target);
//    system("pause");
//    return 0;
//}