#include<iostream>
#include<string>
#include<vector>
using namespace std;

int maxProduct(vector<string>& words)
{
    int n = words.size();
    vector<int> letters(n);
    int  temp = 0;
    for (int i = 0; i < n; i++){
        temp = 0;
        for (int j = 0; j < words[i].size(); j++){
            temp |= (1 << (words[i][j] - 'a'));
        }
        letters[i] = temp;
    }
    int max = 0, pro = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if ((letters[i] & letters[j]) == 0){
                pro = words[i].size()*words[j].size();
                if (pro>max)
                    max = pro;
            }
        }
    }
    return max;
}

//int main()
//{
//    vector<string> words = { "a", "ab", "abc", "d", "cd", "bcd", "abcd" };
//    cout << maxProduct(words);
//    system("pause");
//    return 0;
//}