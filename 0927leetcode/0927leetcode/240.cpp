#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix2(vector<vector<int>>& matrix, int target)
{
    int i = 0, j = matrix[0].size() - 1;
    while (i < matrix.size() && j >= 0){
        int tmpi = i, tmpj = j;
        if (matrix[i][j] < target)
            tmpi++;
        else if (matrix[i][j]>target)
            tmpj--;
        else
            return true;
        i = tmpi;
        j = tmpj;
    }
    return false;
}

//int main()
//{
//    int target;
//    cin >> target;
//    vector<vector<int>> matrix = { 
//        { 1, 4, 7, 11, 15 },
//        { 2, 5, 8, 12, 19 },
//        { 3, 6, 9, 16, 22 },
//        { 10, 13, 14, 17, 24 },
//        { 18, 21, 23, 26, 30 } };
//    cout << searchMatrix2(matrix, target) << endl;
//    system("pause");
//    return 0;
//}
