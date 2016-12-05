#include<iostream>
#include<string>
using namespace std;

int compareVersion(string version1, string version2)
{
    int i = 0, j = 0;
    while (i < version1.size() || j < version2.size()){
        int a = 0, b = 0;
        while (i < version1.size() && version1[i] != '.'){
            a = a * 10 + version1[i] - '0';
            i++;
        }
        i++;
        while (j < version2.size() && version2[j] != '.'){
            b = b * 10 + version2[j] - '0';
            j++;
        }
        j++;
        if (a < b)
            return -1;
        else if (a>b)
            return 1;
    }
    return 0;
}

//int main()
//{
//    string version1 = "1";
//    string version2 = "1.0";
//    cout << compareVersion(version1, version2);
//    system("pause");
//    return 0;
//}