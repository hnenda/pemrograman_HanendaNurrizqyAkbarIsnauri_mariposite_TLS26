#include <iostream>

using namespace std;

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;

    // Array untuk menyimpan daftar astronot dan urutan eliminasi
    int astronot[100];
    int eliminasi[100];
    
    int sisa_astronot = N;
    int total_tereliminasi = 0;

    // 1. Mengisi daftar astronot dari 1 sampai N
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int posisi = 0; // Indeks awal (dimulai dari 0)

    // 2. Tentukan eliminasi sampai tersisa 1 astronot
    while (sisa_astronot > 1) {
        // Hitung indeks astronot yang akan dieliminasi
        posisi = (posisi + K - 1) % sisa_astronot;

        // Ambil astronot yang dieliminasi
        int tereliminasi = astronot[posisi];
        eliminasi[total_tereliminasi] = tereliminasi;
        total_tereliminasi++;

        // Hapus astronot dari array dengan menggeser elemen ke kiri
        for (int i = posisi; i < sisa_astronot - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        sisa_astronot--;

        // 3. Perbarui nilai K berdasarkan nomor astronot yang tereliminasi
        if (tereliminasi % 2 == 0) {
            K = K + 2; // Jika genap
        } else {
            K = K - 1; // Jika ganjil
        }

        // Batas minimal K adalah 2
        if (K < 2) {
            K = 2;
        }
    }

    // 4. Cetak Output Hasil
    cout << "\nUrutan astronot yang dieliminasi: ";
    for (int i = 0; i < total_tereliminasi; i++) {
        cout << eliminasi[i] << " ";
    }

    cout << "\nAstronot terakhir yang bertahan: " << astronot[0] << endl;

    return 0;
}