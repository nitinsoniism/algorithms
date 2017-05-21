// Finding farthest numbers in an array without changing the order of numbers. 
// Stock market profilt question on page number 1 in EPI book

#include <iostream>
#include <string>

using namespace std;

int farthest_numbers(int*, int, int*, int*);

int main() {
    int arr[] = {3, 5, 7, 4, 13, 2, 6, 7, 1};
    int arr1[] = {26, 34, 23, 52, 114, 134, 23, 17, 121, 197, 12, 196};
    int first, second;
    first = second = 0;
    int ret = farthest_numbers(arr, sizeof(arr)/sizeof(arr[0]), &first, &second);
    cout << "biggest diff : " << first << " " << second << " diff: "
        << second - first << endl;
    ret = farthest_numbers(arr1, sizeof(arr1)/sizeof(arr1[0]), &first, &second);
    cout << "biggest diff : " << first << " " << second << " diff: "
        << second - first << endl;
    return 0;
}

int farthest_numbers(int *arr, int len, int *first, int *second) {
    int biggest_diff = 0;
    if (!arr) return -1;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int diff = arr[j] - arr[i];
            if (diff > biggest_diff) {
                cout << "biggest diff " << diff << endl;
                biggest_diff = diff;
                *first = arr[i];
                *second = arr[j];
            }
        }
    }
    return 0;
}
