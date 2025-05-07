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
	int getItemsCount();
	string getCategoryName();
	MenuItem* getItemByID(int index);
	MenuItem* addItem(MenuItem* item);
	bool removeItem(MenuItem* item);
	void displayCategory();
};

