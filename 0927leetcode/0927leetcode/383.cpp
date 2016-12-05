#include<iostream>
#include<string>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    int len1 = ransomNote.size();
    int len2 = magazine.size();
    int dic[26];
    memset(dic, 0, sizeof(dic));
    if (len1 > len2)
        return false;
    for (int i = 0; i < len2; i++){
        dic[magazine[i] - 'a']++;
    }
    for (int j = 0; j < len1; j++){
        if (dic[ransomNote[j] - 'a'] == 0)
            return false;
        else{
            dic[ransomNote[j] - 'a']--;
        }
    }
    return true;
}

//int main()
//{
//    string s, t;
//    cin >> s >> t;
//    cout << canConstruct(s, t);
//    system("pause");
//    return 0;
//}