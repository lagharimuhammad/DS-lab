#include <iostream>
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

class BST
{
public:
    Node *root;
    BST() { root = NULL; }

    Node *insert(Node *node, int val)
    {
        if (!node)
            return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }
    void insertValue(int val)
    {
        root = insert(root, val);
    }
    int countInRange(Node *node, int low, int high)
    {
        if (!node)
            return 0;
        if (node->data < low)
            return countInRange(node->right, low, high);
        if (node->data > high)
            return countInRange(node->left, low, high);
        return 1 + countInRange(node->left, low, high) + countInRange(node->right, low, high);
    }
    int countNodesInRange(int low, int high)
    {
        return countInRange(root, low, high);
    }
};

int main()
{
    BST tree;
    tree.insertValue(33);
    tree.insertValue(40);
    tree.insertValue(59);
    tree.insertValue(55);
    tree.insertValue(1);
    int a = 5, b = 45;
    cout << "Count: " << tree.countNodesInRange(a, b);
}