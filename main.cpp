#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Hotel
{
private:
    int roomNo;
    string customerName;
    int days;
    float billAmount;

public:
    void bookRoom()
    {
        ofstream file("hotel.txt", ios::app);

        cout << "\nEnter Room Number: ";
        cin >> roomNo;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Number of Days: ";
        cin >> days;

        // Room rent per day
        billAmount = days * 2500;

        file << roomNo << endl;
        file << customerName << endl;
        file << days << endl;
        file << billAmount << endl;

        file.close();

        cout << "\nRoom Booked Successfully!\n";
        cout << "Total Bill: Rs. " << billAmount << endl;
    }

    void viewCustomers()
    {
        ifstream file("hotel.txt");

        if (!file)
        {
            cout << "\nNo Records Found!\n";
            return;
        }

        cout << "\n===== CUSTOMER DETAILS =====\n";

        while (file >> roomNo)
        {
            file.ignore();

            getline(file, customerName);
            file >> days;
            file >> billAmount;

            cout << "\nRoom Number   : " << roomNo;
            cout << "\nCustomer Name : " << customerName;
            cout << "\nDays Stayed   : " << days;
            cout << "\nBill Amount   : Rs. " << billAmount;
            cout << "\n---------------------------\n";
        }

        file.close();
    }

    void availableRooms()
    {
        cout << "\n===== AVAILABLE ROOMS =====\n";

        for (int i = 101; i <= 110; i++)
        {
            cout << "Room " << i << " Available\n";
        }
    }
};

int main()
{
    Hotel h;
    int choice;

    do
    {
        cout << "\n================================";
        cout << "\n      HOTEL MANAGEMENT SYSTEM";
        cout << "\n================================";
        cout << "\n1. Book Room";
        cout << "\n2. View Available Rooms";
        cout << "\n3. Customer Details";
        cout << "\n4. Exit";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            h.bookRoom();
            break;

        case 2:
            h.availableRooms();
            break;

        case 3:
            h.viewCustomers();
            break;

        case 4:
            cout << "\nThank You for Using the System!\n";
            break;

        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 4);

    return 0;
}
