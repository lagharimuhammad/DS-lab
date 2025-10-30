#include <iostream>
using namespace std;

struct Node
{
    int productID;
    int quantity;
    Node *left;
    Node *right;
    Node(int id, int qty)
    {
        productID = id;
        quantity = qty;
        left = right = NULL;
    }
};

class inventoryBST
{
public:
    Node *root;
    inventoryBST() { root = NULL; }

    Node *insert(Node *node, int id, int qty)
    {
        if (!node)
            return new Node(id, qty);
        if (id < node->productID)
            node->left = insert(node->left, id, qty);
        else if (id > node->productID)
            node->right = insert(node->right, id, qty);
        else
            node->quantity = qty;
        return node;
    }

    void insertProduct(int id, int qty)
    {
        root = insert(root, id, qty);
    }

    Node *search(Node *node, int id)
    {
        if (!node || node->productID == id)
            return node;
        if (id < node->productID)
            return search(node->left, id);
        return search(node->right, id);
    }

    void searchProduct(int id)
    {
        Node *res = search(root, id);
        if (res)
            cout << "Product ID: " << res->productID << " Quantity: " << res->quantity << endl;
        else
            cout << "Product not found\n";
    }

    void updateQuantity(int id, int newQty)
    {
        Node *res = search(root, id);
        if (res)
            res->quantity = newQty;
        else
            cout << "Product not found\n";
    }

    void findMaxQuantity(Node *node, int &maxID, int &maxQty)
    {
        if (!node)
            return;
        if (node->quantity > maxQty)
        {
            maxQty = node->quantity;
            maxID = node->productID;
        }
        findMaxQuantity(node->left, maxID, maxQty);
        findMaxQuantity(node->right, maxID, maxQty);
    }

    void productWithMaxQuantity()
    {
        int maxID = -1, maxQty = -1;
        findMaxQuantity(root, maxID, maxQty);
        if (maxID == -1)
            cout << "inventory empty\n";
        else
            cout << "Max Quantity Product ID: " << maxID << " Quantity: " << maxQty << endl;
    }
};

int main()
{
    inventoryBST i;
    i.insertProduct(101, 130);
    i.insertProduct(105, 550);
    i.insertProduct(103, 200);
    i.insertProduct(102, 470);

    i.searchProduct(103);
    i.updateQuantity(105, 600);
    i.searchProduct(105);
    i.productWithMaxQuantity();
}
