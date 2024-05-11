//Samudero Dirgantoro 5223600016
#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10

int Data[MAX];
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Pengurutan Quick rekursif
void QuickRekursif(int kiri, int kanan) {
    if (kiri < kanan) {
        int pivot = kiri;
        int i = kiri;
        int j = kanan;

        while (i < j) {
            while (Data[i] <= Data[pivot] && i <= kanan)
                i++;
            while (Data[j] > Data[pivot] && j >= kiri)
                j--;
            if (i < j)
                Tukar(&Data[i], &Data[j]);
        }
        Tukar(&Data[j], &Data[pivot]);
        QuickRekursif(kiri, j - 1);
        QuickRekursif(j + 1, kanan);
    }
}

// Pengurutan Quick non-rekursif
void Quick() {
    int kiri = 0;
    int kanan = MAX - 1;
    int stack[MAX];
    int top = -1;

    stack[++top] = kiri;
    stack[++top] = kanan;

    while (top >= 0) {
        kanan = stack[top--];
        kiri = stack[top--];

        int pivot = kiri;
        int i = kiri;
        int j = kanan;

        while (i < j) {
            while (Data[i] <= Data[pivot] && i <= kanan)
                i++;
            while (Data[j] > Data[pivot] && j >= kiri)
                j--;
            if (i < j)
                Tukar(&Data[i], &Data[j]);
        }
        Tukar(&Data[j], &Data[pivot]);

        if (kiri < j - 1) {
            stack[++top] = kiri;
            stack[++top] = j - 1;
        }

        if (j + 1 < kanan) {
            stack[++top] = j + 1;
            stack[++top] = kanan;
        }
    }
}

// Pengurutan Merge
void Merge(int Data[], int temp[], int kiri, int middle, int kanan) {
    int i = kiri;
    int j = middle + 1;
    int k = kiri;

    while (i <= middle && j <= kanan) {
        if (Data[i] <= Data[j])
            temp[k++] = Data[i++];
        else
            temp[k++] = Data[j++];
    }

    while (i <= middle)
        temp[k++] = Data[i++];

    while (j <= kanan)
        temp[k++] = Data[j++];

    for (i = kiri; i <= kanan; i++)
        Data[i] = temp[i];
}

void MergeSort(int Data[], int temp[], int kiri, int kanan) {
    if (kiri < kanan) {
        int middle = (kiri + kanan) / 2;
        MergeSort(Data, temp, kiri, middle);
        MergeSort(Data, temp, middle + 1, kanan);
        Merge(Data, temp, kiri, middle, kanan);
    }
}


void TampilkanDataSebelum(const char* label) {
    std::cout << label << "\n";
    for (int i = 0; i < MAX; i++) {
        std::cout << "Data sebelum ke " << i << " : " << Data[i] << "\n";
    }
}


void TampilkanDataSesudah(const char* label) {
    std::cout << label << "\n";
    for (int i = 0; i < MAX; i++) {
        std::cout << "Data sesudah ke " << i << " : " << Data[i] << "\n";
    }
}

int main() {
    int pilihan;

    srand(time(0));
    std::cout << "Membangkitkan bilangan acak\n";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1;
    }

    std::cout << "Pilih metode pengurutan:\n1. Quick Sort Rekursif\n2. Quick Sort Non-Rekursif\n3. Merge Sort\n";
    std::cout << "Input: ";
    std::cin >> pilihan;

    // Tampilkan data sebelum diurutkan
    TampilkanDataSebelum("Data Sebelum Diurutkan:");

    // Menu
    switch (pilihan) {
    case 1:
        QuickRekursif(0, MAX - 1);
        TampilkanDataSesudah("Setelah diurut dengan Quick Rekursif:");
        break;
    case 2:
        Quick();
        TampilkanDataSesudah("Setelah diurut dengan Quick Non-Rekursif:");
        break;
    case 3:
        int temp[MAX];
        MergeSort(Data, temp, 0, MAX - 1);
        TampilkanDataSesudah("Setelah diurut dengan Merge:");
        break;
    default:
        std::cout << "Error";
        break;
    }
}
