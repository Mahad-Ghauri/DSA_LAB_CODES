#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int newdata)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->data = newdata;
    newnode->next = head;

    if (head != NULL)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode; // Link newnode to the end
    }
    else
    {
        newnode->next = newnode; // Circular link to itself
        head = newnode;          // Initialize head
    }
}

int size()
{
    if (head == NULL)
    {
        cout << "List is empty....." << endl;
        return 0;
    }

    int count = 0;
    struct node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

void search(int num)
{
    bool found = false;
    struct node *temp = head;
    int pos = 0;

    do
    {
        pos++;
        if (temp->data == num)
        {
            found = true;
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (found)
    {
        cout << "Element : " << num << " is found at " << pos << " position ";
    }
    else
    {
        cout << "element not found...." << endl;
    }
}

bool checkcircular()
{
    if (head == NULL)
    {
        return false;
    }

    struct node *temp = head;
    do
    {
        if (temp == head)
        {
            return true;
        }
        temp = temp->next;
    } while (temp != NULL && temp != head);

    return false;
}

void moveToEnd(int value)
{
    if (head == NULL || (head->next == head && head->data != value))
    {
        return; // Empty list or head alone with a different value
    }

    struct node *last = head;
    struct node *current = head;
    struct node *prev = NULL;

    // Traverse to find the last node of the list
    while (last->next != head)
    {
        last = last->next;
    }

    // To handle the case where we are moving the head
    bool isHeadMoved = false;

    do
    {
        if (current->data == value)
        {
            // If current node is the head
            if (current == head)
            {
                // Move head to the next node
                head = head->next;
                last->next = current; // Link last to current
                current->next = head; // Link current to new head
                last = current;       // Update last
                current = head;       // Move current to the new head
                isHeadMoved = true;   // Flag that we moved head
            }
            else
            {
                // Unlink the current node
                prev->next = current->next;
                last->next = current; // Link last to current
                current->next = head; // Link current to head
                last = current;       // Update last
                current = prev->next; // Move current forward
            }
        }
        else
        {
            prev = current;          // Move prev forward
            current = current->next; // Move current forward
        }
    } while (current != head || (isHeadMoved && current == head));
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    struct node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

int main()
{
    insert(2);
    insert(6);
    insert(4);
    insert(6);
    insert(8);
    insert(10);

    cout << "Displaying List" << endl;
    cout << "List after insertion : ";
    display();
    cout << endl;

    cout << "\nReturning Size" << endl;
    cout << "Size of list is :" << size() << endl;
    cout << endl;

    cout << "Checking for Circular List" << endl;
    if (checkcircular())
    {
        cout << "List is circular!" << endl;
    }
    else
    {
        cout << "List is not circular.." << endl;
    }
    cout << endl;

    moveToEnd(6);
    cout << "Moving all occurrences of '6' To End" << endl;
    display();

    cout << endl;
    cout << "Searching Element" << endl;
    cout << "Searching element '5' : " << endl;
    search(5);
    cout << endl;

    cout << "UserInput" << endl;
    cout << "Enter the value you want to search : ";
    int val;
    cin >> val;
    search(val);
}
