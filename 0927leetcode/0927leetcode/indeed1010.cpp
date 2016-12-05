#include<iostream>
#include<string>
#include<vector>
using namespace std;

//string res = "CODEFESTIVAL2016";
//
//int minOper(string s)
//{
//    int i = 0;
//    int num = 0;
//    while (i < s.length()){
//        if (res[i] != s[i])
//            num++;
//        i++;
//    }
//    return num;
//}
//
//int main()
//{
//    string s;
//    cin >> s;
//    cout << minOper(s);
//    system("pause");
//    return 0;
//}

//vector<bool> passed(vector<bool>& isPassed,string s, int a, int b)
//{
//    int i = 0;
//    int num = 0;
//    int overseas = 0;
//    while (i < s.length()){
//        if (s[i] == 'a' && num < (a + b)){
//            isPassed[i] = true;
//            num++;
//        }
//        if (s[i] == 'b'){
//            overseas++;
//            if (overseas <= b && num < (a + b)){
//                isPassed[i] = true;
//                num++;
//            }
//        }
//        i++;
//    }
//    return isPassed;
//}
//
//int main()
//{
//    int n, a, b;
//    cin >> n >> a >> b;
//    string s;
//    cin >> s;
//    vector<bool> isPassed(n,false);
//    isPassed = passed(isPassed, s, a, b);
//    for (int i = 0; i < isPassed.size(); i++){
//        if (isPassed[i] == true)
//            cout << "Yes" << endl;
//        else
//            cout << "No" << endl;
//    }
//    system("pause");
//    return 0;
//}

//bool isOverall(int i, int j,int w,int h)
//{
//    vector<vector<int>> neigh = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };
//    for (int k = 0; k < neigh.size(); k++){
//        int x = i + neigh[k][0];
//        int y = j + neigh[k][1];
//        if (x >= 0 && x <= w && y >= 0 && y <= h){
//
//        }
//    }
//}
//
//int mincost(vector<vector<int>> cost, int w, int h)
//{
//    int pay = 0;
//    int houses = (w + 1)*(h + 1);
//    vector<vector<bool>> connect(houses, vector<bool>(houses, 0));
//    for (int i = 0; i < houses; i++){
//        connect[i][i] = 1;
//    }
//    for (int i = 0; i <= w; i++){
//        for (int j = 0; j <= h; j++){
//            vis[]
//            pay+=
//        }
//    }
//}