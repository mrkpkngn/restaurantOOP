#include <iostream>
#include "System.h"
#include <cstdlib>

using namespace std;
int main()
{
    cout << "================ RESTAURANT MANAGEMENT SYSTEM ================" << endl;

    // Create the system
    System* restaurantSystem = new System();

    // Create Menu with Categories and Items
    cout << "\n--- Creating Menu ---" << endl;

    // Create Categories
    restaurantSystem->addMenuCategory("Appetizers");
    restaurantSystem->addMenuCategory("Main Course");
    restaurantSystem->addMenuCategory("Desserts");
    restaurantSystem->addMenuCategory("Drinks");

    // Add Menu Items to Categories
    restaurantSystem->addMenuItem("Appetizers", "Nachos", 8.99);
    restaurantSystem->addMenuItem("Appetizers", "Wings", 10.99);
    restaurantSystem->addMenuItem("Appetizers", "Salad", 6.99);

    restaurantSystem->addMenuItem("Main Course", "Burger", 14.99);
    restaurantSystem->addMenuItem("Main Course", "Steak", 24.99);
    restaurantSystem->addMenuItem("Main Course", "Pasta", 16.99);

    restaurantSystem->addMenuItem("Desserts", "Cake", 7.99);
    restaurantSystem->addMenuItem("Desserts", "Ice Cream", 5.99);

    restaurantSystem->addMenuItem("Drinks", "Soda", 2.99);
    restaurantSystem->addMenuItem("Drinks", "Coffee", 3.99);

    // Display the Complete Menu
    restaurantSystem->displayMenu();

    // Create Tables
    cout << "\n--- Creating Tables ---" << endl;
    restaurantSystem->addTable(2);
    restaurantSystem->addTable(4);
    restaurantSystem->addTable(6);

    Table* table1 = restaurantSystem->getTableByID(0);
    Table* table2 = restaurantSystem->getTableByID(1);
    Table* table3 = restaurantSystem->getTableByID(2);

    cout << "Created " << Table::getTotalTables() << " tables" << endl;
    cout << "Table " << table1->getTableNumber() << " has " << table1->getNumSeats() << " seats" << endl;
    cout << "Table " << table2->getTableNumber() << " has " << table2->getNumSeats() << " seats" << endl;
    cout << "Table " << table3->getTableNumber() << " has " << table3->getNumSeats() << " seats" << endl;

    cout << "Press ENTER to continue..." << endl;

    getchar();

    bool quit = false;

    while (!quit)
    {
        bool back = false;
        system("cls");
        int caseSwitch = 0;
        cout << "===== RESTAURANT POS =====" << endl;
        cout << "[1] Menu" << endl;
        cout << "[2] Order" << endl;
        cout << "[3] Table" << endl;
        cout << "[4] Reservation" << endl;
        cout << "[5] Exit" << endl;
        cout << "Enter Option: ";
        cin >> caseSwitch;

        if (cin.fail())
        {
            system("cls");
            cout << "You entered a wrong number! Please try again.\nEnter to Continue..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            continue;
        }

        switch (caseSwitch)
        {
        case 1:
        {
            while (!back)
            {
                system("cls");
                restaurantSystem->displayMenu();
                cout << "===================" << endl;
                int caseSwitchMenu = 0;
                cout << "[1] New Menu Category" << endl;
                cout << "[2] New Menu Item" << endl;
                cout << "[3] Back to Main Menu" << endl;
                cout << "Enter Option: ";
                cin >> caseSwitch;

                switch (caseSwitch)
                {
                case 1:
                {
                    system("cls");
                    string name;
                    cout << "Enter new category name: ";
                    cin.ignore(); // clear leftover newline from previous input
                    getline(cin, name); // read full line including spaces

                    if (name.empty())
                    {
                        system("cls");
                        cout << "Enter a name. Please try again.\nEnter to Continue..." << endl;
                        cin.get(); // wait for Enter
                    }
                    else
                    {
                        restaurantSystem->addMenuCategory(name);
                    }
                    break;
                }

                case 2:
                {
                    system("cls");
                    string category, name;
                    double price;

                    cout << "Enter category you want to add the item to: ";
                    cin.ignore();
                    getline(cin, category);

                    cout << "Enter item name: ";
                    getline(cin, name);

                    cout << "Enter item price: ";
                    while (!(cin >> price))
                    {
                        cout << "Invalid price. Please enter a number: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if (category.empty() || name.empty())
                    {
                        system("cls");
                        cout << "Something went wrong. Please try again.\nEnter to Continue..." << endl;
                        cin.ignore();
                        cin.get();
                    }
                    else
                    {
                        restaurantSystem->addMenuItem(category, name, price);
                    }
                    break;
                }

                case 3:
                    back = true;
                    break;
                default:
                    system("cls");
                    cout << "Invalid option. Please try again.\nEnter to Continue..." << endl;
                    cin.ignore();
                    cin.get();
                    break;
                }
            }
            break;
        }

        case 2:
        {
            while (!back)
            {
                system("cls");
                int caseSwitch = 0;
                cout << "===== PENDING ORDERS =====" << endl;
                restaurantSystem->showPendingOrders();
                cout << "===================" << endl;
                cout << "[1] Create new Dine In Order" << endl;
                cout << "[2] Create new Take Out Order" << endl;
                cout << "[3] Close Order" << endl;
                cout << "[4] Exit" << endl;
                cout << "Enter Option: ";
                cin >> caseSwitch;

                switch (caseSwitch)
                {
                case 1:
                {
                    system("cls");
                    restaurantSystem->displayTables();
                    cout << "====================" << endl;
                    int tableNumber;
                    cout << "Enter Table Number: ";
                    cin >> tableNumber;
                    Table* table = restaurantSystem->getTableByID(tableNumber);
                    if (table == nullptr)
                    {
                        cout << "You have entered a wrong number. Plese try again.\nEnter to continue..." << endl;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                    if (table->isOccupied())
                    {
                        cout << "Table is currently occupied. Please enter a different table.\nEnter to continue...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    int itemsCount;
                    cout << "How many different items do you want to order? ";
                    cin >> itemsCount;

                    if (itemsCount <= 0)
                    {
                        cout << "Invalid number of items.\nEnter to continue...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    OrderItem** orderItems = new OrderItem * [itemsCount];
                    cin.ignore();
                    for (int i = 0; i < itemsCount; ++i)
                    {
                        system("cls");
                        restaurantSystem->displayMenu();

                        string itemName;
                        int quantity;

                        cout << "Enter name of item #" << (i + 1) << ": ";
                        getline(cin, itemName);

                        MenuItem* menuItem = restaurantSystem->getMenuItemByName(itemName);
                        if (menuItem == nullptr)
                        {
                            cout << "Item not found. Try again." << endl;
                            cin.get();
                            i--;
                            continue;
                        }

                        cout << "Enter quantity for " << itemName << ": ";
                        while (!(cin >> quantity) || quantity <= 0)
                        {
                            cout << "Invalid quantity. Try again: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                        cin.ignore();
                        orderItems[i] = new OrderItem(menuItem, quantity);
                    }

                    bool isSuccess = restaurantSystem->addDineIn(restaurantSystem->getTableByID(tableNumber), orderItems, itemsCount);
                    if (isSuccess)
                    {
                        cout << "Order created successfully!\nEnter to continue...";
                    }
                    else
                    {
                        cout << "Something went wrong. Please try again.\nEnter to continue...";
                    }

                    cin.get();

                    delete[] orderItems;
                    break;
                }

                case 2:
                {
                    system("cls");
                    string customerName, pickupTime;

                    cout << "Enter customer name: ";
                    cin.ignore(); // clear newline
                    getline(cin, customerName);

                    cout << "Enter pickup time (e.g. 5:30 PM): ";
                    getline(cin, pickupTime);

                    int orderCount;
                    cout << "How many items to order: ";
                    cin >> orderCount;

                    if (orderCount <= 0) {
                        cout << "Invalid item count.\nEnter to continue...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    OrderItem** orderItems = new OrderItem * [orderCount];
                    cin.ignore(); // clear newline

                    for (int i = 0; i < orderCount; ++i)
                    {
                        system("cls");
                        restaurantSystem->displayMenu();
                        string itemName;
                        int quantity;

                        cout << "Enter item name #" << i + 1 << ": ";
                        getline(cin, itemName);

                        MenuItem* menuItem = restaurantSystem->getMenuItemByName(itemName);
                        if (!menuItem)
                        {
                            cout << "Item not found. Try again.\n";
                            --i;
                            continue;
                        }

                        cout << "Enter quantity: ";
                        while (!(cin >> quantity) || quantity <= 0)
                        {
                            cout << "Invalid quantity. Try again: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }

                        cin.ignore(); // clear newline
                        orderItems[i] = new OrderItem(menuItem, quantity);
                    }

                    bool isSuccess = restaurantSystem->addTakeOut(customerName, pickupTime, orderItems, orderCount);
                    system("cls");
                    if (isSuccess)
                    {
                        Order* order = restaurantSystem->getOrderByID(restaurantSystem->getOrdersCount() - 1);
                        order->printReceipt();
                        cout << "Takeout order placed!\nEnter to continue...";
                    }
                    else
                    {
                        cout << "Something went wrong. Please try again.\nEnter to continue...";
                    }
                    cin.get();
                    delete[] orderItems;
                }

                case 3:
                {
                    int orderID;
                    system("cls");
                    restaurantSystem->showPendingOrders();
                    cout << "=============================" << endl;
                    cout << "Enter Order Number to Close: ";
                    cin >> orderID;
                    Order* order = restaurantSystem->getOrderByID(orderID);
                    if (order == nullptr)
                    {
                        cout << "No Order with this ID is Found.\nEnter to continue...";
                        cin.ignore();
                        cin.get();
                        break;
                    }
                    order->orderComplete();
                    system("cls");
                    order->printReceipt();
                    cout << "=============================" << endl;
                    cout << "Order Successfully Closed!\nEnter to continue...";
                    cin.ignore();
                    cin.get();
                    break;
                }

                case 4:
                {
                    back = true;
                    break;
                }

                default:
                    system("cls");
                    cout << "Invalid option. Please try again.\nEnter to Continue..." << endl;
                    cin.ignore();
                    cin.get();
                    break;

                }
            }
            break;
        }

        case 3:
        {
            while (!back)
            {
                int switchCase;
                system("cls");
                restaurantSystem->displayTables();
                cout << "===================" << endl;
                cout << "[1] Add new table" << endl;
                cout << "[2] Remove table" << endl;
                cout << "[3] Show reservations under table" << endl;
                cout << "[4] Return to Main Menu" << endl;
                cout << "Enter Option: ";
                cin >> switchCase;
                switch (switchCase)
                {
                    case 1:
                    {
                        system("cls");
                        int numSeat;
                        cout << "Enter number of Seats: ";
                        cin >> numSeat;
                        bool isSuccess = restaurantSystem->addTable(numSeat);
                        if(isSuccess) cout << "New table successfully created!\nEnter to continue...";
                        cin.ignore();
                        cin.get();
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        int tableID;
                        restaurantSystem->displayTables();
                        cout << "Enter Table Number to delete: ";
                        cin >> tableID;
                        bool isSuccess = restaurantSystem->deleteTableById(tableID);
                        if(isSuccess) cout << "Table has successfully been deleted.\nEnter to continue..." << endl;
                        cin.ignore();
                        cin.get();
                        break;
                    }
                    case 3:
                    {
                        system("cls");
                        int tableID;
                        restaurantSystem->displayTables();
                        cout << "Enter Table Number: ";
                        cin >> tableID;
                        system("cls");
                        restaurantSystem->getTableByID(tableID)->printReservations();
                        cout << "========================" << endl;
                        cout << "Enter to continue...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    case 4:
                    {
                        back = true;
                        break;
                    }

                    default:
                    {
                        system("cls");
                        cout << "Invalid option. Please try again.\nEnter to Continue..." << endl;
                        cin.ignore();
                        cin.get();
                        break;
                    }

                }
            }
            break;
        }
        case 4:
        {
            while (!back)
            {
                int switchCase;
                system("cls");
                restaurantSystem->displayReservations();
                cout << "===================================" << endl;
                cout << "[1] Add Reservation" << endl;
                cout << "[2] Delete Reservation" << endl;
                cout << "[3] Back to Main Menu" << endl;
                cout << "Enter Option: ";
                cin >> switchCase;
                switch (switchCase)
                {
                    case 1:
                    {
                        system("cls");
                        string customerName, date, Time;
                        int reservedPeople;
                        cout << "Enter Customer Name: ";
                        cin.ignore();
                        getline(cin, customerName);
                        cout << "Enter Number of People: ";
                        cin >> reservedPeople;
                        cin.ignore();
                        cout << "Enter Reservation date (e.g: 05/07/2025): ";
                        getline(cin, date);
                        cout << "Enter Reservation time (e.g: 4:00 PM): ";
                        getline(cin, Time);
                        bool isSuccess = restaurantSystem->addReservation(customerName, reservedPeople, date, Time);
                        if (isSuccess)
                        {
                            cout << "Reservation was successfully made.\nEnter to continue...";
                        }
                        cin.get();
                        break;
                    }
                    case 2:
                    {
                        int reservationID;
                        system("cls");
                        restaurantSystem->displayReservations();
                        cout << "===================" << endl;
                        cout << "Enter Reservation Number to delete: ";
                        cin.ignore();
                        cin >> reservationID;
                        bool isSuccess = restaurantSystem->deleteReservationById(reservationID);
                        if (isSuccess) cout << "Reservation was successfully deleted.\nEnter to continue...";
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    case 3:
                    {
                        back = true;
                        break;
                    }

                    default:
                    {
                        system("cls");
                        cout << "Invalid option. Please try again.\nEnter to Continue..." << endl;
                        cin.ignore();
                        cin.get();
                        break;
                    }

                }
            }
            break;
        }
        case 5:
            quit = true;
            break;
        default:
            system("cls");
            cout << "You entered a wrong number! Please try again.\nEnter to Continue..." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        }
    }
    delete restaurantSystem;
    system("cls");
    cout << "====== PROGRAM COMPLETE ======" << endl;
    getchar();
    return 0;
}