#include<iostream>
#include<vector>
using namespace std;

int pos[4];
vector<string> ipSet;

bool isValid(string s, int start, int end)
{
    string cur(s, start, end - start + 1);
    if (cur.size() == 1){
        if (cur >= "0" && cur <= "9")
            return true;
    } else if (cur.size() == 2){
        if (cur >= "10" && cur <= "99")
            return true;
    } else if (cur.size() == 3){
        if (cur >= "100" && cur <= "255")
            return true;
    }
    return false;
}

//dep:当前划分到第几段，curpos从哪个位置开始划分
void dfs(string s, int dep,int curpos,int maxdep)
{
    if (dep == maxdep){
        if (curpos == s.size()){
            string ip;
            int start = 0;
            for (int i = 0; i < maxdep; i++){
                string cur(s, start, pos[i] - start + 1);
                start = pos[i] + 1;
                if (i < maxdep - 1)
                    ip += cur + ".";
                else
                    ip += cur;
            }
            ipSet.push_back(ip);
        }
        return;
    }
    for (int i = curpos; i < s.size(); i++){
        if (isValid(s, curpos, i)){
            pos[dep] = i;
            dfs(s, dep + 1, i + 1, maxdep);
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    int len = s.size();
    if (len > 12 || len < 4)
        return ipSet;
    dfs(s, 0, 0, 4);
    return ipSet;
}

//int main()
//{
//    string s = "1111";
//    vector<string> res = restoreIpAddresses(s);
//    return 0;
//}