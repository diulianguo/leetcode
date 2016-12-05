#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

#define MAX 2147481647
#define MIN -214748364

//int minTimes(string s1, string s2)
//{
//    for (int i = 0; i < s1.length(); i++){
//        
//    }
//}
//
//int main()
//{
//    string s1, s2;
//    cin >> s1 >> s2;
//    cout << minTimes(s1, s2) << endl;
//    system("pause");
//    return 0;
//}


//int main()
//{
//    int index, start, end, points;
//    vector<int> everydayPoint;
//    int maxpoints = 0, minstart = MAX, maxend = 0;
//    while (cin>>index){
//        if (index == 1){
//            cin >> start >> end >> points;
//            minstart = min(start, minstart);
//            maxend = max(end, maxend);
//            if (everydayPoint.empty() || end > everydayPoint.size() - 1){
//                everydayPoint.resize(end + 1, MIN);
//            }
//            for (int i = start; i <= end; i++){
//                if (points > everydayPoint[i])
//                    everydayPoint[i] = points;
//            }
//        } else if (index == 2){
//            cin >> start >> points;
//            maxpoints += points;
//        }
//    }
//    if (minstart && maxend){
//        for (int i = minstart; i <= maxend; i++){
//            maxpoints += everydayPoint[i];
//        }
//    }
//    cout << maxpoints << endl;
//    system("pause");
//    return 0;
//}