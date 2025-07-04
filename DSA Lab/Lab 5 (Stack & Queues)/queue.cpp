    #include <iostream>
    #include <string>
    using namespace std;

    class Node
    {
    private:
        int data;
        Node *next;

    public:
        Node(int x)
        {
            data = x;
            next = NULL;
        }

        void setNext(Node *other)
        {
            next = other;
        }

        void setData(int x)
        {
            data = x;
        }

        Node *getNext()
        {
            return next;
        }

        int getData()
        {
            return data;
        }
    };

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

        int RemoveNode()
        {
            if (head == NULL)
            {
                cout << "List is empty. No element to dequeue.\n";
                return -1;
            }

            int value = head->getData();
            Node *temp = head;
            head = head->getNext();
            delete temp;
            return value;
        }

        int Peek()
        {
            if (head == NULL)
            {
                cout << "List is empty. No element to peek.\n";
                return -1;
            }
            return head->getData();
        }

        bool isEmpty()
        {
            return head == NULL;
        }
    };

    class Queue
    {
    private:
        List l1;

    public:
        Queue()
        {
            // Default Constructor
        }

        void Enqueue(int value)
        {
            l1.AddNode(value);
            cout << " Enqueued: " << value << " to queue.\n";
        }

        int Dequeue()
        {
            
            return l1.RemoveNode();
        }

        int Peek()
        {
            return l1.Peek();
        }

        bool isEmpty()
        {
            return l1.isEmpty();
        }

        bool isFull()
        {
            return false;
        }
    };

    int main()
    {
        Queue q;

        q.Enqueue(10);
        q.Enqueue(20);
        q.Enqueue(30);

        cout << "Front element: " << q.Peek() << endl;

        cout << " Dequeued " << q.Dequeue() << " from queue." << endl;
        cout << "Front element: " << q.Peek() << endl;

        cout << " Dequeued " << q.Dequeue() << " from queue." << endl;
        cout << " Dequeued " << q.Dequeue() << " from queue." << endl;

        cout << "Is queue empty ? ";
        if (q.isEmpty())
        {
            cout << " Yes " << endl;
        }
        else
        {
            cout << " No " << endl;
        }

        return 0;
    }