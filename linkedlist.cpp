#include <iostream>
// #include <List>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
    ~node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->data = val;
        next = prev = NULL;
    }
};

class dlist
{
public:
    Node *head;
    Node *tail;

    dlist()
    {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val)
    {

        Node *node1 = new Node(val);
        if (head == NULL)
        {
            head = tail = node1;
        }
        head->prev = node1;
        node1->next = head;
        head = head->prev;
    }

    void push_back(int val)
    {
        Node *node1 = new Node(val);
        if (head == NULL)
        {
            head = tail = node1;
        }

        tail->next = node1;
        node1->prev = tail;
        tail = node1;
    }

    int size()
    {
        int i = 0;
        Node *temp = head;
        while (temp != 0)
        {
            i++;
            temp = temp->next;
        }

        return i;
    }

    void insert_at_middle(int val, int pos)
    {
        Node *node1 = new Node(val);
        int size_ = size();
        if (head == NULL)
        {
            head = tail = node1;
            return;
        }
        int i = 0;
        Node *temp = head;
        Node *prev_ = temp;
        while (i != size_)
        {

            if (i == pos)
            {
                node1->prev = temp->prev;
                temp->prev = node1;
                node1->next = temp;
                prev_->next = node1;
                return;
            }
            prev_ = temp;
            i++;
            temp = temp->next;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;
        head->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void print()
    {
        Node *temp = head;
        cout << "NULL<=>";
        while (temp != NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

class List
{
public:
    node *head;
    node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }
    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    void push_front(int value)
    {
        node *n = new node(value);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
    }
    void push_back(int value)
    {
        node *n = new node(value);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
    }
    void print()

    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    void insert_in_middle(int value, int pos)
    {
        node *newnode = new node(value);
        node *prev = head;
        for (int i = 0; i < pos - 1; i++)
        {
            prev = prev->next;
        }
        newnode->next = prev->next;
        prev->next = newnode;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List!!";
        }
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back()
    {
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    int search(int key)
    {
        int i = 0;
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "key found at:";
                return i;
            }
            temp = temp->next;
            i++;
        }
        return -1;
    }
    void reverse()
    {
        node *prev = NULL;
        node *curr = head;
        node *next = head;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    int size()
    {
        int i = 0;
        node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
    void find_cycle()
    {
        node *slow = head;
        node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                cout << "There is a cycle in Linked List";
                return;
            }
        }
        cout << "no cycle found";
        return;
    }
    void remove_cycle()
    {

        node *slow = head;
        node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                if (fast->next == slow || slow == fast)
                {
                    fast->next = NULL;
                    cout << "cycle removed";
                    return;
                }
                fast = fast->next;
                slow = slow->next;
            }
        }
        cout << "no cycle found";
        return;
    }
};
void print_(node *head)

{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}
int recursive_search(node *head, int key, int i)
{
    node *temp = head;
    if (temp == NULL)
    {
        return -1;
    }
    if (temp->data == key)
    {
        return i;
    }
    return recursive_search(temp->next, key, ++i);
}
void remove_nth(node *head, int i, int n, int size)
{
    node *temp = head;
    node *temp2 = NULL;

    while (i < size - n)
    {
        temp = temp->next;
        i++;
    }
    temp2 = temp->next;
    temp->next = temp->next->next;
    temp2->next = NULL;
    delete temp2;
}
node *split(node *head)
{
    node *slow = head;
    node *fast = head;
    node *prev = head;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    return slow;
}
// node* merge(node *head, node *right_head)
// {
//     if (head == nullptr) return right_head;
//     if (right_head == nullptr) return head;
//     List ans;
//      node* head_=head;
//      node* right_head_=right_head;
//     while (head_ != NULL && right_head_ != NULL)
//     {
//         if (head_->data >= right_head_->data)
//         {
//             ans.push_back(right_head_->data);
//             right_head_ = right_head_->next;
//         }
//         else
//         {
//             ans.push_back(head_->data);
//             head_ = head_->next;
//         }
//     }
//     while (head_ != NULL)
//     {
//         ans.push_back(head_->data);
//         head_ = head_->next;
//     }
//     while (right_head_ != NULL)
//     {
//         ans.push_back(right_head_->data);
//         right_head_ = right_head_->next;
//     }
//     cout<< ans.head;
//     return ans.head;
// }

node *merge(node *head, node *right_head)
{
    if (head == nullptr)
        return right_head;
    if (right_head == nullptr)
        return head;

    node *merged_head = nullptr;

    if (head->data <= right_head->data)
    {
        merged_head = head;
        merged_head->next = merge(head->next, right_head);
    }
    else
    {
        merged_head = right_head;
        merged_head->next = merge(head, right_head->next);
    }

    return merged_head;
}

node *merge_sort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *right_head = split(head);
    node *left = merge_sort(head);
    node *right = merge_sort(right_head);

    return merge(left, right);
}
node *SPLIT_reverseSecondHalf(node *head)
{
    node *slow = head;
    node *fast = head;
    node *prev = slow;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;

    node *prev_ = NULL;
    node *curr = slow;
    node *next = slow;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev_;
        prev_ = curr;
        curr = next;
    }

    prev->next = prev_;

    return head;
}
// zigzag code
node *split_(node *head)
{
    node *slow = head;
    node *fast = head;
    node *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    return slow;
}
node *reverse_(node *head2)
{
    node *prev = NULL;
    node *curr = head2;
    node *next = head2;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
node *zigzag(node *head)
{
    node *head2 = split_(head);
    node *revhead = reverse_(head2);

    node *i = head;
    node *j = revhead;
    node *temp = head;
    node *temp2 = revhead;
    node *tail = revhead;
    while (i != NULL)
    {
        i = i->next;
        temp->next = j;
        temp = i;

        tail = j;
        j = j->next;
        temp2->next = i;
        temp2 = j;
    }
    tail->next = j;
    tail = j;

    return head;
}
int main()
{
    List ll;

    ll.push_front(9);
    ll.push_front(8);
    ll.push_front(7);
    ll.push_back(10);
    ll.insert_in_middle(15, 2);

    // ll.print();

    // ll.tail->next = ll.head;

    // ll.print();
    // ll.pop_front();
    // ll.print();
    // ll.pop_back();
    // ll.print();

    // cout << ll.search(10) << endl;
    // cout << "key found at:" << recursive_search(ll.head, 10, 0) << endl;

    // ll.reverse();
    // ll.print();

    // remove_nth(ll.head, 1, 2, ll.size());
    // ll.print();

    // ll.find_cycle();
    // ll.remove_cycle();

    // print_(merge_sort(ll.head));

    // print_(SPLIT_reverseSecondHalf(ll.head));
    // print_(zigzag(ll.head));

    // List<int> l_l;

    // l_l.push_front(5);
    // l_l.push_front(6);
    // l_l.push_front(4);
    // l_l.push_front(8);
    // l_l.push_front(9);
    // l_l.push_front(1);

    // List<int>::iterator itr;
    // for (itr = l_l.begin(); itr != l_l.end(); itr++)
    // { // ll.begin only for iterators
    //     cout << (*itr);
    // }
    // // cout<<l_l.front();// head value

    // Doubly List;

    dlist dll;

    dll.push_front(15);
    dll.push_front(14);
    dll.push_back(16);
    dll.push_back(17);
    dll.insert_at_middle(20, 2);
    dll.print() ;
    
    dll.pop_front();
    dll.print();

    return 0;
}