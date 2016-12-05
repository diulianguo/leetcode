#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int start = 0, end = 0, longl = 0;
    vector<int> exist(256, false);
    vector<int> pos(256, 0);

    for (int i = 0; i < s.size(); i++){
        if (exist[s[i] - 'a']){
            for (int j = start; j <= pos[s[i] - 'a']; j++){
                exist[s[j] - 'a'] = false;
            }
            start = pos[s[i] - 'a'] + 1;
            exist[s[i] - 'a'] = true;
            pos[s[i] - 'a'] = i;
        } else{
            exist[s[i] - 'a'] = true;
            pos[s[i] - 'a'] = i;
            longl = max(longl, i - start + 1);
        }
    }
    return longl;
}

//int main()
//{
//    string t = "dvdf";
//    cout << lengthOfLongestSubstring(t) << endl;
//    return 0;
//}