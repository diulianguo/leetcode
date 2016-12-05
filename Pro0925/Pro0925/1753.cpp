#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

bool isfind = false;
int step;
bool isMatch(vector<vector<bool>> rect)
{
    for (int i = 0; i < rect.size(); i++){
        for (int j = 0; j < rect.size(); j++){
            if (rect[i][j] != rect[0][0])
                return 0;
        }
    }
    return 1;
}

void flip(vector<vector<bool>> &rect, int x, int y)
{
    rect[x][y] = !rect[x][y];
    if (x - 1 >= 0)
        rect[x - 1][y] = !rect[x - 1][y];
    if (x + 1 < rect.size())
        rect[x + 1][y] = !rect[x + 1][y];
    if (y - 1 >= 0)
        rect[x][y - 1] = !rect[x][y - 1];
    if (y + 1 < rect.size())
        rect[x][y + 1] = !rect[x][y + 1];
}

void FlipGame(vector<vector<bool>> &rect, int x, int y, int dep)
{
    if (dep==step){
        isfind = isMatch(rect);
        return;
    }

    if (isfind || x==4)
        return;

    flip(rect, x, y);
    if (y < rect.size() - 1)
        FlipGame(rect, x, y + 1, dep + 1);
    else if(x + 1<rect.size())
        FlipGame(rect, x + 1, 0, dep + 1);//若翻转(x,y)点

    flip(rect, x, y);
    if (y < rect.size() - 1)
        FlipGame(rect, x, y + 1, dep);
    else if (x + 1<rect.size())
        FlipGame(rect, x + 1, 0, dep);//若不翻转(x,y)点，还原状态
}

//int main()
//{
//    vector<vector<bool>> rect(4, vector<bool>(4));
//    char tmp;
//    for (int i = 0; i < rect.size(); i++){
//        for (int j = 0; j < rect.size(); j++){
//            cin >> tmp;
//            if (tmp == 'b')
//                rect[i][j] = true;
//            else
//                rect[i][j] = false;
//        }
//    }
//    for (step = 0; step < rect.size()*rect.size()+1; step++)
//    {
//        FlipGame(rect, 0, 0, 0);
//        if (isfind){
//            break;
//        }
//    }
//    if (isfind)
//        cout << step << endl;
//    else
//        cout << "Impossible" << endl;
//    system("pause");
//    return 0;
//}