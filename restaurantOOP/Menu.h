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
	void addCategory(MenuCategory* category);
	void removeCategory(MenuCategory* category);
	void displayMenu();
};

