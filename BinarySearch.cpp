#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi binary search
int binarySearch(const vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

// Fungsi untuk mencari semua indeks dari nilai yang dicari dalam array asli
vector<int> findIndices(const vector<int>& originalArr, const vector<int>& sortedArr, int x) {
    vector<int> indices;
    int indexInSorted = binarySearch(sortedArr, x);
    if (indexInSorted == -1) {
        return indices; // Nilai tidak ditemukan
    }

    for (int i = 0; i < originalArr.size(); ++i) {
        if (originalArr[i] == x) {
            indices.push_back(i + 1); // Menambahkan 1 agar indeks sesuai dengan contoh (1-based index)
        }
    }
    return indices;
}

int main() {
    vector<int> arr = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    vector<int> sortedArr = arr;

    // Mengurutkan array
    sort(sortedArr.begin(), sortedArr.end());

    // Test Case a
    vector<int> result = findIndices(arr, sortedArr, 1);
    if (!result.empty()) {
        cout << "Angka 1 ada di indeks ke ";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i != result.size() - 1)
                cout << " dan ";
        }
        cout << endl;
    } else {
        cout << "Angka 1 tidak ada dalam array" << endl;
    }

    // Test Case b
    result = findIndices(arr, sortedArr, 50);
    if (!result.empty()) {
        cout << "Angka 50 ada di indeks ke ";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i != result.size() - 1)
                cout << " dan ";
        }
        cout << endl;
    } else {
        cout << "Angka 50 tidak ada dalam array" << endl;
    }

    // Test Case c
    result = findIndices(arr, sortedArr, 100);
    if (!result.empty()) {
        cout << "Angka 100 ada di indeks ke ";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i != result.size() - 1)
                cout << " dan ";
        }
        cout << endl;
    } else {
        cout << "Angka 100 tidak ada dalam array" << endl;
    }

    return 0;
}