#include <iostream>
#include <string>
using namespace std;

// DATA BUKU
const int MAX_BUKU = 100;
int jumlahBuku = 5;
int idBuku[MAX_BUKU] = {
    101, 102, 103, 104, 105
};

string judulBuku[MAX_BUKU] = {
    "Laskar Pelangi",
    "Bumi",
    "Pemrograman C++",
    "Algoritma dan Struktur Data",
    "The Psychology of Money"
};

string penulisBuku[MAX_BUKU] = {
    "Andrea Hirata",
    "Tere Liye",
    "Budi Raharjo",
    "Rosa A.S.",
    "Morgan Housel"
};

bool statusBuku[MAX_BUKU] = {
    true, true, true, true, true
};

// FUNCTION SHOW BOOKS

void showBooks()
{
    cout << "\n========== DAFTAR BUKU ==========\n";

    if (jumlahBuku == 0)
    {
        cout << "Belum ada buku di perpustakaan.\n";
        return;
    }

    for (int i = 0; i < jumlahBuku; i++)
    {
        cout << "\nID       : " << idBuku[i];
        cout << "\nJudul    : " << judulBuku[i];
        cout << "\nPenulis  : " << penulisBuku[i];

        if (statusBuku[i])
        {
            cout << "\nStatus   : Tersedia";
        }
        else
        {
            cout << "\nStatus   : Dipinjam";
        }

        cout << "\n---------------------------------\n";
    }
}

// FUNCTION OVERLOADING
// SEARCH BY ID

void searchBook(int id)
{
    bool ditemukan = false;

    for (int i = 0; i < jumlahBuku; i++)
    {
        if (idBuku[i] != id)
        {
            continue;
        }

        cout << "\n========== BUKU DITEMUKAN ==========\n";
        cout << "ID       : " << idBuku[i] << endl;
        cout << "Judul    : " << judulBuku[i] << endl;
        cout << "Penulis  : " << penulisBuku[i] << endl;

        if (statusBuku[i])
        {
            cout << "Status   : Tersedia\n";
        }
        else
        {
            cout << "Status   : Dipinjam\n";
        }

        ditemukan = true;
        break;
    }

    if (!ditemukan)
    {
        cout << "\nBuku dengan ID tersebut tidak ditemukan.\n";
    }
}


// FUNCTION OVERLOADING
// SEARCH BY JUDUL


void searchBook(string judul)
{
    bool ditemukan = false;

    for (int i = 0; i < jumlahBuku; i++)
    {
        if (judulBuku[i] != judul)
        {
            continue;
        }

        cout << "\n========== BUKU DITEMUKAN ==========\n";
        cout << "ID       : " << idBuku[i] << endl;
        cout << "Judul    : " << judulBuku[i] << endl;
        cout << "Penulis  : " << penulisBuku[i] << endl;

        if (statusBuku[i])
        {
            cout << "Status   : Tersedia\n";
        }
        else
        {
            cout << "Status   : Dipinjam\n";
        }

        ditemukan = true;
        break;
    }

    if (!ditemukan)
    {
        cout << "\nBuku dengan judul tersebut tidak ditemukan.\n";
    }
}


// FUNCTION ADD BOOK

void addBook()
{
    if (jumlahBuku >= MAX_BUKU)
    {
        cout << "\nKapasitas perpustakaan sudah penuh.\n";
        return;
    }

    cout << "\n========== TAMBAH BUKU ==========\n";

    cout << "Masukkan ID buku: ";
    cin >> idBuku[jumlahBuku];

    cin.ignore();

    cout << "Masukkan judul buku: ";
    getline(cin, judulBuku[jumlahBuku]);

    cout << "Masukkan nama penulis: ";
    getline(cin, penulisBuku[jumlahBuku]);

    statusBuku[jumlahBuku] = true;

    jumlahBuku++;

    cout << "\nBuku berhasil ditambahkan!\n";
}

