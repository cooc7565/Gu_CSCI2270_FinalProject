#include "Data.h"

Data data;

int main(int argc, char* argv[])
{
    bool quit = false;

    cout << "======Main Menu======" << endl;
    cout << "1. Insert first item" << endl;
    cout << "2. Insert item" << endl;
    cout << "3. Insert first nested inventory item" << endl;
    cout << "4. Insert nested inventory item" << endl;
    cout << "5. Delete item" << endl;
    cout << "6. Change item quantity" << endl;
    cout << "7. Clear all" << endl;
    cout << "8. Print all items" << endl;
    cout << "9. Print all nested inventory items" << endl;
    cout << "10. Find item" << endl;
    cout << "11. Select inventory" << endl;
    cout << "12. Quit" << endl;

    while (! quit)
    {
        string input;

        cin >> input;

        if (input == "1")
        {
            string name;
            string quantity;

            cin.ignore();
            cout << "Enter item name:" << endl;
            getline(cin, name);
            cout << "Enter item quantity:" << endl;
            getline(cin, quantity);

            int quantityInt = atoi(quantity.c_str());

            data.insertFirstItem(name, quantityInt);
        }
        else if (input == "2")
        {
            string name;
            string quantity;
            string position;

            cin.ignore();
            cout << "Enter item name:" << endl;
            getline(cin, name);
            cout << "Enter item quantity:" << endl;
            getline(cin, quantity);
            cout << "Enter item position:" << endl;
            getline(cin, position);

            int quantityInt = atoi(quantity.c_str());
            int positionInt = atoi(position.c_str());

            data.insertItem(name, positionInt, quantityInt);
        }
        else if (input == "3")
        {
            string inventoryName;
            string itemName;
            string quantity;

            cin.ignore();
            cout << "Enter name of item to convert into inventory:" << endl;
            getline(cin, inventoryName);
            cout << "Enter item name:" << endl;
            getline(cin, itemName);
            cout << "Enter item quantity:" << endl;
            getline(cin, quantity);

            int quantityInt = atoi(quantity.c_str());

            data.insertFirstNestedItem(inventoryName, itemName, quantityInt);
        }
        else if (input == "4")
        {
            string inventoryName;
            string itemName;
            string quantity;
            string position;

            cin.ignore();
            cout << "Enter name of inventory item:" << endl;
            getline(cin, inventoryName);
            cout << "Enter item name:" << endl;
            getline(cin, itemName);
            cout << "Enter item quantity:" << endl;
            getline(cin, quantity);
            cout << "Enter item position:" << endl;
            getline(cin, position);

            int quantityInt = atoi(quantity.c_str());
            int positionInt = atoi(position.c_str());

            data.insertNestedItem(inventoryName, itemName, positionInt, quantityInt);
        }
        else if (input == "5")
        {
            string name;

            cin.ignore();
            cout << "Enter item name:" << endl;
            getline(cin, name);

            data.deleteItem(name);
        }
        else if (input == "6")
        {
            string name;
            string quantity;

            cin.ignore();
            cout << "Enter item name:" << endl;
            getline(cin, name);
            cout << "Enter new item quantity:" << endl;
            getline(cin, quantity);

            int quantityInt = atoi(quantity.c_str());

            data.changeQuantity(name, quantityInt);
        }
        else if (input == "7")
        {
            data.clearAll();
        }
        else if (input == "8")
        {
            data.printAllItems();
        }
        else if (input == "9")
        {
            string name;

            cin.ignore();
            cout << "Enter inventory name:" << endl;
            getline(cin, name);

            data.printInventoryItems(name);
        }
        else if (input == "10")
        {
            string name;

            cin.ignore();
            cout << "Enter item name:" << endl;
            getline(cin, name);

            data.findItem(name);
        }
        else if (input == "11")
        {

        }
        else if (input == "12")
        {
            cout << "Exiting program." << endl;

            return 0;
        }

        cout << "======Main Menu======" << endl;
        cout << "1. Insert first item" << endl;
        cout << "2. Insert item" << endl;
        cout << "3. Insert first nested inventory item" << endl;
        cout << "4. Insert nested inventory item" << endl;
        cout << "5. Delete item" << endl;
        cout << "6. Change item quantity" << endl;
        cout << "7. Clear all" << endl;
        cout << "8. Print all items" << endl;
        cout << "9. Print all nested inventory items" << endl;
        cout << "10. Find item" << endl;
        cout << "11. Select inventory" << endl;
        cout << "12. Quit" << endl;
    }

    return 0;
}
