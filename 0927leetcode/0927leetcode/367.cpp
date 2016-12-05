#include<iostream>
using namespace std;

bool isPerfectSquare(int num)
{
    /*int sum = 0;
    if (num == 1)
        return true;
    for (int i = 2; i < num; i++){
        if (num%i == 0){
            sum++;
        }
    }
    if (sum % 2)
        return true;
    return false;*/
    long left = 1, right = num;
    while (left <= right){
        int x = left + (right - left) / 2;
        if (x*x == num)
            return true;
        else{
            if (x*x > num)
                right = x - 1;
            else
                left = x + 1;
        }
    }
    return false;
}

//int main()
//{
//    int n;
//    cin >> n;
//    cout << isPerfectSquare(n);
//    system("pause");
//    return 0;
//}