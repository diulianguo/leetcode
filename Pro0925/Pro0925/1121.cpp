#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
const int MAX = 1000;
vector<vector<ll>> s(MAX, vector<ll>(MAX));

//s[i][j]表示数列的和为i，拆成的数列中所有数均大于等于j的数列个数
//s[i][j]=s[i-2*j][j]+s[i][j+1]分成两部分，一部分是最所有数都大于等于j的，另一部分是所有数都大于等于j+1的
void init(vector<vector<ll>> &s)
{
    for (int i = 1; i < MAX; i++)
        s[0][i] = 1;

    for (int i = 1; i < MAX; i++){
        for (int j = i / 2 + 1; j < i+1; j++){
            s[i][j] = 1;
        }
    }

    for (int i = 2; i < MAX; i++){
        for (int j = i / 2; j >0; j--){
            s[i][j] = s[i - 2 * j][j] + s[i][j + 1];
        }
    }
}


//int main()
//{
//    int n;
//    for (int i = 0; i < MAX; i++){
//        for (int j = 0; j < MAX; j++){
//            s[i][j] = 0;
//        }
//    }
//    init(s);
//    while (cin >> n && n>0 && n<250){
//        cout << n <<" "<< s[n][1] << endl;
//    }
//    system("pause");
//    return 0;
//}