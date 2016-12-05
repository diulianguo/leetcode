#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string multiply(string num1, string num2)
{
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    int *res = new int[num1.size() + num2.size()];
    for (int i = 0; i < num1.size() + num2.size(); i++)
        res[i] = 0;
    for (int i = 0; i < num1.size(); i++){
        for (int j = 0; j < num2.size(); j++){
            res[i + j] += (num1[i] - '0')*(num2[j] - '0');
            res[i + j + 1] += res[i + j] / 10;
            res[i + j] %= 10;
        }
    }

    int i = num1.size() + num2.size() - 1;
    while (i>0 && res[i] == 0)
        i--;

    string result;
    while (i >= 0){
        result += to_string(res[i]);
        i--;
    }
    return result;
}

//int main()
//{
//    string num1 = "123";
//    string num2 = "24";
//    cout << multiply(num1, num2) << endl;
//    return 0;
//}