#include <iostream>
#include <vector>
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

    void inorder(Node *node, vector<int> &v)
    {
        if (!node)
            return;
        inorder(node->left, v);
        v.push_back(node->data);
        inorder(node->right, v);
    }

    double findMedian()
    {
        vector<int> v;
        inorder(root, v);
        int n = v.size();
        if (n == 0)
            return 0;
        if (n % 2 == 1)
            return v[n / 2];
        return (v[(n / 2) - 1] + v[n / 2]) / 2.0;
    }
};

int main()
{
    BST tree;
    tree.insertValue(17);
    tree.insertValue(51);
    tree.insertValue(1);
    tree.insertValue(33);
    tree.insertValue(8);

    cout << "Median: " << tree.findMedian();
}