#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxArea(vector<int>& height)
{
    int maxArea = 0, area = 0;
    /*for (int i = 0; i < height.size(); i++){
        for (int j = i + 1; j < height.size(); j++){
            if (height[i]>0 && height[j]>0){
                area = min(height[i], height[j])*(j - i);
            } else
                area = 0;
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;*/
    if (height.size() < 2)
        return 0;
    int i = 0, j = height.size() - 1;
    while (i < j){
        area = min(height[i], height[j])*(j - i);
        maxArea = max(area, maxArea);
        if (height[i] < height[j])
            i++;
        else if (height[i]>height[j])
            j--;
        else{
            i++;
            j--;
        }
    }
    return maxArea;
}

//int main()
//{
//    vector<int> height = { 2, 3 };
//    cout << maxArea(height) << endl;
//    return 0;
//}