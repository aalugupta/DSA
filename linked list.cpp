#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insert_at_head(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insert_at_tail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void insert_in_middle(node *&head, node *&tail, int position, int d)
{
    node *temp = new node(d);
    node *h = head;
    if (position == 1)
    {
        insert_at_head(head, d);
        return;
    }
    else
    {
        int count = 1;
        while (count < position - 1)
        {
            h = h->next;
            count++;
        }
        if (h->next == NULL)
        {
            insert_at_tail(tail, d);
            return;
        }
        else
        {
            temp->next = h->next;
            h->next = temp;
        }
    }
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    print(head);

    insert_at_head(head, 57);
    print(head);

    insert_at_head(head, 101);
    print(head);

    insert_at_tail(tail, 62);
    print(head);

    insert_at_tail(tail, 25);
    print(head);

    insert_in_middle(head, tail, 3, 89);
    print(head);
}
