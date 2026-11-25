#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Inisiasi Variabel dan Input
    int rowA, colA, rowB, colB;
    cin >> rowA >> colA >> rowB >> colB;

    // Exception
    try {
        if (colA != rowB) {
            throw invalid_argument("Tidak bisa, jumlah kolom dan baris harus sama");
        }
    }
    catch (invalid_argument& e) {
        cerr << e.what();
    }

    int numA[rowA][colA];
    int numB[rowB][colB];

    // Input Matriks A
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            cin >> numA[i][j];
        };
    };
    
    // Input Matriks B
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            cin >> numB[i][j];
        };
    };

    // Perkalian Matriks
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colB; j++) {
            int hasil = 0;
            for (int k=0;k<colA;k++){
                hasil+= numA[i][k]*numB[k][j];
            }
            cout<<hasil<<" ";
        }
       cout <<endl;
    }

    return 0;
}