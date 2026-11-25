#include <iostream>
using namespace std;

int binarySearch(const int A[], int n, int target) {
    int lower = 0;
    int upper = n - 1;

    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;

        if (A[mid] == target) {
            return mid;
        }
        else if (A[mid] < target) {
            lower = mid + 1;
        }
        else {
            upper = mid - 1;
        }
    }

    return -1;
}

int main() {
    int A[] = {
        102, 105, 108, 112, 115, 120, 125, 130, 135, 140
    };

    int n = sizeof(A) / sizeof(A[0]);

    int target;

    cout << "Enter the value to search: ";
    cin >> target;

    int result = binarySearch(A, n, target);

    if (result != -1) {
        cout << "The value is found."
             << endl;
        cout << "The index is: " << result
             << ", value is: " << A[result]
             << endl;
    }
    else {
        cout << "The value is not found."
             << endl;
    }

    return 0;
}