
#include <iostream>
using namespace std;

// Mengubah angka menjadi satu digit
int digitalRoot(long long n) {
    while (n >= 10) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        n = sum;
    }

    return n;
}

int main() {
    int n;
    cin >> n;

    int frequency[10] = {0};

    for (int i = 0; i < n; i++) {
        long long number;
        cin >> number;

        int result = digitalRoot(number);

        frequency[result]++;
    }

    int mostFrequent = 0;
    int highestFrequency = 0;

    for (int i = 0; i < 10; i++) {
        if (frequency[i] > highestFrequency) {
            highestFrequency = frequency[i];
            mostFrequent = i;
        }
    }

    cout << mostFrequent << endl;
    cout << highestFrequency << endl;

    return 0;
}
