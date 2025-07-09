#include <iostream>
using namespace std;

#include <fstream>
#include <conio.h>
#include <cstring>
#include <cstdlib>
// Forward declarations
void addSweets();
void displaysweet();
void searchsweet();
void updatesweet();
void deletesweet();
void addCustomer();
void displaycustomer();
void searchcustomer();
void updatecustomer();
void deletecustomer();
void takeOrder();
void displayAllOrders();
void heading();
void storeSalesByDate();
void displaySalesByDate();

// Sweet class
class Sweet
{
public:
    static int id;
    char name[50];
    char vendername[50];
    float price, quantity;

    void input()
    {
        cout << "----Sweet Details----" << endl;
        id+=1;
        cout << "Enter Sweet id: " << id << endl;
        cout << "Enter vender name: ";
        cin >> vendername;
        cout << "Enter Sweet name: ";
        cin >> name;
        cout << "Enter Sweet price: ";
        cin >> price;
        cout << "Enter Sweet quantity: ";
        cin >> quantity;
    }

    void display()
    {
        //id++;
        cout << "Sweet id" << "\t" << "Sweet Name" << "\t" << "Vender Name" << "\t" << "Price" << "\t" << "Qantity" << endl;
        cout << " " << id << "       \t" << name << "      \t" << vendername << "  \t" << price << "  \t" << quantity << " kg" << endl;
        // cout << "Sweet id: " << id << endl;
        // cout << "Sweet vender name: " << vendername << endl;
        // cout << "Sweet name: " << name << endl;
        // cout << "Sweet price: " << price << endl;
        // cout << "Sweet quantity: " << quantity << " kg" << endl;
    }
};

// Customer class
class Customer
{
public:
    static int customerid;
    char name[50];
    char address[50];
    char contact[15];
    char date[20];
    void customerinput()
    {
        cout << "----Customer Details----" << endl;
        customerid++;
        cout << "Enter customer id: " << customerid << endl;
        cout << "Enter customer name: ";
        cin >> name;
        cout << "Enter customer address: ";
        cin >> address;
        cout << "Enter customer contact number: ";
        cin >> contact;
        cout << "Enter date: ";
        cin >> date;
    }

    void customerdisplay()
    {
        //customerid++;
        cout << "Customer id:" << customerid << endl;
        cout << "Customer name: " << name << endl;
        cout << "Customer address: " << address << endl;
        cout << "Customer contact number: " << contact << endl;
        cout << "Customer date: " << date << endl;
    }
};

// Sale class
// class Sale
// {
// public:
//     int saleid;
//     float totalamount;
//     char date[30];
//     int los;

//     void saleinput()
//     {
//         cout << "----Sale Details----" << endl;
//         cout << "Enter sale id: ";
//         cin >> saleid;
//         cout << "Enter date (DD/MM/YY): ";
//         cin >> date;
//     }

//     void saledisplay()
//     {
//         cout << "Sale id: " << saleid << endl;
//         cout << "Total amount: " << totalamount << endl;
//         cout << "Date: " << date << endl;
//         cout << "List of Sweet: " << los << endl;
//     }
// };

// Order class
class Order
{
public:
    int customerID;
    char customerName[50];
    int sweetID;
    char sweetName[50];
    float quantity;
    float pricePerKg;
    float total;

    void displayOrder()
    {
        cout << "Customer ID: " << customerID << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Sweet ID: " << sweetID << endl;
        cout << "Sweet Name: " << sweetName << endl;
        cout << "Quantity: " << quantity << " kg" << endl;
        cout << "Price per kg: ₹" << pricePerKg << endl;
        cout << "Total Amount: ₹" << total << endl;
        cout << "-----------------------------\n";
    }
};

