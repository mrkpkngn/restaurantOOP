#pragma once
#include "MenuItem.h"
#include <iostream>

class MenuCategory
{
private:
	string _category;
	MenuItem** _items;
	int _itemsCount;

public:
	MenuCategory(string category);
	~MenuCategory();
	void addItem(MenuItem* item);
	void removeItem(MenuItem* item);
	void displayCategory();
};

