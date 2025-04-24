#include "Table.h"

// -------------------------------- CONSTRUCTORS --------------------------

int Table::_totalTables = 0;

Table::Table(int numSeats)
{
	this->_tableNumber = _totalTables;
	this->_numSeats = numSeats;
	this->_occupied = false;
	
	Table::_totalTables++;
}

// ------------------------- GET FUNCTIONS -------------------------

int Table::getTableNumber()
{
	return this->_tableNumber + 1;
}

bool Table::isOccupied()
{
	return this->_occupied;
}

int Table::getNumSeats()
{
	return this->_numSeats;
}

// ------------------------ PROCESS FUNCTIONS -----------------------

void Table::markAsOccupied()
{
	this->_occupied = true;
}