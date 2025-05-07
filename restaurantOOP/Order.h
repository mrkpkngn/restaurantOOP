#pragma once
#include "OrderItem.h"
#include <iostream>

class Order
{
private:
	static int _totalOrders;

	int _orderID;
	OrderItem** _orderItems;
	int _itemsCount;
	bool _orderComplete;
	double _orderTotal;
public:
	Order(OrderItem** orderItems, int itemsCount);
	virtual ~Order();
	virtual bool isOrderComplete();
	virtual int getOrderID() const;
	virtual double getTotal() const;
	virtual int getItemsCount() const;
	virtual OrderItem* getItem(int index) const;
	OrderItem* addItem(MenuItem* item, int quantity);
	bool removeItem(string name, int quantity);
	virtual void orderComplete();
	virtual void displayOrder() const = 0;
	virtual void printReceipt() const = 0;

};

