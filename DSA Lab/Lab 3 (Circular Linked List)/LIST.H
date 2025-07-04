

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


    //For circular
    void Swap_Nodes(int x)
    {

        Node *beforePrevious = NULL;
        Node *previous = NULL;
        Node *current = head;
        x--;
        while (x--)
        {
            beforePrevious = previous;
            previous = current;
            current = current->getNext();
        }


        if (previous == head)
        {
            head = current;
        }
        else if (beforePrevious != NULL)
        {
            beforePrevious->setNext(current);
        }
        previous->setNext(current->getNext());
        current->setNext(previous);
        tail->setNext(head);
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


    void Delete_Specific_Node(int node_deletion)
    {


        Node *current = head;
        Node *previous = NULL;


        if (head != NULL)
        {
            if (head->getNext() == NULL)
            {
                head = NULL;
                delete head;
            }
            else
            {


                node_deletion--;


                while (node_deletion--)
                {
                    previous = current;
                    current = current->getNext();
                }


                previous->setNext(current->getNext());


                if (current == tail)
                {
                    tail = previous;
                }


                delete current;
            }
        }
    }

    //For Circular Linked List
    List *Update_Node(int oldValue , int newValue)
    {
        Node *current = head;


        do
        {
            if (current->getData() == oldValue)
            {
                current->setData(newValue   );
                break; 
            }
            current = current->getNext();
        } while (current != head); 


        tail->setNext(head);


        return this;
    }
};
#endif
