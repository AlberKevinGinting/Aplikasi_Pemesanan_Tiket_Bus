#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <windows.h> // Dipakai untuk fitur warna pada konsol Windows

using namespace std;

// Fungsi untuk mengubah warna teks di konsol
void aturWarna(int warna) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, warna);
}

// Struktur Data Pesanan
struct Pesanan {
    string namaPemesan;
    vector<string> namaPenumpang;
    vector<int> nomorKursi;
    string pulau;
    string jurusan;
    string kelas;
    long long hargaSatuan;
    int jumlahTiket;
    double diskon;
    long long totalHarga;
    string metodePembayaran;
};

void tampilkanHeader() {
    aturWarna(11); // Warna Cyan
    cout << "===============================================================\n";
    cout << "|        A P L I K A S I    P E M E S A N A N    T I K E T    |   \n";
    cout << "|                       B U S    G A C O R                    | \n";
    cout << "|                         Made by Kevin                       | \n";
    cout << "===============================================================\n";
    aturWarna(7); // Kembali ke warna putih normal
}

void buatGaris() {
    cout << "---------------------------------------------------------------\n";
}

int main() {
    string pengulangan;
    Pesanan p{};
    int pilihPulau, pilihJurusan, pilihKelas, pilihBayar;
    do {
        p = Pesanan{};

        // 1. Nama Pemesan dengan Loop Sederhana (Menggunakan cls & Header)
        while (true) {
            system("cls");
            tampilkanHeader();
            cout << "\n[ DATA PEMESAN ]\n";
            cout << "Masukkan Nama Pemesan : ";
            getline(cin, p.namaPemesan);

            if (p.namaPemesan.empty()) {
                aturWarna(12); // Merah
                cout << "\n[!] SALAH INPUT: Nama pemesan tidak boleh kosong!\n";
                aturWarna(7);
                cout << "Tekan Enter untuk mencoba lagi...";
                cin.get();
                continue;
            }
            else if (p.namaPemesan.length() > 50) {
                aturWarna(12);
                cout << "\n[!] SALAH INPUT: Nama terlalu panjang! Maksimal 50 karakter.\n";
                aturWarna(7);
                cout << "Tekan Enter untuk mencoba lagi...";
                cin.get();
                continue;
            }
            else if (p.namaPemesan.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos) {
                aturWarna(12);
                cout << "\n[!] SALAH INPUT: Nama hanya boleh mengandung huruf dan spasi!\n";
                aturWarna(7);
                cout << "Tekan Enter untuk mencoba lagi...";
                cin.get();
                continue;
            }
            else {
                break; // Jika valid, keluar dari loop nama
            }
        }

        // 2. Pilih Pulau & Jurusan
        while (true) {
            system("cls");
            tampilkanHeader();
            aturWarna(14); // Warna Kuning
            cout << "\n                  >>> PILIH WILAYAH TUJUAN <<<\n";
            aturWarna(7);
            cout << " 1. Pulau Jawa\n";
            cout << " 2. Pulau Sumatera\n";
            cout << "Pilihan (1/2): ";
            cin >> pilihPulau;

            if (pilihPulau == 1) {
                while (true) {
                    p.pulau = "Pulau Jawa";
                    system("cls");
                    tampilkanHeader();
                    aturWarna(14);
                    cout << "\n                     >>> RUTE PULAU JAWA <<<\n";
                    aturWarna(7);
                    cout << " 1. Jakarta - Bandung   (Rp 100.000)\n";
                    cout << " 2. Jakarta - Semarang  (Rp 175.000)\n";
                    cout << " 3. Jakarta - Jogja     (Rp 220.000)\n";
                    cout << " 4. Surabaya - Malang   (Rp  85.000)\n";
                    cout << "Pilihan Jurusan (1-4): ";
                    cin >> pilihJurusan;

                    if (pilihJurusan == 1) { p.jurusan = "Jakarta - Bandung"; p.hargaSatuan = 100000; break; }
                    else if (pilihJurusan == 2) { p.jurusan = "Jakarta - Semarang"; p.hargaSatuan = 175000; break; } 
                    else if (pilihJurusan == 3) { p.jurusan = "Jakarta - Jogja"; p.hargaSatuan = 220000; break; } 
                    else if (pilihJurusan == 4) { p.jurusan = "Surabaya - Malang"; p.hargaSatuan = 85000; break; }
                    else if (pilihJurusan != 1 && pilihJurusan != 2 && pilihJurusan != 3 && pilihJurusan != 4) {
                        aturWarna(12);
                        cout << "\n[!] SALAH INPUT: Pilihan jurusan tidak valid!\n";
                        aturWarna(7);
                        cout << "Tekan Enter untuk mencoba lagi...";
                        cin.get();
                        cin.ignore();
                        continue;
                    } else {
                        break; // Jika valid, keluar dari loop jurusan
                    }
                    break; // Jika valid, keluar dari loop jurusan
                }
                
            
                
            } else if (pilihPulau == 2) {
                while (true) {
                    p.pulau = "Pulau Sumatera";
                    system("cls");
                    tampilkanHeader();
                    aturWarna(14);
                    cout << "\n                   >>> RUTE PULAU SUMATERA <<<\n";
                    aturWarna(7);
                    cout << " 1. Medan - Padang      (Rp 250.000)\n";
                    cout << " 2. Palembang - Lampung (Rp 150.000)\n";
                    cout << " 3. Pekanbaru - Padang  (Rp 180.000)\n";
                    cout << "Pilihan Jurusan (1-3): ";
                    cin >> pilihJurusan;

                    if (pilihJurusan == 1) { p.jurusan = "Medan - Padang"; p.hargaSatuan = 250000; break; }
                    else if (pilihJurusan == 2) { p.jurusan = "Palembang - Lampung"; p.hargaSatuan = 150000; break; }
                    else if (pilihJurusan == 3) { p.jurusan = "Pekanbaru - Padang"; p.hargaSatuan = 180000; break; }
                    else if (pilihJurusan != 1 && pilihJurusan != 2 && pilihJurusan != 3) {
                        aturWarna(12);
                        cout << "\n[!] SALAH INPUT: Pilihan jurusan tidak valid!\n";
                        aturWarna(7);
                        cout << "Tekan Enter untuk mencoba lagi...";
                        cin.get();
                        cin.ignore();
                        continue;
                    } else {
                        break; // Jika valid, keluar dari loop jurusan
                    }
                    break; // Jika valid, keluar dari loop jurusan
                } 
                   
            } else if (pilihPulau != 1 && pilihPulau != 2) {
                aturWarna(12);
                cout << "\n[!] SALAH INPUT: Pilihan pulau tidak valid!\n";
                aturWarna(7);
                cout << "Tekan Enter untuk mencoba lagi...";
                cin.get();
                cin.ignore();
                continue;
            } else {
                break; // Jika valid, keluar dari loop nama
            }
            break; // Jika valid, keluar dari loop pulau
        }

        // 3. Pilih Kelas Bus
        while (true) {
            system("cls");
            tampilkanHeader();
            aturWarna(14);
            cout << "\n                     >>> PILIH KELAS BUS <<<\n";
            aturWarna(7);
            cout << " 1. Executive  (+ Rp 150.000 - Legrest + AC + Wifi)\n";
            cout << " 2. Bisnis     (+ Rp  75.000 - AC + Reclining Seat)\n";
            cout << " 3. Ekonomi    (+ Rp  50.000 - AC)\n";
            cout << "Pilihan Kelas (1-3): ";
            cin >> pilihKelas;

            if (pilihKelas == 1) {p.kelas = "Executive"; p.hargaSatuan += 150000; break; } 
            else if (pilihKelas == 2) {p.kelas = "Bisnis"; p.hargaSatuan += 75000; break;} 
            else if (pilihKelas == 3) {p.kelas = "Ekonomi"; p.hargaSatuan += 50000; break;}
            else  if (pilihKelas != 1 && pilihKelas != 2 && pilihKelas != 3) {
                aturWarna(12);
                cout << "\n[!] SALAH INPUT: Pilihan kelas tidak valid!\n";
                aturWarna(7);
                cout << "Tekan Enter untuk mencoba lagi...";
                cin.get();
                cin.ignore();
                continue;
            } else {
                break; // Jika valid, keluar dari loop kelas
            }
            break; // Jika valid, keluar dari loop kelas
        }

        // 4. Jumlah Tiket
        while (true) {
            system("cls");
            tampilkanHeader();
            cout << "\nMasukkan Jumlah Tiket yang Dibeli: ";
            cin >> p.jumlahTiket;

            if (p.jumlahTiket < 1 || p.jumlahTiket > 32) {
                aturWarna(12);
                cout << "\n[!] SALAH INPUT: Jumlah tiket harus antara 1 sampai 32!\n";
                aturWarna(7);
                cout << "Tekan Enter untuk mencoba lagi...";
                cin.get();
                cin.ignore();
                continue;
            } else if (p.jumlahTiket != int(p.jumlahTiket)) {
                aturWarna(12);
                cout << "\n[!] SALAH INPUT: Jumlah tiket harus berupa angka bulat!\n";
                aturWarna(7);
                cout << "Tekan Enter untuk mencoba lagi...";
                cin.get();
                cin.ignore();
                continue;
            } else {
            break; // Jika valid, keluar dari loop jumlah tiket
            }
            break; // Jika valid, keluar dari loop jumlah tiket
        }

        // Simulasi status kursi dasar
        bool kursiTerisi[33] = {false};
        kursiTerisi[3] = true; 
        kursiTerisi[7] = true;

        // Perulangan untuk input data tiap penumpang & pemilihan kursi interaktif
        for (int i = 0; i < p.jumlahTiket; i++) {
            string nama;
            int kursi;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            aturWarna(10); // Hijau Muda
            cout << "\n--- Masukkan Data Penumpang " << (i + 1) << " ---\n";
            aturWarna(7);
            cout << "  Nama Penumpang : ";
            getline(cin, nama);

            while (true) {
                system("cls");
                tampilkanHeader();
                aturWarna(14);
                cout << "\n               >>> DENAH KURSI - " << p.jurusan << " <<<\n";
                aturWarna(7);
                cout << " [ 01 ] = kosong   [ XX ] = terisi\n";
                cout << "+-----------------------------------+\n";
                cout << "|  DEPAN (Supir)                    |\n";
                cout << "+-----------------------------------+\n";

                for (int r = 1; r <= 8; r++) {
                    int k1 = (r - 1) * 4 + 1;
                    int k2 = (r - 1) * 4 + 2;
                    int k3 = (r - 1) * 4 + 3;
                    int k4 = (r - 1) * 4 + 4;

                    auto cekStatus = [&](int no) {
                        bool taken = kursiTerisi[no];
                        for (int s = 0; s < i; s++) {
                            if (p.nomorKursi[s] == no) taken = true;
                        }

                        if (taken) {
                            cout << "[ XX ]";
                        } else {
                            cout << "[ " << (no < 10 ? "0" : "") << no << " ]";
                        }
                    };

                    cout << "  ";
                    cekStatus(k1);
                    cout << " ";
                    cekStatus(k2);
                    cout << "   |   ";
                    cekStatus(k3);
                    cout << " ";
                    cekStatus(k4);
                    cout << "\n";
                }
                cout << "+-----------------------------------+\n";

                cout << "\nPenumpang ke-" << (i + 1) << " (" << nama << ")\n";
                cout << "Pilih Nomor Kursi (1-32): ";
                cin >> kursi;
                cin.ignore();

                if (kursi < 1 || kursi > 32) {
                    aturWarna(12);
                    cout << "\n[!] SALAH INPUT! Nomor kursi harus antara 1 sampai 32.\n";
                    cout << "[!] Coba masukkan dengan benar.\n";
                    aturWarna(7);
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.get();
                    continue;
                }

                bool sudahDipilih = kursiTerisi[kursi];
                for (int s = 0; s < i; s++) {
                    if (p.nomorKursi[s] == kursi) {
                        sudahDipilih = true;
                        break;
                    }
                }

                if (sudahDipilih) {
                    aturWarna(12);
                    cout << "\n[!] KURSI SUDAH TERISI! Kursi nomor " << kursi << " sudah dipesan orang lain.\n";
                    cout << "[!] Silakan pilih nomor kursi kosong yang lain.\n";
                    aturWarna(7);
                    cout << "Tekan Enter untuk melanjutkan...";
                    cin.get();
                    continue;
                }

                break;
            }

            p.namaPenumpang.push_back(nama);
            p.nomorKursi.push_back(kursi);
        }

        // Perhitungan Diskon (>1 Tiket)
        long long subtotal = p.hargaSatuan * p.jumlahTiket;
        if (p.jumlahTiket > 1) {
            p.diskon = subtotal * 0.10; // Diskon 10%
        } else {
            p.diskon = 0;
        }
        p.totalHarga = subtotal - (long long)p.diskon;

        // 5. Pembayaran Non-Tunai
        while (true) {
            system("cls");
            tampilkanHeader();
            aturWarna(14);
            cout << "\n               >>> METODE PEMBAYARAN NON-TUNAI <<<\n";
            aturWarna(7);
            cout << " 1. Transfer Bank (BCA / Mandiri / BRI)\n";
            cout << " 2. E-Wallet (GoPay / OVO / DANA)\n";
            cout << " 3. QRIS (Scan Semua Aplikasi)\n";
            cout << "Pilihan Pembayaran (1-3): ";
            cin >> pilihBayar;

            if (pilihBayar < 1 || pilihBayar > 3) {
                aturWarna(12);
                cout << "\n[!] SALAH INPUT: Pilihan pembayaran tidak valid!\n";
                aturWarna(7);
                cout << "Tekan Enter untuk mencoba lagi...";
                cin.get();
                cin.ignore();
                continue;
            } else {
                switch (pilihBayar) {
                case 1: p.metodePembayaran = "Transfer Bank"; break;
                case 2: p.metodePembayaran = "E-Wallet"; break;
                case 3: p.metodePembayaran = "QRIS"; break;
                default: p.metodePembayaran = "Non-Tunai"; break;
                }
            }
            break; // Jika valid, keluar dari loop pembayaran
        }

        // 6. TAMPILAN RESI TIKET
        system("cls");
        aturWarna(11);
        cout << "===============================================================\n";
        cout << "               R E S I   P E M E S A N A N   T I K E T           \n";
        cout << "===============================================================\n";
        aturWarna(7);

        cout << left << setw(20) << " Nama Pemesan"     << ": " << p.namaPemesan << "\n";
        cout << left << setw(20) << " Wilayah Tujuan"    << ": " << p.pulau << "\n";
        cout << left << setw(20) << " Rute Perjalanan"   << ": " << p.jurusan << "\n";
        cout << left << setw(20) << " Kelas Bus"         << ": " << p.kelas << "\n";
        cout << left << setw(20) << " Jumlah Tiket"      << ": " << p.jumlahTiket << " Kursi\n";

        buatGaris();
        aturWarna(14);
        cout << " DAFTAR PENUMPANG & NOMOR KURSI:\n";
        aturWarna(7);
        for (int i = 0; i < p.jumlahTiket; i++) {
            cout << "  " << (i + 1) << ". " << left << setw(30) << p.namaPenumpang[i] 
                 << " [ Kursi No. " << right << setw(2) << p.nomorKursi[i] << " ]\n";
        }
        buatGaris();

        cout << left << setw(20) << " Subtotal Harga"    << ": Rp " << subtotal << "\n";
        
        if (p.diskon > 0) {
            aturWarna(10);
            cout << left << setw(20) << " Diskon (10%)"      << ": - Rp " << (long long)p.diskon << " (Promo > 1 Tiket)\n";
            aturWarna(7);
        } else {
            cout << left << setw(20) << " Diskon"            << ": Rp 0\n";
        }

        cout << left << setw(20) << " Metode Bayar"      << ": " << p.metodePembayaran << "\n";
        
        aturWarna(11);
        buatGaris();
        cout << left << setw(20) << " TOTAL BAYAR"       << ": Rp " << p.totalHarga << "\n";
        cout << left << setw(20) << " STATUS"            << ": LUNAS (NON-TUNAI)\n";
        buatGaris();
        cout << "        Terima Kasih Telah Menggunakan Jasa Bus Paling Gacor!       \n";
        cout << "===============================================================\n\n";
        aturWarna(7);

        cout << "Apakah anda ingin melakukan pemesanan lagi? (Ya/Tidak): ";
        cin >> pengulangan;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (pengulangan == "Ya" || pengulangan == "ya");
    aturWarna(10);
    cout << "\nTerima kasih telah menggunakan jasa Bus Paling Gacor. Sampai jumpa!\n";
    cout << "\n     Credit    : Albert Kevin Ginting (X-3) \n";
    cout << "\n     Github    : https://github.com/AlberKevinGinting \n";
    cout << "\n     Instagram : https://www.instagram.com/milo_seger12/ \n";
    cout << "===============================================================\n\n";
    cout << "                Tekan Enter untuk keluar...";
    aturWarna(7);
    cin.get();
    return 0;
}