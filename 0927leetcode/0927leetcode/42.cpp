#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height)
{
    int max = 0, index = 0;
    int n = height.size();
    if (n == 0)
        return 0;
    for (int i = 0; i < n; i++){
        if (height[i]>max){
            max = height[i];
            index = i;
        }
    }
    int root = height[0];
    int area = 0;
    for (int i = 1; i < index; i++){
        if (height[i]>root){
            root = height[i];
        } else{
            area += root - height[i];
        }
    }
    root = height[n - 1];
    for (int i = n - 2; i > index; i--){
        if (height[i] > root){
            root = height[i];
        } else{
            area += root - height[i];
        }
    }
    return area;
}

//int main()
//{
//    vector<int> height = { };
//    cout << trap(height);
//    system("pause");
//    return 0;
//}