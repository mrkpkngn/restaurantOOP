#include "OrderItem.h"

// -------------------------------- CONSTRUCTORS --------------------------

OrderItem::OrderItem(MenuItem* item, int quantity)
{
	this->_item = item;
	this->_quantity = quantity;
	this->_itemTotal = this->_item->getPrice() * this->_quantity;
}

// ------------------------- GET FUNCTIONS -------------------------

MenuItem* OrderItem::getItem()
{
	if (this->_item != nullptr)
	{
		return this->_item;
	}

	return nullptr;
}

int OrderItem::getQuantity()
{
	return this->_quantity;
}

double OrderItem::getItemTotal()
{
	return this->_itemTotal;
}

// ------------------------ PROCESS FUNCTIONS -----------------------

void OrderItem::addQuantity()
{
	this->_quantity++;
	this->_itemTotal += this->_item->getPrice();
}
bool OrderItem::reduceQuantity()
{
	if (this->_quantity > 0)
	{
		this->_quantity--;
		this->_itemTotal -= this->_item->getPrice();
		return true;
	}

	return false;
}