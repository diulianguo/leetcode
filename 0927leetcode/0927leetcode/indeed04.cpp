#include<iostream>
#include<iomanip>
using namespace std;

#define S 100010
double ans[S];
double sum[S];
//int main()
//{
//    int N;
//    cin >> N;
//    ans[1] = 1;
//    sum[1] = 1;
//    for (int i = 2; i <= N; i++) {
//        ans[i] = 1 + (sum[i - 2] * 2) / i;
//        sum[i] = sum[i - 1] + ans[i];
//    }
//    cout << setiosflags(ios::fixed);
//    cout << setprecision(10) << ans[N];
//    return 0;
//}