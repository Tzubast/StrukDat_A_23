#include <iostream>
#include <string>

using namespace std;

struct Data {
    int id;
    string nama;
    int umur;
};

void tampilkanData(Data data[], int n) {
    cout << "Data yang tersimpan:" << endl;
    cout << "ID\tNama\tUmur" << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i].id << "\t" << data[i].nama << "\t" << data[i].umur << endl;
    }
}

int main() {
    Data data[10];
    int jumlahData = 0;

    int pilihan;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Hapus Data" << endl;
        cout << "4. Ubah Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(data, jumlahData);
                break;
            case 2:
                if (jumlahData < 10) {
                    cout << "Masukkan ID: ";
                    cin >> data[jumlahData].id;
                    cout << "Masukkan Nama: ";
                    cin.ignore();
                    getline(cin, data[jumlahData].nama);
                    cout << "Masukkan Umur: ";
                    cin >> data[jumlahData].umur;
                    jumlahData++;
                    cout << "Data telah ditambahkan." << endl;
                } else {
                    cout << "Jumlah data telah mencapai batas maksimal (10)." << endl;
                }
                break;
            case 3:
                if (jumlahData > 0) {
                    int idHapus, indeksHapus = -1;
                    cout << "Masukkan ID data yang ingin dihapus: ";
                    cin >> idHapus;

                    for (int i = 0; i < jumlahData; i++) {
                        if (data[i].id == idHapus) {
                            indeksHapus = i;
                            break;
                        }
                    }

                    if (indeksHapus != -1) {
                        for (int i = indeksHapus; i < jumlahData - 1; i++) {
                            data[i] = data[i + 1];
                        }
                        jumlahData--;
                        cout << "Data dengan ID " << idHapus << " telah dihapus." << endl;
                    } else {
                        cout << "Data dengan ID " << idHapus << " tidak ditemukan." << endl;
                    }
                } else {
                    cout << "Tidak ada data yang dapat dihapus." << endl;
                }
                break;
            case 4:
                if (jumlahData > 0) {
                    int idUbah;
                    cout << "Masukkan ID data yang ingin diubah: ";
                    cin >> idUbah;

                    int indeksUbah = -1;
                    for (int i = 0; i < jumlahData; i++) {
                        if (data[i].id == idUbah) {
                            indeksUbah = i;
                            break;
                        }
                    }

                    if (indeksUbah != -1) {
                        cout << "Masukkan data yang baru:" << endl;
                        cout << "Nama: ";
                        cin.ignore(); 
                        getline(cin, data[indeksUbah].nama);
                        cout << "Umur: ";
                        cin >> data[indeksUbah].umur;
                        cout << "Data dengan ID " << idUbah << " telah diubah." << endl;
                    } else {
                        cout << "Data dengan ID " << idUbah << " tidak ditemukan." << endl;
                    }
                } else {
                    cout << "Tidak ada data yang dapat diubah." << endl;
                }
                break;
            case 5:
                cout << "Terima kasih! Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
