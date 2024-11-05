#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Stack
{
    vector<T> vec;

public:
    void push(T val)
    {
        vec.push_back(val);
    }

    void pop()
    {
        if (vec.size() == 0)
        {
            cout << "Empty Stack";
            return;
        }
        vec.pop_back();
    }
    T top()
    {
        if (vec.size() == 0)
        {
            cout << "Empty Stack";
            return -1;
        }
        int lastind = vec.size() - 1;
        return vec[lastind];
    }
    bool isEmpty()
    {
        if (vec.size() == 0)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        while (!isEmpty())
        {
            cout << top();
            pop();
        }
    }
};

void push_at_correct_position(Stack<int>&s,int element){
    Stack<int>tmp;
    while(!s.isEmpty() && element<s.top()){
        tmp.push(s.top());
        s.pop();
    }
    s.push(element);
    while(!tmp.isEmpty()){
        s.push(tmp.top());
        tmp.pop();
    }
}

void sort(Stack<int> &s)
{
    if (s.isEmpty())
    {
        return ;
    }
    int a = s.top();
    s.pop();
    sort(s);
    // if (a > s.top() || s.isEmpty())
    // {
    //     s.push(a);
    //     return ;
    // }
    // else
    // {
    //     int b = s.top();
    //     s.pop();
    //     s.push(a);
    //     s.push(b);
    //     return ;
    // }
    push_at_correct_position(s,a);
}
template <class T>
void push_at_bottom(Stack<T> &s, T val) // we have to use 'T' as we can any type of stack int ,char etc
{
    if (s.isEmpty())
    {
        s.push(val);
        return;
    }
    T temp = s.top();
    s.pop();
    push_at_bottom(s, val);
    s.push(temp);
}
void reverse_string(Stack<char> s, string str)
{
    for (int i = 0; i < str.length(); i++)
    {

        char ch = str[i];
        s.push(ch);
    }
    s.print();
}
template <class T>
void reverse_stack(Stack<T> &s)
{
    if (s.isEmpty())
    {
        return;
    }
    T temp = s.top();
    s.pop();
    reverse_stack(s);
    push_at_bottom(s, temp);
}
void stock_span(Stack<int> s, int arr[], int n)
{
    int span[n];
    s.push(0);
    span[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        while (!s.isEmpty() && curr >= arr[s.top()])
        {
            s.pop();
        }
        if (s.isEmpty())
        {
            span[i] = i + 1;
            s.push(i);
        }
        else
        {
            int prevhigh = s.top();
            span[i] = i - prevhigh;
            s.push(i);
        }
    }
    cout << "span:";
    for (int i : span)
    {
        cout << i << ",";
    }
}
void next_greater_element(Stack<int> s, int arr[], int n)
{
    int ans[n];
    ans[n - 1] = -1;
    s.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        int curr = arr[i];
        while (!s.isEmpty() && curr >= arr[s.top()])
        {
            s.pop();
        }
        if (s.isEmpty())
        {
            ans[i] = -1;
            s.push(i);
        }
        else
        {
            ans[i] = arr[s.top()];
            s.push(i);
        }
    }
    cout << "ans:";
    for (int i : ans)
    {
        cout << i << ",";
    }
}
bool valid_paranthesis(Stack<char> s, string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if ((s.top() == '(' && ch == ')') || (s.top() == '{' && ch == '}') || (s.top() == '[' && ch == ']'))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (s.isEmpty())
    {
        return true;
    }
    return false;
}

bool duplicate_paranthesis(Stack<char> s, string str)
{
    for (char ch : str)
    {
        if (ch != ')')
        {
            s.push(ch);
        }
        else
        {
            if (s.top() == '(')
            {
                return true;
            }
            while (!s.isEmpty() && s.top() != '(')
            {
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}
vector<int> left_lower(int hist[], int n)
{
    Stack<int> s1;
    vector<int> leftlower(n, -1);
    leftlower[0] = -1;
    s1.push(0);
    for (int i = 1; i < n; i++)
    {
        int curr = hist[i];
        while (!s1.isEmpty() && curr <= hist[s1.top()])
        {
            s1.pop();
        }
        if (s1.isEmpty())
        {
            leftlower[i] = -1;
            s1.push(i);
        }
        else
        {
            leftlower[i] = s1.top();
            s1.push(i);
        }
    }
    return leftlower;
}
vector<int> right_lower(int hist[], int n)
{
    Stack<int> s1;
    vector<int> rightlower(n, n - 1);
    s1.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        int curr = hist[i];
        while (!s1.isEmpty() && curr <= hist[s1.top()])
        {
            s1.pop();
        }
        if (s1.isEmpty())
        {
            s1.push(i);
        }
        else
        {
            rightlower[i] = s1.top();
            s1.push(i);
        }
    }
    return rightlower;
}
vector<int> max_area_histogram(int hist[], int n)
{
    vector<int> leftlower = left_lower(hist, n);
    vector<int> rightlower = right_lower(hist, n);
    int width;
    vector<int> area(n, -1);
    for (int i = 0; i < n; i++)
    {
        width = rightlower[i] - leftlower[i];
        area[i] = hist[i] * width;
    }
    return area;
}
int main()
{
    Stack<int> s;
    Stack<char> s2;

    s.push(1);
    s.push(2);
    s.push(4);
    s.push(3);
    // push_at_bottom(s, 8);
    // push_at_bottom(s, 9);
    // push_at_bottom(s, 5);
    // reverse_stack(s);
     
     sort(s);
     s.print();

    // push_at_bottom(s2, 'a'); // we can't pass "a" as it will be string but we have to pass only char
    // push_at_bottom(s2, 'l');
    // push_at_bottom(s2, 'u');

    // reverse_string(s2, "Shikhar"); // in reverse string we are passing copy of s2
    // s2.print();                    // this will print only alu as this is original

    int arr[] = {234, 769, 386, 928, 279, 68, 9, 909, 2, 5, 7};

    int n = sizeof(arr) / sizeof(int);

    // stock_span(s, arr, n);
    // next_greater_element(s, arr, n);

    // cout << valid_paranthesis(s2, "({[]})");
    // cout << duplicate_paranthesis(s2, "(a+s)");
    // for (int i : max_area_histogram(arr, n))
    // {
    //     cout << i << "\n";
    // }

    return 0;
}
