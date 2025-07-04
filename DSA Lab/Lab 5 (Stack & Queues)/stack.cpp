#include <iostream>
using namespace std;

class Stack
{
private:
    int *arr;    // Array to store stack elements
    int top;     // Index of the top element
    int maxSize; // Maximum size of the stack

public:
    // Constructor to initialize the stack
    Stack(int size)
    {
        arr = new int[size];
        maxSize = size;
        top = -1;
    }

   // Push an element onto the stack
    void push(char value)
    {   
        if (top == maxSize - 1)
        {
            cout << "Stack overflow. Unable to push " << value << "\n";
            return;
        }
        arr[++top] = value;
    }

    // Pop an element from the stack
    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow. No element to pop.\n";
            return -1;
        }
        return arr[top--];
    }

    // Peek at the top element of the stack
    char peek() const
    {
        if (isEmpty())
        {
            return -1; // Returnkking -1 if stack is empty
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() const
    {
        return top == -1;
    }
    // Destructor to free allocated memory
    ~Stack()
    {
        delete[] arr;
    }

    void Push_And_Pop(string other)
    {
        for (int i = 0; i < other.length(); i++)
        {
            char token = other[i];

            if (!isdigit(token))
            {
                if (!ispunct(token))
                {
                    cout << "\n Pushed: " << token << " in the stack " << endl;
                    arr[++top] = token;
                }
                // else
                // {
                //     cout << "\n The element is not an aplhabet " << endl;
                // }
                else if (token == '*')
                {
                    cout << "\n Poped '*' out of the stack " << endl;
                    arr[top--];
                }
                // else
                // {
                //     cout << "\n The elemnt is not * " << endl;
                // }
            }
        }
    }
};

int main()
{
    string name = "EA*Y*TR*";
    Stack s(name.length());
    s.Push_And_Pop(name);

    return 0;
}
