#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int longestValidParentheses(string s)
{
    stack<pair<int,char>> tmp;
    int length = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            tmp.push(pair<int, char>(i, s[i]));
        } else if (s[i] == ')'){
            if (!tmp.empty() && tmp.top().second== '('){
                int len = 0;
                tmp.pop();
                if (tmp.empty())
                    len = i + 1;
                else{
                    len = i - tmp.top().first;
                }
                length = max(length, len);
            } else{
                tmp.push(pair<int, char>(i, s[i]));
            }
        }
    }
    return length;
}

bool isValid(string s)
{
    stack<char> tmp;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            tmp.push(s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
            bool small = s[i] == ')' && !tmp.empty() && tmp.top() == '(';
            bool mid = s[i] == ']' && !tmp.empty() && tmp.top() == '[';
            bool large = s[i] == '}'&& !tmp.empty() && tmp.top() == '{';
            if (small || mid || large)
                tmp.pop();
            else
                tmp.push(s[i]);
        }
    }
    if (tmp.empty())
        return true;
    return false;
}

//int main()
//{
//    string s = "(())";
//    //cout << longestValidParentheses(s) << endl;
//    cout << isValid(s) << endl;
//    return 0;
//}