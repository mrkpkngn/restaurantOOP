#include "MenuItem.h"

// -------------------------------- CONSTRUCTORS --------------------------

MenuItem::MenuItem(string name, double price) {
	this->_name = name;
	this->_price = price;
}

// ------------------------- GET FUNCTIONS -------------------------

string MenuItem::getName() {
	return this->_name;
}

double MenuItem::getPrice(){
	return this->_price;
}
