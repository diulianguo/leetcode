#include<iostream>
using namespace std;

int arrangeCoins(int n)
{
    int k = 0;
    k = sqrt(n * 2.0);
    if (k*(k + 1)<=2*n)
        return k;
    return k - 1;
}

//int main()
//{
//    int n;
//    cin >> n;
//    cout << arrangeCoins(n) << endl;
//    return 0;
//}