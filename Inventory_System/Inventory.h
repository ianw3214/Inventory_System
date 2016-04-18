#pragma once

#include <iostream>
#include <string>
#include <vector>

// structure to store the items in
struct item {
	int ID;
	std::string name;
	int cost;
};

// structure for item storage in vector
struct invType {
	item _item;
	int _count;
};

// class declaration
class Inventory {

public:
	Inventory(int);					// empty constructor
	void addItem(int, int);			// function to add an item (ID, Count)
	void showInv();					// function to show the contents of the inventory
	void remove(int, int);

private:
	std::vector<invType> _inv;		// inventory vector
	std::vector<item> itemList;		// list of items 
	int iSize;						// size of the inventory
};