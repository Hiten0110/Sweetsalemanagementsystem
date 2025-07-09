#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
// heading of the project
void displayheading()
{
    cout << "\n========================================NURSERY SALE MANAGEMENT SYSTEM=================================================\n"
         << endl;
    cout << "\n**BY YUKTI GARG\n"
         << endl;
}
class Plant
{
public:
    char nameofplant[20];
    char typeofplant[30];
    float priceofplant;
    int quantityofplant;

    void input_plant()
    {
        cout << "enter the name of plant:";
        cin >> nameofplant;
        cout << "enter the type of plant:";
        cin >> typeofplant;
        cout << "enter the price of plant:";
        cin >> priceofplant;
        cout << "enter the quantity of plant:";
        cin >> quantityofplant;
    }
    void display_plant()
    {
        cout << "name of plant" << nameofplant << endl;
        cout << "type of plant" << typeofplant << endl;
        cout << "price of plant" << priceofplant << endl;
        cout << "quantity of plant" << quantityofplant << endl;
    }
};

class Flower
{
public:
    char nameofflower[20];
    char typeofflower[20];
    float priceofflower;
    int quantityofflower;

    void input_flower()
    {
        cout << "enter the name of flower:";
        cin >> nameofflower;
        cout << "enter the type of flower:";
        cin >> typeofflower;
        cout << "enter the price of flower:";
        cin >> priceofflower;
        cout << "enter the quantity of flower:";
        cin >> quantityofflower;
    }
    void display_flower()
    {
        cout << "name of flower" << nameofflower << endl;
        cout << "type of flower" << typeofflower << endl;
        cout << "price of flower" << priceofflower << endl;
        cout << "quantity of flower" << quantityofflower << endl;
    }
};
class Customer
{
public:
    char name[20];
    char phno[10];
    char address[20];
    int customerid;

    void input_customer()
    {

        cout << "enter customer name" << endl;
        cin >> name;
        cout << " enter customer phone number" << endl;
        cin >> phno;
        cout << "enter customer address" << endl;
        cin >> address;
    }
    void display_customer()
    {
        int i;
        for (i = 1; i <= 100; i++)
        {
            customerid += i;
            cout << "customer id:" << customerid << endl;
            cout << "customer name" << name << endl;
            cout << "customer phone number" << phno << endl;
            cout << "customer address" << address << endl;
        }
        // cout << "customer id:" << customerid << endl;
        //  cout << "customer name" << name << endl;
        //  cout << "customer phone number" << phno << endl;
        //  cout << "customer address" << address << endl;
    }
};
class Order
{
public:
    char customerName[30];
    char productName[30];
    char productType[10];
    int quantity;
    float pricePerUnit;
    float total;

    void displayOrder()
    {
        cout << "\n--- Order Details ---\n";
        cout << "Customer Name : " << customerName << endl;
        cout << "Product Name  : " << productName << endl;
        cout << "Product Type  : " << productType << endl;
        cout << "Quantity      : " << quantity << endl;
        cout << "Price/Unit    : ₹" << pricePerUnit << endl;
        cout << "Total         : ₹" << total << endl;
    }
};

