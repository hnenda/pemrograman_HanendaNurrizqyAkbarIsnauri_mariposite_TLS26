#include <iostream>

using namespace std;

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K : ";
    cin >> K;
    int astronot[100];
    int eliminasi[100];
    
    int sisa_astronot = N;
    int total_tereliminasi = 0;
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }
    int posisi = 0;
    while (sisa_astronot > 1) {
        posisi = (posisi + K - 1) % sisa_astronot;
        int tereliminasi = astronot[posisi];
        eliminasi[total_tereliminasi] = tereliminasi;
        total_tereliminasi++;
        for (int i = posisi; i < sisa_astronot - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        sisa_astronot--;
        if (tereliminasi % 2 == 0) {
            K = K + 2; 
        } else {
            K = K - 1; 
        }
        if (K < 2) {
            K = 2;
        }
    }
    cout << "\nUrutan astronot yang dieliminasi: ";
    for (int i = 0; i < total_tereliminasi; i++) {
        cout << eliminasi[i] << " ";
    }
    cout << "\nAstronot terakhir yang bertahan: " << astronot[0] << endl;
    return 0;
}