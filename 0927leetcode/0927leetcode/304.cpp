#include<iostream>
#include<vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> acc;
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        vector<int> temp;
        acc.resize(matrix.size());
        for (int i = 0; i < matrix.size(); i++){
            temp.push_back(0);
            acc[i].push_back(0);
            for (int j = 0; j < matrix[0].size(); j++){
                if (i>0){
                    temp.push_back(temp.back() + matrix[i][j]);
                    acc[i].push_back(acc[i - 1][j + 1] + temp.back());
                } else
                    acc[i].push_back(acc[i].back() + matrix[i][j]);
            }
            temp.clear();
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row1 > 0)
            return acc[row2][col2 + 1] - acc[row1 - 1][col2 + 1] - acc[row2][col1] + acc[row1 - 1][col1];
        else
            return acc[row2][col2 + 1] - acc[row2][col1];
    }
};

//int main()
//{
//    vector<vector<int>> matrix =
//    { { 3, 0, 1, 4, 2 },
//    { 5, 6, 3, 2, 1 },
//    { 1, 2, 0, 1, 5 },
//    { 4, 1, 0, 1, 7 },
//    { 1, 0, 3, 0, 5 } };
//    NumMatrix numMatrix(matrix);
//    cout << numMatrix.sumRegion(0, 1, 0, 4) << endl;
//    cout << numMatrix.sumRegion(1, 1, 2, 2) << endl;
//    cout << numMatrix.sumRegion(1, 2, 2, 4) << endl;
//    system("pause");
//    return 0;
//}