// Admin class
class Admin
{
public:
    void adminMenu()
    {
        int ch;
        char cho;

        do
        {
            cout << "\n----Main Menu----" << endl;
            cout << "1. Press 1 to enter in Sweets Sub Menu" << endl;
            cout << "2. Press 2 to enter in Customer Sub Menu" << endl;
            cout << "3. Press 3 to enter in Sales Sub Menu" << endl;
            cout << "4. Press 4 to enter in Order Sub Menu" << endl;
            cout << "5. Press 5 to Exit" << endl;
            cout << "Enter your choice: ";
            cin >> ch;

            switch (ch)
            {
            case 1:
            {
                int n;
                int how, i;
                cout << "---Sweet Sub Menu---" << endl;
                cout << "1. Add Sweet" << endl;
                cout << "2. Display Sweet" << endl;
                cout << "3. Search Sweet" << endl;
                cout << "4. Update Sweet" << endl;
                cout << "5. Delete Sweet" << endl;
                cout << "6. Go back to main menu" << endl;
                cout << "Enter your choice: ";
                cin >> n;
                if (n == 1)
                {

                    cout << "How many Sweet detail do you want to add:";
                    cin >> how;
                    for (i = 1; i <= how; i++)
                    {
                        addSweets();
                    }
                }
                else if (n == 2)
                    displaysweet();
                else if (n == 3)
                    searchsweet();
                else if (n == 4)
                    updatesweet();
                else if (n == 5)
                    deletesweet();
                else if (n == 6)
                    adminMenu();
                else
                    cout << "Invalid choice";
                break;
            }
            case 2:
            {
                int cust;
                cout << "---Customer Sub Menu---" << endl;
                cout << "1. Add Customer" << endl;
                cout << "2. Display Customer" << endl;
                cout << "3. Search Customer" << endl;
                cout << "4. Update Customer" << endl;
                cout << "5. Delete Customer" << endl;
                cout << "6. Go back to main menu" << endl;
                cout << "Enter your choice: ";
                cin >> cust;
                if (cust == 1)
                {
                    int how, i;
                    cout << "How many Customer detail do you want to add:";
                    cin >> how;
                    for (i = 1; i <= how; i++)
                    {
                        addCustomer();
                    }
                }
                else if (cust == 2)
                    displaycustomer();
                else if (cust == 3)
                    searchcustomer();
                else if (cust == 4)
                    updatecustomer();
                else if (cust == 5)
                    deletecustomer();
                else if (cust == 6)
                    adminMenu();
                else
                    cout << "Invalid choice";
                break;
            }
            case 3:
            {
                int salemenu;
                cout << "---Sale Sub Menu---" << endl;
                cout << "1. Store Today's Sale Record" << endl;
                cout << "2. Go back to main menu" << endl;
                cout << "Enter your choice: ";
                cin >> salemenu;

                // if (salemenu == 1)
                //     //storeSalesByDate();
                // else if (salemenu == 2)
                //     adminMenu();
                // else
                //     cout << "Invalid choice";
                break;
            }

            case 4:
            {
                int co1;
                cout << "---Order Sub Menu---" << endl;
                cout << "1. Take order" << endl;
                cout << "2. Display All Order" << endl;
                cout << "3. Go back to main menu" << endl;
                cout << "Enter your choice:";
                cin >> co1;
                if (co1 == 1)
                    takeOrder();
                else if (co1 == 2)
                    displayAllOrders();
                else if (co1 == 3)
                    adminMenu();
                else
                    cout << "Wrong Input";
                break;
            }
            case 5:
                cout << "Exiting.......";
                exit(0);
                break;
            default:
                cout << "Wrong input";
            }

            cout << "\nDo you want to continue (y/n): ";
            cin >> cho;

        } while (cho == 'y' || cho == 'Y');
    }
};

// Main function
// Static variable definitions (must be outside class)
// Sweet funtion start
void addSweets()
{
    Sweet s;
    ofstream fout("sweet.txt", ios::binary | ios::app);
    s.input();
    fout.write((char *)&s, sizeof(s));
    fout.close();
    cout << "\nSweet added successfully.\n";
}

void displaysweet()
{
    Sweet s;
    ifstream fin("sweet.txt", ios::binary);
    while (fin.read((char *)&s, sizeof(s)))
    {
        s.display();
        cout << "-------------------\n";
    }
    fin.close();
}

void searchsweet()
{
    int searchid;
    Sweet s;
    int found = 0;
    cout << "Enter Sweet ID to search: ";
    cin >> searchid;
    ifstream fin("sweet.txt", ios::binary);
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (s.id == searchid)
        {
            cout << "Sweet Found:\n";
            s.display();
            found = 1;
            break;
        }
    }
    fin.close();
    if (!found)
    cout << "Sweet not found.\n";
}

