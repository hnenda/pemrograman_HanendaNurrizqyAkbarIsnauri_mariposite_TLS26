
#include <iostream>

using namespace std;

int main() {
    char pesan[100];
    char pesan_sandi[100];
    int nilai_sebelumnya = 0;
    int panjang = 0;

    cout << "Masukkan pesan: ";
    cin >> pesan;

    // Hitung panjang string secara manual
    while (pesan[panjang] != '\0') {
        panjang++;
    }

    // Proses setiap karakter dalam pesan
    for (int i = 0; i < panjang; i++) {
        char c = pesan[i];

        // Konversi manual ke huruf kapital jika huruf kecil ('a' - 'z')
        if (c >= 'a' && c <= 'z') {
            c = c - 32;
        }

        // Ambil posisi alfabet (A = 1, B = 2, ..., Z = 26)
        int posisi_sekarang = c - 'A' + 1;
        int posisi_baru;

        // Cek apakah huruf pertama
        if (i == 0) {
            posisi_baru = posisi_sekarang;
        } else {
            posisi_baru = posisi_sekarang + nilai_sebelumnya;
        }

        // Jika melebihi 26, putar kembali ke A
        if (posisi_baru > 26) {
            posisi_baru = posisi_baru - 26;
        }

        // Simpan posisi asli huruf ini untuk huruf berikutnya
        nilai_sebelumnya = posisi_sekarang;

        // Konversi angka posisi kembali ke huruf kapital
        pesan_sandi[i] = (posisi_baru - 1) + 'A';
    }

    // Berikan karakter penanda akhir string
    pesan_sandi[panjang] = '\0';

    cout << "Pesan Sandi: " << pesan_sandi << endl;

    return 0;
}