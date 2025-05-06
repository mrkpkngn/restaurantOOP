#pragma once
#include "Reservation.h"
class Table
{
private:
	static int _totalTables;

	int _tableNumber;
	bool _occupied;
	int _numSeats;
	Reservation** _reservations;
	int _numReservations;
public:
	Table(int numSeats);
	~Table();
	static int getTotalTables();
	int getTableNumber();
	bool isOccupied();
	int getNumSeats();
	int getNumReservations();
	void addReservation(Reservation* reservation);
	Reservation* getReservation(int index);
	void markAsFree();
	void markAsOccupied();
};

