#include<iostream>
#include<vector>
using namespace std;

int lastRemaining(int n)
{
    int start = 1, rest = n, step = 2;
    bool left = true;
    while (rest > 1){
        rest /= 2;
        if (left)
            start = start + step*rest - step / 2;
        else
            start = start - step*rest + step / 2;
        left = !left;
        step *= 2;
    }
    return start;
}

//int main()
//{
//    int n;
//    while (cin >> n){
//        cout << lastRemaining(n) << endl;
//    }
//}