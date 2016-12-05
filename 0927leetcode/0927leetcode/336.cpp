#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;

bool isValidPali(string words, int begin, int end)
{
    while (begin < end){
        if (words[begin] != words[end])
            return false;
        begin++;
        end--;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words)
{
    map<string, int> m;
    set<int> t;
    for (int i = 0; i < words.size(); i++){
        string s = words[i];
        m[words[i]] = i;
        t.insert(s.size());
    }
    vector<vector<int>> res;
    for (int i = 0; i < words.size(); i++){
        string s = words[i];
        reverse(s.begin(), s.end());
        if (m.count(s) && m[s] != i){//count()是返回key出现的次数，在map里，key只能是0和1
            res.push_back({ i, m[s] });
        }

        int len = s.size();
        for (auto it = t.begin(); it != t.find(len); it++){
            int d = *it;
            if (isValidPali(s, 0, len - d - 1) && m.count(s.substr(len - d, d)))
                res.push_back({ i, m[s.substr(len - d, d)] });
            if (isValidPali(s, d, len - 1) && m.count(s.substr(0, d)))
                res.push_back({ m[s.substr(0, d)], i });
        }
    }
    return res;
}

//int main()
//{
//    vector<string> words = { "abcd", "dcba", "lls", "s", "sssll" };
//    vector<vector<int>> res = palindromePairs(words);
//    return 0;
//}