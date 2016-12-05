#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string addStrings(string num1, string num2)
{
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int n = max(num1.size(), num2.size()) + 1;
    int *res = new int[n];
    for (int i = 0; i < n; i++)
        res[i] = 0;
    int i = 0;
    if (n>num1.size()){
        int add = n - num1.size();
        while (i<add){
            num1 += '0';
            i++;
        }
    }
    i = 0;
    if (n > num2.size()){
        int add = n - num2.size();
        while (i < add){
            num2 += '0';
            i++;
        }
    }

    int j = 0, carry = 0;
    while (j < n){
        res[j] = (num1[j] - '0') + (num2[j] - '0') + carry;
        carry = res[j] / 10;
        res[j] %= 10;
        j++;
    }

    j = n - 1;
    while (j > 0 && res[j] == 0)
        j--;

    string result;
    while (j >= 0){
        result += to_string(res[j]);
        j--;
    }
    return result;
}

//int main()
//{
//    string num1 = "98";
//    string num2 = "9";
//    cout << addStrings(num1, num2) << endl;
//    return 0;
//}