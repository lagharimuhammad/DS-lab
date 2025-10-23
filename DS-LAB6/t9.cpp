#include <iostream>
using namespace std;

struct CircularQueue{
    int arr[10],front,rear,count;
    CircularQueue(){front=rear=count=0;}
    bool full(){return count==10;}
    bool empty(){return count==0;}
    void enqueue(int x){if(full())return;arr[rear]=x;rear=(rear+1)%10;count++;}
    void dequeue(){if(empty())return;front=(front+1)%10;count--;}
    void display(){for(int i=0;i<count;i++)cout<<arr[(front+i)%10]<<" ";}
};

int main(){
    CircularQueue q;
    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.dequeue();
    q.display();
}
// Reason:
// Circular Queue is most suitable because it efficiently reuses freed space when a message finishes.
// It handles continuous incoming and outgoing messages without wasting memory, ensuring one message
// is processed at a time while maintaining order.