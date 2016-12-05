#include<iostream>
#include<string>
#include<stack>
using namespace std;

string simplifyPath(string path)
{
    stack<string> ss;
    for (int i = 0; i < path.size(); i++){
        string s;
        while (i<path.size() && path[i] == '/')
            i++;
        while (i<path.size() && path[i] != '/')
            s += path[i++];
        if (s == ".." && !ss.empty())
            ss.pop();
        if (s != "" && s != "." && s != "..")
            ss.push(s);
    }
    if (ss.empty())
        return "/";
    string s;
    while (!ss.empty()){
        s = "/" + ss.top() + s;
        ss.pop();
    }
    return s;
}

//int main()
//{
//    string path;
//    cin >> path;
//    cout << simplifyPath(path) << endl;
//    system("pause");
//    return 0;
//}