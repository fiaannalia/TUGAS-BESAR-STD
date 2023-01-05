#include <iostream>
#include "hospital.h"
#include "menu.h"

using namespace std;

int main()
{
    // Data Dokter
    list_dokter LD;
    adr_dokter A;
    createListDokter(LD);
    list_perawat LP;
    adr_perawat B;
    createListPerawat(LP);

    infotypeD dokter;
    infotypePr perawat;
    int pilihan;
    pilihan = pilihmenu();
    while (pilihan != 0)
    {
        if (pilihan == 1)
        {
            int n;
            string id,nama,poli;
            // Menambahkan data Dokter"
            cout << "Masukkan berapa banyak data yang akan dimasukkan : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Masukkan Data Ke " << i + 1 << endl;
                cout << "Masukkan ID Dokter : ";
                cin >> id;
                cout << "Masukkan Nama Dokter : ";
                cin >> nama;
                cout << "Masukkan Poli Dokter : ";
                cin >> poli;
                A = createElemenDokter(nama,id,poli);
                insertDr(LD, A);
                //cout << endl;
            }
            cout << "Berhasil Menambahkan Data" << endl;
            printInfoDokter(LD);
            /*a = createElemenDokter("Budi", "15123", "Obgyn");
            insertDr(LD, a);

            a = createElemenDokter("Ani", "87721", "Saraf");
            insertDr(LD, a);

            a = createElemenDokter("Rini", "08706", "THT");
            insertDr(LD, a);

            a = createElemenDokter("Rani", "03206", "Mata");
            insertDr(LD, a);

            printInfoDokter(LD);*/
        }
        else if (pilihan == 2)
        {
            // Menambahkan Data Perawat
            string nama,id;
            int m;
            cout << "Masukkan berapa banyak data yang akan dimasukkan : ";
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                cout << "Masukkan Data Ke " << j + 1 << endl;
                cout << "Masukkan ID Perawat : ";
                cin >> id;
                cout << "Masukkan Nama Perawat : ";
                cin >> nama;
                B = createElemenPerawat(nama,id);
                insertPr(LP, B);
                cout << endl;
            }

            // b = createElemenPerawat("Aisha", "12398");
            // insertPr(LP, b);

            // b = createElemenPerawat("Tsania", "57321");
            // insertPr(LP, b);

            // b = createElemenPerawat("Devi", "84765");
            // insertPr(LP, b);

            // b = createElemenPerawat("Putri", "53345");
            // insertPr(LP, b);

            // cout << endl;
            cout << "Berhasil Menambahkan Data" << endl;
            cout << endl;
            printInfoPerawat(LP);
        }
        else if (pilihan == 3)
        {
            // Mencari Data Dokter tertentu
            if (first(LD) != NULL)
            {
                string dokterdicari;
                cout << "Nama Dokter yang ingin dicari : ";
                cin >> dokterdicari;
                adr_dokter x;
                x = cariDokter(LD, dokterdicari);
                if (x != NULL)
                {
                    cout << "Data Dokter Ditemukan." << endl;
                    cout << "Dokter atas nama " << info(x).nama_dr << endl;
                    cout << "ID Dokter : " << info(x).id_dr << endl;
                    cout << "Poli : " << info(x).poli_dr << endl;
                }
                else
                {
                    cout << "Data tidak ditemukan." << endl;
                }
            }
            else
            {
                cout << "Belum ada dokter." << endl;
            }
        }
        else if (pilihan == 4)
        {
            printInfoDokter(LD);
            printInfoPerawat(LP);
            string dr, pr;
            cout << "Masukkan nama dokter: ";
            cin >> dr;
            cout << "Masukkan nama perawat: ";
            cin >> pr;
            adr_dokter D;
            adr_perawat P;
            D = cariDokter(LD, dr);
            P = cariPerawat(LP, pr);
            if (D != NULL && P != NULL)
            {
                createElemenRelasi(D, P);
                cout << "Relasi dokter " << dr << " dan perawat " << pr << " berhasil dibuat" << endl;
                cout << endl;
            }
            else
            {
                cout << "Relasi gagal dibuat";
                cout << endl;
            }
        }
        else if (pilihan == 5)
        {
            string x;
            cout << "Masukkan nama perawat: ";
            cin >> x;
            PrintDataPrPadaDr(LD, LP, x);
        }
        else if (pilihan == 6)
        {
            string dok;
            cout << "Masukan nama dokter yang ingin dihapus relasinya: ";
            cin >> dok;
            deleteDokter(LD, dok);
            cout << "Relasi berhasil dihapus" << endl;
        }
        else if (pilihan == 7)
        { // belom
            string per, dr;
            adr_dokter D;
            adr_relasi R;
            cout << "Masukkan nama dokter dari perawat yang akan dihapus datanya: ";
            cin >> dr;
            D = cariDokter(LD, dr);
            cout << "Masukkan nama perawat yang akan dihapus datanya: ";
            cin >> per;
            R = findelmrelasi(D, per);
            deleteR(D, R);
            cout << "Data berhasil dihapus";
            cout << endl;
        }
        else if (pilihan == 8)
        {
            if (first(LD) != NULL)
            {
                printAllData(LD,LP);
            }
            else
            {
                cout << "data masih kosong" << endl;
            }
        }
        else if (pilihan == 9)
        {
            adr_dokter x;
            string dok;
            cout << "Masukkan nama dokter yang ingin diketahui jumlah perawatnya: ";
            cin >> dok;
            int jum = 0;
            x = cariDokter(LD, dok);
            jum = hitungPr(x);
            cout << "Dokter " << dok << " memiliki jumlah perawat " << jum;
            cout << endl;
        }
        else if (pilihan == 10)
        {
            NilaiMax(LD);
        }
        else
        {
            cout << "Pilihan Tidak Tersedia" << endl;
        }
        cout << "Kembali ke menu? (y/n): ";
        char kembali;
        cin >> kembali;
        if (kembali == 'y')
        {
            system("cls");
            pilihan = pilihmenu();
        }
        else
        {
            pilihan = 0;
        }
    }
    cout << "Terima Kasih" << endl;
    return 0;
}
