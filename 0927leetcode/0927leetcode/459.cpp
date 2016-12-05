#include<iostream>
#include<string>
using namespace std;

bool ifTemp(string str, int step)
{
    string temp;
    int i;
    for (i = 0; i < step; i++)
        temp += str[i];
    while (i < str.size()){
        string cur;
        int next = i + step;
        while (i < next){
            cur += str[i];
            i++;
        }
        if (cur != temp)
            return false;
    }
    return true;
}

bool repeatedSubstringPattern(string str)
{
    int n = str.size();
    for (int step = 1; step <= n / 2; step++){
        if (str.size()%step==0 && ifTemp(str,step))
            return true;
    }
    return false;
}

//int main()
//{
//    string str = "aba";
//    cout << repeatedSubstringPattern(str) << endl;
//    return 0;
//}