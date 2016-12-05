#include<iostream>
#include<queue>
using namespace std;

class Stack {
private:
    queue<int> in;
    queue<int> out;
public:
    // Push element x onto stack.
    void push(int x)
    {
        if (in.empty()){
            in.push(x);
            while (!out.empty()){
                in.push(out.front());
                out.pop();
            }
            return;
        }
        if (out.empty()){
            out.push(x);
            while (!in.empty()){
                out.push(in.front());
                in.pop();
            }
        }
    }

    // Removes the element on top of the stack.
    void pop()
    {
        if (!in.empty()){
            in.pop();
        }
        if (!out.empty()){
            out.pop();
        }
    }

    // Get the top element.
    int top()
    {
        if (!in.empty())
            return in.front();
        if (!out.empty())
            return out.front();
    }

    // Return whether the stack is empty.
    bool empty()
    {
        return in.empty() && out.empty();
    }
};

//int main()
//{
//    Stack q;
//    q.push(1);
//    q.pop();
//    cout << q.empty();
//    system("pause");
//    return 0;
//}