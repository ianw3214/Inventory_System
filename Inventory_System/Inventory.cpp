/*	TODO
	+ remove item
	- more items
	- changing costs
	- read item list from file
*/

#include "Inventory.h"

// constructor
Inventory::Inventory(int size) {

	// call the function to initialize the item names and IDs
	initIDs();

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

// function to show the inventory contents onto the screen
void Inventory::showInv() {

	std::cout << "+--------------------+" << std::endl;

	// loop through the inventory loop and list the name and count of the items
	for (int i = 0; i < _inv.size(); i++) {
		// output the information of the current item to the user
		std::cout << "ID: " << _inv[i]._item.ID << " - " <<  _inv[i]._item.name << " : " << _inv[i]._count << std::endl;
	}

	std::cout << "+--------------------+" << std::endl;

	return;

}

// function to remove an item based on ID
void Inventory::remove(int ID, int Count) {

	// loop through the inventory vector to search for the item to remove
	for (int i = 0; i < _inv.size(); i++) {
		if (_inv.at(i)._item.ID == ID) {		// if the item ID matches
			if (_inv.at(i)._count <= Count) {	// if more items are being removed than exist
				_inv.erase(_inv.begin()+i);		// erase the item from the inventory
			}
			else {
				_inv.at(i)._count -= Count;		// minus the count from the vector
			}
			return;								// break out of the loop if an item was removed
		}
	}

	// print an error message if the loop doesn't find a match
	std::cout << "ITEM FAILED TO REMOVE" << std::endl;
	return;

}

// function to show all the items that are in the system
void Inventory::showItems() {

	std::cout << "+--------------------+" << std::endl;

	// loop through the items loop and list the name and count of the items
	for (int i = 0; i < itemList.size(); i++) {
		// output the information of the current item to the user
		std::cout << "ID: " << itemList[i].ID << " - " << itemList[i].name << std::endl;
	}

	std::cout << "+--------------------+" << std::endl;

	return;
}

// function to initialize the IDs of all the items
void Inventory::initIDs() {

	// initialize the item list
	itemList.push_back({ 0, "NOTHING", 0 });	// 0 - NOTHING
	itemList.push_back({ 1, "WOOD" , 1 });		// 1 - WOOD
	itemList.push_back({ 2, "STONE" , 1 });		// 2 - STONE
	itemList.push_back({ 3, "GRAVEL" , 1 });	// 3 - GRAVEL

	return;
}