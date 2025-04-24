#include "Menu.h"

// -------------------------------- CONSTRUCTORS --------------------------

Menu::Menu()
{
	this->_categories = new MenuCategory * [100] {nullptr};
	this->_categoriesCount = 0;
}

Menu::~Menu()
{
	for (int x = 0; x < this->_categoriesCount; x++)
	{
		delete this->_categories[x];
	}

	delete[] this->_categories;
}

// ------------------------ PROCESS FUNCTIONS -----------------------

MenuCategory* Menu::addCategory(MenuCategory* category) 
{
	this->_categories[this->_categoriesCount] = category;
	this->_categoriesCount++;
	return category;
}

bool Menu::removeCategory(MenuCategory* category)
{
	for (int x = 0; x < this->_categoriesCount; x++)
	{
		if (this->_categories[x] == category)
		{
			delete this->_categories[x];

			for (int y = x; y < this->_categoriesCount; y++)
			{
				this->_categories[y] = _categories[y + 1];
			}

			return true;
		}

	}

	cout << "Error!: Cant Find Category" << endl;
	return false;
}

void Menu::displayMenu()
{
	cout << "-------------------- MENU --------------------" << endl;
	for (int x = 0; x < this->_categoriesCount; x++)
	{
		this->_categories[x]->displayCategory();
	}
}