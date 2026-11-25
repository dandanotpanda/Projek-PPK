#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int rows1, columns1, rows2, columns2;
    cin >> rows1 >> columns1 >> rows2 >> columns2;

    if (columns1 != rows2) {
        cout << "Tidak bisa, jumlah kolom dan baris harus sama" << endl;
        return 0;
    }

    int num1[rows1][columns1];
    int num2[rows2][columns2];

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            cin >> num1[i][j];
        }
    }

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < columns2; j++) {
            cin >> num2[i][j];
        }
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            int hasil = 0;
            for (int k = 0; k < columns1; k++) {
                hasil += num1[i][k] * num2[k][j];
            }
            cout << "hasil: " << hasil << " ";
        }
        cout << endl;
    }
    
    return 0;
}