#include <bits/stdc++.h>
using namespace std;
struct File {
    string name;
    int size;
    int days;
};

// ham swap 2 file
void swap(File &a, File &b) {
    File temp = a;
    a = b;
    b = temp;
}

// selection sort
void selectionSort(File files[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (files[j].size < files[minIdx].size ||
                (files[j].size == files[minIdx].size && files[j].days > files[minIdx].days)) {
                minIdx = j; // cap nhat chi so cua phan tu nho nhat
            }
        }
        swap(files[i], files[minIdx]);
    }
}

void deleteSmallest(File files[], int &n) {
    if (n == 0) return; // neu khong co file nao thi khong lam gi ca

    int minSize = files[0].size; // tim dung luong nho nhat (phai o vi tri dau sau khi sap xep)

    int maxDays = -1, delIdx = -1; // luu thoi gian luu lon nhat va vi tri can xoa
    for (int i = 0; i < n; i++) {
        if (files[i].size == minSize && files[i].days > maxDays) { // neu dung luong bang minSize va days lon nhat
            maxDays = files[i].days; // cap nhat days lon nhat
            delIdx = i; // luu chi so phan tu can xoa
        }
    }

    if (delIdx != -1) { // neu tim thay phan tu can xoa
        for (int i = delIdx; i < n - 1; i++) { // dich cac phan tu sau phan tu bi xoa len 1 vi tri
            files[i] = files[i + 1];
        }
        n--; // giam so luong file
    }
}
void displayFiles(File files[], int n) { //ham hien thi
    cout << "Danh sach file:\n";
    for (int i = 0; i < n; i++) {
        cout << "File: " << files[i].name << ", Size: " << files[i].size
             << "kB, Days: " << files[i].days << " days\n";
    }
}

int main() {
    int capacity = 100;  // so luong file toi da
    File *files = new File[capacity]; // cap phat mang dong danh sach file
    int n = 0;

    char choice;
    do {
        if (n >= capacity) {
            cout << "Khong the them file moi (da dat gioi han).\n";
            break;
        }
        cout << "Nhap ten file: ";
        cin >> files[n].name;
        cout << "Nhap dung luong (kB): ";
        cin >> files[n].size;
        cout << "Nhap so ngay luu: ";
        cin >> files[n].days;
        n++;
        cout << "Ban co muon nhap them file (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    selectionSort(files, n);
    cout << "\nDanh sach file sau khi sap xep:\n";
    displayFiles(files, n);
    deleteSmallest(files, n);
    cout << "\nDanh sach file sau khi xoa:\n";
    displayFiles(files, n);
    delete[] files;
    return 0;
}
