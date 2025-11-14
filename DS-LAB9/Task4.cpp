#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int height(Node *n) { return n ? n->height : 0; }
void update(Node *n)
{
    if (n)
        n->height = 1 + max(height(n->left), height(n->right));
}
int balance(Node *n)
{
    return n ? height(n->left) - height(n->right) : 0;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    update(y);
    update(x);
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    update(x);
    update(y);
    return y;
}

Node *insertAVL(Node *root, int key)
{
    if (!root)
        return new Node(key);
    if (key < root->key)
        root->left = insertAVL(root->left, key);
    else if (key > root->key)
        root->right = insertAVL(root->right, key);
    else
        return root;

    update(root);

    int b = balance(root);
    if (b > 1 && key < root->left->key)
        return rightRotate(root);
    if (b < -1 && key > root->right->key)
        return leftRotate(root);
    if (b > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (b < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void printLevel(Node *root)
{
    if (!root)
    {
        cout << "(empty)\n";
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            Node *n = q.front();
            q.pop();
            cout << n->key << "(" << n->height << ") ";
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
        cout << "\n";
    }
}

void printBalances(Node *root)
{
    if (!root)
        return;
    printBalances(root->left);
    cout << root->key << "(" << balance(root) << ") ";
    printBalances(root->right);
}

int main()
{
    Node *root = nullptr;
    int arr[] = {10, 5, 15, 3, 7};
    for (int v : arr)
        root = insertAVL(root, v);

    cout << "Before inserting 12:\n";
    printLevel(root);

    root = insertAVL(root, 12);

    cout << "\nAfter inserting 12:\n";
    printLevel(root);

    cout << "\nBalance factors:\n";
    printBalances(root);

    cout << "\nHeight: " << height(root) << "\n";

    return 0;
}