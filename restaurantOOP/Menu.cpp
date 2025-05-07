#include "Menu.h"

// -------------------------------- CONSTRUCTORS --------------------------

Menu::Menu()
{
	this->_categories = new MenuCategory * [100] {nullptr};
	this->_categoriesCount = 0;
}

Menu::~Menu()
{
	if (_categories != nullptr) {
		for (int x = 0; x < this->_categoriesCount; x++)
		{
			if (this->_categories[x] != nullptr) {
				delete this->_categories[x];
				this->_categories[x] = nullptr;
			}
		}
		delete[] this->_categories;
		this->_categories = nullptr;
	}
}

//------------------------- GET FUNCTIONS ---------------------------
int Menu::getCategoriesCount()
{
	return this->_categoriesCount;
}

MenuCategory* Menu::getCategoryByID(int index)
{
	if (index < this->_categoriesCount)
	{
		return this->_categories[index];
	}
	cout << "Error!: Category not found!" << endl;
	return nullptr;
}
// ------------------------ PROCESS FUNCTIONS -----------------------

MenuCategory* Menu::addCategory(MenuCategory* category)
{
	for (int i = 0; i < this->_categoriesCount; i++)
	{
		if (this->_categories[i] == nullptr)
		{
			this->_categories[i] = category;
			return category;
		}
	}

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

			for (int y = x; y < this->_categoriesCount - 1; y++)
			{
				this->_categories[y] = _categories[y + 1];
			}

			this->_categories[this->_categoriesCount - 1] = nullptr;
			this->_categoriesCount--;
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