#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int val)
{
    Node *node = new Node;
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

Node *insert(Node *root, int val)
{
    if (!root)
        return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

bool search(Node *root, int val)
{
    if (!root)
        return false;
    if (root->data == val)
        return true;
    if (val < root->data)
        return search(root->left, val);
    return search(root->right, val);
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 6);
    root = insert(root, 33);
    root = insert(root, 22);
    root = insert(root, 75);
    root = insert(root, 49);

    int val;
    cin >> val;
    if (search(root, val))
        cout << "Value exists";
    else
    {
        root = insert(root, val);
        inorder(root);
    }
}