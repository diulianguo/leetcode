#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

void dfs(int index, int leftnum,int rightnum,int max, string& tmp, vector<string>& res)
{
    if (index == 2*max){
        res.push_back(tmp);
        return;
    }
    //先假设该位置放左括号
    if (leftnum < max){
        tmp += '(';
        dfs(index + 1, leftnum + 1, rightnum, max, tmp, res);
        tmp.pop_back();
    }
    //再假设该位置放右括号
    if (leftnum > rightnum && rightnum < max){
        tmp += ')';
        dfs(index + 1, leftnum, rightnum + 1, max, tmp, res);
        tmp.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    if (n <= 0)
        return res;

    string tmp;
    dfs(0, 0, 0, n, tmp, res);
    return res;
}

//int main()
//{
//    int n = 3;
//    vector<string> res = generateParenthesis(n);
//    return 0;
//}