#pragma once
#include "MenuCategory.h"
class Menu
{
private:
	MenuCategory** _categories;
	int _categoriesCount;
public:
	Menu();
	~Menu();
	MenuCategory* addCategory(MenuCategory* category);
	bool removeCategory(MenuCategory* category);
	void displayMenu();
};

