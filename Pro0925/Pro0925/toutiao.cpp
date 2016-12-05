#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
typedef long long int ll;

string onenum(vector<string> &num,ll n, ll m)
{
    int len = num.size();
    sort(num.begin(), num.end());
    return num[m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    if (n < m)
        return 0;
    vector<string> num(n);
    for (int i = 0; i < n; i++){
        num[i] = to_string(i+1);
    }
    string s=onenum(num, n, m);
    int len = s.size();
    for (int i = 0; i < len; i++){
        cout << s[i] - '0';
    }
    cout << endl;
    system("pause");
    return 0;
}


#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include <vector>
#include <iterator>
using namespace std;
typedef long long int ll;

string onenum(vector<string> &num, ll n, ll m)
{
    int len = num.size();
    vector<string>::iterator itr = num.begin();
    advance(itr, m);
    partial_sort(num.begin(), itr, num.end());
    return num[m - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    if (n < m)
        return 0;
    vector<string> num(n);
    for (int i = 0; i < n; i++){
        num[i] = to_string(i + 1);
    }
    string s = onenum(num, n, m);
    int len = s.size();
    for (int i = 0; i < len; i++){
        cout << s[i] - '0';
    }
    cout << endl;
    system("pause");
    return 0;
}
