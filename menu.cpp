#include "menu.h"

int pilihmenu()
{
    int menu;
    cout << "===================================================" << endl;
    cout << "             SELAMAT DATANG DI HOSPITAL            " << endl;
    cout << "===================================================" << endl;
    cout << endl;
    cout << "1. Menambahkan data dokter" << endl;
    cout << "2. Menambahkan data perawat " << endl;
    cout << "3. Mencari data dokter tertentu " << endl;
    cout << "4. Menambahkan relasi data perawat yang akan membantu dokter " << endl;
    cout << "5. Mencari data perawat pada dokter tertentu" << endl;
    cout << "6. Menghapus data dokter berserta relasinya" << endl;
    cout << "7. Menghapus data perawat pada dokter tertentu" << endl; // belom
    cout << "8. Menampilkan seluruh data dokter beserta para perawat yang membantunya" << endl;
    cout << "9. Menghitung banyaknya perawat yang membantu pada dokter tertentu" << endl;
    cout << "10. Menampilkan data poli yang paling banyak perawatnya" << endl;
    cout << "11. Program utama dari aplikasi Hospital" << endl;
    cout << endl;
    cout << "Masukkan Pilihan Menu : ";
    cin >> menu;
    return menu;
}
