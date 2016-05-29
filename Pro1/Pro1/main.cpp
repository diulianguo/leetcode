#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> sumindex;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target){
                    sumindex.push_back(i);
                    sumindex.push_back(j);
                    break;
                }
            }
        }
        return sumindex;
    }

    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> sumindex;
        int l = 0;
        for (int i = 0; i < nums.size() / 3; i++){
            for (int j = nums.size() / 3; j < nums.size() * 2 / 3; j++){
                for (int k = nums.size() * 2 / 3; j < nums.size(); j++){
                    if (nums[i] + nums[j] + nums[k] == 0){
                        sumindex[l].push_back(i);
                        sumindex[l].push_back(j);
                        sumindex[l].push_back(k);
                        l++;
                        break;
                    }else
                        k++;
                }
            }
        }
        return sumindex;
    }
};

int main()
{

}