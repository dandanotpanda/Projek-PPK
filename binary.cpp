#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

int binarySearch(const int A[], int n, int target) {

    if (!is_sorted(A, A + n)) {
        throw invalid_argument("Array must be sorted.");
    }

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

    try {
        cout << "Enter the value to search: ";
        if (!(cin >> target)) {
            throw invalid_argument("Invalid input.");
        }

        int result = binarySearch(A, n, target);

        if (result != -1) {
            cout << "The value is found."
                 << "\nThe index is: " << result
                 << ", value is: " << A[result] << endl;
        }
        else {
            cout << "The value is not found." << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }

    return 0;
}