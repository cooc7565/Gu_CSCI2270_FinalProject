#include "Data.h"

Data::Data()
{
    //ctor
}

Data::~Data()
{
    //dtor
}

void Data::insertFirstItem(std::string name, int quantity)
{
    // Insert first item to head of linked list

    DataElem* node = new DataElem(name, quantity);

    if (front == NULL)
    {
        node->next = back;
        node->previous = NULL;
        front = node;
    }
    else
    {
        cout << "First item already exists." << endl;
    }
}

void Data::insertItem(std::string name, int position, int quantity)
{
    // Insert item to a given integer position on linked list

    DataElem* node = new DataElem(name, quantity);
    DataElem* temp = front;

    int i = 0;

    while (temp != NULL)
    {
        if (i == position)
        {
            if (temp->next != NULL)
            {
                node->next = temp->next;
                node->previous = temp;
                temp->next->previous = node;
                temp->next = node;

                return;
            }
            else if (temp->next == NULL)
            {
                node->previous = temp;
                node->next = NULL;
                temp->next = node;

                return;
            }
        }

        temp = temp->next;
        i++;
    }

    cout << "Position out of bounds." << endl;
}

void Data::insertFirstNestedItem(std::string nestedName, std::string name, int quantity)
{
    // Convert item into inventory and add first item to head of item linked list

    DataElem* node = new DataElem(name, quantity);
    DataElem* temp = front;

    while (temp != NULL)
    {
        if (temp->name == nestedName)
        {
            if (temp->front == NULL)
            {
                node->next = temp->back;
                node->previous = NULL;
                temp->front = node;
            }
            else
            {
                cout << "First item already exists." << endl;
            }

            return;
        }

        temp = temp->next;
    }

    cout << "Inventory not found." << endl;
}

void Data::insertNestedItem(std::string nestedName, std::string name, int position, int quantity)
{
    // Insert item into nested inventory at a given position on item linked list

    DataElem* node = new DataElem(name, quantity);
    DataElem* temp = front;

    while (temp != NULL)
    {
        if (temp->name == nestedName)
        {
            DataElem *temp2 = temp->front;
            int i = 0;

            while (temp2 != NULL)
            {
                if (i == position)
                {
                    if (temp2->next != NULL)
                    {
                        node->next = temp2->next;
                        node->previous = temp2;
                        temp2->next->previous = node;
                        temp2->next = node;

                        return;
                    }
                    else if (temp2->next == NULL)
                    {
                        node->previous = temp2;
                        node->next = NULL;
                        temp2->next = node;

                        return;
                    }
                }

                temp2 = temp2->next;
                i++;
            }

            cout << "Position out of bounds." << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "Inventory not found." << endl;
}

void Data::deleteItem(std::string name)
{
    // Delete a given item or nested inventory

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
    // Change quantity data of a given item

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
    // Delete all items and nested inventories

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
    // Print all items and nested inventories

    DataElem* temp = front;

    while (temp != NULL)
    {
        cout << "Item: " << temp->name << " Quantity: " << temp->quantity << endl;
        temp = temp->next;
    }
}

void Data::printInventoryItems(std::string name)
{
    // Print all items within a nested inventory

    DataElem *temp = front;

    while (temp != NULL)
    {
        if (temp->name == name)
        {
            DataElem *temp2 = temp->front;

            while (temp2 != NULL)
            {
                cout << "Item: " << temp2->name << " Quantity: " << temp2->quantity << endl;
                temp2 = temp2->next;
            }
        }

        temp = temp->next;
    }
}

void Data::findItem(std::string name)
{
    // Find a given item and display its name and quantity

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
