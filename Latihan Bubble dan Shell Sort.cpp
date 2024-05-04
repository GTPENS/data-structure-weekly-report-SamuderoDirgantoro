#include <iostream>
#include <string>
using namespace std;

struct Pegawai {
    int NIP;
    string Nama;
    string Alamat;
    char Golongan;
};

// Fungsi untuk menampilkan data pegawai
void tampilkanPegawai(Pegawai arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "NIP: " << arr[i].NIP << ", Nama: " << arr[i].Nama << ", Alamat: " << arr[i].Alamat << ", Golongan: " << arr[i].Golongan << "\n";
    }
    cout << "\n";
}

// Fungsi Bubble berdasarkan NIP
void bubbleNIP(Pegawai arr[], int n, bool urutanNaik) {
    int i, j;
    Pegawai temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (urutanNaik) {
                if (arr[j].NIP > arr[j + 1].NIP) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            else {
                if (arr[j].NIP < arr[j + 1].NIP) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    tampilkanPegawai(arr, n);
}

// Fungsi Bubble berdasarkan Nama
void bubbleNAMA(Pegawai arr[], int n, bool urutanNaik) {
    int i, j;
    Pegawai temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (urutanNaik) {
                if (arr[j].Nama > arr[j + 1].Nama) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            else {
                if (arr[j].Nama < arr[j + 1].Nama) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    tampilkanPegawai(arr, n);
}

// Fungsi Shell berdasarkan NIP
void shellNIP(Pegawai arr[], int n, bool urutanNaik) {
    int i, j, gap;
    Pegawai temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            if (urutanNaik) {
                for (j = i; j >= gap && arr[j - gap].NIP > temp.NIP; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            }
            else {
                for (j = i; j >= gap && arr[j - gap].NIP < temp.NIP; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            }
            arr[j] = temp;
        }
    }
    tampilkanPegawai(arr, n);
}

// Fungsi Shell berdasarkan Nama
void shellNAMA(Pegawai arr[], int n, bool urutanNaik) {
    int i, j, gap;
    Pegawai temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            if (urutanNaik) {
                for (j = i; j >= gap && arr[j - gap].Nama > temp.Nama; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            }
            else {
                for (j = i; j >= gap && arr[j - gap].Nama < temp.Nama; j -= gap) {
                    arr[j] = arr[j - gap];
                }
            }
            arr[j] = temp;
        }
    }
    tampilkanPegawai(arr, n);
}

int main() {
    // Contoh data pegawai
    Pegawai pegawai[] = {
        {101, "Dimas", "Jakarta", 'A'},
        {103, "Anwar", "Bandung", 'B'},
        {102, "Budi", "Surabaya", 'C'},
        {104, "Jojo", "Yogyakarta", 'A'}
    };
    int n = sizeof(pegawai) / sizeof(pegawai[0]);

    // Pilihan metode pengurutan
    int metode;
    cout << "Pilih metode pengurutan:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Shell Sort\nInput: ";
    cin >> metode;

    // Pilihan urutan
    int urutan;
    cout << "Pilih urutan:\n";
    cout << "1. Naik\n";
    cout << "2. Turun\nInput: ";
    cin >> urutan;

    // Pilihan pengurutan berdasarkan
    int berdasarkan;
    cout << "Pilih pengurutan berdasarkan:\n";
    cout << "1. NIP\n";
    cout << "2. Nama\nInput: ";
    cin >> berdasarkan;

    // Mengurutkan data berdasarkan pilihan
    switch (berdasarkan) {
    case 1:
        switch (metode) {
        case 1:
            bubbleNIP(pegawai, n, (urutan == 1));
            break;
        case 2:
            shellNIP(pegawai, n, (urutan == 1));
            break;
        default:
            cout << "Pilihan tidak valid.";
        }
        break;
    case 2:
        switch (metode) {
        case 1:
            bubbleNAMA(pegawai, n, (urutan == 1));
            break;
        case 2:
            shellNAMA(pegawai, n, (urutan == 1));
            break;
        default:
            cout << "Pilihan tidak valid.";
        }
        break;
    default:
        cout << "Pilihan tidak valid.";
    }

    return 0;
}
