#include<iostream>
#include<string>
using namespace std;


string convertToTitle(int n)
{
    int tmp = n;
    string res;
    while (tmp){
        res += 'A' + (tmp - 1) % 26;
        tmp = (tmp - 1) / 26;
    }
    reverse(res.begin(), res.end());
    return res;
}

//int main()
//{
//    int n = 26;
//    cout << convertToTitle(n) << endl;
//    return 0;
//}