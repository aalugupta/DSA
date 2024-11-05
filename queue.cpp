#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node(T val)
    {
        this->data = val;
        this->next = NULL;
    }
};

template <class T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;

public:
    Queue()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void push(T val)
    {
        Node<T> *node1 = new Node<T>(val);
        if (head == NULL)
        {
            head = tail = node1;
        }
        else
        {
            tail->next = node1;
            tail = node1;
        }
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "Empty queue";
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    T front()
    {
        if (head == NULL)
        {
            cout << "EMPTY QUEUE";
            return -1;
        }
        return head->data;
    }
    int size()
    {
        int i = 0;
        Node<T> *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
    bool empty()
    {

        if (size() == 0)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        while (!empty())
        {
            cout << front();
            pop();
        }
    }
    void reverse()
    {
        stack<int> s;
        while (!empty())
        {
            s.push(front());
            pop();
        }
        while (!s.empty())
        {
            push(s.top());
            s.pop();
        }
    }
};
class circular_queue
{
    int *arr;
    int front = -1;
    int rear = -1;
    int capacity;
    int curr_size;

public:
    circular_queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        curr_size = 0;
    }
    void push(int val)
    {
        if (curr_size == capacity)
        {
            cout << "queue is full";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        curr_size++;
    }
    void pop()
    {
        if (curr_size == 0)
        {
            cout << "queue is empty";
            return;
        }
        front = (front + 1) % capacity;
        arr[front] = -1;
        curr_size--;
    }
    int front_()
    {
        if (curr_size == 0)
        {
            cout << "queue is empty";
            return -1;
        }
        front = (front + 1) % capacity;
        return arr[front];
    }
};

// Questions

void first_non_repeating(string str)
{
    int count[26] = {0};
    Queue<char> q;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        q.push(ch);
        count[ch - 'a']++;

        while (!q.empty() && count[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            cout << "-1" << ",";
        }
        else
        {
            cout << q.front() << ",";
        }
    }
}
void interleave_two_queues(Queue<int> q1)
{
    Queue<int> q2;
    int n = q1.size();
    for (int i = 0; i < n / 2; i++)
    {
        int temp = q1.front();
        q1.pop();
        q2.push(temp);
    }
    for (int i = 0; i < n / 2; i++)
    {
        int temp = q2.front();
        q2.pop();
        q1.push(temp);

        int temp2 = q1.front();
        q1.pop();
        q1.push(temp2);
    }
    q1.print();
}
int main()
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(0);

    // cout << q.front();

    // circular_queue cq(3);
    // cq.push(0);
    // cq.push(1);
    // cq.push(2);

    // cq.pop();

    // cq.push(4);
    // cq.pop();

    // cout << cq.front_();

    first_non_repeating("tjyt;iudsjhloworlde");
    interleave_two_queues(q);
    // q.reverse();
    // q.print();

    return 0;
}