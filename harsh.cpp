#include <iostream>
#include <string>
#include<fstream>
using namespace std;
void addcustomer();

// ---------- CLASSES START ----------

class Customer {
private:
    string name;
    string passportNo;
    string email;

public:
    void input() {
        cout << "Enter customer name: ";
        getline(cin, name);
        cout << "Enter passport number: ";
        getline(cin, passportNo);
        cout << "Enter email: ";
        getline(cin, email);
    }

    void display() {
        cout << "\nCustomer Details:\n";
        cout << "Name: " << name << endl;
        cout << "Passport Number: " << passportNo << endl;
        cout << "Email: " << email << endl;
    }
};

class Flight {
private:
    string flightNo;
    string origin;
    string destination;
    string departureTime;

public:
    void input() {
        cout << "Enter flight number: ";
        getline(cin, flightNo);
        cout << "Enter origin city: ";
        getline(cin, origin);
        cout << "Enter destination city: ";
        getline(cin, destination);
        cout << "Enter departure time (e.g., 15:30): ";
        getline(cin, departureTime);
    }

    void display() {
        cout << "\nFlight Details:\n";
        cout << "Flight Number: " << flightNo << endl;
        cout << "From: " << origin << " To: " << destination << endl;
        cout << "Departure Time: " << departureTime << endl;
    }
};

class Staff {
private:
    string staffID;
    string name;
    string role;

public:
    void input() {
        cout << "Enter staff ID: ";
        getline(cin, staffID);
        cout << "Enter staff name: ";
        getline(cin, name);
        cout << "Enter role (Pilot, Crew, etc.): ";
        getline(cin, role);
    }

    void display() {
        cout << "\nStaff Details:\n";
        cout << "ID: " << staffID << endl;
        cout << "Name: " << name << endl;
        cout << "Role: " << role << endl;
    }
};

class Booking {
private:
    string bookingID;
    Customer customer;
    Flight flight;

public:
    void input() {
        cout << "Enter booking ID: ";
        getline(cin, bookingID);
        cout << "\n--- Enter Customer Details ---\n";
        customer.input();
        cout << "\n--- Enter Flight Details ---\n";
        flight.input();
    }

    void display() {
        cout << "\nBooking ID: " << bookingID << endl;
        customer.display();
        flight.display();
    }

    string getBookingID() {
        return bookingID;
    }
};

class Payment {
private:
    string paymentID;
    string bookingID;
    float amount;

public:
    void input(string bID) {
        bookingID = bID;
        cout << "Enter payment ID: ";
        getline(cin, paymentID);
        cout << "Enter amount: ";
        cin >> amount;
        cin.ignore(); // clear newline character
    }

    void display() {
        cout << "\nPayment Details:\n";
        cout << "Payment ID: " << paymentID << endl;
        cout << "Booking ID: " << bookingID << endl;
        cout << "Amount: $" << amount << endl;
    }
};

// ---------- LOGIN FUNCTION ----------

bool adminLogin() {
    string username, password;
    const string correctUser = "admin";
    const string correctPass = "1234";

    cout << "====== Admin Login ======\n";
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    if (username == correctUser && password == correctPass) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Invalid credentials! Access denied.\n";
        return false;
    }
}

// ---------- MAIN PROGRAM ----------

int main() {
    if (!adminLogin()) {
        return 0;  // exit if login fails
    }

    //Customer customer;
    Flight flight;
    Staff staff;
    Booking booking;
    Payment payment;

    int choice;
    bool running = true;

    while (running) {
        cout << "\n=========== MAIN MENU ===========\n";
        cout << "1. Customer\n";
        cout << "2. Flight\n";
        cout << "3. Staff\n";
        cout << "4. Booking\n";
        cout << "5. Payment\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // handle input properly

        switch (choice) {
        case 1:
            cout << "\n--- CUSTOMER SECTION ---\n";
            // customer.input();
            // customer.display();
            // break;

        case 2:
            cout << "\n--- FLIGHT SECTION ---\n";
            flight.input();
            flight.display();
            break;

        case 3:
            cout << "\n--- STAFF SECTION ---\n";
            staff.input();
            staff.display();
            break;

        case 4:
            cout << "\n--- BOOKING SECTION ---\n";
            booking.input();
            booking.display();
            break;

        case 5:
            cout << "\n--- PAYMENT SECTION ---\n";
            payment.input(booking.getBookingID());
            payment.display();
            break;

        case 6:
            cout << "Exiting the system. Goodbye!\n";
            running = false;
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
void addcustomer()
{
    Customer customer;
    ofstream fout("cust.txt",ios::binary);
    customer.input();
    fout.write((char*)&customer,sizeof(customer));
    fout.close();
}

