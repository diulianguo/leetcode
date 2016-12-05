#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<math.h>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    if (heights.size() == 0)
        return 0;
    int width = 1, area = 0, maxarea = 0;
    int count = 0, root;
    stack<int> harray;
    for (int i = 0; i < heights.size(); i++){
        if (harray.empty() || heights[i] >= harray.top()){
            harray.push(heights[i]);
        } else{
            count = 0;
            while (!harray.empty() && heights[i] < harray.top()){
                root = harray.top();
                harray.pop();
                count++;
                maxarea = max(maxarea, root*count);
            }
            for (int j = 0; j < count + 1; j++){
                harray.push(heights[i]);
            }
        }
    }
    count = 0;
    while (!harray.empty()){
        count++;
        root = harray.top();
        harray.pop();
        maxarea = max(maxarea, root*count);
    }
    return maxarea;
}

//int main()
//{
//    vector<int> heights = { 2, 1, 2 };
//    cout << largestRectangleArea(heights);
//    system("pause");
//    return 0;
//}