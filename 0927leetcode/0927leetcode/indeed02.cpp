#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> MatixProduct(vector<vector<int>> Amat, vector<vector<int>> Bmat)
{
    int n, m, k;
    n = Amat.size();
    m = Amat[0].size();
    k = Bmat[0].size();
    vector<vector<int>> product(n, vector<int>(k));
    int cur = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            //product
            for (int k = 0; k < m; k++){
                cur += Amat[i][k] * Bmat[k][j];
            }
            product[i][j] = cur;
            cur = 0;
        }
    }
    return product;
}

//int main()
//{
//    int n, m, k;
//    cin >> n >> m >> k;
//    vector<vector<int>> Amat(n, vector<int>(m));
//    vector<vector<int>> Bmat(m, vector<int>(k));
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < m; j++){
//            cin >> Amat[i][j];
//        }
//    }
//    for (int i = 0; i < m; i++){
//        for (int j = 0; j < k; j++){
//            cin >> Bmat[i][j];
//        }
//    }
//    vector<vector<int>> product = MatixProduct(Amat, Bmat);
//    for (int i = 0; i < n; i++){
//        for (int j = 0; j < k; j++){
//            cout << product[i][j] << " ";
//        }
//        cout << endl;
//    }
//    system("pause");
//    return 0;
//}