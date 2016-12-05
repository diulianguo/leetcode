#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
using namespace std;

int bulbSwitch(int n)
{
    return sqrt(n);
}

bool isPowerOfThree(int n)
{
    if (n <= 0)
        return false;
    int x = (int)(log(n) / log(3)+0.5);
    double y = log(n) / log(3);
    if (pow(3, x) == n)
        return true;
    return false;
}

bool isPowerOfFour(int num)
{
    if (num <= 0)
        return false;
    int x = (int)(log(num) / log(4) + 0.5);
    if (pow(4, x) == num)
        return true;
    return false;
}

int integerBreak(int n)
{
    vector<int> DP(n+1, 0);
    DP[0] = 0, DP[1] = 0, DP[2] = 1;
    for (int i = 2; i < n+1; i++){
        for (int j = 1; j < i; j++){
            DP[i] = max(DP[i], max(i - j, DP[i - j])*j);
        }
    }
    return DP[n];
}

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    if (x%y == 0)
        return y;
    int z;
    while (x%y){
        z = x%y;
        x = y;
        y = z;
    }
    return y;
}

bool canMeasureWater(int x, int y, int z)
{
    if (z == 0)
        return true;
    if ((x + y)>=z && z % gcd(max(x,y), min(x,y))==0)
        return true;
    return false;
}

int countNumbersWithUniqueDigits(int n)
{
    int count = 9, res = 10;
    if (n == 0)
        return 1;
    for (int i = 2; i < n + 1; i++){
        count *= (11 - i);
        res += count;
    }
    return res;
}

int findNthDigit(int n)
{
    int i = 0, num = n;
    //1位数有9位
    //2位数有2*9*10个
    //3位数有3*9*100个
    while (num > (i + 1) * 9 * pow(10, i)){
        num -= (i + 1) * 9 * pow(10, i);
        i++;
    }
    int index = (num - 1) / (i + 1);
    int start = pow(10, i);
    int realnum = start + index;
    int subindex = (num - 1) % (i + 1);

    return (int)(realnum / (pow(10, i - subindex))) % 10;
}

int canArrangeWords(int num, char** arr)
{
    // WRITE YOUR CODE HERE
    char** tmparr = new char*[num];
    int n;
    for (int i = 1; i<num; i++){
        n = strlen(arr[i]);
        for (int j = 0; j<i; j++){
            tmparr[j] = arr[j];
        }
        for (int j = i + 1; j<num; j++){
            tmparr[j - 1] = arr[j];
        }

        if (arr[i][n - 1] == arr[0][0]){
            int flag = canArrangeWords(num - 1, tmparr);
            if (flag)
                return 1;
        }
        n = strlen(arr[0]);
        for (int j = 1; j<num; j++){
            tmparr[j - 1] = arr[j];
        }
        if (arr[i][0] = arr[0][n - 1]){
            int flag = canArrangeWords(num - 1, tmparr);
            if (flag)
                return 1;
        }
    }
    return 0;
}

int writeNum(long long int n)
{
    int bits = 0;
    long long int tmp = n;
    while (tmp){
        bits++;
        tmp /= 10;
    }
    int num = bits;
    long long int max = 0,min=1;
    while (num){
        max = max * 10 + 1;
        num--;
    }
    num = bits-1;
    while (num){
        min *= 10;
        num--;
    }
    int i = 1, j;
    num = 0;
    int subnum = 1;

    while (i < bits){
        j = i-1;
        subnum = 1;
        while (j){
            subnum *= 2;
            j--;
        }
        num += subnum;
        i++;
    }
    subnum = 1;
    if (max <= n){
        j = bits - 1;
        while (j){
            subnum *= 2;
            j--;
        }
        num += subnum;
    } else{
        num += n - min + 1;
    }
    return num;

}

int card[1000][1000];
int N, M;
int times = 0;

void reverse(int x)
{
    int i, j, k;
    //x代表每一行
    if (x + M > N){
        for (i = x; i < N; i++){
            for (j = 0; j < N; j++){
                if (card[i][j] == 0){
                    times = -1;
                    return;
                }
            }
        }
        return;
    }
    for (j = 0; j < N; j++){
        if (card[x][j] == 1)
            continue;
        else{
            if (x + M>N){
                times = -1;
                return;
            }
            times++;
            for (i = x; i < x + M; i++){
                for (k = j; k < j + M; k++){
                    card[i][k] = !card[i][k];
                }
            }
        }
    }
    reverse(x + 1);
}

