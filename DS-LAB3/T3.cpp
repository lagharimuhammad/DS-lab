#include <bits/stdc++.h>
using namespace std;

struct Customer
{
    string name;
    Customer* next;
    Customer(string n) : name(n), next(nullptr) {}
};

Customer* bookTicket(Customer* head, string name)
{
    Customer* newCustomer = new Customer(name);

    if (!head || head->name > name)
    {
        newCustomer->next = head;
        return newCustomer;
    }

    Customer* current = head;
    while (current->next && current->next->name < name)
    {
        current = current->next;
    }

    newCustomer->next = current->next;
    current->next = newCustomer;
    return head;
}

Customer* cancelBooking(Customer* head, string name)
{
    if (!head)
        return nullptr;

    if (head->name == name)
    {
        Customer* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Customer* current = head;
    while (current->next && current->next->name != name)
    {
        current = current->next;
    }

    if (current->next)
    {
        Customer* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    return head;
}

bool isBooked(Customer* head, string name)
{
    Customer* current = head;
    while (current)
    {
        if (current->name == name)
            return true;
        current = current->next;
    }
    return false;
}

void showAllBookings(Customer* head)
{
    if (!head)
    {
        cout << "No bookings at the moment.\n";
        return;
    }
    Customer* current = head;
    cout << "Currently booked passengers: ";
    while (current)
    {
        cout << current->name << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Customer* head = nullptr;
    int option;
    string name;

    do
    {
        cout << "\n--- Airline Booking System ---\n";
        cout << "1. Book a Ticket\n";
        cout << "2. Cancel a Booking\n";
        cout << "3. Check Booking\n";
        cout << "4. View All Bookings\n";
        cout << "5. Exit\n";
        cout << "Enter your option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter passenger name for booking: ";
            cin >> name;
            head = bookTicket(head, name);
            break;

        case 2:
            cout << "Enter passenger name to cancel: ";
            cin >> name;
            head = cancelBooking(head, name);
            break;

        case 3:
            cout << "Enter passenger name to check: ";
            cin >> name;
            if (isBooked(head, name))
                cout << name << " is successfully booked.\n";
            else
                cout << name << " does not have a booking.\n";
            break;

        case 4:
            showAllBookings(head);
            break;

        case 5:
            cout << "Thank you for using the booking system.\n";
            break;

        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    } while (option != 5);

    return 0;
}
