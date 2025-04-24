#include "MenuCategory.h"

MenuCategory::MenuCategory(string category)
{
	this->_category = category;
	this->_items = new MenuItem * [100];
	this->_itemsCount = 0;
}


MenuCategory::~MenuCategory()
{
	for (int x = 0; x < this->_itemsCount; x++)
	{
		delete this->_items[x];
	}
	delete[] _items;
};


void MenuCategory::addItem(MenuItem* item)
{
	this->_items[_itemsCount] = item;
	_itemsCount++;
}

void MenuCategory::removeItem(MenuItem* item)
{
	for (int x = 0; x < this->_itemsCount; x++)
	{
		if (this->_items[x] == item)
		{
			delete _items[x];

			for (int y = x; y < this->_itemsCount; y++)
			{
				this->_items[y] = this->_items[y + 1];
				return;
			}
		}
	}

	cout << "Error!: Can't Find Item" << endl;
}
void MenuCategory::displayCategory()
{
	cout << "----- " << this->_category << " -----" << endl;
	for (int x = 0; x < this->_itemsCount; x++)
	{
		cout << "- " << this->_items[x]->getName();
		if (this->_items[x]->getName().length() < 6) cout << "\t\t\t";
		else cout << "\t\t";
		cout << "Price: " << this->_items[x]->getPrice() << endl;
	}
}