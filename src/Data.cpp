#include "Data.h"

Data::Data()
{
    //ctor
}

Data::~Data()
{
    //dtor
}

void Data::insertItemFront(std::string name, int quantity)
{
    DataElem* node = new DataElem(name, quantity);

    if (front == NULL)
    {
        front = node;
        back = node;
    }
    else
    {
        front->previous = node;
        node->next = front;
        front = node;
    }
}

void Data::insertItemBack(std::string name, int quantity)
{
    DataElem *node = new DataElem(name, quantity);

    if (back == NULL)
    {
        front = node;
        back = node;
    }
    else
    {
        back->next = node;
        node->previous = back;
        back = node;
    }
}

void Data::insertInventoryFront(std::string inventoryName, std::string itemName)
{
    DataElem* node = new DataElem(itemName);

    if (front == NULL)
    {
        front = node;
        back = node;
    }
    else
    {
        front->previous = node;
        node->next = front;
        front = node;
    }
}

void Data::insertInventoryBack(std::string inventoryName, std::string itemName)
{
    DataElem *node = new DataElem(itemName);

    if (back == NULL)
    {
        front = node;
        back = node;
    }
    else
    {
        back->next = node;
        node->previous = back;
        back = node;
    }
}

void Data::deleteItem(std::string name)
{
    DataElem* temp = front;
    bool itemFound = false;

    while (temp != NULL)
    {
        if (temp->name == name)
        {
            itemFound = true;
            break;
        }

        temp = temp->next;
    }

    if (itemFound)
    {
        if (temp == front)
        {
            temp->next->previous = NULL;
        }
        else if (temp == back)
        {
            temp->previous->next = NULL;
        }
        else
        {
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
        }

        delete temp;
    }
    else
    {
        cout << "Item not found." << endl;
    }
}

void Data::changeQuantity(std::string name, int quantity)
{
    DataElem* temp = front;

    while (temp != NULL)
    {
        if (temp->name == name)
        {
            temp->quantity = quantity;
            cout << "Quantity changed to: " << temp->quantity << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Item not found." << endl;
}

void Data::clearAll()
{
    DataElem *node = back;

    while (node != NULL)
    {
        DataElem *node2 = node;
        node = node->previous;
        delete node2;
    }

    front = NULL;
    back = NULL;
}

void Data::printAllItems()
{
    DataElem *temp = front;

    while (temp != NULL)
    {
        cout << "Item: " << temp->name << " Quantity: " << temp->quantity << endl;
        temp = temp->next;
    }
}

void Data::printInventoryItems(std::string name)
{

}

void Data::findItem(std::string name)
{
    DataElem* temp = front;

    while (temp != NULL)
    {
        if (temp->name == name)
        {
            cout << "Item: " << temp->name << " Quantity: " << temp->quantity << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Item not found." << endl;
}

void Data::selectInventory(std::string name)
{

}
