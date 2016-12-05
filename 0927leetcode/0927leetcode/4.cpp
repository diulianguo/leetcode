#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    /*if (nums1.size() == 0 && nums2.size() == 0)
        return 0;
    if (nums1.size() == 0){
        sort(nums2.begin(), nums2.end());
        return (nums2[0] + nums2[nums2.size() - 1]) / 2.0;
    }
    if (nums2.size() == 0){
        sort(nums1.begin(), nums1.end());
        return (nums1[0] + nums1[nums1.size() - 1]) / 2.0;
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int min1, max1, min2, max2;
    min1 = nums1[0];
    max1 = nums1[nums1.size() - 1];
    min2 = nums2[0];
    max2 = nums2[nums2.size() - 1];
    if (max2 <= min1){
        return (min2 + max1) / 2.0;
    } else if (max2 > min1 && max2 <= max1){
        return (min(min1, min2) + max1) / 2.0;
    } else if (max2 <= max1 && min2>=min1){
        return (min1 + max1) / 2.0;
    } else
        return (min1 + max2) / 2.0;*/
    vector<int> nums=nums1;
    nums.resize((nums1.size() + nums2.size()));
    int k = 0;
    for (int i = nums1.size(); i < nums.size(); i++){
        nums[i] = nums2[k++];
    }
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n % 2){
        return nums[n/2];
    } else{
        return (nums[(n - 1) / 2] + nums[n / 2]) / 2.0;
    }
    return 0;
}

//int main()
//{
//    vector<int> nums1 = { 1, 2 };
//    vector<int> nums2 = { 3, 4 };
//    cout << findMedianSortedArrays(nums1, nums2);
//    system("pause");
//    return 0;
//}