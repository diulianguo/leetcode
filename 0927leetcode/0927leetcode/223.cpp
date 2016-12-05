#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int square(int A, int B, int C, int D)
{
    int width = abs(A - C);
    int height = abs(B - D);
    return width*height;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int S1 = square(A, B, C, D);
    int S2 = square(E, F, G, H);

    int A1 = max(A, E);
    int B1 = max(B, F);
    int C1 = min(C, G);
    int D1 = min(D, H);
    int SS = square(A1, B1, C1, D1);
    if (A1 >= C1 || B1 >= D1)
        return S1 + S2;
    return S1 + S2 - SS;
}

