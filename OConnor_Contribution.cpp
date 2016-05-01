//I thought that it would simplify your code more by combining the "insert first item" and "insert item function into
//just one function that insterts an item. I wrote the code below that just uses a simple if statement that checks if the 
//data element is on the first element or not.


void Data::insertItem(std::string name, int position, int quantity)
{
    // Insert item to a given integer position on linked list

    DataElem* node = new DataElem(name, quantity);

        if (front == NULL)
    {
        node->next = back;
        node->previous = NULL;
        front = node;
    }
    else
    {

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

}
