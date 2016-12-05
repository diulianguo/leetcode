#include<iostream>
#include<vector>
#include<string>
using namespace std;

void dfs(int start, string s, bool** dp, vector<string> &tmp,vector<vector<string>> &res)
{
    if (start == s.size()){
        res.push_back(tmp);
        return;
    }
    for (int i = start; i < s.size(); i++){
        if (dp[start][i]){
            tmp.push_back(s.substr(start, i - start + 1));
            dfs(i + 1, s, dp, tmp, res);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    bool **dp = new bool*[s.size()];
    for (int i = 0; i < s.size(); i++){
        dp[i] = new bool[s.size()];
    }
    //dp[i][j]表示s[i...j]是不是回文串,这里原来有问题的是我是从前往后求dp，但是求dp[i][j]需要用到后面的dp[i+1][j-1]
    /*for (int i = 0; i < s.size(); i++){
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
    }*/
    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < s.size(); j++){
            dp[i][j] = 0;
        }
    }

    for (int i = s.size()-1; i >=0; i--){
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

    vector<vector<string>> res;
    vector<string> tmp;
    dfs(0, s, dp, tmp, res);
    return res;
}

//int minCut(string s)
//{
//    bool **dp = new bool*[s.size()];
//    for (int i = 0; i < s.size(); i++){
//        dp[i] = new bool[s.size()];
//    }
//    for (int i = 0; i < s.size(); i++){
//        for (int j = 0; j < s.size(); j++){
//            dp[i][j] = 0;
//        }
//    }
//    for (int i = s.size() - 1; i >= 0; i--){
//        for (int j = i; j < s.size(); j++){
//            if (i == j)
//                dp[i][j] = 1;
//            else{
//                if (s[i] == s[j]){
//                    if (j == i + 1 || dp[i + 1][j - 1])
//                        dp[i][j] = 1;
//                } else
//                    dp[i][j] = 0;
//            }
//        }
//    }
//
//    vector<vector<string>> res;
//    vector<string> tmp;
//    dfs(0, s, dp, tmp, res);
//    int mincut = res[0].size();
//    for (int i = 1; i < res.size(); i++){
//        if (res[i].size() < mincut)
//            mincut = res[i].size();
//    }
//    return mincut - 1;
//}

//int main()
//{
//    string s = "abbab";
//    vector<vector<string>> res = partition(s);
//    return 0;
//}