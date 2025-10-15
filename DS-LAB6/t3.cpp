#include <iostream>
using namespace std;

struct OrderItem
{
    int itemId;
    int quantity;
    int tableNumber;
    int orderId;
};

class OrderQueue
{
private:
    OrderItem *orders;
    int front;
    int rear;
    int capacity;
    int size;
public:
    OrderQueue(int cap)
    {
        capacity = cap;
        orders = new OrderItem[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    ~OrderQueue()
    {
        delete[] orders;
    }
    bool isFull()
    {
        return size == capacity;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool enqueue(int orderId, int itemId, int quantity, int tableNumber)
    {
        if (isFull())
        {
            cout << "Queue is full" << orderId << endl;
            return false;
        }
        rear = (rear + 1) % capacity;
        orders[rear].orderId = orderId;
        orders[rear].itemId = itemId;
        orders[rear].quantity = quantity;
        orders[rear].tableNumber = tableNumber;
        size++;
        cout << "ID: " << orderId << " Item: " << itemId << " Qty: " << quantity << " Table: " << tableNumber << endl;
        return true;
    }
    bool dequeue(OrderItem &order)
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return false;
        }
        order = orders[front];
        front = (front + 1) % capacity;
        size--;
        cout << "ID: " << order.orderId << " Item: " << order.itemId << " Qty: " << order.quantity << " Table: " << order.tableNumber << endl;
        return true;
    }
    void displayAllOrders()
    {
        if (isEmpty())
        {
            cout << "No orders in queue" << endl;
            return;
        }
        int index = front;
        for (int i = 0; i < size; i++)
        {
            cout << orders[index].orderId << orders[index].itemId << orders[index].quantity << orders[index].tableNumber << endl;
            index = (index + 1) % capacity;
        }
    }
    OrderItem peek()
    {
        OrderItem temp;
        if (!isEmpty())
        {
            temp = orders[front];
        }
        return temp;
    }
    int getSize()
    {
        return size;
    }
    int getCapacity()
    {
        return capacity;
    }
    void resizeQueue()
    {
        int newCapacity = capacity * 2;
        OrderItem *newOrders = new OrderItem[newCapacity];
        int index = front;
        for (int i = 0; i < size; i++)
        {
            newOrders[i] = orders[index];
            index = (index + 1) % capacity;
        }
        delete[] orders;
        orders = newOrders;
        front = 0;
        rear = size - 1;
        capacity = newCapacity;

        cout << "Queue resized to capacity: " << capacity << endl;
    }
};
class ProcessedOrdersLog
{
private:
    OrderItem *processedOrders;
    int count;
    int capacity;
public:
    ProcessedOrdersLog(int cap)
    {
        capacity = cap;
        processedOrders = new OrderItem[capacity];
        count = 0;
    }
    ~ProcessedOrdersLog()
    {
        delete[] processedOrders;
    }

    void addProcessedOrder(OrderItem order)
    {
        if (count < capacity)
        {
            processedOrders[count++] = order;
        }
        else
        {
            int newCapacity = capacity * 2;
            OrderItem *newLog = new OrderItem[newCapacity];
            for (int i = 0; i < count; i++)
            {
                newLog[i] = processedOrders[i];
            }
            delete[] processedOrders;
            processedOrders = newLog;
            capacity = newCapacity;
            processedOrders[count++] = order;
        }
    }
    void displayProcessedOrders()
    {
        if (count == 0)
        {
            cout << "No processed orders yet" << endl;
            return;
        }
        for (int i = 0; i < count; i++)
        {
            cout << processedOrders[i].orderId << processedOrders[i].itemId << processedOrders[i].quantity << processedOrders[i].tableNumber << endl;
        }
        cout << "Total processed orders: " << count << endl;
    }
};

int main()
{
    OrderQueue orderQueue(5);
    ProcessedOrdersLog processedLog(10);
    orderQueue.enqueue(101, 1, 2, 5);
    orderQueue.enqueue(102, 3, 1, 7);
    orderQueue.enqueue(103, 2, 4, 3);
    orderQueue.enqueue(104, 5, 2, 5);
    orderQueue.enqueue(105, 1, 3, 9);
    orderQueue.displayAllOrders();
    orderQueue.enqueue(106, 4, 1, 2);
    orderQueue.resizeQueue();
    orderQueue.enqueue(106, 4, 1, 2);
    orderQueue.enqueue(107, 6, 2, 8);
    OrderItem processedOrder;
    for (int i = 0; i < 4; i++)
    {
        if (orderQueue.dequeue(processedOrder))
        {
            processedLog.addProcessedOrder(processedOrder);
        }
    }
    orderQueue.displayAllOrders();
    processedLog.displayProcessedOrders();
    while (!orderQueue.isEmpty())
    {
        if (orderQueue.dequeue(processedOrder))
        {
            processedLog.addProcessedOrder(processedOrder);
        }
    }
    orderQueue.dequeue(processedOrder);
    processedLog.displayProcessedOrders();
    return 0;
}
