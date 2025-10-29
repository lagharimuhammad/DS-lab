#include <iostream>
using namespace std;

class BSTNode
{
public:
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int value) : data(value), left(NULL), right(NULL) {}
};

class BST
{
private:
    BSTNode *root;

    BSTNode *insertHelper(BSTNode *node, int value)
    {
        if (node == NULL)
        {
            return new BSTNode(value);
        }
        if (value < node->data)
        {
            node->left = insertHelper(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }

    BSTNode *deleteHelper(BSTNode *node, int value)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (value < node->data)
        {
            node->left = deleteHelper(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteHelper(node->right, value);
        }
        else
        {
            if (node->left == NULL)
            {
                BSTNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BSTNode *temp = node->left;
                delete node;
                return temp;
            }
            BSTNode *temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data);
        }
        return node;
    }

    BSTNode *searchHelper(BSTNode *node, int value)
    {
        if (node == NULL || node->data == value)
        {
            return node;
        }
        if (value < node->data)
        {
            return searchHelper(node->left, value);
        }
        return searchHelper(node->right, value);
    }

    void inorderHelper(BSTNode *node)
    {
        if (node != NULL)
        {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

    void preorderHelper(BSTNode *node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }

    void postorderHelper(BSTNode *node)
    {
        if (node != NULL)
        {
            postorderHelper(node->left);
            postorderHelper(node->right);
            cout << node->data << " ";
        }
    }

    BSTNode *findMinNode(BSTNode *node)
    {
        while (node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

    BSTNode *findMaxNode(BSTNode *node)
    {
        while (node->right != NULL)
        {
            node = node->right;
        }
        return node;
    }

    int heightHelper(BSTNode *node)
    {
        if (node == NULL)
        {
            return -1;
        }
        int leftHeight = heightHelper(node->left);
        int rightHeight = heightHelper(node->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }

    int countNodesHelper(BSTNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
    }

    void destroyTree(BSTNode *node)
    {
        if (node != NULL)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    void displayHelper(BSTNode *node, int space)
    {
        if (node == NULL)
        {
            return;
        }
        space += 5;
        displayHelper(node->right, space);
        cout << endl;
        for (int i = 5; i < space; i++)
        {
            cout << " ";
        }
        cout << node->data << endl;
        displayHelper(node->left, space);
    }

public:
    BST() : root(NULL) {}

    ~BST()
    {
        destroyTree(root);
    }

    void insert(int value)
    {
        root = insertHelper(root, value);
        cout << "Inserted " << value << endl;
    }

    void remove(int value)
    {
        if (search(value))
        {
            root = deleteHelper(root, value);
            cout << "Deleted " << value << endl;
        }
        else
        {
            cout << value << " not found in tree" << endl;
        }
    }

    bool search(int value)
    {
        return searchHelper(root, value) != NULL;
    }

    void searchAndDisplay(int value)
    {
        if (search(value))
        {
            cout << value << " found in tree" << endl;
        }
        else
        {
            cout << value << " not found in tree" << endl;
        }
    }

    void inorderTraversal()
    {
        cout << "Inorder: ";
        if (root == NULL)
        {
            cout << "Tree is empty";
        }
        else
        {
            inorderHelper(root);
        }
        cout << endl;
    }

    void preorderTraversal()
    {
        cout << "Preorder: ";
        if (root == NULL)
        {
            cout << "Tree is empty";
        }
        else
        {
            preorderHelper(root);
        }
        cout << endl;
    }

    void postorderTraversal()
    {
        cout << "Postorder: ";
        if (root == NULL)
        {
            cout << "Tree is empty";
        }
        else
        {
            postorderHelper(root);
        }
        cout << endl;
    }

    void findMin()
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
        }
        else
        {
            cout << "Minimum value: " << findMinNode(root)->data << endl;
        }
    }

    void findMax()
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
        }
        else
        {
            cout << "Maximum value: " << findMaxNode(root)->data << endl;
        }
    }

    void height()
    {
        cout << "Height of tree: " << heightHelper(root) << endl;
    }

    void countNodes()
    {
        cout << "Total nodes: " << countNodesHelper(root) << endl;
    }

    bool isEmpty()
    {
        return root == NULL;
    }

    void displayTree()
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
        }
        else
        {
            cout << "Tree structure:" << endl;
            displayHelper(root, 0);
        }
    }
};

int main()
{
    BST tree;
    int choice, value;

    cout << "Binary Search Tree Operations" << endl;

    while (true)
    {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Inorder Traversal" << endl;
        cout << "5. Preorder Traversal" << endl;
        cout << "6. Postorder Traversal" << endl;
        cout << "7. Find Minimum" << endl;
        cout << "8. Find Maximum" << endl;
        cout << "9. Height of Tree" << endl;
        cout << "10. Count Nodes" << endl;
        cout << "11. Display Tree Structure" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.remove(value);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            tree.searchAndDisplay(value);
            break;

        case 4:
            tree.inorderTraversal();
            break;

        case 5:
            tree.preorderTraversal();
            break;

        case 6:
            tree.postorderTraversal();
            break;

        case 7:
            tree.findMin();
            break;

        case 8:
            tree.findMax();
            break;

        case 9:
            tree.height();
            break;

        case 10:
            tree.countNodes();
            break;

        case 11:
            tree.displayTree();
            break;

        case 12:
            cout << "Khuda Hafiz..." << endl;
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
