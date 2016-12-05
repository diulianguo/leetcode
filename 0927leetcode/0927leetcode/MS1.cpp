#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef long long ll;

bool isOdd(ll x)
{
    int x0 = x % 10;
    if (x0 % 2)
        return true;
    else
        return false;
}

//int main()
//{
//    int n;
//    cin >> n;
//    stack<ll> p;
//    int temp;
//    for (int i = 0; i < n; i++){
//        cin >> temp;
//        if (p.empty()){
//            p.push(temp);
//        } else{
//            int top = p.top();
//            if (isOdd(top) ^ isOdd(temp)){
//                p.pop();
//            } else{
//                p.push(temp);
//            }
//        }
//    }
//    cout << p.size() << endl;
//    system("pause");
//    return 0;
//}