int integerReplacement(int n)
{
    if (n <= 1)
        return 0;
    while (n !=1){
        if (n % 2)
            return min(integerReplacement(n+1), integerReplacement(n-1)) + 1;
        else
            return integerReplacement(n / 2) + 1;
    }
}

vector<int> largestDivisibleSubset(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result(nums.size());
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++){
        for (int j = 0; j < i; j++){
            if (nums[i] % nums[j] == 0 && result[j].size()>result[i].size())
                result[i] = result[j];
        }
        result[i].push_back(nums[i]);
        if (ret.size() < result[i].size())
            ret = result[i];
    }
    return ret;
}

string number(string num,int n)
{
    /*int len = 0, i=0, j=i+1;
    long long int x = num;
    vector<int> nums;
    if (num <= 0)
        return 0;
    if (n == 0)
        return num;
    while (x){
        nums.push_back(x % 10);
        x /= 10;
    }
    x = 0;
    len = nums.size();
    if (len <= n)
        return 0;
    if (n > 1)
    {
        long long int subnum=number(num, n - 1);
        return number(subnum, 1);
    }
    vector<int>::iterator itr = nums.begin();
    if (n == 1){
        while(i<len && j<len){
            if (nums[len - i - 1] < nums[len - j - 1]){
                nums.erase(itr + len - i - 1);
                break;
            } else{
                i++;
                j = i + 1;
            }
        }
        if (j == len){
            nums.erase(itr + len - i - 1);
        }
        for (i = nums.size()-1; i >=0; i--){
            x = x * 10 + nums[i];
        }
    }
    return x;*/
    int i = 0, j = i + 1;
    int len = num.size();
    if (len <= n)
        return 0;
    if (n > 1)
    {
        string subnum = number(num, n - 1);
        return number(subnum, 1);
    }
    string::iterator itr = num.begin();
    if (n == 1){
        while (i<len && j<len){
            if (num[i] < num[j]){
                num.erase(itr + i);
                break;
            } else{
                i++;
                j = i + 1;
            }
        }
        if (j == len){
            num.erase(itr + i);
        }
    }
    return num;
}

const int MAXINT = 32767;
void Dijkstra(int v0,int *dist,int *prevn,int **map,int n,int m)
{
    bool *S=new bool [n];//判断是否已经加入集合中
    for (int i = 1; i <n+1; i++){
        dist[i] = map[v0][i];
        S[i] = false;
        if (dist[i] == MAXINT)
            prevn[i] = -1;
        else
            prevn[i] = v0;
    }//初始化v0到所有其他顶点的距离
    dist[v0] = 0;
    S[v0] = true;
    for (int i = 2; i < n + 1; i++){
        int mindist = MAXINT;
        int u = v0;
        for (int j = 1; j < n + 1; j++){
            if ((!S[j]) && dist[j] < mindist){
                u = j;
                mindist = dist[j];
            }
        }
        S[u] = true;
        for (int j = 1; j < n + 1; j++){
            if ((!S[j]) && map[u][j] < MAXINT){
                if (dist[u] + map[u][j]<dist[j]){
                    prevn[j] = u;
                    dist[j] = dist[u] + map[u][j];
                }
            }
        }
    }
}

int maxHouse(vector<vector<int>> &matrix,int x, int y)
{
    if (x<0 || x > matrix.size() - 1 || y<0 || y > matrix.size() - 1){
        return 0;
    }
    if (matrix[x][y] == 0)
        return 0;
    int up = 0, down = 0, left = 0, right = 0, area = 0;
    matrix[x][y] = 0;
    area++;
    int width = matrix[x].size();
    int height = matrix.size();
    if (y - 1 >= 0 && y - 1<height)
        up = maxHouse(matrix, x, y - 1);
    if (y + 1 >= 0 && y + 1<height)
        down = maxHouse(matrix, x, y + 1);
    if (x - 1 >= 0 && x - 1 <= width)
        left = maxHouse(matrix, x - 1, y);
    if (x + 1 >= 0 && x + 1 <= width)
        right = maxHouse(matrix, x + 1, y);
    area += up + down + left + right;
    return area;
}

