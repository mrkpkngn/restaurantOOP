// restaurantOOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Menu.h"
#include "Table.h"
#include "DineIn.h"

int main()
{
	// 1. First create the fundamental MenuItems
	MenuItem* coffee = new MenuItem("Coffee", 2.50);
	MenuItem* burger = new MenuItem("Burger", 5.99);
	MenuItem* fries = new MenuItem("Fries", 2.99);

	// 2. Build the Menu structure
	MenuCategory* drinks = new MenuCategory("Drinks");
	drinks->addItem(coffee);

	MenuCategory* food = new MenuCategory("Food");
	food->addItem(burger);
	food->addItem(fries);

	Menu* menu = new Menu();
	menu->addCategory(drinks);
	menu->addCategory(food);

	// 3. Create a Table for dine-in
	Table* table1 = new Table(4); // 4-seater table

	// 4. Create the DineIn order
	DineIn* dineInOrder = new DineIn(
		table1, // table
		new OrderItem* [3] {
			new OrderItem(burger, 1),
			new OrderItem(fries, 2),
			new OrderItem(coffee, 1)
		},
		3  // itemCount
	);

	dineInOrder->printReceipt(); // Prints receipt with quantities

	dineInOrder->removeItem("Coffee");

	dineInOrder->printReceipt(); // Prints receipt with quantities

	delete dineInOrder;
	delete menu;

	return 0;
}
