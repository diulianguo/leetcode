#include<iostream>
#include<vector>
#include<string>
using namespace std;

string removeKdigits(string num, int k)
{
    string res;
    if (k > num.size())
        return res;
    if (k == num.size())
        return "0";
    int len = num.size() - k;
    for (int i = 0; i < num.size(); i++){
        while (k && res.size() && res.back()>num[i]){
            res.pop_back();
            k--;
        }
        res.push_back(num[i]);
    }
    res.resize(len);
    while (!res.empty() && res[0] == '0')
        res.erase(res.begin());
    return res.empty() ? "0" : res;
}

//int main()
//{
//    string s;
//    cin >> s;
//    int k;
//    cin >> k;
//    cout << removeKdigits(s, k);
//    system("pause");
//    return 0;
//}