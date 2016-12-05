#include<iostream>
#include<vector>
#include<map>
using namespace std;

double calDistance(pair<int, int> A, pair<int, int> B)
{
    double res = (double)((A.first - B.first)*(A.first - B.first) + (A.second - B.second)*(A.second - B.second));
    return sqrt(res);
}

int numberOfBoomerangs(vector<pair<int, int>>& points)
{
    int samep, res = 0;
    for (int i = 0; i < points.size(); i++){
        map<double, int> dist;
        for (int j = 0; j < points.size(); j++){
            double d = calDistance(points[i], points[j]);
            if (i!=j)
                dist[d] ++;
        }
        for (auto it = dist.begin(); it != dist.end(); it++){
            if (it->second>1)
                res += it->second*(it->second - 1);
        }
    }
    return res;
}

//int main()
//{
//    vector<pair<int, int>> points = { { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 }, { 5, 5 }, { 6, 6 }, { 7, 7 }, { 8, 8 } };
//    cout << numberOfBoomerangs(points) << endl;
//    return 0;
//}