void takeOrder()
{
    Customer c;
    Plant p;
    Flower f;
    Order o;

    int customerID;
    char plantName[20], flowerName[20];
    int plantQty = 0, flowerQty = 0;
    int foundCustomer = 0, foundPlant = 0, foundFlower = 0;
    float totalBill = 0.0;
    float plantTotal = 0.0, flowerTotal = 0.0;

    cout << "\n--- Take Order (Plant + Flower) ---\n";
    cout << "Enter Customer ID: ";
    cin >> customerID;

    // Find customer
    ifstream finCust("customer1.txt", ios::binary);
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
    c.display_customer();

    // ---------- PLANT ORDER ----------
    cout << "\nEnter Plant Name: ";
    cin >> plantName;
    cout << "Enter Quantity for Plant: ";
    cin >> plantQty;

    fstream plantFile("plant.txt", ios::in | ios::out | ios::binary);
    streampos plantPos;
    while (plantFile.read((char *)&p, sizeof(p)))
    {
        if (strcmp(p.nameofplant, plantName) == 0)
        {
            foundPlant = 1;
            plantPos = plantFile.tellg();

            if (plantQty > p.quantityofplant)
            {
                cout << "Only " << p.quantityofplant << " available.\n";
                plantFile.close();
                return;
            }

            p.quantityofplant -= plantQty;
            plantFile.seekp(plantPos - static_cast<streamoff>(sizeof(p)));
            plantFile.write((char *)&p, sizeof(p));
            plantTotal = plantQty * p.priceofplant;
            break;
        }
    }
    plantFile.close();

    // ---------- FLOWER ORDER ----------
    cout << "\nEnter Flower Name: ";
    cin >> flowerName;
    cout << "Enter Quantity for Flower: ";
    cin >> flowerQty;

    fstream flowerFile("flower.txt", ios::in | ios::out | ios::binary);
    streampos flowerPos;
    while (flowerFile.read((char *)&f, sizeof(f)))
    {
        if (strcmp(f.nameofflower, flowerName) == 0)
        {
            foundFlower = 1;
            flowerPos = flowerFile.tellg();

            if (flowerQty > f.quantityofflower)
            {
                cout << "Only " << f.quantityofflower << " available.\n";
                flowerFile.close();
                return;
            }

            f.quantityofflower -= flowerQty;
            flowerFile.seekp(flowerPos - static_cast<streamoff>(sizeof(f)));
            flowerFile.write((char *)&f, sizeof(f));
            flowerTotal = flowerQty * f.priceofflower;
            break;
        }
    }
    flowerFile.close();

    if (!foundPlant)
    {
        cout << "Plant not found!\n";
    }
    if (!foundFlower)
    {
        cout << "Flower not found!\n";
    }

    if (!foundPlant && !foundFlower)
        return;

    ofstream fout("order1.txt", ios::binary | ios::app);

    if (foundPlant)
    {
        strcpy(o.customerName, c.name);
        strcpy(o.productName, plantName);
        strcpy(o.productType, "plant");
        o.quantity = plantQty;
        o.pricePerUnit = p.priceofplant;
        o.total = plantTotal;
        fout.write((char *)&o, sizeof(o));
    }

    if (foundFlower)
    {
        strcpy(o.customerName, c.name);
        strcpy(o.productName, flowerName);
        strcpy(o.productType, "flower");
        o.quantity = flowerQty;
        o.pricePerUnit = f.priceofflower;
        o.total = flowerTotal;
        fout.write((char *)&o, sizeof(o));
    }

    fout.close();

    // ------ DISPLAY FINAL BILL -------
    cout << "\n---------- ORDER BILL ----------\n";
    cout << "Customer Name: " << c.name << endl;

    if (foundPlant)
    {
        cout << "\nPLANT ORDERED:\n";
        cout << "Name     : " << plantName << endl;
        cout << "Quantity : " << plantQty << endl;
        cout << "Price    : ₹" << p.priceofplant << " per unit\n";
        cout << "Total    : ₹" << plantTotal << endl;
    }

    if (foundFlower)
    {
        cout << "\nFLOWER ORDERED:\n";
        cout << "Name     : " << flowerName << endl;
        cout << "Quantity : " << flowerQty << endl;
        cout << "Price    : ₹" << f.priceofflower << " per unit\n";
        cout << "Total    : ₹" << flowerTotal << endl;
    }

    totalBill = plantTotal + flowerTotal;
    cout << "\n-------------------------------";
    cout << "\nTotal Bill (Plant + Flower): ₹" << totalBill;
    cout << "\n-------------------------------\n";
    cout << "Order saved successfully!\n";
}
// adding plant
void addplant()
{
    Plant p;
    ofstream outfile("plant.txt", ios::binary | ios::app);
    p.input_plant();
    outfile.write((char *)&p, sizeof(p));
    outfile.close();
    cout << "plant added successfully" << endl;
}
// display all plants
void displayplant()
{
    Plant p;
    ifstream infile("plant.txt", ios::binary);
    cout << "\n====list of plant====\n";
    while (infile.read((char *)&p, sizeof(p)))
    {
        p.display_plant();
    }
    infile.close();
}
// search a plant name
void searchplant()
{
    char plantn[50];
    int found = 0;
    Plant p;
    cout << "enter the plant name to search";
    cin >> plantn;
    ifstream fin("plant.txt", ios::binary);
    while (fin.read((char *)&p, sizeof(p)))
    {
        if (strcmp(p.nameofplant, plantn) == 0)
        {
            cout << "\n plant found: \n";
            p.display_plant();
            found = 1;
            break;
        }
    }
    fin.close();
    if (!found)
    {
        cout << "plant not found";
    }
}
// update a plant
void updateplant()
{
    char updateplant[20], found = 0;
    Plant p;
    cout << "enter the plant name to update ";
    cin >> updateplant;
    fstream file("plant.txt", ios::in | ios::out | ios::binary);
    streampos pos = file.tellg();
    while (file.read((char *)&p, sizeof(p)))
    {
        if (strcmp(p.nameofplant, updateplant) == 0)
        {
            cout << "existing record \n";
            p.display_plant();
            cout << "enter the new details";
            p.input_plant();

            file.seekp(pos);
            file.write((char *)&p, sizeof(p));
            cout << "plant updated sucessfully. \n";
            found = 1;
            break;
        }
    }
    file.close();
}
// delete a plant
void deleteplant()
{
    char deletenameofplant[20];
    Plant p;
    int found = 0;
    cout << "enter the plant name to delete";
    cin >> deletenameofplant;
    ifstream fin("plant.txt", ios::binary);
    ofstream fout("temp.txt", ios::binary);
    while (fin.read((char *)&p, sizeof(p)))
    {
        if (strcmp(p.nameofplant, deletenameofplant) == 0)
        {
            found = 1;
            cout << "plant deleted" << endl;
            p.display_plant();
        }
        else
        {
            fout.write((char *)&p, sizeof(p));
        }
    }
    fin.close();
    fout.close();
    remove("plant.txt");
    rename("temp.txt", "plant.txt");
    if (found)
    {
        cout << "plant deletd successfully" << endl;
    }
    else
    {
        cout << "plant  not found" << endl;
    }
}
// adding a flower
void addflower()
{
    Flower f;
    ofstream outfile("flower.txt", ios::binary | ios::app);
    f.input_flower();
    outfile.write((char *)&f, sizeof(f));
    outfile.close();
    cout << "flower added successfully" << endl;
}
// display all flower
void displayflower()
{
    Flower f;
    ifstream infile("flower.txt", ios::binary);
    cout << "\n====list of flower====\n";
    while (infile.read((char *)&f, sizeof(f)))
    {
        f.display_flower();
    }
    infile.close();
}
// search a flower by name
void searchflower()
{
    char flowern[50];
    int found = 0;
    Flower f;
    cout << "enter the flower name to search";
    cin >> flowern;
    ifstream fin("flower.txt", ios::binary);
    while (fin.read((char *)&f, sizeof(f)))
    {
        if (strcmp(f.nameofflower, flowern) == 0)
        {
            cout << "\n flower found: \n";
            f.display_flower();
            found = 1;
            break;
        }
    }
    fin.close();
    if (!found)
    {
        cout << "flower not found";
    }
}
// update a flower
void updateflower()
{
    char updateflower[20];
    int found = 0;
    Flower f;
    cout << "enter the flower name to update ";
    cin >> updateflower;
    fstream file("flower.txt", ios::in | ios::out | ios::binary);
    while (file.read((char *)&f, sizeof(f)))
    {
        if (strcmp(f.nameofflower, updateflower) == 0)
        {
            cout << "existing record \n";
            f.display_flower();
            cout << "enter the new details";
            f.input_flower();
            streampos pos = file.tellg();
            file.seekp(pos);
            file.write((char *)&f, sizeof(f));
            cout << "flower updated sucessfully. \n";
            found = 1;
            break;
        }
    }
    file.close();
}

