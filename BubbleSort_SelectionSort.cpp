#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Struktur untuk menyimpan data nama dan alamat
struct Data {
    std::string nama;
    std::string alamat;
};

// Fungsi untuk menampilkan data
void display(const std::vector<Data>& data) {
    std::cout << "Nama\tAlamat\n";
    for (const auto& d : data) {
        std::cout << d.nama << "\t" << d.alamat << "\n";
    }
}

// Fungsi untuk melakukan Bubble Sort
void bubbleSort(std::vector<Data>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (data[j].nama > data[j + 1].nama) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

// Fungsi untuk melakukan Selection Sort
void selectionSort(std::vector<Data>& data) {
    int n = data.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (data[j].nama < data[minIndex].nama) {
                minIndex = j;
            }
        }
        std::swap(data[i], data[minIndex]);
    }
}

int main() {
    // Data awal
    std::vector<Data> data = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    // Menggunakan Bubble Sort
    std::vector<Data> bubbleSortedData = data;
    bubbleSort(bubbleSortedData);
    std::cout << "Hasil Bubble Sort:\n";
    display(bubbleSortedData);

    // Menggunakan Selection Sort
    std::vector<Data> selectionSortedData = data;
    selectionSort(selectionSortedData);
    std::cout << "\nHasil Selection Sort:\n";
    display(selectionSortedData);

    return 0;
}