namespace search {
    typedef long long int ll;
    string KleinCombination(ll target, string s)
    {
        int n = s.size();
        int i = 0, j = 0, k = 0, l = 0, m = 0;
        string code(5,'a');
        for (i = 0; i < n;i++){
            for (j = 0; j < n;j++){
                if (j == i)
                    continue;
                for (k = 0; k < n;k++){
                    if (k == i || k == j)
                        continue;
                    for (l = 0; l < n;l++){
                        if (l == k || l == j || l == i)
                            continue;
                        for (m = 0; m < n;m++){
                            if (m == l || m == k || m == j || m == i)
                                continue;
                            int a = s[i] - 64;
                            /*int b = pow((int)(s[j] - 64),2);
                            int c = pow((int)(s[k] - 64),3);
                            int d = pow((int)(s[l] - 64),4);
                            int e = pow((int)(s[m] - 64),5);*/
                            int b = (s[j] - 64)*(s[j] - 64);
                            int c = (s[k] - 64)*(s[k] - 64)*(s[k] - 64);
                            int d = (s[l] - 64)*(s[l] - 64)*(s[l] - 64)*(s[l] - 64);
                            int e = (s[m] - 64)*(s[m] - 64)*(s[m] - 64)*(s[m] - 64)*(s[m] - 64);
                            if (a - b + c - d + e == target){
                                code[0] = s[i];
                                code[1] = s[j];
                                code[2] = s[k];
                                code[3] = s[l];
                                code[4] = s[m];
                                return code;
                            }
                        }
                    }
                }
            }
        }
        return "no solution";
    }
}

//int main()
//{
//    int m, n;
//    cin >> m >> n;
//    if (m == 0){
//        cout << 0;
//        return 0;
//    }
//    if (n < 2 || n>16)
//        return 0;
//    vector<int> num;
//    while (m){
//        num.push_back(m%n);
//        m = m / n;
//        if (m < n){
//            num.push_back(m);
//            break;
//        }
//    }
//    for (int i = num.size()-1; i >=0; i--){
//        if (n<10)
//            cout << num[i];
//        else{
//            if (num[i]>9){
//                cout << (char)(num[i] - 10 + 'A');
//            } else
//                cout << num[i];
//        }
//    }
//    system("pause");
//    return 0;
//}

void combination(vector<int>& candidates, int start, int end, int target, vector<int>&tmp, vector<vector<int>> &result)
{
    if (target == 0){
        result.push_back(tmp);
        return;
    }
    if (start > end){
        return;
    }
    for (int i = start; i < end + 1; i++){
        tmp.push_back(candidates[i]);
        combination(candidates, i + 1, end, target - candidates[i], tmp, result);
        tmp.pop_back();
        while (i < end && candidates[i] == candidates[i + 1]){
            i++;
        }
    }
}

int casenum(vector<int>num, int sum)
{
    /*int n = num.size();
    sort(num.begin(), num.end());
    int max = 0;
    for (int i = 0; i < n; i++){
        max += num[i];
    }
    if (sum<num[0] || sum>max)
        return 0;
    for (int i = 0; i < n; i++){
        if (num[i] == sum)
            return 1;
    }
    if (sum == max)
        return 1;*/
    sort(num.begin(), num.end());
    vector<vector<int>> result;
    vector<int> tmp;
    int end = num.size() - 1;
    combination(num, 0, end, sum, tmp, result);
    return result.size();
}

//int main()
//{
//    int n, sum;
//    cin >> n >> sum;
//    vector<int>num;
//    int tmp;
//    for (int i = 0; i < n; i++){
//        cin >> tmp;
//        num.push_back(tmp);
//    }
//    cout << casenum(num, sum);
//    system("pause");
//    return 0;
//}

//int main()
//{
//    //t map[MAXNUM][MAXNUM];
//    //nt dist[MAXNUM];//当前顶点到其他各点的距离
//    //int prevn[MAXNUM];//各个点当前的前驱
//    //int n, m;//n个顶点，m条边
//    //cin >> n >> m;
//    //int u, v, w;
//    //int *dist = new int[n+1];
//    //int *prevn = new int[n+1];
//    //int **map = new int* [n+1];
//    //for (int i = 1; i < n + 1; i++){
//    //    map[i] = new int[n + 1];
//    //    for (int j = 1; j < n + 1; j++){
//    //        map[i][j] = MAXINT;
//    //    }
//    //}
//    //for (int i = 1; i < m+1; i++){
//    //    cin >> u >> v >> w;
//    //    map[u][v] = w;
//    //}
//    //Dijkstra(1,dist,prevn,map,n,m);
//    //cout << dist[n];
//    /*int maxArea = 0;
//    vector<vector<int>> matrix;
//    int n, m;
//    cin >> n >> m;
//    matrix.resize(n);
//    for (int i = 0; i < matrix.size(); i++){
//        matrix[i].resize(m);
//        for (int j = 0; j < matrix[i].size(); j++){
//            cin >> matrix[i][j];
//        }
//    }
//
//    for (int i = 0; i < matrix.size(); i++){
//        for (int j = 0; j < matrix[i].size(); j++){
//            int area = maxHouse(matrix, i, j);
//            if (area>maxArea){
//                maxArea = area;
//            }
//        }
//    }
//    cout << maxArea;*/
    /*int n;
    string s;
    vector<long long int> target;
    vector<string> secret;
    while (1){
        cin >> n;
        cin >> s;
        if (n != 0 && s != "END"){
            target.push_back(n);
            secret.push_back(s);
        }
        if (n == 0 && s == "END")
            break;
    }
    for (int i = 0; i < target.size(); i++){
        cout << search::KleinCombination(target[i], secret[i])<<endl;
    }
    system("pause");
    return 0;
}*/

