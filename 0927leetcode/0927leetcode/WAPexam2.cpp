#include<iostream>
#include<queue>
using namespace std;

int s[2000];
int edge[2000][3];//每个房间的3个相邻房间分别是
int child[2000][2];
int father[2000];
int edgeNum[2000];//每个房间有多少个相邻房间，即多少个门
int ans[2000][200][3];//每个房间,M个wifi,3个孩子节点的满足点
bool used[2000];
bool constructed[2000];

//int main()
//{
//    int N, M, x, y;
//    cin >> N >> M;
//    for (int i = 1; i <= N; i++)
//        cin >> s[i];
//    for (int i = 1; i < N; i++) {
//        cin >> x >> y;
//        edgeNum[x]++; edgeNum[y]++;
//        for (int j = 0; j < 3; j++)
//        if (edge[x][j] == 0) {
//            edge[x][j] = y;
//            break;
//        }
//        for (int j = 0; j < 3; j++)
//        if (edge[y][j] == 0) {
//            edge[y][j] = x;
//            break;
//        }
//    }
//    //construct
//    queue<int> qc;
//    for (int i = 1; i <= N; i++) {
//        if (edgeNum[i] == 1) {
//            qc.push(i);
//            father[i] = i;
//            break;
//        }
//    }
//    int root = qc.front();
//    queue<int> q;
//    while (!qc.empty())
//    {
//        int fa = qc.front();
//        qc.pop();
//        constructed[fa] = true;
//        int l = 0;
//        for (int i = 0; i < 3; i++) {
//            if (edge[fa][i] == 0) break;
//            if (!constructed[edge[fa][i]]) {
//                qc.push(edge[fa][i]);
//                child[fa][l] = edge[fa][i];
//                l++;
//                father[edge[fa][i]] = fa;
//            }
//        }
//        if (l == 0) q.push(fa);
//    }
//
//    //dp
//    while (!q.empty()) {
//        int cur = q.front();
//        q.pop();
//        int childNum = father[cur] == cur ? 1 : edgeNum[cur] - 1;
//        bool allChildOk = true;
//        for (int i = 0; i < childNum; i++) {
//            if (!used[child[cur][i]]) {
//                allChildOk = false;
//                break;
//            }
//        }
//        if (!allChildOk) continue;
//        used[cur] = true;
//        if (childNum == 0) {
//            for (int j = 1; j <= M; j++) {
//                ans[cur][j][0] = 0;
//                ans[cur][j][1] = s[cur];
//                ans[cur][j][2] = 0;
//            }
//        } else if (childNum == 1) {
//            int pre = child[cur][0];
//            for (int j = 1; j <= M; j++) {
//                ans[cur][j][0] = max(ans[pre][j][1], ans[pre][j][2]);
//                ans[cur][j][1] = s[cur] + s[pre] + ans[pre][j - 1][0];
//                ans[cur][j][2] = max(ans[pre][j][1] + s[cur], ans[pre][j][2]);
//            }
//        } else {
//            int pre1 = child[cur][0];
//            int pre2 = child[cur][1];
//            for (int j = 1; j <= M; j++) {
//                for (int k = 0; k <= j; k++) {
//                    int temp = max(ans[pre1][k][1], ans[pre1][k][2]) + max(ans[pre2][j - k][1], ans[pre2][j - k][2]);
//                    if (temp > ans[cur][j][0]) ans[cur][j][0] = temp;
//                }
//                for (int k = 0; k < j; k++) {
//                    int temp = s[pre1] + s[pre2] + ans[pre1][k][0] + ans[pre2][j - 1 - k][0];
//                    if (temp > ans[cur][j][0]) ans[cur][j][0] = temp;
//                }
//                for (int k = 0; k < j; k++) {
//                    int temp = s[cur] + s[pre1] + s[pre2] + ans[pre1][k][0] + ans[pre2][j - 1 - k][0];
//                    if (temp > ans[cur][j][1]) ans[cur][j][1] = temp;
//                }
//                for (int k = 0; k <= j; k++) {
//                    int temp = ans[pre1][k][2] + ans[pre2][j - k][2];
//                    if (temp > ans[cur][j][2]) ans[cur][j][2] = temp;
//                    if (j - k >= 1) {
//                        temp = s[cur] + ans[pre1][k][2] + ans[pre2][j - k][1];
//                        if (temp > ans[cur][j][2]) ans[cur][j][2] = temp;
//                    }
//                    if (k >= 1) {
//                        temp = s[cur] + ans[pre1][k][1] + ans[pre2][j - k][2];
//                        if (temp > ans[cur][j][2]) ans[cur][j][2] = temp;
//                    }
//                    if (k >= 1 && j - k >= 1) {
//                        temp = s[cur] + ans[pre1][k][1] + ans[pre2][j - k][1];
//                        if (temp > ans[cur][j][2]) ans[cur][j][2] = temp;
//                    }
//                }
//            }
//        }
//        if (!used[father[cur]]) q.push(father[cur]);
//    }
//    cout << max(ans[root][M][1], ans[root][M][2]) << endl;
//    return 0;
//}
