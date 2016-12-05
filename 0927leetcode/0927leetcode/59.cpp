#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> res(n, vector<int>(n));
    int i = 0, j = -1, count = 0;
    //µÚÒ»ÐÐ
    while (count < n*n){
        while (j < n - 1 && !res[i][j + 1])
            res[i][++j] = ++count;
        while (i < n - 1 && !res[i + 1][j])
            res[++i][j] = ++count;
        while (j > 0 && !res[i][j - 1])
            res[i][--j] = ++count;
        while (i > 0 && !res[i - 1][j])
            res[--i][j] = ++count;
    }
    return res;
}

//int main()
//{
//    int n;
//    cin >> n;
//    vector<vector<int>> res = generateMatrix(n);
//    return 0;
//}