//int minX(int a, int b, int c)
//{
//    int n = 0, csum = 0, xsum = 0, minxsum = INT_MAX;
//    vector<int> cnum;
//    vector<int> xnum, minx;
//    while (c){
//        cnum.push_back(c % 10);
//        c = c / 10;
//    }
//    for (int i = 0; i < cnum.size(); i++){
//        csum += cnum[i];
//    }
//    int x = min(a, b);
//    while (!(x>max(a, b) || x < min(a, b))){
//        xsum = 0;
//        int tmpx = x;
//        while (tmpx){
//            xnum.push_back(tmpx % 10);
//            tmpx = tmpx / 10;
//        }
//        for (int i = 0; i < xnum.size(); i++){
//            xsum += xnum[i];
//        }
//        if (abs(xsum-csum) < minxsum){
//            minxsum = abs(xsum - csum);
//            minx = xnum;
//        }
//        x++;
//        xnum.clear();
//    }
//    x = 0;
//    for (int i = minx.size()-1; i >=0; i--){
//        x = x * 10 + minx[i];
//    }
//    return x;
//}
//
//int main()
//{
//    int a, b, c;
//    cin >> a >> b >> c;
//    cout << minX(a, b, c);
//    system("pause");
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//    int m;
//    while (cin >> m){
//        unsigned long long n = unsigned(m);
//        unsigned long long i = 1;
//        unsigned long long k;
//        while (1){
//            k = i&n;
//            if (k == 0)
//                break;
//            i = i << 1;
//        }
//        if (i != 1)
//            i = i >> 1;
//        cout << i + n << endl;
//
//    }
//    return 0;
//
//}
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//    int m;
//    while (cin >> m){
//        unsigned long long n = unsigned(m);
//        unsigned long long i = 1;
//        unsigned long long k;
//        int flag = 0;
//        while (1){
//            k = i&n;
//            if (flag == 0 && k>0){
//                flag = 1;
//            } else if (flag == 1 && k == 0){
//                break;
//            }
//            i = i << 1;
//        }
//        i = i >> 1;
//        cout << int(i + n) << endl;
//
//    }
//    return 0;
//
//}

bool isSquare(string s,int n)
{
    if (n % 2)
        return 0;
    int i = 0, j = i + n / 2;
    while (j<n){
        if (s[i] == s[j]){
            i++;
            j++;
        } else
            return 0;
    }
    return 1;
}

int SquareNum(string s)
{
    int n = s.size();
    int num = 0, l = 0;;
    int sublen = n - n % 2;
    if (n < 2)
        return 0;
    string tmp;
    map<string,int> squStr;
    for (int i = 0; i < n - 1; i++){
        for (int j = 2; j <= sublen-i; j += 2){
            int p = 0;
            tmp.resize(j);
            for (int k = i; k < i + j; k++){
                tmp[p++]=s[k];
            }
            if (isSquare(tmp, j)){
                if (!squStr.count(tmp)){
                    num++;
                    squStr[tmp] = j;
                } 
                
            }
        }
    }
    return num;
}

//int main()
//{
//    string s;
//    cin >> s;
//    cout << SquareNum(s);
//    system("pause");
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//int main()
//{
//    int m;
//    while (cin >> m){
//        unsigned long long n = unsigned(m);
//        unsigned long long i = 1;
//        unsigned long long k;
//        int flag = 0;
//        unsigned long long mark = 1;
//        while (1){
//            k = i&n;
//            if (k>0){
//                if (mark != i){
//                    n = n&(~i);
//                    n = n^mark;
//                    mark = mark << 1;
//
//                } else{
//                    n = n&(~i);
//                    mark = i;
//
//                }
//
//
//
//
//            } else if (k == 0){
//                n = n^i;
//                break;
//            }
//            i = i << 1;
//        }
//        cout << n << endl;
//
//    }
//    return 0;
//
//}

