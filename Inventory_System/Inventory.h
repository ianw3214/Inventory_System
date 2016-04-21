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
	Inventory(int);					// constructor with inventory size
	void addItem(int, int);			// function to add an item (ID, Count)
	void showInv();					// function to show the contents of the inventory
	void remove(int, int);			// function to remove items from the inventory
	void showItems();				// function to show all the items 

private:
	std::vector<invType> _inv;		// inventory vector
	std::vector<item> itemList;		// list of items 
	int iSize;						// size of the inventory

	void initIDs();					// function to initialize the ID of items
};

