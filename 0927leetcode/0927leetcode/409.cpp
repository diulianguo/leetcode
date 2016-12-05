#include<iostream>
#include<vector>
#include<map>
using namespace std;

int longestPalindrome(string s)
{
    int n = s.length();
    map<char,int> dic;
    for (int i = 0; i < n; i++){
        dic[s[i]]++;
    }
    int sing = 0, even = 0, odd = 0;
    for (auto it = dic.begin(); it != dic.end(); it++){
        if (it->second == 1){
            sing = 1;
        } else if (it->second && it->second % 2 == 0){
            even += it->second;
        } else if (it->second % 2){
            odd += it->second - 1;
        }
    }
    if (sing==0 && odd)
        odd++;
    return sing + even + odd;
}

//int main()
//{
//    string s = "ccaaa";
//    cout << longestPalindrome(s);
//    system("pause");
//    return 0;
//}