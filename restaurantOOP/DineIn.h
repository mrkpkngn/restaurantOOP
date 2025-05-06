#pragma once
#include "Order.h"
#include "Table.h"
class DineIn : public Order
{
private:
	Table* _orderTable;

public:
	DineIn(Table* orderTable, OrderItem** orderItems, int itemsCount);
	~DineIn() override;
	void orderComplete() override;
	void displayOrder() const override;
	void printReceipt() const override;
};

