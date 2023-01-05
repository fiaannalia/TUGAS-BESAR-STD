#ifndef HOSPITAL_H_INCLUDED
#define HOSPITAL_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(R) R->prev
#define first(L) (L).first
#define last(L) (L).last
#define frelasi(p) (p)->frelasi
#define perawat(p) (p)->perawat

typedef struct elm_relasi *adr_relasi;

struct dokter{
    string id_dr;
    string nama_dr;
    string poli_dr;
};

typedef struct elm_dokter *adr_dokter;
typedef dokter infotypeD;

struct elm_dokter{
    infotypeD info;
    adr_dokter next;
    adr_relasi frelasi;
};

struct list_dokter{
    adr_dokter first;
    adr_dokter last;
};

struct perawat{
    string id_perawat;
    string nama_perawat;
};

typedef struct elm_perawat *adr_perawat;
typedef perawat infotypePr;

struct elm_perawat {
    adr_perawat next;
    adr_perawat prev;
    infotypePr info;
};

struct list_perawat{
    adr_perawat first;
    adr_perawat last;
};

struct elm_relasi{
    adr_perawat perawat;
    adr_relasi prev;
    adr_relasi next;
};



void createListDokter(list_dokter &LD);
adr_dokter createElemenDokter(string namaDokter, string idDokter,string poliDokter);
void insertDr(list_dokter &LD, adr_dokter P);
void printInfoDokter(list_dokter LD);
adr_dokter cariDokter(list_dokter LD,string D);
void deleteFirstDr(list_dokter &LD,adr_dokter &P);
void deleteLastDr(list_dokter &LD,adr_dokter &P);
void deleteAfterDr(list_dokter &LD,adr_dokter &P);
void deleteDokter(list_dokter &LD,string nama);

void createListPerawat (list_perawat &LP);
adr_perawat createElemenPerawat (string namaPerawat, string idPerawat);
void insertPr(list_perawat &LP,adr_perawat P);
void printInfoPerawat(list_perawat L);
adr_perawat cariPerawat(list_perawat LP,string x);
void PrintDataPrPadaDr(list_dokter LD,list_perawat LP,string nama);

void createElemenRelasi(adr_dokter D, adr_perawat P);
adr_relasi findelmrelasi(adr_dokter dokter, string perawat);
void deleteFirstR(adr_dokter &D,adr_relasi &R);
void deleteLastR(adr_dokter D,adr_relasi &R);
void deleteAfterR(adr_dokter D,adr_relasi &R);
void delete1R(adr_dokter &D,adr_relasi &R);
void deleteR(adr_dokter &D,adr_relasi &R);

void printAllData(list_dokter LD, list_perawat LP);
int hitungPr(adr_dokter d);
void NilaiMax(list_dokter LD);


#endif // HOSPITAL_H_INCLUDED
