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

// entry point
int main(int argc, char* argv[]) {

	Inventory inv(10);

	inv.addItem(1,5);
	inv.addItem(2, 3);
	inv.addItem(3, 4);

	inv.showInv();

	system("PAUSE");
	return 0;

}