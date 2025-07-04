#include <iostream>
#include <cstdlib>
using namespace std;

void Insert(int * , int);
void Delete(int * , int);

int main()
{
	
	int size;
	int arr[size] , choice;
	
	
	cout << " Enter the size of the array : ";
	cin >> size;
	
	cout << "\n";
	
	cout << " Enter the elements of the array :";
	for(int i=0; i<size; i++)
	{
		cin >> arr[i];
	}
	
	
	for(int i=0; i<size; i++)
	{
		cout << "Index " << i+1  << ": " << arr[i];
		cout << endl;
	}

	while(true)
	{
		cout << endl;
		cout << " Choose from the following options " << endl;
		cout << " 1--> To Insert a new element at specific position " << endl;
		cout << " 2--> To Delete a element at specific position " << endl;
		cout << " 3--> Exit the program " << endl;
		cin >> choice;
	
		switch(choice)
		{
			case 1:
				cout << "\n";
				Insert(arr , size);
				break;
				
			case 2:
				cout << "\n";
				Delete(arr, size);
				break;
			
			case 3:
				return 1;
			
			default:
				cout << "Invalid Choice !!! " << endl;
				break;
		}	
	}	
	return 0;
}

void Delete(int *array ,  int num1)	
{
	
	int index ;
	cout << endl;
a:
	cout << " Enter the position you want to delete a new element : ";
	cin >> index;
	if(index > num1)
	{
		cout << " The position is greater than the size of the array " << endl;
		goto a;
	}
	
	for(int i=index-1 ; i<num1; i++)
	{
		array[i] = array[i+1];	
	}
	num1--;
	
	for(int i=0; i<num1; i++)
	{
		cout << "Index " << i+1  << ": " << array[i];
		cout << endl;
	}
	
	
}

void Insert(int *array ,  int num1)
{
	
	int index ;
	cout << endl;
a:
	cout << " Enter the position you want to insert a new element : ";
	cin >> index;
	if(index > num1)
	{
		cout << " The position is greater than the size of the array " << endl;
		goto a;
	}
	
	int newElement;
	cout << " Insert a new element at position " << index << ": ";
	cin >> newElement;
	
	int position = 0;
	while(index--)
	{
		position++;
	}
	array[position-1] = newElement;
	
	
	for(int i=0; i<num1; i++)
	{
		cout << "Index " << i+1  << ": " << array[i];
		cout << endl;
	}
	
}
