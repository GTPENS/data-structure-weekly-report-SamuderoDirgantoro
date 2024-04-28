//Samudero Dirgantoro
#include <iostream>
#include <string>
using namespace std;

struct Pegawai {
    int NIP;
    string Nama;
    string Alamat;
    char Golongan;
};

// Fungsi  menampilkan data pegawai
void tampilkanPegawai(Pegawai arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "NIP: " << arr[i].NIP << ", Nama: " << arr[i].Nama << ", Alamat: " << arr[i].Alamat << ", Golongan: " << arr[i].Golongan << "\n";
    }
    cout << "\n";
}

// Fungsi langsung (straight insertion) berdasarkan NIP
void langsungNIP(Pegawai arr[], int n, bool urutanNaik) {
    int i, j, perbandingan = 0, pergeseran = 0;
    Pegawai key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        if (urutanNaik) {
            while (j >= 0 && arr[j].NIP > key.NIP) {
                arr[j + 1] = arr[j];
                j = j - 1;
                perbandingan++;
                pergeseran++;
            }
        }
        else {
            while (j >= 0 && arr[j].NIP < key.NIP) {
                arr[j + 1] = arr[j];
                j = j - 1;
                perbandingan++;
                pergeseran++;
            }
        }
        arr[j + 1] = key;
        pergeseran++;
    }
    cout << "Pengurutan berdasarkan NIP\n";
    cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << "\n";
    tampilkanPegawai(arr, n);
}

// Fungsi langsung (straight insertion) berdasarkan Nama
void langsungNAMA(Pegawai arr[], int n, bool urutanNaik) {
    int i, j, perbandingan = 0, pergeseran = 0;
    Pegawai key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        if (urutanNaik) {
            while (j >= 0 && arr[j].Nama > key.Nama) {
                arr[j + 1] = arr[j];
                j = j - 1;
                perbandingan++;
                pergeseran++;
            }
        }
        else {
            while (j >= 0 && arr[j].Nama < key.Nama) {
                arr[j + 1] = arr[j];
                j = j - 1;
                perbandingan++;
                pergeseran++;
            }
        }
        arr[j + 1] = key;
        pergeseran++;
    }
    cout << "Pengurutan berdasarkan Nama\n";
    cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << "\n";
    tampilkanPegawai(arr, n);
}

// Fungsi biner (binary insertion) berdasarkan NIP
void binerNIP(Pegawai arr[], int n, bool urutanNaik) {
    int i, j, perbandingan = 0, pergeseran = 0;
    Pegawai key;
    int low, high, mid;
    for (i = 1; i < n; i++) {
        key = arr[i];
        low = 0;
        high = i - 1;

        while (low <= high) {
            mid = (low + high) / 2;
            if (urutanNaik) {
                if (key.NIP < arr[mid].NIP) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if (key.NIP > arr[mid].NIP) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            perbandingan++;
        }

        for (j = i - 1; j >= low; j--) {
            arr[j + 1] = arr[j];
            pergeseran++;
        }
        arr[low] = key;
        pergeseran++;
    }
    cout << "Pengurutan berdasarkan NIP\n";
    cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << "\n";
    tampilkanPegawai(arr, n);
}

// Fungsi biner (binary insertion) berdasarkan Nama
void binerNAMA(Pegawai arr[], int n, bool urutanNaik) {
    int i, j, perbandingan = 0, pergeseran = 0;
    Pegawai key;
    int low, high, mid;
    for (i = 1; i < n; i++) {
        key = arr[i];
        low = 0;
        high = i - 1;

        while (low <= high) {
            mid = (low + high) / 2;
            if (urutanNaik) {
                if (key.Nama < arr[mid].Nama) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if (key.Nama > arr[mid].Nama) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            perbandingan++;
        }

        for (j = i - 1; j >= low; j--) {
            arr[j + 1] = arr[j];
            pergeseran++;
        }
        arr[low] = key;
        pergeseran++;
    }
    cout << "Pengurutan berdasarkan Nama\n";
    cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << "\n";
    tampilkanPegawai(arr, n);
}

// Fungsi seleksi berdasarkan NIP
void seleksiNIP(Pegawai arr[], int n, bool urutanNaik) {
    int i, j, minIndex, perbandingan = 0, pergeseran = 0;
    Pegawai temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (urutanNaik) {
                if (arr[j].NIP < arr[minIndex].NIP) {
                    minIndex = j;
                }
            }
            else {
                if (arr[j].NIP > arr[minIndex].NIP) {
                    minIndex = j;
                }
            }
            perbandingan++;
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        pergeseran++;
    }
    cout << "Pengurutan berdasarkan NIP\n";
    cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << "\n";
    tampilkanPegawai(arr, n);
}

// Fungsi seleksi berdasarkan Nama
void seleksiNAMA(Pegawai arr[], int n, bool urutanNaik) {
    int i, j, minIndex, perbandingan = 0, pergeseran = 0;
    Pegawai temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (urutanNaik) {
                if (arr[j].Nama < arr[minIndex].Nama) {
                    minIndex = j;
                }
            }
            else {
                if (arr[j].Nama > arr[minIndex].Nama) {
                    minIndex = j;
                }
            }
            perbandingan++;
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        pergeseran++;
    }
    cout << "Pengurutan berdasarkan Nama\n";
    cout << "Perbandingan: " << perbandingan << ", Pergeseran: " << pergeseran << "\n";
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
    cout << "1. Straight Insertion\n";
    cout << "2. Binary Insertion\n";
    cout << "3. Selection Sort\nInput:";
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
            if (urutan == 1) {
                langsungNIP(pegawai, n, true);
            }
            else {
                langsungNIP(pegawai, n, false);
            }
            break;
        case 2:
            if (urutan == 1) {
                binerNIP(pegawai, n, true);
            }
            else {
                binerNIP(pegawai, n, false);
            }
            break;
        case 3:
            if (urutan == 1) {
                seleksiNIP(pegawai, n, true);
            }
            else {
                seleksiNIP(pegawai, n, false);
            }
            break;
        default:
            cout << "Pilihan tidak valid.";
        }
        break;
    case 2:
        switch (metode) {
        case 1:
            if (urutan == 1) {
                langsungNAMA(pegawai, n, true);
            }
            else {
                langsungNAMA(pegawai, n, false);
            }
            break;
        case 2:
            if (urutan == 1) {
                binerNAMA(pegawai, n, true);
            }
            else {
                binerNAMA(pegawai, n, false);
            }
            break;
        case 3:
            if (urutan == 1) {
                seleksiNAMA(pegawai, n, true);
            }
            else {
                seleksiNAMA(pegawai, n, false);
            }
            break;
        default:
            cout << "Pilihan tidak valid.";
        }
        break;
    default:
        cout << "Pilihan tidak valid.";
    }
}
