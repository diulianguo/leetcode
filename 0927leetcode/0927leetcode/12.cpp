#include<iostream>
#include<string>
#include<map>
using namespace std;

//string intToRoman(int num)
//{
//    string res;
//    int numbers[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
//    string roman[13] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
//    for (int i = 12; i >=0; i--){
//        if (num<numbers[i])
//            continue;
//        while (num >= numbers[i]){
//            num -= numbers[i];
//            res += roman[i];
//        }
//    }
//    return res;
//}

string intToRoman(int num)
{
    string res = "";
    char roman[] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
    int value[] = { 1000, 500, 100, 50, 10, 5, 1 };

    for (int n = 0; n < 7; n += 2) {
        int x = num / value[n];
        if (x < 4) {
            for (int i = 1; i <= x; ++i) res += roman[n];
        } else if (x == 4) 
            res = res + roman[n] + roman[n - 1];
        else if (x > 4 && x < 9) {
            res += roman[n - 1];
            for (int i = 6; i <= x; ++i) res += roman[n];
        } else if (x == 9) 
            res = res + roman[n] + roman[n - 2];
        num %= value[n];
    }
    return res;
}

int romanToInt(string s)
{
    int num = 0;

    map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    for (int i = 0; i < s.size()-1; i++){
        int j = i + 1;
        if (s[j]>s[i]){
            num -= roman[s[i]];
        } else
            num += roman[s[i]];
    }
    return num;
}

//int main()
//{
//    string s;
//    cin >> s;
//    //cout << intToRoman(num) << endl;
//    cout << romanToInt(s);
//    system("pause");
//    return 0;
//}