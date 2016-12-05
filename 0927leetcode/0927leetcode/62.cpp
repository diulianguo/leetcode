#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int m, int n)
{
    //�ݹ鷽��ʱ�䳬��
    /*if (m == 1 || n == 1)
        return 1;
    else
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);*/
    vector<vector<int>> steps(m, vector<int>(n, 1));
    //steps[m-1][n-1]��ʾmxn�����񣬴����Ͻǵ����½�(m-1,n-1)�ж����ַ�����
    //steps[x][y]����ǰλ��(x,y)�ķ�������Ϊ������ߺ��ϱߵ�λ�õķ������ܺ�
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            steps[i][j] = steps[i][j - 1] + steps[i - 1][j];
        }
    }
    return steps[m - 1][n - 1];
}

//int main()
//{
//    int m, n;
//    cin >> m >> n;
//    cout << uniquePaths(m, n);
//    system("pause");
//    return 0;
//}