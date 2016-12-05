#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int lengthOfLIS(vector<int>& nums)
{
    //int maxlen = 0;
    //for (int i = 0; i < nums.size(); i++){
    //    vector<int> insub;
    //    insub.push_back(nums[i]);
    //    for (int j = i + 1; j < nums.size(); j++){
    //        if (nums[j]>insub.back())
    //            insub.push_back(nums[j]);
    //    }
    //    int len = insub.size();
    //    maxlen = max(maxlen,len);
    //}
    //return maxlen;
    if (nums.size() == 0)
        return 0;
    vector<int> len(nums.size());//�ֱ���nums[0]...nums[i]Ϊ���Ԫ�ص����еĳ���
    vector<int> pre(nums.size());//ÿ��������еĵ����ڶ���Ԫ���������е�����
    for (int i = 0; i < nums.size(); i++){
        len[i] = 1;
        pre[i] = i;
    }
    for (int i = 1; i < nums.size(); i++){
        for (int j = 0; j < i; j++){
            if (nums[j]<nums[i] && len[j] + 1>len[i]){
                len[i] = len[j] + 1;
                pre[i] = j;
            }
        }
    }
    int maxlen = 0;
    for (int i = 0; i < len.size(); i++){
        maxlen = max(maxlen, len[i]);
    }
    return maxlen;
}

//int main()
//{
//    vector<int> nums = { 2, 4, - 2, -3 };
//    cout << lengthOfLIS(nums) << endl;
//    system("pause");
//    return 0;
//}