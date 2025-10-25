#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    string name;
    float price;
    string description;
    bool available;
};

void swap(Product &a, Product &b)
{
    Product temp = a;
    a = b;
    b = temp;
}

int partition(Product arr[], int low, int high)
{
    float pivot = arr[high].price;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j].price < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printProducts(Product arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i].name << " " << arr[i].price << " " << arr[i].description << " " << (arr[i].available ? "Available" : "Not Available") << endl;
}

int main()
{
    Product products[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> products[i].name;
        cin >> products[i].price;
        cin.ignore();
        getline(cin, products[i].description);
        cin >> products[i].available;
    }
    quickSort(products, 0, 2);
    printProducts(products, 3);
    return 0;
}