#include <iostream>
using namespace std;


class Node
{
private:
	int data;
	Node *next;
	
public:
	Node(int val)
	{
		data = val;
		next = NULL;
	}
	
	void setData(int value)
	{
		data = value;
	}
	
	int getData()
	{
		return data;
	}
	
	void setNext(Node* other)
	{
		next = other;
	}
	
	
	Node* getNext()
	{
		return next;
	}
	
	
	void Display(Node* other) 
	{
    cout << " List : ";
    Node* temp = other; 
    while (temp) 
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
	}
	
	
};

int main()
{
	int arr[] = { 2,4,6,8,10};
	
	Node *head = NULL;
	
	
	for(int i=0; i<5 ; i++)
	{
		if(head == NULL)
		{
			head = new Node(arr[i]);
		}
		else
		{
			Node *temp = new Node(arr[i]);
			temp->setNext(head);
			head = temp;
		}
	}
	
	head->Display(head);
	
// ----------- Deleting a required node -------------------	
	
	
	int required_integer = 2;
	Node *current = head;
	Node *previous = NULL;
	
	int count = 0;
	while(current->getNext() != NULL)
	{
		count++;
		current = current->getNext();
		
		if(current->getData() == required_integer)
		{	
			break;
		}
	}
	
	current = head;
	

	while(count--)
	{
    	previous = current;
    	current = current->getNext();
	}
	
	
	if (previous == NULL)
	{
        head = current->getNext();
    } 
	else 
	{
        previous->setNext(current->getNext());
    }
    delete current;

	cout << "\n\n After Deleting the node " << endl;

	cout << "\n";
    head->Display(head); 
	
	
	
//	-------------------- Reversing the List --------------------------

	cout << endl;

	previous = NULL;
	current = head;
	Node *next = NULL;

	while (current != NULL)
	{
   		next = current->getNext();
    	current->setNext(previous);
    	previous = current;
    	current = next;
	}

	cout << "\n\n After Reversing the list " << endl;
	head = previous;
	head->Display(head);
	
	return 0;
}
