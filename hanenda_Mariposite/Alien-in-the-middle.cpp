
#include <iostream>

using namespace std;

int main() {
    char pesan[100];
    char pesan_sandi[100];
    int nilai_sebelumnya = 0;
    int panjang = 0;
    cout << "Masukkan pesan: " << endl;
    cin >> pesan;
    while (pesan[panjang] != '\0') {
        panjang++;
    }
    for (int i = 0; i < panjang; i++) {
        char c = pesan[i];
        if (c >= 'a' && c <= 'z') {
            c = c - 32;
        }
        int posisi_sekarang = c - 'A' + 1;
        int posisi_baru;
        if (i == 0) {
            posisi_baru = posisi_sekarang;
        } else {
            posisi_baru = posisi_sekarang + nilai_sebelumnya;
        }
        if (posisi_baru > 26) {
            posisi_baru = posisi_baru - 26;
        }
        nilai_sebelumnya = posisi_sekarang;
        pesan_sandi[i] = (posisi_baru - 1) + 'A';
    }
    pesan_sandi[panjang] = '\0';
    cout << "Pesan Sandi: " << pesan_sandi << endl;
    return 0;
}