// delete a flower
void deleteflower()
{
    char deletenameofflower[20];
    Flower f;
    int found = 0;
    cout << "enter the flower name to delete";
    cin >> deletenameofflower;
    ifstream fin("flower.txt", ios::binary);
    ofstream fout("temp.txt", ios::binary);
    while (fin.read((char *)&f, sizeof(f)))
    {
        if (strcmp(f.nameofflower, deletenameofflower) == 0)
        {
            found = 1;
            cout << "flower deleted" << endl;
            f.display_flower();
        }
        else
        {
            fout.write((char *)&f, sizeof(f));
        }
    }
    fin.close();
    fout.close();
    remove("flower.txt");
    rename("temp.txt", "flower.txt");
    if (found)
    {
        cout << "flower deletd successfully" << endl;
    }
    else
    {
        cout << "flower not found" << endl;
    }
}
// adding a customer
void addcustomer()
{
    Customer c;
    ofstream outfile("customer1.txt", ios::app);
    c.input_customer();
    outfile.write((char *)&c, sizeof(c));
    outfile.close();
    cout << "customer added successfully" << endl;
}
// display all customer
void displaycustomer()
{
    Customer c;
    ifstream infile("customer1.txt", ios::binary);
    cout << "\n====list of customer====\n";
    while (infile.read((char *)&c, sizeof(c)))
    {
        c.display_customer();
    }
    infile.close();
}
// search a customer by name
void searchcustomer()
{

    char customerphone[10];
    int found = 0;
    Customer c;
    cout << "enter the customer phone no. to search";
    cin >> customerphone;
    ifstream fin("customer1.txt", ios::in);
    while (fin.read((char *)&c, sizeof(c)))
    {
        if (strcmp(c.phno, customerphone) == 0)
        {
            cout << "\n customer found: \n";
            c.display_customer();
            found = 1;
            break;
        }
    }
    fin.close();
    if (!found)
    {
        cout << "customer not found";
    }
}
// update a customer
void updatecustomer()
{
    char updatecustomer[20];
    int found = 0;
    Customer c;
    cout << "enter the customer name to update ";
    cin >> updatecustomer;
    fstream file("customer1.txt", ios::in | ios::out | ios::binary);
    while (file.read((char *)&c, sizeof(c)))
    {
        if (strcmp(c.name, updatecustomer) == 0)
        {
            cout << "existing record \n";
            c.display_customer();
            cout << "enter the new details";
            c.input_customer();
            streampos pos = file.tellg();
            file.seekp(pos);
            file.write((char *)&c, sizeof(c));
            cout << "customer updated sucessfully. \n";
            found = 1;
            break;
        }
    }
    file.close();
}
// delete a customer
void deletecustomer()
{
    char deletenameofcustomer[20];
    Customer c;
    int found = 0;
    cout << "enter the customer name to delete";
    cin >> deletenameofcustomer;
    ifstream fin("customer1.txt", ios::binary);
    ofstream fout("temp1.txt", ios::binary);
    while (fin.read((char *)&c, sizeof(c)))
    {
        if (strcmp(c.name, deletenameofcustomer) == 0)
        {
            found = 1;
            cout << "customer deleted" << endl;
            c.display_customer();
        }
        else
        {
            fout.write((char *)&c, sizeof(c));
        }
    }
    fin.close();
    fout.close();
    remove("customer1.txt");
    rename("temp1.txt", "customer1.txt");
    if (found)
    {
        cout << "customer deletd successfully" << endl;
    }
    else
    {
        cout << "customer not found" << endl;
    }
}
void mainmenu()
{
    int main_choice, sub_choice;
    do
    {
        cout << "\n ****main menu**** \n";
        cout << "1. plant section\n";
        cout << "2. flower section \n";
        cout << "3. customer details \n";
        cout << "4. order \n";
        cout << "5. exit \n";
        cout << "enter your choice :";
        cin >> main_choice;
        switch (main_choice)
        {
        case 1:
            cout << "\n ********** welcome to plant section********** \n"
                 << endl;
            cout << "1. adding a plant" << endl;
            cout << "2. display all plants" << endl;
            cout << "3. search a plant " << endl;
            cout << "4. update a plant" << endl;
            cout << "5. delete a plant" << endl;
            cout << "6. Go back to main menu:" << endl;
            cout << "enter your choice:";
            cin >> sub_choice;
            switch (sub_choice)
            {
            case 1:
                addplant();
                break;
            case 2:
                displayplant();
                break;
            case 3:
                searchplant();
                break;
            case 4:
                updateplant();
                break;
            case 5:
                deleteplant();
                break;
            case 6:
                mainmenu();
                break;
            default:
                cout << "invalid option .\n";
            }
            break;
        case 2:
            cout << "\n *********welcome to flower section*\n"
                 << endl;
            cout << "1. adding a flower " << endl;
            cout << "2. display all flowers" << endl;
            cout << "3. search a flower" << endl;
            cout << "4. update a flower" << endl;
            cout << "5. delete a flower" << endl;
            cout << "6. Go to main menu" << endl;
            cout << "Enter your choice:";
            cin >> sub_choice;
            switch (sub_choice)
            {
            case 1:
                addflower();
                break;
            case 2:
                displayflower();
                break;
            case 3:
                searchflower();
                break;
            case 4:
                updateflower();
                break;
            case 5:
                deleteflower();
                break;
            case 6:
                mainmenu();
                break;
            default:
                cout << "invalid option. \n";
            }
            break;
        case 3:
            cout << " \n **********customer details are **********\n"
                 << endl;
            cout << "1. adding a customer" << endl;
            cout << "2. display all customers" << endl;
            cout << "3. search a customer" << endl;
            cout << "4. update a customer" << endl;
            cout << "5. delete a customer" << endl;
            cout << "6. Go to main menu" << endl;
            cout << "Enter your choice:";
            cin >> sub_choice;
            switch (sub_choice)
            {
            case 1:
                addcustomer();
                break;
            case 2:
                displaycustomer();
                break;
            case 3:
                searchcustomer();
                break;
            case 4:
                updatecustomer();
                break;
            case 5:
                deletecustomer();
                break;
            case 6:
                mainmenu();
                break;
            default:
                cout << "invalid choice \n";
            }
            break;
        case 4:
            takeOrder();
            break;

        case 5:
            cout << "==== thank you! ==== \n";
            break;
        default:
            cout << "invalid choice .\n";
        }
    } while (main_choice != 5);
}

