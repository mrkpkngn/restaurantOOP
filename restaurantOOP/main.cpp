// restaurantOOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Menu.h"

int main()
{
    // Create menu
    Menu* menu = new Menu();

    // Create first category: Drinks
    MenuCategory* drinks = new MenuCategory("Drinks");
    drinks->addItem(new MenuItem("Coffee", 2.50));
    drinks->addItem(new MenuItem("Tea", 2.00));
    drinks->addItem(new MenuItem("Soda", 1.50));

    // Create second category: Food
    MenuCategory* food = new MenuCategory("Food");
    food->addItem(new MenuItem("Burger", 5.99));
    food->addItem(new MenuItem("Fries", 2.99));
    food->addItem(new MenuItem("Salad", 4.50));

    // Add categories to the menu
    menu->addCategory(drinks);
    menu->addCategory(food);

    std::cout << "Menu created successfully!" << std::endl;

    menu->displayMenu();

    // When done, clean up everything
    delete menu; // Deletes categories and items too (via destructors)

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
