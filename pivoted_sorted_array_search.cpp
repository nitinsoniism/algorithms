//Searchign an elememt in an array that is sorted but pivoted.
//A sorted array is shifted and looks like this:
//array:          1, 2, 3, 4, 5, 6, 7
//shifted right:  5, 6, 7, 1, 2, 3, 4
//shifted left:   3, 4, 5, 6, 7, 1, 2
#include <iostream>
#include <string>

using namespace std;

int search(int arr[], int low, int high, int key)
{
    if (!arr) return -1;
    if (low > high) return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] >= arr[low])
    {
        //left side of the mid is sorted
        //do regular binary search on left if key is on the left of the mid
        if (key >= arr[low] && key < arr[mid])
            return search(arr, low, mid - 1, key);
        else
            return search(arr, mid + 1, high, key);
    }
    else
    {
        //right side of the mid is sorted.
        if (key > arr[mid] && key <= arr[high])
            return search(arr, mid + 1, high, key);
        else
            return search(arr, low, mid - 1, key);
    }
}

int main()
{
    int arr1[] = {5, 6, 7, 1, 2, 3, 4};
    int arr2[] = {3, 4, 5, 6, 7, 1, 2};
    int arr3[] = {3, 4, 5, 6, 100};
    
    cout << search(arr1, 0, 6, 7) << endl;
    cout << search(arr2, 0, 6, 7) << endl;
    cout << search(arr3, 0, 4, 100) << endl;
    cout << search(arr3, 0, 4, 7) << endl;
    return 0;
}
