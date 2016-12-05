#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int maxProduct(vector<int>& nums)
{
    int mintemp = nums[0];
    int maxtemp = nums[0];
    int maxPro = INT_MIN;
    for (int i = 1; i < nums.size(); i++){
        int temp = mintemp;
        mintemp = min(min(mintemp * nums[i], nums[i]), maxtemp*nums[i]);
        maxtemp = max(max(maxtemp*nums[i], nums[i]), temp*nums[i]);
        maxPro = max(maxtemp, maxPro);
    }
    return maxPro;
}

//int main()
//{
//    vector<int> array = { -2, 3, -4 };
//    cout << maxProduct(array) << endl;
//    system("pause");
//    return 0;
//}