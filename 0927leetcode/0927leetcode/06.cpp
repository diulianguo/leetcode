#include<iostream>
#include<string>
#include<vector>
using namespace std;

string convert(string s, int numRows)
{
    vector<vector<char>> zigzag(numRows, vector<char>(s.size()));
    int i = 0, j = 0, k = 0;
    if (numRows == 1)
        return s;
    while (k < s.size() && numRows >= 3){
        while (k < s.size() && i < numRows){
            zigzag[i][j] = s[k];
            i++;
            k++;
        }
        j++;
        i -= 2;
        while (k < s.size() && i > 0){
            zigzag[i][j] = s[k];
            i--;
            k++;
        }
        j++;
    }
    i = 0, j = 0, k = 0;
    while (k < s.size() && numRows == 2){
        while (k < s.size() && i < numRows){
            zigzag[i][j] = s[k];
            i++;
            k++;
        }
        j++;
        i = 0;
    }

    string res;
    for (i = 0; i < zigzag.size(); i++){
        for (j = 0; j < zigzag[i].size(); j++){
            if (zigzag[i][j] != '\0')
                res += zigzag[i][j];
        }
    }
    return res;
}

//int main()
//{
//    string s = "ABCD";
//    cout << convert(s, 4) << endl;
//    return 0;
//}