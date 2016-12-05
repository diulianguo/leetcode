#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
    int n = nums.size();
    vector<string> res;
    if (n == 0)
        return res;
    int i = 0, j, x;
    string temp;
    while (i < n){
        x = i;
        j = x + 1;
        while (j < n && nums[j] == nums[x] + 1){
            j++;
            x++;
        }
        if (j == i + 1)
            temp = to_string(nums[i]);
        else
            temp = to_string(nums[i]) + "->" + to_string(nums[j - 1]);
        res.push_back(temp);
        i = j;
    }
    return res;
}

//int main()
//{
//    vector<int> nums = { 0, 1, 2, 4, 5, 7 };
//    summaryRanges(nums);
//}