//#include <iostream>
//#include<vector>
//#include<algorithm>
//#include<set>
//#include<string.h>
//#define N 6
//#define MAX_INT 999999
//using namespace std;
//
//// �ߵĽṹ��
//typedef struct {
//    int x;
//    int y;
//    int cost;
//} Tpath;
//
////��ͨͼ���ڽӾ���
//void gprim();
//
////main
//int main(int argc, char** argv)
//{
//    gprim();
//
//    return 0;
//}
//����prim�㷨
//void gprim()
//{
//    int w, h;
//    cin >> w >> h;
//    int houses = (w + 1)*(h + 1);
//    vector<vector<int>> g(houses, vector<int>(houses, -1));
//    int costi;
//    for (int i = 0; i <= w; i++){
//        cin >> costi;
//        for (int j = 0; j <= h; j++){
//            if (j != i)
//                g[i][j] = costi;
//        }
//    }
//    for (int i = 0; i <= h; i++){
//        cin >> costi;
//        for (int j = 0; j <= w; j++){
//            if (j != i)
//                g[i][j] = costi;
//        }
//    }
//    vector<Tpath> p;   //��¼��
//    vector<int>u;      //����S
//    u.push_back(0);    //��V0���뵽S��
//    int node1 = 0, node2 = 0, cost = 0;
//    int i = 0;
//    vector<int>::iterator  it;
//    for (u.size(); u.size() < houses;){
//        // get the lowcost path
//        node1 = -1;
//        node2 = -1;
//        cost = MAX_INT;
//        for (it = u.begin(); it != u.end(); it++){      // ��V-S��������Ѱ�ҵ���S������lowcost�Ľڵ�Ͷ�Ӧ�ıߡ������¼����Ϊ Ϊcost,node1,node2
//            int k = (*it);
//            for (i = 0; i < houses; i++){
//                if (i == (*it))continue;
//                if (g[k][i] >= 0 && (find(u.begin(), u.end(), i) == u.end()) && g[k][i] < cost){
//                    node1 = k;
//                    node2 = i;
//                    cost = g[k][i];
//                }
//            }
//        }
//
//        // ���ýڵ���뵽S�� ����¼��·��path
//        Tpath path;
//        path.cost = cost;
//        path.x = node1;
//        path.y = node2;
//        p.push_back(path);
//        u.push_back(node2);
//    }
//    //���
//    vector<Tpath>::iterator itO;
//    for (itO = p.begin(); itO != p.end(); itO++){
//        printf("(%d ,%d) cost: %d\n", itO->x + 1, itO->y + 1, itO->cost);
//    }
//}
#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string.h>
#define MAX_INT 999999
using namespace std;

// �ߵĽṹ��
typedef struct {
    int x;
    int y;
    int cost;
} Tpath;

void gprim();

//main
//int main(int argc, char** argv)
//{
//    gprim();
//
//    return 0;
//}
//����prim�㷨
void gprim()
{
    int w, h;
    cin >> w >> h;
    int houses = (w + 1)*(h + 1);
    vector<vector<int>> g(houses, vector<int>(houses, -1));
    int costi;
    for (int i = 0; i < w; i++){
        cin >> costi;
        for (int j = i*(h+1); j < i*(h+1) + h + 1; j++){
            int k = j + h + 1;
            if (k < houses)
                g[j][k] = costi;
        }
    }
    for (int i = 0; i < h; i++){
        cin >> costi;
        for (int j = i ; j < houses-h; j+=h+1){
            int k = j  + 1;
            if (k < houses)
                g[j][k] = costi;
        }
    }
    vector<Tpath> p;   //��¼��
    vector<int>u;      //����S
    u.push_back(0);    //��V0���뵽S��
    int node1 = 0, node2 = 0, cost = 0;
    int i = 0;
    vector<int>::iterator  it;
    for (u.size(); u.size() < houses;){
        // get the lowcost path
        node1 = -1;
        node2 = -1;
        cost = MAX_INT;
        for (it = u.begin(); it != u.end(); it++){      // ��V-S��������Ѱ�ҵ���S������lowcost�Ľڵ�Ͷ�Ӧ�ıߡ������¼����Ϊ Ϊcost,node1,node2
            int k = (*it);
            for (i = 0; i < houses; i++){
                if (i == (*it))continue;
                if (g[k][i] >= 0 && (find(u.begin(), u.end(), i) == u.end()) && g[k][i] < cost){
                    node1 = k;
                    node2 = i;
                    cost = g[k][i];
                }
            }
        }

        // ���ýڵ���뵽S�� ����¼��·��path
        Tpath path;
        path.cost = cost;
        path.x = node1;
        path.y = node2;
        p.push_back(path);
        u.push_back(node2);
    }
    //���
    vector<Tpath>::iterator itO;
    int mincost = 0;
    for (itO = p.begin(); itO != p.end(); itO++){
        //printf("(%d ,%d) cost: %d\n", itO->x + 1, itO->y + 1, itO->cost);
        mincost += itO->cost;
    }
    printf("%d", mincost);
    system("pause");
}