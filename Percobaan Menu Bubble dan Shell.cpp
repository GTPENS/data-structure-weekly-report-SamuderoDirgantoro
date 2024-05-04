#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 10
using namespace std;

int Data[MAX];

// Pertukaran bilangan
void Tukar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Pengurutan metode Bubble
void Bubble() {
    int i, j;
    for (i = 0; i < MAX - 1; i++) {
        for (j = 0; j < MAX - i - 1; j++) {
            if (Data[j] > Data[j + 1]) {
                Tukar(&Data[j], &Data[j + 1]);
            }
        }
    }
}

// Pengurutan metode Shell
void Shell() {
    int i, j, gap;
    for (gap = MAX / 2; gap > 0; gap /= 2) {
        for (i = gap; i < MAX; i++) {
            for (j = i - gap; j >= 0 && Data[j] > Data[j + gap]; j -= gap) {
                Tukar(&Data[j], &Data[j + gap]);
            }
        }
    }
}

void TampilkanData(const char* label) {
    cout << label << "\n";
    for (int i = 0; i < MAX; i++) {
        cout << "Data ke " << i << " : " << Data[i] << "\n";
    }
}

int main() {
    int pilihan;
    // Generate bilangan acak
    srand(time(0));
    cout << "Membangkitkan bilangan acak\n";
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1;
    }

    cout << "Pilih metode pengurutan:\n 1. Pengurutan Bubble\n 2. Pengurutan Shell\n Masukkan pilihan Anda: ";
    cin >> pilihan;
    // Menu
    switch (pilihan) {
    case 1:
        Bubble();
        TampilkanData("Bubble:");
        break;
    case 2:
        Shell();
        TampilkanData("Shell:");
        break;
    default:
        std::cout << "Invalid.\n";
        break;
    }
}
