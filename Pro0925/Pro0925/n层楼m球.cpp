//#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int f[10001][10001];

int calcThrowNumber(int numOfFloors, int numOfBalls)
{
    //implement your code her

    for (int i = 0; i < numOfFloors; i++){
        f[i][0] = 0;
        f[i][1] = i;
    }
    int temp;
    for (int i = 1; i < numOfFloors + 1; i++){
        for (int j = 1; j < numOfBalls + 1; j++){
            int min = 2147483647;
            for (int k = 1; k < i + 1; k++){
                temp = 1 + max(f[k - 1][j - 1], f[i - k][j]);
                if (temp < min)
                    min = temp;
            }
            f[i][j] = min;
        }
    }
    return f[numOfFloors][numOfBalls];
}
//int main()
//{
//    int numOfFloors, numOfBalls;
//    //while (scanf("%d%d", &numOfFloors, &numOfBalls) != EOF) {
//    //    printf("%d\n", calcThrowNumber(numOfFloors, numOfBalls));
//    //}
//    while (cin >> numOfFloors >> numOfBalls){
//        cout << calcThrowNumber(numOfFloors, numOfBalls);
//    }
//}