#include "DineIn.h"

// -------------------------------- CONSTRUCTORS --------------------------

DineIn::DineIn(Table* orderTable, OrderItem** orderItems, int itemsCount) :
	Order(orderItems, itemsCount)
{
	this->_orderTable = orderTable;
	this->_orderTable->markAsOccupied();
}


DineIn::~DineIn()
{
	cout << "Dine In Destructor Called" << endl;
}

// ------------------------ PROCESS FUNCTIONS -----------------------

void DineIn::orderComplete()
{
	Order::orderComplete();
	this->_orderTable->markAsFree();
}

void DineIn::displayOrder() const
{
	cout << "----- ORDER " << this->getOrderID() << " -----" << endl;
	cout << "FOR DINE IN" << endl;
	cout << "Item\t\tQty." << endl;

	for (int x = 0; x < this->getItemsCount(); x++)
	{
		OrderItem* currentItem = this->getItem(x);

		cout << "- " << currentItem->getItem()->getName();
		if (currentItem->getItem()->getName().length() < 6) cout << "\t\t";
		else cout << "\t";
		cout << currentItem->getQuantity() << "\t" << endl;
	}
	cout << "-------------------" << endl;
}

void DineIn::printReceipt() const
{
	cout << "----- Dine In Receipt -----" << endl;
	cout << "Order ID: " << this->getOrderID() << endl;
	cout << "Table Number: " << this->_orderTable->getTableNumber() << endl;
	cout << "Items Ordered:" << endl;
	cout << "Item\t\tPrice\tQty.\tTotal" << endl;

	for (int x = 0; x < this->getItemsCount(); x++)
	{
		OrderItem* currentItem = this->getItem(x);

		cout << "- " << currentItem->getItem()->getName();
		if (currentItem->getItem()->getName().length() < 6) cout << "\t\t";
		else cout << "\t";
		cout << currentItem->getItem()->getPrice() << ",-" << "\t";
		cout << currentItem->getQuantity() << "\t";
		cout << currentItem->getItemTotal() << ",-" << endl;
	}

	cout << "Total:\t\t\t\t" << this->getTotal() << ",-" << endl;
	cout << "----------------------------" << endl;
}