#include<iostream>
#include<vector>
using namespace std;

bool vis[100];

bool canStart(vector<int>& gas, vector<int>& cost, int index,int& end)
{
    if (gas[index]<cost[index]){
        end = index;
        return false;
    }
    int res = 0;
    int travel = 0;
    while (gas[index] + res > cost[index]){
        travel++;
        res = gas[index] + res - cost[index];
        if (index == gas.size() - 1){
            if (travel == gas.size())
                return true;
            else
                index = 0;
        } else{
            index++;
        }
    }
    end = index;
    if (travel == gas.size()){
        return true;
    } else{
        if (gas[end] + res == cost[end] && travel == gas.size() - 1)
            return true;
        return false;
    }
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int end = 0, i = 0;
    memset(vis, 0, sizeof(vis));
    while(i < gas.size() && !vis[i]){
        bool flag = canStart(gas, cost, i, end);
        vis[i] = true;
        if (flag)
            return i;
        else{
            if (end == gas.size() - 1){
                i = 0;
            } else{
                i = end + 1;
            }
            if (vis[i])
                return -1;
        }
    }
    return -1;
}

//int main()
//{
//    vector<int> gas = { 99,98,97,100 };
//    vector<int> cost = { 100,100,100,97 };
//    cout << canCompleteCircuit(gas, cost);
//    system("pause");
//    return 0;
//}
