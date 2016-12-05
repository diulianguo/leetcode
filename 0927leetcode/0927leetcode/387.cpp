#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int firstUniqChar(string s)
{
    vector<int> res;
    map<char, int> dic;
    for (int i = 0; i < s.size(); i++){
        dic[s[i]]++;
    }
    for (int i = 0; i < s.size(); i++){
        if (dic[s[i]] == 1)
            return i;
    }
    return -1;
}

//int main()
//{
//    string s = "loveleetcode";
//    cout << firstUniqChar(s);
//    system("pause");
//    return 0;
//}