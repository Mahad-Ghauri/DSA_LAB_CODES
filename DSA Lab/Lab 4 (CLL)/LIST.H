#ifndef LIST_H
#define LIST_H

#include "NODE.H"

class List
{

public:
    Node *head = NULL;
    Node *tail = NULL;

    List()
    {
        head = NULL;
        tail = NULL;
    }

    void AddNode(int value)
    {
        if (head == NULL)
        {
            head = new Node(value);
            tail = head;
        }
        else
        {
            tail->setNext(new Node(value));
            tail = tail->getNext();
        }
    }

    void Add_NewNode(int value)
    {
        Node *addingNode = new Node(value);

        if (head == NULL)
        {
            head = addingNode;
            tail = addingNode;
            tail->setNext(head);
        }
        else
        {
            tail->setNext(addingNode);
            tail = tail->getNext();
            tail->setNext(head);
        }
    }

    void Display()
    {
        Node *temp = head;
        cout << " List: ";
        while (temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }

        cout << endl;
    }

    List *CircularList()
    {
        if (head == NULL)
        {
            return this;
        }

        tail->setNext(head);

        return this;
    }

    void Circular_Display()
    {
        Node *temp = head;

        cout << " List: ";
        do
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        } while (temp != head);

        cout << endl;
    }

    bool Check_Node(int value)
    {
        bool found = false;
        Node *current = head;

        while (current != NULL)
        {
            if (current->getData() != value)
            {
                current = current->getNext();
            }
            else
            {
                found = true;
                break;
            }
        }

        return found;
    }

    bool Check_Circular_List()
    {
        bool found = false;
        Node *current = head;

        while (current->getNext() != NULL)
        {
            if (current->getNext() == NULL)
            {
                found = true;
                return found;
            }
            else
            {
                return found;
            }
            current = current->getNext();
        }

        return found;
    }

    int getSize()
    {
        int count = 0;
        Node *temp = head;

        do
        {
            count++;
            temp = temp->getNext();
        } while (temp != head);

        return count;
    }

    List *Move_End()
    {
        Node *current = head;
        Node *previous = NULL;
        Node *last = tail;

        int count = getSize();

        int array[count];
        current = head;

        for (int i = 0; i < count; i++)
        {
            array[i] = current->getData();
            current = current->getNext();
        }

        int arr[count];
        Node *temp = head;

        for (int i = 0; i < count; i++)
        {
            if (current->getData() == current->getData())
            {
                temp = current;
                previous->setNext(current->getNext());
                delete current;
                last->setNext(temp);
                temp->setNext(head);
            }
            else
            {
                current = current->getNext();
            }
        }
        return this;
    }
};
#endif