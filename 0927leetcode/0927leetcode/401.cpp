#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//�ӵ�indexλ��ʼ�ţ��ܹ���n��1,�ܹ�max��λ��
void dfs(vector<string>& res, int tmp, int index, int n, int max)
{
    if (n == 0 && ((tmp<=11 &&max==4)||(tmp<=59 && max==6))){
        string t = to_string(tmp);
        if (max == 6 && t.size()<2){
            t = "0" + t;
        }
        res.push_back(t);
        return;
    }
    if (index > max - 1)
        return;
    tmp += 1 << index;//��ǰ����
    dfs(res, tmp, index + 1, n - 1, max);
    tmp -= 1 << index;//��ǰ�Ʋ���
    dfs(res, tmp, index + 1, n, max);
}

//��xյ���������nյ��ʱ���ʾ�����п���ֵ
vector<string> time(int x, int n)
{
    vector<string> res;
    int tmp = 0;
    dfs(res, tmp, 0, x, n);
    return res;
}

vector<string> readBinaryWatch(int num)
{
    vector<string> res;
    for (int i = 0; i <= num; i++){
        int j = num - i;
        vector<string> hour = time(i, 4);
        sort(hour.begin(), hour.end());
        vector<string> minute = time(j, 6);
        sort(minute.begin(), minute.end());
        for (int x = 0; x < hour.size(); x++){
            for (int y = 0; y < minute.size(); y++){
                res.push_back(hour[x] + ":" + minute[y]);
            }
        }
    }
    return res;
}

//int main()
//{
//    int n;
//    cin >> n;
//    vector<string> time = readBinaryWatch(n);
//    return 0;
//}