void updatesweet()
{
    int updateid, found = 0;
    Sweet s;
    cout << "Enter Sweet ID to update: ";
    cin >> updateid;
    
    fstream file("sweet.txt", ios::in | ios::out | ios::binary);
    while (file.read((char *)&s, sizeof(s)))
    {
        if (s.id == updateid)
        {
            cout << "Existing Record:\n";
            s.display();
            cout << "Enter new details:\n";
            s.input();
            std::streampos pos = file.tellg();
            file.seekp(pos - static_cast<std::streamoff>(sizeof(s)));
            file.write((char *)&s, sizeof(s));
            cout << "Sweet updated successfully.\n";
            found = 1;
            break;
        }
    }
    file.close();
    
    if (!found)
    cout << "Sweet ID not found.\n";
}
void deletesweet()
{
    int deleteid;
    Sweet s;
    int found = 0;
    cout << "Enter Sweet id to delete:";
    cin >> deleteid;
    ifstream fin("sweet.txt", ios::binary);
    ofstream fout("temp.txt", ios::binary);
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (s.id == deleteid)
        {
            found = 1;
            cout << "Sweet Deleted" << endl;
            s.display();
        }
        else
        {
            fout.write((char *)&s, sizeof(s));
        }
    }
    fin.close();
    fout.close();
    remove("sweet.txt");
    rename("temp.txt", "sweet.txt");
    if (found)
    {
        cout << "Sweet deleted successfully" << endl;
    }
    else
    {
        cout << "Sweet id not found" << endl;
    }
}
// sweet funtion end
// customer functions start
void addCustomer()
{
    Customer u;
    ofstream fout("customer.txt", ios::app);
    u.customerinput();
    fout.write((char *)&u, sizeof(u));
    fout.close();
    cout << "\nCustomer added successfully.\n";
}
void displaycustomer()
{
    Customer u;
    ifstream fin("customer.txt", ios::binary);
    while (fin.read((char *)&u, sizeof(u)))
    {
        
        u.customerdisplay();
        cout << "-------------------\n";
    }
    fin.close();
}
void searchcustomer()
{
    int searchcustomerid;
    Customer u;
    int found = 0;
    cout << "Enter Customer ID to search: ";
    cin >> searchcustomerid;
    ifstream fin("customer.txt", ios::binary);
    while (fin.read((char *)&u, sizeof(u)))
    {
        if (u.customerid == searchcustomerid)
        {
            cout << "Customer Found:\n";
            u.customerdisplay();
            found = 1;
            break;
        }
    }
    fin.close();
    if (!found)
    cout << "Customer not found.\n";
}
void updatecustomer()
{
    int updatecustomerid, found = 0;
    Customer u;
    cout << "Enter Customer ID to update: ";
    cin >> updatecustomerid;
    
    fstream file("customer.txt", ios::in | ios::out | ios::binary);
    while (file.read((char *)&u, sizeof(u)))
    {
        if (u.customerid == updatecustomerid)
        {
            cout << "Existing Record:\n";
            u.customerdisplay();
            cout << "Enter new details:\n";
            u.customerinput();
            std::streampos pos = file.tellg();
            file.seekp(pos - static_cast<std::streamoff>(sizeof(u)));
            file.write((char *)&u, sizeof(u));
            cout << "Sweet updated successfully.\n";
            found = 1;
            break;
        }
    }
    file.close();
    
    if (!found)
    cout << "Sweet ID not found.\n";
}
void deletecustomer()
{
    int deletecustomerid;
    Customer u;
    int found = 0;
    cout << "Enter Customer id to delete:";
    cin >> deletecustomerid;
    ifstream fin("customer.txt", ios::binary);
    ofstream fout("temp.txt", ios::binary);
    while (fin.read((char *)&u, sizeof(u)))
    {
        if (u.customerid == deletecustomerid)
        {
            found = 1;
            cout << "Customer Deleted" << endl;
            u.customerdisplay();
        }
        else
        {
            fout.write((char *)&u, sizeof(u));
        }
    }
    fin.close();
    fout.close();
    remove("customer.txt");
    rename("temp.txt", "customer.txt");
    if (found)
    {
        cout << "Customer deleted successfully" << endl;
    }
    else
    {
        cout << "Customer id not found" << endl;
    }
}
// customer funtions end

// to take order
void takeOrder()
{
    int sweetID, customerID;
    float quantity;
    Sweet s;
    Customer c;
    Order o;
    int foundCustomer = 0, foundSweet = 0;
    cout << "\n---- Take Order ----\n";
    cout << "Enter Customer ID: ";
    cin >> customerID;
    ifstream finCust("customer.txt", ios::binary);
    while (finCust.read((char *)&c, sizeof(c)))
    {
        if (c.customerid == customerID)
        {
            foundCustomer = 1;
            break;
        }
    }
    finCust.close();
    if (!foundCustomer)
    {
        cout << "Customer not found!\n";
        return;
    }
    cout << "\nCustomer Found:\n";
    c.customerdisplay();
    
    cout << "\nAvailable Sweets:\n";
    displaysweet();
    cout << "\nEnter Sweet ID to order: ";
    cin >> sweetID;
    fstream file("sweet.txt", ios::in | ios::out | ios::binary);
    streampos pos;
    while (file.read((char *)&s, sizeof(s)))
    {
        if (s.id == sweetID)
        {
            foundSweet = 1;
            pos = file.tellg();
            break;
        }
    }
    if (!foundSweet)
    {
        cout << "Sweet not found!\n";
        file.close();
        return;
    }
    cout << "\nSweet Selected:\n";
    s.display();
    
    cout << "Enter quantity in kg: ";
    cin >> quantity;
    if (quantity > s.quantity)
    {
        cout << "Sorry! Only " << s.quantity << " kg available.\n";
        file.close();
        return;
    }
    s.quantity -= quantity;
    file.seekp(pos - static_cast<streamoff>(sizeof(s)));
    file.write((char *)&s, sizeof(s));
    file.close();
    
    o.customerID = c.customerid;
    strcpy(o.customerName, c.name);
    o.sweetID = s.id;
    strcpy(o.sweetName, s.name);
    o.quantity = quantity;
    o.pricePerKg = s.price;
    o.total = quantity * s.price;
    
    ofstream fout("order.txt", ios::binary | ios::app);
    fout.write((char *)&o, sizeof(o));
    fout.close();
    
    cout << "\nOrder Summary:\n";
    o.displayOrder();
    cout << "Order saved to file successfully!\n";
}

