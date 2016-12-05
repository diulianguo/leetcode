#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPali(string words, int begin, int end)
{
    while (begin < end){
        if (words[begin] != words[end])
            return false;
        begin++;
        end--;
    }
    return true;
}


string longestPalindrome(string s)
{
    /*int n = s.size();
    for (int len = n; len >= 0; len--){
        for (int i = 0; i < n; i++){
            if (i + len <= n && isPali(s, i, i + len - 1))
                return s.substr(i, len);
        }
    }
    return "";*/
    int start = 0;
    bool **flag = new bool* [s.size()];
    for (int i = 0; i < s.size(); i++){
        flag[i] = new bool[s.size()];
    }
    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < s.size(); j++){
            if (i >= j)
                flag[i][j] = true;
            else
                flag[i][j] = false;
        }
    }
    int max = 1;
    for (int j = 1; j < s.size(); j++){
        for (int i = 0; i < j; i++){
            if (s[i] == s[j]){
                flag[i][j] = flag[i + 1][j - 1];
                if (flag[i][j] && j - i + 1>max){
                    max = j - i + 1;
                    start = i;
                }
            } else
                flag[i][j] = false;
        }
    }
    return s.substr(start, max);
}

//int main()
//{
//    string s;
//    cin >> s;
//    cout << longestPalindrome(s) << endl;
//    system("pause");
//    return 0;
//}