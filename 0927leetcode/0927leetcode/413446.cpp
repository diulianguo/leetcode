#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//int numberOfArithmeticSlices(vector<int>& A)
//{
//    int num = 0;
//    if (A.size() <= 2)
//        return num;
//
//    vector<vector<int>> dp(A.size(), vector<int>(A.size()));
//    for (int i = A.size() - 1; i >= 0; i--){
//        for (int j = i; j < A.size(); j++){
//            if (i == j || i==j-1)
//                dp[i][j] = 1;
//            else{
//                if (dp[i + 1][j]){
//                    if (A[i + 2] - A[i + 1] == A[i + 1] - A[i])
//                        dp[i][j] = 1;
//                }
//            }
//        }
//    }
//
//    for (int i = 0; i < A.size() - 2; i++){
//        for (int j = i + 2; j < A.size(); j++){
//            if (dp[i][j])
//                num++;
//        }
//    }
//    return num;
//}

//413
//int numberOfArithmeticSlices(vector<int>& A)
//{
//    int len = 2, num = 0;
//    for (int i = 2; i < A.size(); i++){
//        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
//            len++;
//        else{
//            if (len > 2)
//                num += (len - 1)*(len - 2) / 2;
//            len = 2;
//        }
//    }
//    if (len > 2)
//        num += (len - 1)*(len - 2) / 2;
//    return num;
//}

//446
int numberOfArithmeticSlices(vector<int>& A)
{
    //dp[i][delta]+=dp[j][delta]+1,j是0到i-1索引指向的所有数,dp[i][delta]表示以A[i]结尾，公差为delta的等差数列的切片个数
    if (A.size() == 0)
        return 0;

    vector<unordered_map<int,int>> dp(A.size());
    int num = 0;
    for (int i = 0; i < A.size(); ++i){
        for (int j = 0; j < i; ++j){
            if ((long long)A[i] - (long long)A[j] > INT_MAX || (long long)A[i] - (long long)A[j] < INT_MIN) continue;
            int dif = A[i] - A[j];
            dp[i][dif] += 1;
            if (dp[j].count(dif)>0){
                dp[i][dif] += dp[j][dif];
                num += dp[j][dif];
            }
        }
    }
    return num;
}

//int main()
//{
//    vector<int> A = { 0,2000000000,-294967296 };
//    cout << numberOfArithmeticSlices(A) << endl;
//    return 0;
//}