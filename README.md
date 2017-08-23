# Inventory_System

## Inventory System Created in C++

---

### Features:


Features include:

- Built in item list
- Add items to inventory
- Show items in inventory
- Remove items from the inventory

---

### TODOs:

- custom items read from text files
- unique items that can't stack

---

### Usage:

Using [gitzip](http://kinolien.github.io/gitzip/), type in *https://github.com/ianw3214/Inventory_System/tree/master/include* and press download to get the necessary files.
Extract the zip and put the **Inventory.cpp** and **Inventory.h** files into your project folder. 

To use the inventory system, make sure you link and include the header file:

```c++
#include "Inventory.h"
```

The inventory requires an integer input that will determine it's size and how many items it can carry. An input of 0 will result in a size of 10.

```c++
// an inventory with a threshold of 10
Inventory inv(10);
```

Sample code showing basic functions of the inventory system:

```c++
#include "inventory.h"
#include <iostream>

int main(){

	// add an inventory
	Inventory inv(20);
	
	// show the different types of items
	inv.showItems();

	// add 5 items of ID 1
	inv.addItem(1, 5);

	// show the contents of the inventory
	inv.showInv();

	// remove 2 items of ID 1
	inv.remove(1,2);

	return 0;
}
```

---

### Customization:

To change the way the properties of items stored, change the item struct in **Inventory.h**.

Default Struct:
```c++
// structure to store the items in
struct item {
	int ID;
	std::string name;
	int cost;
};
```

To add/change the items, change the initIDs() function in **Inventory.cpp**.

Default Items:
```c++
void Inventory::initIDs() {

	// initialize the item list
	itemList.push_back({ 0, "NOTHING", 0 });	// 0 - NOTHING
	itemList.push_back({ 1, "WOOD" , 1 });		// 1 - WOOD
	itemList.push_back({ 2, "STONE" , 1 });		// 2 - STONE
	itemList.push_back({ 3, "GRAVEL" , 1 });	// 3 - GRAVEL
	itemList.push_back({ 4, "IRON", 3 });		// 4 - IRON
	itemList.push_back({ 5, "GOLD", 4 });		// 5 - GOLD
	itemList.push_back({ 6, "PLATINUM", 5 });	// 6 - PLATINUM
	itemList.push_back({ 7, "COPPER", 4 });		// 7 - COPPER
	itemList.push_back({ 8, "BRICK", 3});		// 8 - BRICK

	return;
}
```

---

Creator: *Ian Wang*
Created: *May 29th 2016*
