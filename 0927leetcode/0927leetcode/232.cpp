#include<iostream>
#include<stack>
using namespace std;

class Queue {
private:
    stack<int> in;
    stack<int> out;
public:
    // Push element x to the back of queue.
    void push(int x)
    {
        in.push(x);
    }
    void move()
    {
        while (!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void)
    {
        if (out.empty()){
            move();
        } 
        if (!out.empty()){
            out.pop();
        }
    }

    // Get the front element.
    int peek(void)
    {
        if (out.empty()){
            move();
        } 
        if (!out.empty()){
            return out.top();
        }
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        return in.empty() && out.empty();
    }
};