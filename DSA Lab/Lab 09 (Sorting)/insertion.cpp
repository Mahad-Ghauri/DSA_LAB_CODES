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

void insertion_Sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];

        int j = i-1;

        while (j >= 0 && arr[j] > key)
        {

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j+1] = key;
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
    insertion_Sort(sortedArray, size);

    cout << " The array after sorting: ";
    display_Array(sortedArray, size);

    return 0;
}