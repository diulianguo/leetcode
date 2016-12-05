#include<iostream>
#include<string>
using namespace std;

string shortestPalindrome(string s)
{
    int n = s.size();
    string t, res;
    for (int i = n-1; i >=0; i--){
        t += s[i];
    }
    for (int i = 0; i < t.size(); i++){
        if (t.substr(i, n - i) == s.substr(0, n - i)){
            break;
        } else
            res += t[i];
    }
    return res + s;
}

//int main()
//{
//    string s = "abcd";
//    cout << shortestPalindrome(s) << endl;
//    return 0;
//}