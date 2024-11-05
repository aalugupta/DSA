#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {

        for (int j = 0; j < n - i - 1; ++j)// in shorting we always have to swap elememnts using inner loop index as it is designed according to neccesary conditions of shorting
        {

            if (arr[j] > arr[j + 1])//we cant directly take arr[i] as it value is changing and thus wrong elements are being compared
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;//we cant take min = arr[i] as it will affect swapping afterwards
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr)// we cant use arr[i] directly because arr[i] value is changing in swapping
        {
            swap(arr[prev], arr[prev + 1]);
            prev--;
        }
        // arr[prev+1]=curr;
    }
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11};
    int arr2[]={'f','b','a','e','c','d'};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    print_array(arr2, n);

    // bubble_sort(arr, n);
    // selection_sort(arr, n);
    insertion_sort(arr2, n);

    // cout << "Sorted array: ";
    print_array(arr2, n);

    return 0;
}
