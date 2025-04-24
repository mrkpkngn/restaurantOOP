#include "MenuItem.h"

MenuItem::MenuItem(string name, double price) {
	this->_name = name;
	this->_price = price;
}

string MenuItem::getName() {
	return this->_name;
}

double MenuItem::getPrice(){
	return this->_price;
}
