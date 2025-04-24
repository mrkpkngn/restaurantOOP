#pragma once
class Table
{
private:
	static int _totalTables;

	int _tableNumber;
	bool _occupied;
	int _numSeats;
public:
	Table(int numSeats);

	int getTableNumber();
	bool isOccupied();
	int getNumSeats();

	void markAsOccupied();
};

