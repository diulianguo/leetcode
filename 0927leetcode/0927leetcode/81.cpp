#include<iostream>
#include<vector>
using namespace std;

bool searchDup(vector<int>& nums, int target)
{
    int n = nums.size();
    if (n == 0)
        return -1;
    if (n == 1)
        return nums[0] == target ? true : false;

    int i = 0, j = n - 1;
    //���ַ���i,j�ķ�Χ�ڲ���target
    while (i < j){
        if (j - i == 1){
            if (nums[i] == target || nums[j] == target)
                return true;
            else
                return false;
        }
        int mid = (i + j) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < nums[j]){
            //�ұ���������
            if (target>nums[mid] && target <= nums[j])
                i = mid + 1;
            else
                j = mid - 1;
        } else if (nums[mid] > nums[j]){
            //�����������
            if (target >= nums[i] && target < nums[mid])
                j = mid - 1;
            else
                i = mid + 1;
        } else{
            //�޷��ж��ı�����
            j--;
        }
    }
    if (nums[i] == target)
        return true;
    else
        return false;
}

//int main()
//{
//    vector<int> nums = { 1, 1, 3, 1 };
//    int target = 3;
//    cout << searchDup(nums, target);
//    system("pause");
//    return 0;
//}