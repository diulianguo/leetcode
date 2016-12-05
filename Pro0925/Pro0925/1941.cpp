#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
const int MAX = 2048;
char img[MAX][MAX];
int pow2[32];

//x,y是当前要画的三角形看做一个矩形，左上角的坐标
void SieTrian(int x,int y,int n)
{
    if (n == 1){
        img[x][y + 1] = '/';
        img[x + 1][y] = '/';
        img[x + 1][y + 1] = '_';
        img[x][y + 2] = '\\';
        img[x + 1][y + 3] = '\\';
        img[x + 1][y + 2] = '_';
    } else{
        SieTrian(x, y + /*pow(2,n-1)*/pow2[n-1], n - 1);
        SieTrian(x + /*pow(2,n-1)*/pow2[n - 1], y, n - 1);
        SieTrian(x + /*pow(2,n-1)*/pow2[n - 1], y + /*pow(2,n)*/pow2[n], n - 1);
   }
}

void Paint(int n)
{
    int height = /*pow(2,n)*/pow2[n];
    int width = pow2[n + 1];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cout << img[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//int main()
//{
//    pow2[0] = 1;
//    for (int i = 1; i<30; ++i)
//        pow2[i] = pow2[i - 1] * 2;
//    int n;
//    while (cin >> n && (n > 0 && n <= 10)){
//        memset(img, ' ', sizeof(img));
//        SieTrian(0, 0, n);
//        Paint(n);
//    }
//    system("pause");
//    return 0;
//}


