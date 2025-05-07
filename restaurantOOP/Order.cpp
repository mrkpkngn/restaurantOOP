#include "Order.h"


// -------------------------------- CONSTRUCTORS --------------------------
int Order::_totalOrders = 0;

Order::Order(OrderItem** orderItems, int itemsCount)
{
	this->_orderID = _totalOrders;

	this->_orderTotal = 0.0;

	this->_itemsCount = itemsCount;
	this->_orderItems = new OrderItem * [100] {nullptr};
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
	if (_orderItems != nullptr) {
		for (int x = 0; x < this->_itemsCount; x++)
		{
			if (this->_orderItems[x] != nullptr)
			{
				delete this->_orderItems[x];
				this->_orderItems[x] = nullptr;
			}
		}
		delete[] _orderItems;
		_orderItems = nullptr;
	}
}

// ------------------------- GET FUNCTIONS -------------------------

bool Order::isOrderComplete()
{
	return this->_orderComplete;
}

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

void Order::orderComplete() {
    this->_orderComplete = true;
}


OrderItem* Order::addItem(MenuItem* item, int quantity)
{
	OrderItem* orderItem = new OrderItem(item, quantity);
	for (int x = 0; x < this->_itemsCount; x++)
	{
		if (this->_orderItems[x] == nullptr) {
			this->_orderItems[x] = orderItem;
			this->_orderTotal += item->getPrice();
			return orderItem;
		}

		if (this->_orderItems[x]->getItem()->getName() == item->getName())
		{
			this->_orderItems[x]->addQuantity();
			this->_orderTotal += item->getPrice();
			delete orderItem;
			return this->_orderItems[x];
		}
	}

	this->_orderItems[_itemsCount] = orderItem;
	this->_itemsCount++;
	this->_orderTotal += item->getPrice();
	return orderItem;
}

bool Order::removeItem(string name, int quantity) {
	for (int x = 0; x < this->_itemsCount; x++) {
		if (this->_orderItems[x]->getItem()->getName() == name) {
			bool isSuccess = false;
			for (int y = 0; y < quantity; y++)
			{
				isSuccess = this->_orderItems[x]->reduceQuantity();
			}

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
	cout << "Error!: Can't Find Item" << endl;
	return false;
}