#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    vector<int> res;
    map<int, int> fre;
    set<int> times;
    for (int i = 0; i < nums.size(); i++){
        if (fre.find(nums[i]) == fre.end())
            fre[nums[i]] = 1;
        else
            fre[nums[i]]++;
    }
    multimap<int, int> ufre;
    for (auto it = fre.begin(); it != fre.end(); it++){
        ufre.insert(pair<int, int>(it->second, it->first));
    }
    for (auto it = ufre.rbegin(); it != ufre.rend(); it++){
        if (res.size() < k)
            res.push_back(it->second);
    }
    return res;
}

//int main()
//{
//    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
//    vector<int> res = topKFrequent(nums, 2);
//    return 0;
//}