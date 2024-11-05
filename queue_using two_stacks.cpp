#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1, s2;

public:
    void push(int val)
    {
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                int temp = s1.top();
                s2.push(temp);
                s1.pop();
            }
            s1.push(val);

            while (!s2.empty())
            {
                int temp = s2.top();
                s1.push(temp);
                s2.pop();
            }

            return;
        }
        s1.push(val);
    }

    void pop()
    {
        s1.pop();
    }

    int front()
    {
        return s1.top();
    }
};

int main()
{
    Queue q1;

    q1.push(5);
    q1.push(7);
 
    q1.pop();

    cout << q1.front();

    return 0;
}