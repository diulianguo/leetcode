#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

const int NMAX = 3402;
const int MAX = 12880;
struct charm {
    int w;
    int d;
};
charm array[NMAX];
int n;
int dp[MAX];

//贪心法时间超限
//void DP(int m)
//{
//    int max = 1;
//    int index = 0;
//    if (n == 0 || m == 0)
//        return;
//    for (int j = 0; j < n; j++){
//        if (dp[j].d>max && dp[j].w < m){
//            max = dp[j].d;
//            index = j;
//        }
//    }
//    maxD += dp[index].d;
//    int w = dp[index].w;
//    dp[index].w = dp[index].d = 0;
//    DP(m - w);
//}

void DP(int m)
{
    for (int i = 0; i < n; i++){
        for (int j = m; j>=array[i].w; j--){
            dp[j] = max(dp[j], dp[j - array[i].w] + array[i].d);
        }
    }
}

//int main()
//{
//    int m;
//    while (cin >> n >> m && !(n > 3402 || m > 12880)){
//        for (int i = 0; i < n; i++){
//            cin >> array[i].w >> array[i].d;
//        }
//        memset(dp, 0, sizeof(dp));
//        DP(m);
//        cout << dp[m] << endl;
//    }
//    system("pause");
//    return 0;
//}
