#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValidSerialization(string preorder)
{
    int degree = 1, i = 0;//每个非空节点提供了两个入度和一个出度
    //diff = outdegree - indegree
    string cur;
    stack<string> s;
    while (i < preorder.size()){
        while (i<preorder.size() && preorder[i] != ','){
            cur += preorder[i];
            i++;
        }
        s.push(cur);
        i++;
        while (!s.empty()&& s.size()>=3){
            cur = s.top();
            if (cur == "#"){
                s.pop();
                cur = s.top();
                if (cur == "#"){
                    s.pop();
                    cur = s.top();
                    if (cur != "#"){
                        s.pop();
                        s.push("#");
                    } else{
                        s.push("#");
                        s.push("#");
                        s.push("#");
                        break;
                    }
                } else{
                    s.push("#");
                    break;
                }
            } else
                break;
        }
        cur.clear();
        /*degree -= 1;
        if (degree < 0)
            return false;
        if (cur != "#")
            degree += 2;
        cur.clear();
        i++;*/
    }
    /*if (degree < 0)
        return false;
    return degree == 0;*/
    if (s.size() == 1 && s.top() == "#")
        return true;
    return false;
}

//int main()
//{
//    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
//    cout << isValidSerialization(preorder) << endl;
//    system("pause");
//    return 0;
//}