#pragma once
#include"MenuItem.h"

class OrderItem
{
private:
	MenuItem* _item;
	int _quantity;
	double _itemTotal;
public:
	OrderItem(MenuItem* item, int quantity);
	MenuItem* getItem();
	int getQuantity();
	double getItemTotal();
	void addQuantity();
	bool reduceQuantity();
};

