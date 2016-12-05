#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
    vector<vector<int>> threeSum(vector<int>& nums,int target)
    {
        /*for (int i = 0; i < nums.size() - 2; i++){
            for (int j = i + 1; j < nums.size() - 1; j++){
                int a = nums[i] + nums[j];
                for (int k = j + 1; k < nums.size(); k++){
                    if (a*nums[k]>0)
                        continue;
                    if (a == 0 && nums[k] != 0)
                        continue;
                    if (nums[i] + nums[j] + nums[k] == 0){
                        sumindex.push_back(vector<int> {nums[i], nums[j], nums[k]});
                    }
                    k++;
                }
                j++;
            }
            i++;
        }*/
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++){
            int a = target-nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k){
                int b = nums[j] + nums[k];
                if (b < a)
                    j++;
                else if (b>a)
                    k--;
                else{
                    vector<int> sumindex(3,0);
                    sumindex[0] = nums[i];
                    sumindex[1] = nums[j];
                    sumindex[2] = nums[k];
                    res.push_back(sumindex);

                    while (j < k && nums[j] == sumindex[1])
                        j++;
                    while (j < k && nums[k] == sumindex[2])
                        k--;
                }
            }
            while (i+1 < nums.size() - 2 && nums[i+1] == nums[i])
                i++;
        }
        return res;
    }

    int threeSumCloset(vector<int> &nums, int target)
    {
        int sum;
        int closetsum= nums[0] + nums[1] + nums[nums.size()-1];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k){
                sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(closetsum - target))
                    closetsum = sum;
                if (sum>target)
                    k--;
                else if (sum < target)
                    j++;
                else
                    return sum;
            }
        }
        return closetsum;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size()-3; i++){
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]>target)
                break;
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;
            for (int j = i + 1; j < nums.size()-2; j++){
                int sum = target - nums[i] - nums[j];
                int k = j + 1;
                int h = nums.size() - 1;
                while (k < h){
                    if (nums[k] + nums[h] < sum)
                        k++;
                    else if (nums[k] + nums[h] > sum)
                        h--;
                    else{
                        vector<int> sumindex(4, 0);
                        sumindex[0] = nums[i];
                        sumindex[1] = nums[j];
                        sumindex[2] = nums[k];
                        sumindex[3] = nums[h];
                        res.push_back(sumindex);

                        while (k < h && nums[k] == sumindex[2])
                            k++;
                        while (k < h && nums[h] == sumindex[3])
                            h--;
                    }
                }
                while (j + 1 < nums.size() && nums[j + 1] == nums[j])
                    j++;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return res;
    }
//};

    int removeElement(vector<int>& nums, int val)
    {
        int n = nums.size();
        int i = 0;
        while(i<n){
            if (nums[i] == val){
                if (n==1){
                    nums.resize(0);
                    return 0;
                }
                for (int j = i + 1; j < n; j++){
                    nums[j - 1] = nums[j];
                }
                n--;
            } else
                i++;
        }
        nums.resize(n);
        return nums.size();
    }

    int missingNumber(vector<int> &nums)
    {

    }

void main()
{
    vector<int> A(4);
    for (int i = 0; i < 4; i++){
        cin >> A[i];
    }
    //vector<vector<int>> res = threeSum(A, 0);
    //vector<vector<int>> res = fourSum(A, 0);
    //int res = threeSumCloset(A, 1);
    removeElement(A, 3);
}