int minTime(int n, int k)
{
    //因为每个孩子的代价一样，所以用广度优先搜索，所有所有的可能路径
    queue<int> bfsTree;
    int step[10000];
    bool visit[10000];
    memset(visit, 0, sizeof(visit));

    bfsTree.push(n);
    step[n] = 0;
    visit[n] = 1;
    while (!bfsTree.empty()){
        int cur = bfsTree.front();
        bfsTree.pop();

        int next;
        for (int i = 0; i < n; i++){
            int next;
            if (i == 0)
                next = cur - 1;
            else if (i == 1)
                next = cur + 1;
            else
                next = 2 * cur;

            if (next<0 || next>10000){
                continue;
            }

            if (!visit[next]){
                bfsTree.push(next);
                visit[next] = 1;
                step[next] = step[cur] + 1;
                if (next == k)
                    return step[next];
            }
        }
    }
}

void dfs(vector<vector<char>> &field ,int x,int y)
{
    //深度优先遍历,把所有相邻区域的W都改成.，下次就不再计算，field一定要传引用
    int n = field.size();
    int m = field[0].size();
    if (field[x][y] == '.')
        return;
    field[x][y] = '.';
    if (y - 1 >= 0)
        dfs(field, x, y - 1);
    if (y + 1 < m)
        dfs(field, x, y + 1);
    if (x + 1 < n)
        dfs(field, x + 1, y);
    if (x + 1 < n && y - 1 >= 0)
        dfs(field, x + 1, y - 1);
    if (x + 1 < n && y + 1 < m)
        dfs(field, x + 1, y + 1);
    if (x - 1 >= 0)
        dfs(field, x - 1, y);
    if (x - 1 >= 0 && y - 1 >= 0)
        dfs(field, x - 1, y - 1);
    if (x - 1 >= 0 && y + 1 < m)
        dfs(field, x - 1, y + 1);
    
}

int n, k;
int ans = 0;
int vis[8];//记录某一列是否放上了棋子
vector<vector<char>> board(8, vector<char>(8));
void chessBoard(int x, int sum)
{
    //x开始行
    if (sum == k){
        ans++;
        return;
    }
    for (int i = x; i < n; i++){
        for (int j = 0; j < n; j++){
            if (board[i][j] == '#' && !vis[j]){
                vis[j] = 1;
                chessBoard(i + 1, sum + 1);
                vis[j] = 0;
            }
        }
    }
}

//v当前已经涂的体积，m当前层数，s当前得到的面积，r和h是当前层的半径和高
//int n, m;
//int ansS = INT_MAX;

//bool jude(int nowi,int r,int h,int v)
//{
//    int nowv = v + r*r*h;
//    if (nowv > n)
//        return 0;
//    for (int i = 1; i<=m - nowi; i++){
//        nowv += i*i*i;
//        if (nowv > n)
//            return 0;
//    }
//    for (int i = nowi; i <= m; i++){
//        v += r*r*h;
//        r--;
//        h--;
//    }
//    if (v < n)
//        return 0;
//    return 1;
//}
//void minS(int nowi,int nowv,int nows,int r,int h)
//{
//    //搜索时r,h的下届都是剩余的层数+1，因为每层r,h都至少减1
//    if (nowv > n || nows > ansS)
//        return;
//    if (nowi == m + 1){
//        if (nowv==n && nows < ansS)
//            ansS = nows;
//        return;
//    }
//    for (int i = r; i>m - nowi; i--){
//        for (int j = h; j > m - nowi; j--){
//            int curS = nows + 2 * i*j + i*i;
//            if (nowi != 1)
//                curS -= i*i;
//            if (jude(nowi,i,j,nowv))
//                minS(nowi + 1, nowv + i*i*j, curS, i - 1, j - 1);
//        }
//    }
//
//}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<char>> field(n, vector<char>(k));
    int i, j,num=0;
    for (i = 0; i < n; i++){
        for (j = 0; j < k; j++){
            cin >> field[i][j];
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < k; j++){
            if (field[i][j] == 'W'){
                num++;
                dfs(field, i, j);
            }
        }
    }
    cout << num << endl;
    system("pause");
    return 0;
}
   /* while (cin>>n>>k && n != -1 && k != -1){
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> board[i][j];
            }
        }
        ans = 0;
        chessBoard(0, 0);
        cout << ans << endl;
    }*/
    //cin >> n >> m;
    //int maxR = sqrt(n*1.0);//最下面一层的最大半径，即所有层都一样大
    //int maxh = n;//最大高度n,即每一层的半径都是1
    //minS(1, 0, 0, maxR, maxh);
    //cout << ansS;
//    system("pause");
//    return 0;
//}