// FUNCTION BORROW BOOK

void borrowBook()
{
    int id;

    cout << "\nMasukkan ID buku yang ingin dipinjam: ";
    cin >> id;

    for (int i = 0; i < jumlahBuku; i++)
    {
        if (idBuku[i] != id)
        {
            continue;
        }

        if (statusBuku[i])
        {
            statusBuku[i] = false;

            cout << "\nBuku \"" << judulBuku[i]
                 << "\" berhasil dipinjam.\n";
        }
        else
        {
            cout << "\nBuku tersebut sedang dipinjam.\n";
        }

        return;
    }

    cout << "\nBuku tidak ditemukan.\n";
}

// FUNCTION RETURN BOOK

void returnBook()
{
    int id;

    cout << "\nMasukkan ID buku yang ingin dikembalikan: ";
    cin >> id;

    for (int i = 0; i < jumlahBuku; i++)
    {
        if (idBuku[i] != id)
        {
            continue;
        }

        if (!statusBuku[i])
        {
            statusBuku[i] = true;

            cout << "\nBuku \"" << judulBuku[i]
                 << "\" berhasil dikembalikan.\n";
        }
        else
        {
            cout << "\nBuku tersebut belum dipinjam.\n";
        }

        return;
    }

    cout << "\nBuku tidak ditemukan.\n";
}

// FUNCTION REMOVE BOOK

void removeBook()
{
    int id;
    bool ditemukan = false;

    cout << "\nMasukkan ID buku yang ingin dihapus: ";
    cin >> id;

    for (int i = 0; i < jumlahBuku; i++)
    {
        if (idBuku[i] != id)
        {
            continue;
        }

        // Geser data buku setelahnya ke kiri
        for (int j = i; j < jumlahBuku - 1; j++)
        {
            idBuku[j] = idBuku[j + 1];
            judulBuku[j] = judulBuku[j + 1];
            penulisBuku[j] = penulisBuku[j + 1];
            statusBuku[j] = statusBuku[j + 1];
        }

        // Kurangi jumlah buku
        jumlahBuku--;

        ditemukan = true;

        cout << "\nBuku berhasil dihapus.\n";

        break;
    }

    if (!ditemukan)
    {
        cout << "\nBuku tidak ditemukan.\n";
    }
}

// FUNCTION SEARCH MENU

void searchMenu()
{
    int pilihan;

    cout << "\n========== SEARCH BOOK ==========\n";
    cout << "1. Cari berdasarkan ID\n";
    cout << "2. Cari berdasarkan Judul\n";
    cout << "Pilih: ";
    cin >> pilihan;

    switch (pilihan)
    {
        case 1:
        {
            int id;

            cout << "Masukkan ID buku: ";
            cin >> id;

            searchBook(id);

            break;
        }

        case 2:
        {
            string judul;

            cin.ignore();

            cout << "Masukkan judul buku: ";
            getline(cin, judul);

            searchBook(judul);

            break;
        }

        default:
            cout << "\nPilihan tidak tersedia.\n";
            break;
    }
}

// MAIN PROGRAM

int main()
{
    int pilihan;

    while (true)
    {
        cout << "\n\n====================================\n";
        cout << "      LIBRARY MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Show Books\n";
        cout << "2. Search Book\n";
        cout << "3. Add Book\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Remove Book\n";
        cout << "7. Exit\n";

        cout << "====================================\n";
        cout << "Jumlah buku : " << jumlahBuku
             << "/" << MAX_BUKU << endl;

        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                showBooks();
                break;

            case 2:
                searchMenu();
                break;

            case 3:
                addBook();
                break;

            case 4:
                borrowBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                removeBook();
                break;

            case 7:
                cout << "\nProgram selesai. Terima kasih!\n";
                break;

            default:
                cout << "\nPilihan tidak valid.\n";
                continue;
        }

        if (pilihan == 7)
        {
            break;
        }
    }

    return 0;
}