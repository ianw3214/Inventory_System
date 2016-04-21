/*	Inventory System Program

	TODO
	- user input
	- shop system
	- crafting system? (maybe)
*/

#include <iostream>
#include <string>
#include <vector>
#include "Inventory.h"

// enumeration to help identify user inputs in the get action function
enum inputs {
	quit,
	addItem,
	removeItem,
	showInv,
	showItemList
};

// function declarations
inputs getUserAction();
void addItemToInv(Inventory*);
void removeItemFromInv(Inventory*);

// entry point
int main(int argc, char* argv[]) {

	// the main inventory that will store all the data
	Inventory inv(10);

	// variable to decide whether to quit the program or not
	bool quit = false;

	// loop the program as long as the user doesn't want to quit
	do {
		int inp = getUserAction();	// get the user input for what action to do
		if (inp == 0) {
			// set quit equal to true
			quit = true;
			// output a goodbye message
			std::cout << "Goodbye!!" << std::endl;
		}
		else if (inp == 1) {		// add an item
			// call the add item function
			addItemToInv(&inv);	
		}
		else if (inp == 2){			// remove an item
			// call the remove item function
			removeItemFromInv(&inv);
		}
		else if (inp == 3) {		// show the inventory
			// call the show inventory function
			inv.showInv();
		}
		else if (inp == 4) {		// show the item list
			// call the show items function
			inv.showItems();
		}
		else {						// something went wrong!?
			// tell the user that something went wrong
			std::cout << "Something went wrong, please try again!" << std::endl;
		}
	} while (!quit);

	system("PAUSE");
	return 0;

}

// function to get inputs from the user
inputs getUserAction() {

	// string to hold the user input
	std::string inp;

	// boolean to store whether the user input is valid or not
	bool valid = false;

	// input for the function to return 
	inputs fInput;

	// ask the user for an input as long as the previous one wasn't valid
	do {	
		// print out all the options for the user
		std::cout << "What would you like to do?" << std::endl;
		std::cout << "[q]: Quit the application" << std::endl;
		std::cout << "[a]: Add an item" << std::endl;
		std::cout << "[r]: Remove an item" << std::endl;
		std::cout << "[i]: Show inventory contents" << std::endl;
		std::cout << "[s]: Show all items" << std::endl;

		// get an input
		while (getline(std::cin, inp)) {
			// make sure the input is not affected by cin from other functions
			if (inp != "") {
				break;
			}
		}
		if (inp[0] == 'q' || inp[0] == 'Q')	{		// if the input is q
			// return the result and validate the input
			fInput = quit;
			valid = true;
		}else if (inp[0] == 'a' || inp[0] == 'A') {	// if the input is a
			// return the result and validate the input
			fInput = addItem;
			valid = true;
		}else if (inp[0] == 'r' || inp[0] == 'R') {	// if the input is r
			// return the result and validate the input
			fInput = removeItem;
			valid = true;
		}else if (inp[0] == 'i' || inp[0] == 'I') {	// if the input is i
			// return the result and validate the input
			fInput = showInv;
			valid = true;
		}else if (inp[0] == 's' || inp[0] == 'S') {	// if the input is s
			// return the result and validate the input
			fInput = showItemList;
			valid = true;
		}else {
			// the input is invalid if the program has run to this point
			// notify the user to change the input
			std::cout << "That was not a valid input..." << std::endl;
		}

	} while (!valid);

	// return the final result to the user
	return fInput;

}

// function to add an item of users choice
void addItemToInv(Inventory* inv) {

	// show the list of possible items for the user to add
	inv->showItems();

	// integers to store user inputs
	int uID, uC;	// ID and Count

	// get the user input for ID and count of item to add
	std::cout << "What item would you like to add?" << std::endl;
	std::cout << "( please enter the ID )" << std::endl;
	std::cin >> uID;
	std::cout << "How many would you like to add?" << std::endl;
	std::cin >> uC;

	// add the item according to the ID and count
	inv->addItem(uID, uC);

	return;
}

// function to remove an item of the users choice
void removeItemFromInv(Inventory* inv) {

	// show the list items in the current inventory
	inv->showInv();

	// integers to store user inputs
	int uID, uC;	// ID and Count

	// get the user input for ID and count of item to remove
	std::cout << "What item would you like to remove?" << std::endl;
	std::cout << "( please enter the ID )" << std::endl;
	std::cin >> uID;
	std::cout << "How many would you like to remove?" << std::endl;
	std::cin >> uC;

	// add the item according to the ID and count
	inv->remove(uID, uC);

	return;
}