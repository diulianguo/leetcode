#include<iostream>
#include<string>
using namespace std;

int strStr(string haystack, string needle)
{
    if (haystack.size() < needle.size())
        return -1;
    if (needle.size() == 0)
        return 0;

    int len = needle.size();
    for (int i = 0; i <= haystack.size() - len; i++){
        if (haystack.substr(i, len) == needle)
            return i;
    }
    return -1;
}

//int main()
//{
//    string haystack ="a";
//    string needle = "a";
//    cout << strStr(haystack, needle) << endl;
//    return 0;
//}