/*	TODO
	- remove item
	- more items
	- changing costs
	- read item list from file
*/

#include "Inventory.h"

// constructor
Inventory::Inventory(int size) {

	// initialize the item list
	itemList.push_back({0, "NOTHING", 0});		// 0 - NOTHING
	itemList.push_back({1, "WOOD" , 1});		// 1 - WOOD
	itemList.push_back({ 2, "STONE" , 1 });		// 2 - STONE
	itemList.push_back({ 3, "GRAVEL" , 1 });	// 3 - GRAVEL

	// set the default size to 10
	if (size == 0) {
		iSize = 10;
	}

	// set the size of the inventory
	iSize = size;

}

// function to add an item to the inventory vector
void Inventory::addItem(int inpID, int inpCount) {

	// if the inventory is full
	if ( _inv.size() >= iSize ) {
		std::cout << "SORRY, INVENTORY IS FULL..." << std::endl;
		return;								// break out of the functon
	}

	// loop through the inventory to see if the item is already in
	for (int i = 0; i < _inv.size(); i++) {
		if(inpID == _inv[i]._item.ID){		// if the input id matches the id on the current loop
			_inv[i]._count += inpCount;		// add the amount into the current count
			return;							// break out of the function
		}
	}
	
	// if the item is not currently in the vector, keep going
	// temporary item to insert
	item temp;

	// loop through the item types to find the item to insert
	for (int i = 0; i < itemList.size(); i++) {
		if (inpID==itemList[i].ID) {		// if the input id matches the id on the current loop
			temp = itemList[i];				// set the temporary item to the one in the loop
		}
	}

	// set the value of temp if there is no value
	if (temp.ID == NULL) {					// if the temporary item was not set to a value
		temp = itemList[0];					// set the item equal to nothing
	}

	// push the item and count into the inventory vector
	invType a = { temp, inpCount };
	_inv.push_back(a);

	return;

}

void Inventory::showInv() {

	// loop through the inventory loop and list the name and count of the items
	for (int i = 0; i < _inv.size(); i++) {
		// output the information of the current item to the user
		std::cout << _inv[i]._item.name << " : " << _inv[i]._count << std::endl;
	}

	return;

}