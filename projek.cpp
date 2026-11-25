
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

int binarySearch(const vector<int>& A, int target) {

    if (!is_sorted(A.begin(), A.end())) {
        throw invalid_argument("Array must be sorted.");
    }

    int lower = 0;
    int upper = A.size() - 1;

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

    vector<int> A = {
        2, 3, 5, 7, 11, 13, 17, 19, 23,
        29, 31, 37, 41, 43, 47, 53, 59,
        61, 67, 71, 73, 79, 83, 89, 97
    };

    int target;

    try {
        cout << "Enter the value to search: ";
        if (!(cin >> target)) {
            throw invalid_argument("Invalid input.");
        }

        int result = binarySearch(A, target);

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
