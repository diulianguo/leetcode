#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

void reverseWords(string &s)
{
    stack<char> words;
    stack<char> sentence;
    for (int i = 0; i < s.size(); i++){
        if (s[i] != ' ')
            words.push(s[i]);
        else{
            if (!words.empty()){
                if (!sentence.empty()){
                    sentence.push(' ');
                }
                while (!words.empty()){
                    char top = words.top();
                    words.pop();
                    sentence.push(top);
                }
            }
        }
    }
    if (!words.empty()){
        if (!sentence.empty()){
            sentence.push(' ');
        }
        while (!words.empty()){
            sentence.push(words.top());
            words.pop();
        }
    }
    s.clear();
    while (!sentence.empty()){
        s.push_back(sentence.top());
        sentence.pop();
    }
}

//int main()
//{
//    string s = "the sky is blue";
//    reverseWords(s);
//    cout << s;
//    system("pause");
//    return 0;
//}