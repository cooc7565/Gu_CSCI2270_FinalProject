#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

struct DataElem
{
	std::string name;
	int quantity;
	DataElem *next;
    DataElem *previous;
    DataElem *front;
    DataElem *back;

	DataElem(){};
	DataElem(std::string in_name, int in_quantity)
	{
		name = in_name;
		quantity = in_quantity;
		next = NULL;
		previous = NULL;
		front = NULL;
		back = NULL;
	}
	DataElem(std::string in_name)
	{
		name = in_name;
		quantity = 0;
		next = NULL;
		previous = NULL;
		front = NULL;
		back = NULL;
	}
};

class Data
{
    public:
        Data();
        ~Data();
        void insertItemFront(std::string name, int quantity);
        void insertItemBack(std::string name, int quantity);
        void insertInventoryFront(std::string inventoryName, std::string itemName, int quantity);
        void insertInventoryBack(std::string inventoryName, std::string itemName, int quantity);
        void deleteItem(std::string name);
        void changeQuantity(std::string name, int quantity);
        void clearAll();
        void printAllItems();
        void printInventoryItems(std::string name);
        void findItem(std::string name);
        void selectInventory(std::string name);

    protected:

    private:
        DataElem *front;
        DataElem *back;
};

#endif // DATA_H
