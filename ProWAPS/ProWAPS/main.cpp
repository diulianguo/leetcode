#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int matricindex(int rows, int columns, int nums, vector<vector<int>> matrics)
    {
        vector<int> A, B;
        vector<int> Dp(nums*(nums-1)/2,0);
        int min_pixels = 0;
        bool add_flag = false;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                int conflict = 0;
                add_flag = false;
                for (int k = 0; k < nums-1; k++){
                    for (int l = k + 1; l < nums; l++){
                        A = matrics[k];
                        B = matrics[l];
                        if (A[i*columns + j] != B[i*columns + j] && !Dp[conflict]){
                            Dp[conflict] = 1;//如果能解决当前A与B矩阵的conflict,且未加入当前的步数集合中，则加入
                            add_flag = true;
                        }
                        conflict++;
                    }
                }
                if (add_flag)
                    min_pixels++;
            }
        }
        return min_pixels;
    }
};

int main()
{
    /*vector<vector<int>> matrics;
    int n, m, k, x;
    cout << "Please input N,M,K:" << endl;
    cin >> n >> m >> k;
    matrics.resize(k);
    for (int i = 0; i < k; i++){
        cout << "Please input matric " << i << ":"<<endl;
        for (int j = 0; j < n; j++){
            for (int l = 0; l < m; l++){
                cin >> x;
                matrics[i].push_back(x);
            }
        }
    }
    Solution WAPS;
    cout << "the minimum number of pixels is:" << WAPS.matricindex(n, m, k, matrics) << endl;*/
    vector<vector<int>> matrics;
    int rows, columns, nums, x;
    cin >> rows >> columns >> nums;
    matrics.resize(nums);
    for (int i = 0; i < nums; i++){
        for (int j = 0; j < rows; j++){
            for (int l = 0; l < columns; l++){
                cin >> x;
                matrics[i].push_back(x);
            }
        }
    }
    vector<int> A, B;
    vector<int> Dp(nums*(nums - 1) / 2, 0);
    int min_pixels = 0;
    bool add_flag = false;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            int conflict = 0;
            add_flag = false;
            for (int k = 0; k < nums - 1; k++){
                for (int l = k + 1; l < nums; l++){
                    A = matrics[k];
                    B = matrics[l];
                    if (A[i*columns + j] != B[i*columns + j] && !Dp[conflict]){
                        Dp[conflict] = 1;//如果能解决当前A与B矩阵的conflict,且未加入当前的步数集合中，则加入
                        add_flag = true;
                    }
                    conflict++;
                }
            }
            if (add_flag)
                min_pixels++;
        }
    }
    cout << endl << endl << min_pixels << endl;
    system("pause");
    return 0;
}
//91a7d2ea - bf2d - 4c59 - b1d1 - bb6d708e184b