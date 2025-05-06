#include "Table.h"

// -------------------------------- CONSTRUCTORS --------------------------

int Table::_totalTables = 0;

Table::Table(int numSeats)
{
	this->_tableNumber = _totalTables;
	this->_numSeats = numSeats;
	this->_occupied = false;
	this->_reservations = new Reservation * [12] {nullptr};
	this->_numReservations = 0;
	
	Table::_totalTables++;
}

Table::~Table()
{
	if (_reservations != nullptr) {
		delete[] _reservations;
		_reservations = nullptr;

		Table::_totalTables--;
	}
}

// ------------------------- GET FUNCTIONS -------------------------


int Table::getTotalTables()
{
	return Table::_totalTables;
}

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

int Table::getNumReservations()
{
	return this->_numReservations;
}

Reservation* Table::getReservation(int index)
{
	return this->_reservations[index];
}

// ------------------------ PROCESS FUNCTIONS -----------------------

void Table::addReservation(Reservation* reservation)
{
	for (int i = 0; i < this->_numReservations; i++)
	{
		if (this->_reservations[i] == nullptr)
		{
			this->_reservations[i] = reservation;
			return;
		}
	}
	this->_reservations[this->_numReservations] = reservation;
	this->_numReservations++;
}



void Table::markAsFree()
{
	this->_occupied = false;
}

void Table::markAsOccupied()
{
	this->_occupied = true;
}