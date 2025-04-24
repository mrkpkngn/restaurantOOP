#include "Order.h"


// -------------------------------- CONSTRUCTORS --------------------------
int Order::_totalOrders = 0;

Order::Order(OrderItem** orderItems, int itemsCount)
{
	this->_orderID = _totalOrders;

	this->_orderTotal = 0.0;

	this->_itemsCount = itemsCount;
	this->_orderItems = new OrderItem * [100];
	for (int x = 0; x < this->_itemsCount; x++)
	{
		this->_orderItems[x] = orderItems[x];
		this->_orderTotal += this->_orderItems[x]->getItemTotal();
	}

	this->_orderComplete = false;

	Order::_totalOrders++;

}

Order::~Order()
{
	for (int x = 0; x < this->_itemsCount; x++)
	{
		delete this->_orderItems[x];
	}

	delete[] _orderItems;
}

// ------------------------- GET FUNCTIONS -------------------------

int Order::getOrderID() const
{
	return this->_orderID;
}

double Order::getTotal() const
{
	return this->_orderTotal;
}

int Order::getItemsCount() const
{
	return this->_itemsCount;
}

OrderItem* Order::getItem(int index) const
{
	if (this->_orderItems[index] != nullptr)
	{
		return this->_orderItems[index];
	}

	cout << "Error!: Cant Find Item";

	return nullptr;
}


// ------------------------ PROCESS FUNCTIONS -----------------------

OrderItem* Order::addItem(MenuItem* item, int quantity)
{
	OrderItem* orderItem = new OrderItem(item, quantity);

	this->_orderItems[_itemsCount] = orderItem;
	this->_orderTotal += item->getPrice();
	return orderItem;
}
bool Order::removeItem(string name) {
	for (int x = 0; x < this->_itemsCount; x++) {
		if (this->_orderItems[x]->getItem()->getName() == name) {
			bool isSuccess = this->_orderItems[x]->reduceQuantity();

			if (!isSuccess || this->_orderItems[x]->getQuantity() == 0) {
				this->_orderTotal -= this->getItem(x)->getItem()->getPrice() * (this->_orderItems[x]->getQuantity() + 1);
				delete this->_orderItems[x];
				for (int y = x; y < this->_itemsCount - 1; y++)
				{
					this->_orderItems[y] = this->_orderItems[y + 1];
				}

				this->_itemsCount--;
				this->_orderItems[this->_itemsCount] = nullptr;
			}
			else {
				this->_orderTotal -= this->_orderItems[x]->getItem()->getPrice();
			}
			return true;
		}
	}
	cout << "Error!: Can't Find Item" <<endl;
	return false;
}