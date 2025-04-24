#pragma once
#include <string>

using namespace std;

class MenuItem
{
private:
	string _name;
	double _price;
public:
	MenuItem(string name, double price);
	string getName();
	double getPrice();
};

