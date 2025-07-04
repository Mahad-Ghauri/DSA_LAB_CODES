#include <iostream>
#include <string>
using namespace std;

void Display_Array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Bubble_Sort(int arr[], int size)
{

    int counter = 1;
    while (counter < size)
    {
        for (int i = 0; i < size - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                /*
                Swapping the elements
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                */
            }
        }
        counter++;
    }
}

int main()
{
    int arr[] = {29, 10, 14, 37, 13, 45, 22, 7, 2, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << " The array before sorting: ";
    Display_Array(arr, size);

    int sortedArray[size];
    copy(arr, arr + size, sortedArray);
    Bubble_Sort(sortedArray, size);

    cout << " The array after sorting: ";
    Display_Array(sortedArray, size);

    return 0;
}