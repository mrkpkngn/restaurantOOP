#include <iostream>
#include "System.h"

int main()
{
    cout << "================ RESTAURANT MANAGEMENT SYSTEM ================" << endl;

    // Create the system
    System* restaurantSystem = new System();

    // Create Menu with Categories and Items
    cout << "\n--- Creating Menu ---" << endl;

    // Create Categories
    MenuCategory* appetizers = restaurantSystem->addMenuCategory("Appetizers");
    MenuCategory* mainCourse = restaurantSystem->addMenuCategory("Main Course");
    MenuCategory* desserts = restaurantSystem->addMenuCategory("Desserts");
    MenuCategory* drinks = restaurantSystem->addMenuCategory("Drinks");

    // Add Menu Items to Categories
    MenuItem* nachos = appetizers->addItem(restaurantSystem->addMenuItem("Nachos", 8.99));
    MenuItem* wings = appetizers->addItem(restaurantSystem->addMenuItem("Wings", 10.99));
    MenuItem* salad = appetizers->addItem(restaurantSystem->addMenuItem("Salad", 6.99));

    MenuItem* burger = mainCourse->addItem(restaurantSystem->addMenuItem("Burger", 14.99));
    MenuItem* steak = mainCourse->addItem(restaurantSystem->addMenuItem("Steak", 24.99));
    MenuItem* pasta = mainCourse->addItem(restaurantSystem->addMenuItem("Pasta", 16.99));

    MenuItem* cake = desserts->addItem(restaurantSystem->addMenuItem("Cake", 7.99));
    MenuItem* iceCream = desserts->addItem(restaurantSystem->addMenuItem("Ice Cream", 5.99));

    MenuItem* soda = drinks->addItem(restaurantSystem->addMenuItem("Soda", 2.99));
    MenuItem* coffee = drinks->addItem(restaurantSystem->addMenuItem("Coffee", 3.99));

    // Display the Complete Menu
    restaurantSystem->displayMenu();

    // Create Tables
    cout << "\n--- Creating Tables ---" << endl;
    Table* table1 = restaurantSystem->addTable(2);
    Table* table2 = restaurantSystem->addTable(4);
    Table* table3 = restaurantSystem->addTable(6);

    cout << "Created " << Table::getTotalTables() << " tables" << endl;
    cout << "Table " << table1->getTableNumber() << " has " << table1->getNumSeats() << " seats" << endl;
    cout << "Table " << table2->getTableNumber() << " has " << table2->getNumSeats() << " seats" << endl;
    cout << "Table " << table3->getTableNumber() << " has " << table3->getNumSeats() << " seats" << endl;

    // Create Reservations
    cout << "\n--- Creating Reservations ---" << endl;
    Reservation* reservation1 = restaurantSystem->addReservation("John Smith", 2, "25-04-2025", "18:00");
    Reservation* reservation2 = restaurantSystem->addReservation("Maria Garcia", 4, "25-04-2025", "19:30");

    if (reservation1 != nullptr) {
        reservation1->reservationDetails();
    }
    if (reservation2 != nullptr) {
        reservation2->reservationDetails();
    }

    // Create Dine-In Order
    cout << "\n--- Creating Dine-In Order ---" << endl;

    // Create order items individually first
    OrderItem* item1 = new OrderItem(wings, 2);
    OrderItem* item2 = new OrderItem(burger, 1);
    OrderItem* item3 = new OrderItem(soda, 2);

    // Then create the array of pointers
    OrderItem** orderItems1 = new OrderItem * [3] {nullptr};
    orderItems1[0] = item1;
    orderItems1[1] = item2;
    orderItems1[2] = item3;

    DineIn* dineInOrder = restaurantSystem->addDineIn(table1, orderItems1, 3);

    cout << "Is table " << table1->getTableNumber() << " occupied? " << (table1->isOccupied() ? "Yes" : "No") << endl;

    // Print Dine-In receipt
    cout << "\n--- Initial Dine-In Receipt ---" << endl;
    dineInOrder->printReceipt();

    // Add item to dine-in order
    cout << "\n--- Adding Cake to Dine-In Order ---" << endl;
    dineInOrder->addItem(cake, 1);
    dineInOrder->printReceipt();

    // Remove an item from dine-in order
    cout << "\n--- Removing Soda from Dine-In Order ---" << endl;
    bool removed = dineInOrder->removeItem("Soda");
    cout << "Item removed: " << (removed ? "Yes" : "No") << endl;
    dineInOrder->printReceipt();

    // Create Take-Out Order
    cout << "\n--- Creating Take-Out Order ---" << endl;

    // Create order items individually first
    OrderItem* takeoutItem1 = new OrderItem(nachos, 1);
    OrderItem* takeoutItem2 = new OrderItem(pasta, 2);

    // Then create the array of pointers
    OrderItem** orderItems2 = new OrderItem * [2] {nullptr};
    orderItems2[0] = takeoutItem1;
    orderItems2[1] = takeoutItem2;

    TakeOut* takeOutOrder = restaurantSystem->addTakeOut("Jane Doe", "20:15", orderItems2, 2);

    // Print Take-Out receipt
    cout << "\n--- Initial Take-Out Receipt ---" << endl;
    takeOutOrder->printReceipt();

    // Add item to take-out order
    cout << "\n--- Adding Ice Cream to Take-Out Order ---" << endl;
    takeOutOrder->addItem(iceCream, 2);
    takeOutOrder->printReceipt();

    // Remove an item from take-out order
    cout << "\n--- Removing Nachos from Take-Out Order ---" << endl;
    removed = takeOutOrder->removeItem("Nachos");
    cout << "Item removed: " << (removed ? "Yes" : "No") << endl;
    takeOutOrder->printReceipt();

    // Display pending orders
    cout << "\n--- Showing Pending Orders ---" << endl;
    restaurantSystem->showPendingOrders();

    // Complete the orders
    cout << "\n--- Completing Dine-In Order ---" << endl;
    dineInOrder->orderComplete();
    cout << "Is table " << table1->getTableNumber() << " occupied? " << (table1->isOccupied() ? "Yes" : "No") << endl;

    cout << "\n--- Completing Take-Out Order ---" << endl;
    takeOutOrder->orderComplete();

    // Test menu modifications
    cout << "\n--- Removing Wings from Appetizers ---" << endl;
    bool result = appetizers->removeItem(wings);
    cout << "Item removed: " << (result ? "Yes" : "No") << endl;

    // Display the updated menu
    cout << "\n--- Updated Menu ---" << endl;
    restaurantSystem->displayMenu();

    // Clean up allocated memory
    cout << "\n--- Cleaning Up ---" << endl;
    delete restaurantSystem; // This will clean up everything through the destructors

    cout << "\n================ PROGRAM COMPLETE ================" << endl;

    return 0;
}