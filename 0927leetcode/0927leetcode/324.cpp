#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void wiggleSort(vector<int>& nums)
{
    int len = nums.size();
    /*sort(nums.begin(), nums.end());
    vector<int> newnum(len);
    int k = 1, i = len - 1;
    while(i>=0 && k<len){
        newnum[k] = nums[i];
        k += 2;
        i--;
    }
    k = 0;
    while(i>=0 && k<len){
        newnum[k] = nums[i];
        k += 2;
        i--;
    }
    nums = newnum;*/
    for (int i = 1; i < len; i++){
        if (i % 2 && nums[i] <= nums[i - 1]){
            int temp = nums[i];
            nums[i] = nums[i - 1];
            nums[i - 1] = temp;
        }
        if ((i % 2 == 0) && nums[i] >= nums[i - 1]){
            int temp = nums[i];
            nums[i] = nums[i - 1];
            nums[i - 1] = temp;
        }
    }
}

//int main()
//{
//    vector<int> nums = { 1, 3, 2, 2, 3, 1 };
//    wiggleSort(nums);
//    int n = nums.size();
//    return 0;
//}