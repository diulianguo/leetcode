//#include<iostream>
//#include<vector>
//#include<string>
//#include<map>
//using namespace std;

//int minnum(vector<string> ilegal, string s)
//{
//    return 0;
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//    int m;
//    cin >> m;
//    map<string, int> ilegal;
//    string temp;
//    for (int i = 0; i < m; i++){
//        cin >> temp;
//        ilegal[temp]++;
//    }
//    int i = 0;
//    vector<bool>
//    while (i < n){
//        temp = s.substr(i, 2);
//        if (ilegal.find(temp) == ilegal.end()){
//
//        }
//    }
//}

//#include<iostream>
//#include<stack>
//#include<vector>
//#include<set>
//#include<string>
//#include<string.h>
//#include<math.h>
//
//using namespace std;
//int array[100000];
//int main()
//{
//    int n, m;
//    while (cin >> n) {
//        int x;
//        vector<set<int>>  d(26);
//        string temp;
//        string s;
//        cin >> s;
//        cin >> m;
//        for (int i = 0; i<m; i++){
//            cin >> temp;
//            d[temp[0] - 'a'].insert(temp[1] - 'a');
//            d[temp[1] - 'a'].insert(temp[0] - 'a');
//        }
//        memset(array, 0, sizeof(array));
//        array[s.size() - 1] = 1;
//        int maxc = 1;
//        for (int i = s.size() - 2; i >= 0; i--){
//            array[i] = 1;
//            for (int j = i + 1; j<s.size(); j++){
//                if (d[s[i] - 'a'].count(s[j] - 'a') == 0)
//                    array[i] = max(array[i], array[j] + 1);
//            }
//            if (array[i]>maxc)
//                maxc = array[i];
//        }
//
//        cout << n - maxc << endl;
//
//
//    }
//    return 0;
//}
