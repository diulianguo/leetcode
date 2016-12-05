#include<iostream>
using namespace std;

int KindNum(char a)
{
    bool letter = (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
    bool number = (a >= '0' && a <= '9');
    if (letter)
        return 0;
    else
        return 1;
}

bool isPalindrome(string s)
{
    if (s.size() == 0)
        return true;

    string word;
    for (int i = 0; i < s.size(); i++){
        bool letter = (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9');
        if (letter)
            word += s[i];
    }
    int i = 0, j = word.size()-1;
    while (i < j){
        if (word[i] == word[j] || (abs(word[i] - word[j]) == abs('A' - 'a') && KindNum(word[i]) == KindNum(word[j]))){
            i++;
            j--;
        } else
            return false;
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal : Panama";
    cout << isPalindrome(s) << endl;
    return 0;
}
