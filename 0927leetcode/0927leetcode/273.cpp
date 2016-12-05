#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    string s;
    if (strs.size() == 0)
        return s;
    if (strs.size() == 1)
        return strs[0];
    for (int len = 0; len < strs[0].size(); len++){
        for (int i = 1; i < strs.size(); i++){
            if (len >= strs[i].length() || strs[i][len] != strs[0][len]){
                    return strs[0].substr(0, len);
            }
        }
    }
    return strs[0];
}
//
//int main()
//{
//    vector<string> strs = { "abb", "abc" };
//    cout << longestCommonPrefix(strs) << endl;
//    system("pause");
//    return 0;
//}