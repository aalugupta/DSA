#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
static int idx = 0;
Node *preorder(vector<int> &nodes) // for building tree
{
    if (idx == nodes.size())
    {
        return NULL;
    }
    if (nodes[idx] == -1)
    {
        idx++;
        return NULL;
    }
    Node *node = new Node(nodes[idx++]);
    node->left = preorder(nodes);
    node->right = preorder(nodes);

    return node;
}

void preorder(Node *root) // for traversal
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    int currHeight = max(leftheight, rightheight) + 1;

    return currHeight;
}

int sum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    int currsum = leftsum + rightsum + root->data;

    return currsum;
}

int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftcount = count(root->left);
    int rightcount = count(root->right);
    int currcount = leftcount + rightcount + 1;

    return currcount;
}

int Diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int currDia = leftHeight + rightHeight + 1;

    int leftDia = Diameter(root->left);
    int rightDia = Diameter(root->right);

    int maxDia = max(max(leftDia, rightDia), currDia);
    return maxDia;
}

pair<int, int> Diameter2(Node *root)
{
    if (root == NULL)
    {
        return make_pair(0, 0);
    }

    pair<int, int> leftInfo = Diameter2(root->left);
    pair<int, int> rightInfo = Diameter2(root->right);

    int currDia = leftInfo.second + rightInfo.second + 1; // pair->Diameter,Height
    int height = max(leftInfo.second, rightInfo.second) + 1;
    int maxDia = max(max(leftInfo.first, rightInfo.first), currDia);

    return make_pair(maxDia, height);
}
bool isIdentical(Node *root, Node *subRoot)
{
    if (root == NULL && subRoot == NULL)
    {
        return true;
    }
    else if (root == NULL || subRoot == NULL)
    {
        return false;
    }
    if (root->data != subRoot->data)
    {
        return false;
    }
    return isIdentical(root->left, subRoot->left) &&
           isIdentical(root->right, subRoot->right);
}
bool subTree(Node *root, Node *subRoot)
{
    if (root == NULL && subRoot == NULL)
    {
        return true;
    }
    else if (root == NULL || subRoot == NULL)
    {
        return false;
    }

    if (root->data == subRoot->data)
    {
       return isIdentical(root,subRoot);
    }
    return false;
}

int main()
{
    vector<int> nodes = {1, 8, -1, -1, 3, 4, 5, 6};
    vector<int> arr = {8, -1, -1};
    Node *root = preorder(nodes);
    idx=0;
    Node *root2 = preorder(arr);
    preorder(root);
    cout << endl;
    preorder(root2);
    cout << endl;
    // cout << height(root);
    // cout << endl;
    // cout << sum(root);
    // cout << endl;
    // cout << count(root);
    // cout << Diameter(root);
    // cout << Diameter2(root).first;
    // cout << Diameter2(root).second;
    cout << subTree(root, root2);
    return 0;
}
