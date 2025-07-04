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
            temp->next = newnode;
        }
        else
        {

            newnode->next = newnode;
            head = newnode;
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

        if (head == NULL || head->next == head)
        {
            return;
        }

        struct node *last = head;
        struct node *current = head;
        struct node *prev = NULL;

        while (last->next != head) // last is traversed to the last node of the list
        {
            last = last->next;
        }

        struct node *originallast = last;
        do
        {
            if (current->data == value)
            {

                if (current == head) // If the first node is the required node to be moved
                {
                    head = head->next; // Head is moved one node forward

                    last->next = current; // TO move the current node to end 

                    current->next = head; //  Reassure the Current points to new head

                    last = current; // UPdates the last to current
                    current = head; // Current points to the same node as th head
                }
                else
                {
                    cout << " 1" << endl;
                    prev->next = current->next;

                    last->next = current;
                    cout << " 2" << endl;

                    current->next = head;

                    last = current; 

                    current = prev->next;
                    cout << " 3" << endl;
                }
            }
            else
            {
                // Simple traversing through the list
                prev = current;
                current = current->next;
            }
        } while (current != originallast->next);

        
    }

    void display()
    {

        struct node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        // cout << "(head)" << endl;
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
        cout << "Moving all occureneces of '6' To End" << endl;
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