#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//没完成呀没完成
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
{
    int i = 0, j = 0;
    vector<int> res;
    int del = nums1.size() + nums2.size() - k;
    while (i < nums1.size() && j < nums2.size()){
        int maxnum = max(nums1[i], nums2[j]);
        if (nums1[i]>nums2[j]){
            j++;
        } else
            i++;
        while (k && res.size() && res.back() < maxnum){
            res.pop_back();
            k--;
        }
        res.push_back(maxnum);
    }
    return res;
}

//int main()
//{
//    int k;
//    cin >> k;
//    vector<int> nums1 = { 3, 4, 6, 5 };
//    vector<int> nums2 = { 9, 1, 2, 5, 8, 3 };
//    vector<int> res = maxNumber(nums1, nums2, k);
//    return 0;
//}