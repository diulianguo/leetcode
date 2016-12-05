#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

//int findKthLargest(vector<int>& nums, int k)
//{
//    int res;
//    make_heap(nums.begin(), nums.end());
//    //加入新数据 先在容器中加入，再调用push_heap()
//    //删除数据  要先调用pop_heap()，再在容器中删除
//    for (int i = 0; i < k; i++){
//        res = nums.front();
//        pop_heap(nums.begin(), nums.end());
//        nums.pop_back();
//    }
//    return res;
//}

//int findKthLargest(vector<int>& nums, int k)
//{
//    int res = nums.front();
//    priority_queue<int> q;
//    for (int i = 0; i < nums.size(); i++){
//        q.push(nums[i]);
//    }
//    for (int i = 0; i < k; i++){
//        if (!q.empty()){
//            res = q.top();
//            q.pop();
//        }
//    }
//    return res;
//}

int findKthLargest(vector<int>& nums, int k)
{
    int privot = nums[0];
    int i = 0, j = nums.size() - 1;
    int low = 0, high = nums.size();
    k = nums.size() - k + 1;
    while (low < high){
        privot = nums[low];
        i = low;
        j = high - 1;
        while (i <= j){
            while (i <= j && nums[i] <= privot)
                i++;
            while (i <= j && nums[j] > privot)
                j--;
            if (i < j){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        swap(nums[j], nums[low]);

        if (j < k - 1)
            low = j + 1;
        else if (j > k - 1)
            high = j;
        else
            return nums[j];
    }
}


//int main()
//{
//    vector<int> nums = { -1,2};
//    int k;
//    cin >> k;
//    cout << findKthLargest(nums, k);
//    return 0;
//}