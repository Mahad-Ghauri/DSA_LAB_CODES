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

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    int left_Array[n1], right_Array[n2];

    for (int i = 0; i < n1; i++)
    {
        left_Array[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right_Array[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (left_Array[i] < right_Array[j])
        {
            arr[k] = left_Array[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = right_Array[j];

            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = left_Array[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = right_Array[j];
        j++;
        k++;
    }
}

void merge_Sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        merge_Sort(arr, low, mid);
        merge_Sort(arr, mid + 1, high);

        merge(arr, low, mid, high);
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
    merge_Sort(sortedArray, 0, size - 1);

    cout << " The array after sorting: ";
    display_Array(sortedArray, size);

    return 0;
}