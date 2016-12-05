#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int maxRotateFunction(vector<int>& A)
{
    int n = A.size();
    if (n < 2)
        return 0;
    long long int maxv = 0;
    for (int i = 0; i < n; i++){
        int head = i;
        long long int sum = 0;
        for (int j = 0; j < n; j++){
            if (head < n)
                sum += A[j] * head;
            else
                sum += A[j] * (head - n);
            head++;
        }
        maxv = max(maxv, sum);
    }
    return maxv;
}

//int main()
//{
//    vector<int> A = { 4, 3, 2, 6 };
//    cout << maxRotateFunction(A);
//    system("pause");
//    return 0;
//}