#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isBST(Node *root, int minVal, int maxVal)
{
    if (!root)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "BST";
    else
        cout << "Not BST";
}
