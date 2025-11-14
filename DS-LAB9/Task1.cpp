#include <iostream>
#include <vector>
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
void updateHeight(Node *n)
{
    if (n)
        n->height = 1 + max(height(n->left), height(n->right));
}

void inorder(Node *root, vector<int> &out)
{
    if (!root)
        return;
    inorder(root->left, out);
    out.push_back(root->key);
    inorder(root->right, out);
}

Node *sortedToAVL(const vector<int> &arr, int l, int r)
{
    if (l > r)
        return nullptr;
    int mid = (l + r) / 2;
    Node *root = new Node(arr[mid]);
    root->left = sortedToAVL(arr, l, mid - 1);
    root->right = sortedToAVL(arr, mid + 1, r);
    updateHeight(root);
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
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            Node *n = q.front();
            q.pop();
            cout << n->key << "(" << height(n) << ") ";
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
        cout << "\n";
    }
}

int main()
{
    Node *bst = new Node(4);
    bst->right = new Node(8);
    bst->right->right = new Node(10);
    bst->right->right->right = new Node(12);
    bst->right->right->right->right = new Node(16);

    cout << "Original BST:\n";
    printLevel(bst);

    vector<int> sorted;
    inorder(bst, sorted);

    Node *avl = sortedToAVL(sorted, 0, sorted.size() - 1);

    cout << "\nConverted AVL:\n";
    printLevel(avl);

    return 0;
}
