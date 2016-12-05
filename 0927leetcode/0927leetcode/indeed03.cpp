#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stack>
using namespace std;

#define MAX 2147483647
//从i位置开始深度优先遍历
vector<char> tmp;
void odfs(vector<vector<char>>& oper,int i, int k)
{
    if (i == k)
        return;
    for (int i = 0; i < 2; i++){
        if (i == 0){
            //若当前取+
            tmp.push_back('+');
            if (tmp.size() == k){
                oper.push_back(tmp);
            } else{
                odfs(oper, i + 1, k);
            }
            tmp.pop_back();
        } else if (i == 1){
            //若当前取*
            tmp.push_back('*');
            if (tmp.size() == k){
                oper.push_back(tmp);
            } else{
                odfs(oper, i + 1, k);
            }
            tmp.pop_back();
        }
    }
}

vector<bool> vis(6);
vector<int> curr;
void ndfs(vector<vector<int>>& nums, vector<int>& Array,int i)
{
    int n = Array.size();
    if (i == n)
        return;
    for (int j = 0; j < n; j++){
        if (!vis[j]){
            vis[j] = 1;
            curr.push_back(Array[j]);
            if (curr.size() == n){
                nums.push_back(curr);
            } else{
                ndfs(nums, Array, i + 1);
            }

            vis[j] = 0;
            curr.pop_back();
        }
    }
}

int minAbs(vector<int> Array, int key)
{
    int n = Array.size(), sum = MAX, cur = 0;
    vector<vector<char>> operators;
    odfs(operators, 0, n - 1);
    vector<vector<int>> nums;
    ndfs(nums, Array, 0);
    for (int k = 0; k < nums.size(); k++){
        for (int i = 0; i < operators.size(); i++){
            stack<int> num;
            for (int j = nums[k].size() - 1; j >= 0; j--){
                num.push(nums[k][j]);
            }
            for (int j = 0; j < operators[i].size(); j++){
                int a, b;
                a = num.top();
                num.pop();
                b = num.top();
                num.pop();
                if (operators[i][j] == '+')
                    num.push(a + b);
                else
                    num.push(a*b);
                if (num.size() == 1 && abs(num.top() - key) < sum)
                    sum = abs(num.top() - key);
            }
        }
    }
    return sum;
}



//int main()
//{
//    int n, key;
//    cin >> n >> key;
//    vector<int> Array(n);
//    for (int i = 0; i < 6; i++){
//        vis[i] = 0;
//    }
//    for (int i = 0; i < n; i++)
//        cin >> Array[i];
//    cout << minAbs(Array, key) << endl;
//    system("pause");
//    return 0;
//}

//李珈de 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include<string>
#include<stack>

using namespace std;
int a[6];
int b[6];
int c[6];
int mind = 100000000;
void sum(int pre, int a[], int i, int n, int k)
{
    if (i == 0){
        pre = a[i];
        sum(pre, a, i + 1, n, k);
        return;
    }
    if (i == n){
        if (abs(pre - k)<mind)mind = abs(pre - k);
        return;
    }
    int tmp = pre;
    pre += a[i];
    sum(pre, a, i + 1, n, k);
    pre = tmp;
    pre *= a[i];
    sum(pre, a, i + 1, n, k);

}

void suffle(int a[], int b[], int n, int k, int i)
{
    if (i == n){
        for (int l = 0; l<n; l++){
            a[l] = c[b[l]];
        }
        sum(0, a, 0, n, k);
        return;
    }
    for (int l = i; l<n; l++){
        swap(b[i], b[l]);
        suffle(a, b, n, k, i + 1);
        swap(b[l], b[i]);
    }
}
//int main()
//{
//    int n, m, k;
//    cin >> n >> k;
//    for (int i = 0; i<n; i++){
//        cin >> a[i];
//        c[i] = a[i];
//        b[i] = i;
//    }
//    suffle(a, b, n, k, 0);
//    cout << mind << endl;
//
//
//
//    return 0;
//}