#include<iostream>
#include<string>
using namespace std;

string delra(string s)
{
    string res = s;
    int i = 0, j = i + 1;
    while (i < res.size() && j < res.size()){
        if (res[i] == 'r' && res[j] == 'a'){
            auto it = res.begin() + i;
            res.erase(it);
            res.erase(it);
        } else{
            i++;
            j++;
        }
    }
    return res;
}

//int main()
//{
//    string ori;
//    cin >> ori;
//    cout << delra(ori) << endl;
//    system("pause");
//    return 0;
//}