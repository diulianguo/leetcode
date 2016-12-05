#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int i, j;
    for (i = 0; i < matrix.size(); i++){
        j = matrix[i].size();
        if (matrix[i][0] <= target && target <= matrix[i][j - 1]){
            break;
        }
    }
    if (i == matrix.size())
        return false;
    //在当前行二分查找
    int left = 0, right = matrix[i].size() - 1;
    while (left < right){
        int mid = (left + right) / 2;
        if (matrix[i][mid]>target)
            right = mid - 1;
        else if (matrix[i][mid] < target)
            left = mid + 1;
        else
            return true;
    }
    if (matrix[i][left] == target)
        return true;
    else
        return false;
}

//int main()
//{
//    vector<vector<int>> matrix = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 } };
//    cout << searchMatrix(matrix, 0) << endl;
//    system("pause");
//    return 0;
//}
