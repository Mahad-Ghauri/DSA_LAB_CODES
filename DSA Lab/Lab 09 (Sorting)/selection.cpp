#include <iostream>
#include <string>
using namespace std;

void display_Array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selection_Sort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }
}

int main()
{
    int arr[] = {29, 10, 14, 37, 13, 45, 22, 7, 2, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << " The array before sorting: ";
    display_Array(arr, size);

    int sortedArray[size];
    copy(arr, arr + size, sortedArray);
    selection_Sort(sortedArray, size);

    cout << " The array after sorting: ";
    display_Array(sortedArray, size);

    return 0;
}