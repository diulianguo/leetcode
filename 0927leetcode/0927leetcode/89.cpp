#include<iostream>
#include<vector>
using namespace std;

vector<int> grayCode(int n)
{
    vector<int> res;
    res.push_back(0);
    if (n == 0)
        return res;

    res.push_back(1);
    if (n == 1){
         return res;
    }

    for (int j = 1; j < n; j++){//从1到n-1都要算一遍，其实跟递归一样的效率
        for (int i = res.size()-1; i >= 0; i--){
            int tmp = (1 << j) + res[i];
            res.push_back(tmp);
        }
    }
    return res;
}