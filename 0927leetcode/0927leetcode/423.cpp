#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

string originalDigits(string s)
{
    map<char, int> dic;
    for (int i = 0; i < s.size(); i++){
        if (dic.count(s[i])>0)
            dic[s[i]]++;
        else
            dic[s[i]] = 1;
    }
    vector<int> num;
    //0,2,4,6,8
    while (dic['z']){
        dic['z']--;
        dic['e']--;
        dic['r']--;
        dic['o']--;
        num.push_back(0);
    }
    while (dic['w']){
        dic['t']--;
        dic['w']--;
        dic['o']--;
        num.push_back(2);
    }
    while (dic['u']){
        dic['f']--;
        dic['o']--;
        dic['u']--;
        dic['r']--;
        num.push_back(4);
    }
    while (dic['x']){
        dic['s']--;
        dic['i']--;
        dic['x']--;
        num.push_back(6);
    }
    while (dic['g']){
        dic['e']--;
        dic['i']--;
        dic['g']--;
        dic['h']--;
        dic['t']--;
        num.push_back(8);
    }
    //1,3,5,7
    while (dic['o']){
        dic['o']--;
        dic['n']--;
        dic['e']--;
        num.push_back(1);
    }
    while (dic['t']){
        dic['t']--;
        dic['h']--;
        dic['r']--;
        dic['e']--;
        dic['e']--;
        num.push_back(3);
    }
    while (dic['f']){
        dic['f']--;
        dic['i']--;
        dic['v']--;
        dic['e']--;
        num.push_back(5);
    }
    while (dic['s']){
        dic['s']--;
        dic['e'] -= 2;
        dic['v']--;
        dic['n']--;
        num.push_back(7);
    }
    //9
    while (dic['n']){
        dic['n'] -= 2;
        dic['i']--;
        dic['e']--;
        num.push_back(9);
    }
    sort(num.begin(), num.end());
    int i = 0;
    string res;
    while (i < num.size()){
        res += to_string(num[i]);
        i++;
    }
    return res;
}

//int main()
//{
//    string t = "owoztneoer";
//    cout << originalDigits(t) << endl;
//    return 0;
//}