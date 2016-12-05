#include<iostream>
#include<string>
using namespace std;

string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string pre = countAndSay(n - 1);
    string cur(2 * pre.size(),'0');
    int count = 0, i = 0, k = 0;
    while (i < pre.size()){
        count = 1;
        int j = i + 1;
        while (j<pre.size() && pre[j] == pre[i]){
            count++;
            j++;
        }
        string temp = to_string(count);
        cur[k++] = temp[0];
        cur[k++] = pre[i];
        i += count;
    }
    cur.resize(k);
    return cur;
}

//int main()
//{
//    int n;
//    cin >> n;
//    cout << countAndSay(n);
//    system("pause");
//    return 0;
//}