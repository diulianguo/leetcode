#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int finMED(vector<int> a, int i, int j)
{
    int n = a.size();
    if (i < j){
        int k = j - i + 1;
        if (k % 2)
            return a[(i + j) / 2];
        else
            return a[(i + j) / 2 + 1];
    } else{
        int left = j + 1;
        int right = n - i;
        int k = (left + right) / 2;
        if (k <= j)
            return a[k];
        else
            return a[i + k - j - 1];
    }
    if (n % 2)
        return a[n / 2];
    else
        return max(a[n / 2 - 1], a[n / 2]);
}

int converv(vector<int> a, int r)
{
    int n = a.size();
    sort(a.begin(), a.end());
    vector<int> b(n);
    while (r<n)
    {
        for (int i = 0; i < n; i++){
            b[i] = finMED(a, i, (i + r - 1) % n);
        }
        sort(b.begin(), b.end());
        a = b;
        r++;
    }
    return finMED(a, 0, n - 1);
}

//int main()
//{
//    /*int n, r;
//    cin >> n >> r;
//    vector<int> a(n);*/
//    //for (int i = 0; i < n; i++){
//    //    cin >> a[i];
//    //}
//    vector<int> a = { 1, 2, 3, 4, 5, 6, 7 };
//    cout << converv(a,5) << endl;
//    system("pause");
//    return 0;
//}