int main()
{
    Plant p;
    Flower f;
    Customer c;
    int main_choice, sub_choice;

    char username[20], password[20];
    cout << "====Login Page====" << endl;
    cout << "Enter your username:";
    cin >> username;
    cout << "Enter your password:";
    cin >> password;
    if (strcmp(username, "yukti") == 0)
    {
        if (strcmp(password, "yuk12345") == 0)
        {
            cout << "login successfull" << endl;
        }
        else
        {
            cout << "you have entered wrong password" << endl;
            exit(0);
        }
    }
    else
    {
        cout << "you have entered wrong username" << endl;
        exit(0);
    }

    displayheading();
    mainmenu();

    //     cout << "\n ****main menu**** \n";
    //     cout << "1. plant section\n";
    //     cout << "2. flower section \n";
    //     cout << "3. customer details \n";
    //     cout << "4. order \n";
    //     cout << "5. exit \n";
    //     cout << "enter your choice :";
    //     cin >> main_choice;
    //     switch (main_choice)
    //     {
    //     case 1:
    //     do{
    //         cout << "\n ********** welcome to plant section********** \n"
    //              << endl;
    //         cout << "1. adding a plant" << endl;
    //         cout << "2. display all plants" << endl;
    //         cout << "3. search a plant " << endl;
    //         cout << "4. update a plant" << endl;
    //         cout << "5. delete a plant" << endl;
    //         cout << "enter your choice:";
    //         cin >> sub_choice;
    //         switch (sub_choice)
    //         {
    //         case 1:
    //             addplant();
    //             break;
    //         case 2:
    //             displayplant();
    //             break;
    //         case 3:
    //             searchplant();
    //             break;
    //         case 4:
    //             updateplant();
    //             break;
    //         case 5:
    //             deleteplant();
    //             break;
    //         default:
    //             cout << "invalid option .\n";
    //         }
    //         break;
    //     case 2:
    //         cout << "\n *********welcome to flower section*\n"
    //              << endl;
    //         cout << "1. adding a flower " << endl;
    //         cout << "2. display all flowers" << endl;
    //         cout << "3. search a flower" << endl;
    //         cout << "4. update a flower" << endl;
    //         cout << "5. delete a flower" << endl;
    //         cout << "Enter your choice:";
    //         cin >> sub_choice;
    //         switch (sub_choice)
    //         {
    //         case 1:
    //             addflower();
    //             break;
    //         case 2:
    //             displayflower();
    //             break;
    //         case 3:
    //             searchflower();
    //             break;
    //         case 4:
    //             updateflower();
    //             break;
    //         case 5:
    //             deleteflower();
    //             break;
    //         default:
    //             cout << "invalid option. \n";
    //         }
    //         break;
    //     case 3:
    //         cout << " \n **********customer details are **********\n"
    //              << endl;
    //         cout << "1. adding a customer" << endl;
    //         cout << "2. display all customers" << endl;
    //         cout << "3. search a customer" << endl;
    //         cout << "4. update a customer" << endl;
    //         cout << "5. delete a customer" << endl;
    //         cout << "Enter your choice:";
    //         cin >> sub_choice;
    //         switch (sub_choice)
    //         {
    //         case 1:
    //             addcustomer();
    //             break;
    //         case 2:
    //             displaycustomer();
    //             break;
    //         case 3:
    //             searchcustomer();
    //             break;
    //         case 4:
    //             updatecustomer();
    //             break;
    //         case 5:
    //             deletecustomer();
    //             break;
    //         default:
    //             cout << "invalid choice \n";
    //         }
    //         break;
    //     case 4:
    //         takeOrder();
    //         break;

    //     case 5:
    //         cout << "==== thank you! ==== \n";
    //         break;
    //     default:
    //         cout << "invalid choice .\n";
    //     }
    // } while (main_choice != 5);
    return 0;
}