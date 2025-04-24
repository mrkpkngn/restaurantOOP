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
	MenuItem* addItem(MenuItem* item);
	bool removeItem(MenuItem* item);
	void displayCategory();
};

