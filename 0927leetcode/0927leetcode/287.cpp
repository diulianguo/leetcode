#include<iostream>
#include<vector>
using namespace std;

//int findDuplicate(vector<int>& nums)
//{
//    for (int i = 0; i < nums.size(); i++){
//        for (int j = 0; j < nums.size(); j++){
//            if (i != j && nums[j] == nums[i])
//                return nums[i];
//        }
//    }
//}

int findDuplicate(vector<int>& nums)
{
    int min = 0, max = nums.size() - 1;
    while (min <= max){
        int mid = (max - min) / 2 + min;
        int k = 0;
        for (int i = 0; i <nums.size(); i++){
            if (nums[i] <= mid)
                k++;
        }
        if (k>mid)
            max = mid - 1;
        else
            min = mid + 1;
    }
    return min;
}

//int main()
//{
//    vector<int> nums = { 1, 3, 4, 2, 2 };
//    cout << findDuplicate(nums) << endl;
//    return 0;
//}