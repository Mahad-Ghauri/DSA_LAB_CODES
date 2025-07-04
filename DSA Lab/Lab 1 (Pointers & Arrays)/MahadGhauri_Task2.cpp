#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
	
	int size;
	int arr[size] , target;
	
	
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


	cout << " Enter the element you want to search ";
	cin >> target;
	
	for(int i=0; i<size; i++)
	{
		if(arr[i] == target)
		{
			cout << " Element " << arr[i] << " found at index " << i+1 << endl;
		}
		else
		{
			cout << " Element not found " << -1 << " at index " << i+1 << endl;
		}
	}

	
	return 0;
	
}
