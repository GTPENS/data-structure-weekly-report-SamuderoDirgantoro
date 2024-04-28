//Samudero Dirgantoro 5223600016
#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

int Data[MAX];

//pertukaran bilangan
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//pengurutan langsung
void langsung() {
    int i, j, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        j = i - 1;
        while (j >= 0 && x < Data[j]) {
            Data[j + 1] = Data[j];
            j--;
        }
        Data[j + 1] = x;
    }
}

//pengurutan biner
void biner() {
    int i, j, l, r, m, x;
    for (i = 1; i < MAX; i++) {
        x = Data[i];
        l = 0;
        r = i - 1;
        while (l <= r) {
            m = (l + r) / 2;
            if (x < Data[m])
                r = m - 1;
            else
                l = m + 1;
        }
        for (j = i - 1; j >= l; j--)
            Data[j + 1] = Data[j];
        Data[l] = x;
    }
}

//pengurutan seleksi
void seleksi() {
    int i, j, k;
    for (i = 0; i < MAX - 1; i++) {
        k = i;
        for (j = i + 1; j < MAX; j++) {
            if (Data[k] > Data[j])
                k = j;
        }
        Tukar(&Data[i], &Data[k]);
    }
}

//mencetak data
void TampilkanData(const char* label) {
    std::cout << label << "\n";
    for (int i = 0; i < MAX; i++) {
        std::cout << "Data ke " << i << " : " << Data[i] << "\n";
    }
}

int main() {
    int pilihan;
    //Generate bilangan acak
    srand(time(0));
    std::cout << "Membangkitkan bilangan acak\n";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1;
    }
    // Meminta pengguna memilih metode pengurutan
    std::cout << "Pilih metode pengurutan:\n";
    std::cout << "1. Penyisipan Langsung\n";
    std::cout << "2. Penyisipan Biner\n";
    std::cout << "3. Metode Seleksi\n";
    std::cout << "Masukkan pilihan Anda: \n";
    std::cin >> pilihan;
    //Menu
    switch (pilihan) {
    case 1:
        langsung();
        TampilkanData("Penyisipan Langsung:");
        break;
    case 2:
        biner();
        TampilkanData("Penyisipan Biner:");
        break;
    case 3:
        seleksi();
        TampilkanData("Metode Seleksi:");
        break;
    default:
        std::cout << "error\n";
        break;
    }
}