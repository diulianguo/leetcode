#include<iostream>
using namespace std;

typedef unsigned int uint32_t;

int hammingWeight(uint32_t n)
{
    int num = 0;
    while (n){
        if (n % 2)
            num++;
        n /= 2;
    }
    return num;
}

//int main()
//{
//    uint32_t n;
//    cin >> n;
//    cout << hammingWeight(n);
//    int a = 10, k = 2, m = 1;
//    a /= SQR(k + m) / SQR(k + m);
//    cout << a;
//    system("pause");
//    return 0;
//}