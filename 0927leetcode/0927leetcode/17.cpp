#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

void dfs(vector<string>& res,string digits,string tmp,int index,map<int,string> dic)
{
    if (tmp.size() == digits.size()){
        res.push_back(tmp);
        return;
    }
    string cur = dic[digits[index] - '0'];
    for (int i = 0; i < cur.size(); i++){
        tmp += cur[i];
        dfs(res, digits, tmp, index + 1, dic);
        tmp.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    map<int, string> dic;
    dic[0] = "";
    dic[1] = "";
    dic[2] = "abc";
    dic[3] = "def";
    dic[4] = "ghi";
    dic[5] = "jkl";
    dic[6] = "mno";
    dic[7] = "pqrs";
    dic[8] = "tuv";
    dic[9] = "wxyz";
    vector<string> res;
    if (digits.size() == 0)
        return res;

    string tmp;
    dfs(res, digits, tmp, 0, dic);
    return res;
}

//int main()
//{
//    string digits = "";
//    vector<string> res = letterCombinations(digits);
//    return 0;
//}