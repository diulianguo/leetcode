#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

int minCut(string s)
{
    bool **dp = new bool*[s.size()];
    for (int i = 0; i < s.size(); i++){
        dp[i] = new bool[s.size()];
    }
    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < s.size(); j++){
            dp[i][j] = 0;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--){
        for (int j = i; j < s.size(); j++){
            if (i == j)
                dp[i][j] = 1;
            else{
                if (s[i] == s[j]){
                    if (j == i + 1 || dp[i + 1][j - 1])
                        dp[i][j] = 1;
                } else
                    dp[i][j] = 0;
            }
        }
    }

    int *count = new int[s.size() + 1];
    for (int i = 0; i < s.size(); i++)
        count[i] = INT_MAX;
    count[s.size()] = 0;
    for (int i = s.size() - 1; i >= 0; i--){
        for (int j = i; j <s.size(); j++){
            if (dp[i][j]){
                count[i] = min(count[i], count[j + 1] + 1);
            }
        }
    }
    return count[0] - 1;
}

//int main()
//{
//    string s = "aaab";
//    cout << minCut(s) << endl;
//    return 0;
//}