#include <iomanip> // Add this include directive at the top of the file to fix the error

// Existing code remains unchanged
#include "MenuCategory.h"

// -------------------------------- CONSTRUCTORS --------------------------

MenuCategory::MenuCategory(string category)
{
this->_category = category;
this->_items = new MenuItem * [100] {nullptr};
this->_itemsCount = 0;
}

MenuCategory::~MenuCategory()
{
if (_items != nullptr) {
	for (int x = 0; x < this->_itemsCount; x++)
	{
		if (this->_items[x] != nullptr) {
			delete this->_items[x];
			this->_items[x] = nullptr;
		}
	}
	delete[] _items;
	_items = nullptr;
}
}

// ------------------------ GET FUNCTIONS ---------------------------

int MenuCategory::getItemsCount()
{
return this->_itemsCount;
}

MenuItem* MenuCategory::getItemByID(int index)
{
if (index < this->_itemsCount)
{
	return this->_items[index];
}
cout << "Error!: Item not found!" << endl;
return nullptr;
}

string MenuCategory::getCategoryName()
{
return this->_category;
}

// ------------------------ PROCESS FUNCTIONS -----------------------

MenuItem* MenuCategory::addItem(MenuItem* item)
{
for (int i = 0; i < this->_itemsCount; i++)
{
	if (this->_items[i] == nullptr)
	{
		this->_items[i] = item;
		return item;
	}
}

this->_items[_itemsCount] = item;
_itemsCount++;

return item;
}

bool MenuCategory::removeItem(MenuItem* item)
{
for (int x = 0; x < this->_itemsCount; x++)
{
	if (this->_items[x] == item)
	{
		delete this->_items[x];

		for (int y = x; y < this->_itemsCount - 1; y++)
		{
			this->_items[y] = this->_items[y + 1];
		}

		this->_items[this->_itemsCount - 1] = nullptr;
		this->_itemsCount--;
		return true;
	}
}

cout << "Error!: Can't Find Item" << endl;
return false;
}

void MenuCategory::displayCategory()
{
cout << "----- " << this->_category << " -----" << endl;
for (int x = 0; x < this->_itemsCount; x++)
{
	cout << "- " << this->_items[x]->getName();
	if (this->_items[x]->getName().length() < 6) cout << "\t\t\t";
	else cout << "\t\t";
	cout << "Price: " << fixed << setprecision(2) << this->_items[x]->getPrice() << ",-" << endl;
}
}