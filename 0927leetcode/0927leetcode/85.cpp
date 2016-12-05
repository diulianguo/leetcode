#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<math.h>
using namespace std;
extern int largestRectangleArea(vector<int>& heights);

//int largestRectangleArea(vector<int>& heights)
//{
//    if (heights.size() == 0)
//        return 0;
//    int width = 1, area = 0, maxarea = 0;
//    int count = 0, root;
//    stack<int> harray;
//    for (int i = 0; i < heights.size(); i++){
//        if (harray.empty() || heights[i] >= harray.top()){
//            harray.push(heights[i]);
//        } else{
//            count = 0;
//            while (!harray.empty() && heights[i] < harray.top()){
//                root = harray.top();
//                harray.pop();
//                count++;
//                maxarea = max(maxarea, root*count);
//            }
//            for (int j = 0; j < count + 1; j++){
//                harray.push(heights[i]);
//            }
//        }
//    }
//    count = 0;
//    while (!harray.empty()){
//        count++;
//        root = harray.top();
//        harray.pop();
//        maxarea = max(maxarea, root*count);
//    }
//    return maxarea;
//}

int maximalRectangle(vector<vector<char>>& matrix)
{
    //从每一行开始，假设以该行为底画直方图，即转化为求该直方图的最大矩形面积
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return 0;
    int height = matrix.size();
    int width = matrix[0].size();
    int count = 0;
    vector<vector<int>> heights(height, vector<int>(width));
    for (int j = 0; j < width; j++){
        for (int k = 0; k < height; k++){
            if (matrix[k][j] == '1'){
                count = 1;
                int i = k + 1;
                while (i < height && matrix[i][j] == '1'){
                    count++;
                    i++;
                }
                heights[k][j] = count;
            } else{
                count = 0;
                continue;
            }
        }
    }
    int maxarea = 0;
    for (int i = 0; i < height; i++){
        maxarea = max(maxarea, largestRectangleArea(heights[i]));
    }
    return maxarea;
}

//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<vector<char>> matrix(n, vector<char>(m));
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < m; j++){
//            cin >> matrix[i][j];
//        }
//    }
//    cout << maximalRectangle(matrix);
//    system("pause");
//    return 0;
//}