#include<iostream>
#include<vector>
#include<string>
using namespace std;

//[1,2,3,...,n]组成的n位数的全排列个数是n!
int NumofPermutation(int n)
{
    int num = 1;
    for (int j = n; j > 1; j--){
        num *= j;
    }
    return num;
}

int curNum(vector<int>& nums, int n, int& k)
{
    int subnum = NumofPermutation(n - 1);
    int index;
    if (k%subnum)
        index = k / subnum;
    else
        index = k / subnum - 1;
    int cur = nums[index];
    auto it = nums.begin() + index;
    nums.erase(it);
    if (k%subnum)
        k = k%subnum;
    else
        k = subnum;
    return cur;
}

string getPermutation(int n, int k)
{
    vector<int> nums(n);
    for (int i = 0; i < n; i++){
        nums[i] = i + 1;
    }
    string kth;
    for (int i = 0; i < n; i++){
        int cur = curNum(nums, n - i, k);
        kth += to_string(cur);
    }
    return kth;
}

//int main()
//{
//    int n, k;
//    cin >> n >> k;
//    string s = getPermutation(n, k);
//    cout << s;
//    system("pause");
//    return 0;
//}