void displayAllOrders()
{
    Order o;
    ifstream fin("order.txt", ios::binary);
    cout << "\n---- All Orders ----\n";
    while (fin.read((char *)&o, sizeof(o)))
    {
        o.displayOrder();
    }
    fin.close();
}
void heading()
{
    cout << "***************************************" << endl;
    cout << "*   SWEET SHOP SALE MANAGMENT SYSTEM  *" << endl;
    cout << "***************************************" << endl;
    cout << "Project By:- Hiten Mahendru" << endl;
    cout << "Guided By:- Ms. Madhu Chauhan" << endl;
    cout << "College:- Jagannath Community College" << endl;
}

// void showSalesByDate() {
    
//     char searchDate[15];
//     cout << "Enter date to search sales (DD-MM-YYYY): ";
//     cin >> searchDate;

//     ifstream fin("customer.txt", ios::binary);
//     if (!fin) {
    //         cout << "No customer data found.\nPress any key to continue...";
    //         getch();
    //         return;
    //     }
    
    //     Customer c;
    //     Product p;
    //     int count = 0;
    //     float totalAmount = 0;
    
    //     cout << "\nSales on Date: " << searchDate << "\n";
    //     cout << "ID\tName\tProduct\tQty\tPrice\tAmount\n";
    
    //     while (fin.read((char*)&c, sizeof(c))) {
        //         if (strcmp(c.getDate(), searchDate) == 0) {
            //             // Now find the product info
            //             ifstream prodFile("product.dat", ios::binary);
            //             while (prodFile.read((char*)&p, sizeof(p))) {
                //                 if (p.getId() == c.getProductID()) {
//                     float price = p.getPrice();
//                     float amount = c.getQuantity() * price;
//                     float discountAmt = amount * c.getDiscount() / 100;
//                     float finalAmt = amount - discountAmt;
//                     cout << c.getId() << "\t" << c.getName() << "\t" << p.getName() << "\t"
//                          << c.getQuantity() << "\t" << price << "\t" << c.getDiscount()
//                          << "%\t\t" << finalAmt << "\n";
//                     totalAmount += finalAmt;
//                     count++;
//                     break;
//                 }
//             }
//             prodFile.close();
//         }
//     }

//     fin.close();

//     if (count == 0)
//         cout << "No sales found on this date.\n";
//     else
//         cout << "\nTotal Sales Amount on " << searchDate << ": " << totalAmount << "\n";

//     cout << "Press any key to continue...";

// }
int Sweet::id = 0;
int Customer::customerid = 0;

int main()
{
    heading();
    char username[20], password[20], ch;
    int i = 0;

    cout << "================ LOGIN PAGE ================\n";
    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";

    // Read password with masking
    while (true)
    {
        ch = _getch(); // Read char without displaying it
        if (ch == 13)  // Enter key
        {
            password[i] = '\0';

            cout << endl;
            break;
        }
        else if (ch == 8 && i > 0) // Backspace key
        {
            cout << "\b \b";
            i--;
        }
        else if (i < 19) // Limit password length
        {
            password[i++] = ch;
            cout << '*';
        }
    }

    // Check credentials
    if (strcmp(username, "Hiten") == 0)
    {
        if (strcmp(password, "8860") == 0)
        {
            cout << "Login successful\n";
        }
        else
        {
            cout << "You Have Entered Wrong Password" << endl;
            exit(0);
        }
    }
    else
    {
        cout << "You Have Entere0d Wrong Username" << endl;
        exit(0);
    }
    Admin a;
    a.adminMenu();

    return 0;
}