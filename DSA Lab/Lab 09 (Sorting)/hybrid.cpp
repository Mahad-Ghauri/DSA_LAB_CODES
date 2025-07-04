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

void bubble_Sort(int arr[], int low, int high)
{
    for (int i = low; i < high-1; i++)
    {
        for (int j = low; j < high - (i - low) ; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void hybrid_Sort(int arr[], int low, int high, int threshold)
{
    if (low < high)
    {
        // Use Bubble Sort if the size of the sub-array is small
        if (high - low + 1 <= threshold)
        {
            bubble_Sort(arr, low, high);
        }
        else
        {
            // Partition and continue with Quick Sort
            int pivot = partition(arr, low, high);

            hybrid_Sort(arr, low, pivot - 1, threshold);
            hybrid_Sort(arr, pivot + 1, high, threshold);
        }
    }
}

int main()
{
    int arr[] = {29, 10, 14, 37, 13, 45, 22, 7, 2, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int threshold = 10; // Threshold for switching to Bubble Sort

    cout << "The array before sorting: ";
    display_Array(arr, size);

    hybrid_Sort(arr, 0, size - 1, threshold);

    cout << "The array after hybrid sorting: ";
    display_Array(arr, size);

    return 0;
}
