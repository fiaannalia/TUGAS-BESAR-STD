#include "hospital.h"

void createListDokter(list_dokter &LD)
{
    first(LD) = NULL;
    last(LD) = NULL;
}

adr_dokter createElemenDokter(string namaDokter, string idDokter, string poliDokter)
{
    adr_dokter P = new elm_dokter;
    info(P).nama_dr = namaDokter;
    info(P).id_dr = idDokter;
    info(P).poli_dr = poliDokter;
    next(P) = NULL;
    frelasi(P) = NULL;
    return P;
}

void insertDr(list_dokter &LD, adr_dokter P)
{
    if (first(LD) == NULL)
    {
        first(LD) = P;
        last(LD) = P;
        next(P) = first(LD);
    }
    else
    {
        adr_dokter Q = first(LD);
        while (next(Q) != first(LD))
        {
            Q = next(Q);
        }
        next(P) = first(LD);
        next(Q) = P;
        last(LD) = P;
    }
}

void printInfoPerawat(list_perawat L)
{
    adr_perawat P = first(L);
    cout << "List Perawat Di Rumah Sakit: " << endl;
    if (first(L) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        while (next(P) != NULL)
        {
            cout << "Nama Perawat : " << info(P).nama_perawat << endl;
            cout << "ID Perawat : " << info(P).id_perawat << endl;
            cout << endl;
            P = next(P);
        }
        cout << "Nama Perawat : " << info(P).nama_perawat << endl;
        cout << "ID Perawat : " << info(P).id_perawat << endl;
        cout << endl;
    }
}

void printInfoDokter(list_dokter LD)
{
    adr_dokter P = first(LD);
    if (first(LD) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        while (next(P) != first(LD))
        {
            cout << "Nama Dokter : " << info(P).nama_dr << endl;
            cout << "ID Dokter : " << info(P).id_dr << endl;
            cout << "Poli Dokter : " << info(P).poli_dr << endl;
            cout << endl;
            P = next(P);
        }
        cout << "Nama Dokter : " << info(P).nama_dr << endl;
        cout << "ID Dokter : " << info(P).id_dr << endl;
        cout << "Poli Dokter : " << info(P).poli_dr << endl;
        cout << endl;
    }
}

adr_dokter cariDokter(list_dokter LD, string D)
{
    adr_dokter P = first(LD);
    if (first(LD) == NULL)
    {
        cout << "list kosong" << endl;
        return NULL;
    }
    else
    {
        while (next(P) != first(LD))
        {
            if (info(P).nama_dr == D)
            {
                return P;
            }
            P = next(P);
        }
        if (info(P).nama_dr == D)
        {
            return P;
        }
        else
        {
            return NULL;
        }
    }
}

void deleteFirstDr(list_dokter &LD, adr_dokter &P)
{
    if (first(LD) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        adr_dokter Q = first(LD);
        while (next(Q) != first(LD))
        {
            Q = next(Q);
        }
        P = first(LD);
        first(LD) = next(first(LD));
        next(Q) = first(LD);
        next(P) = NULL;
        last(LD) = Q;
        frelasi(P) = NULL;
    }
}

void deleteLastDr(list_dokter &LD, adr_dokter &P)
{
    if (first(LD) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        adr_dokter Q = first(LD);
        adr_dokter R = first(LD);
        while (next(Q) != first(LD))
        {
            R = Q;
            Q = next(Q);
        }
        P = next(R);
        next(R) = first(LD);
        next(P) = NULL;
        last(LD) = R;
        frelasi(P) = NULL;
    }
}

void deleteAfterDr(list_dokter &LD, adr_dokter &P)
{
    if (first(LD) != NULL)
    {
        adr_dokter Q = first(LD);
        while (next(Q) != P)
        {
            Q = next(Q);
        }
        adr_dokter prec = Q;
        next(prec) = next(P);
        next(P) = NULL;
        frelasi(P) = NULL;
    }
}

void deleteDokter(list_dokter &LD, string nama)
{
    adr_dokter P = cariDokter(LD, nama);
    if (P != NULL)
    {
        if (P == first(LD))
        {
            deleteFirstDr(LD, P);
        }
        else if (P == last(LD))
        {
            deleteLastDr(LD, P);
        }
        else
        {
            deleteAfterDr(LD, P);
        }
    }
    else
    {
        cout << "tidak ada dokter" << endl;
    }
}

void createListPerawat(list_perawat &LP)
{
    first(LP) = NULL;
    last(LP) = NULL;
}

adr_perawat createElemenPerawat(string namaPerawat, string idPerawat)
{
    adr_perawat P = new elm_perawat;
    info(P).nama_perawat = namaPerawat;
    info(P).id_perawat = idPerawat;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertPr(list_perawat &LP, adr_perawat P)
{
    if (first(LP) == NULL)
    {
        first(LP) = P;
        last(LP) = P;
    }
    else
    {
        next(last(LP)) = P;
        prev(P) = last(LP);
        last(LP) = P;
    }
}

adr_perawat cariPerawat(list_perawat LP, string x)
{
    adr_perawat P = first(LP);

    while (P != NULL)
    {
        if (info(P).nama_perawat == x)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}


void PrintDataPrPadaDr(list_dokter LD, list_perawat LP, string nama)
{
    adr_perawat p = cariPerawat(LP, nama);
    if (p != NULL)
    {
        adr_dokter d; // mencari data perawat pada dokter
        d = first(LD);
        while (next(d) != first(LD))
        {
            adr_relasi r = frelasi(d);
            if (r != NULL)
            {
                while (r != NULL)
                {
                    if (perawat(r) == p)
                    {
                        cout << "Perawat " << nama << " ada di dokter " << info(d).nama_dr;
                        cout << endl;
                    }
                    r = next(r);
                }
            }
            d = next(d);
        }
    }
}

void createElemenRelasi(adr_dokter D, adr_perawat P)
{
    adr_relasi r, p;

    p = frelasi(D);

    r = new elm_relasi;

    if (p == NULL)
    {
        perawat(r) = P;
        next(r) = NULL;
        prev(r) = NULL;
        frelasi(D) = r;
    }
    else
    {
        while (next(p) != NULL)
        {
            p = next(p);
        }
        perawat(r) = P;
        prev(r) = p;
        next(p) = r;
        next(r) = NULL;
    }
}

adr_relasi findelmrelasi(adr_dokter dokter, string perawat)
{
    adr_relasi P = frelasi(dokter);
    while (P != NULL)
    {
        if (info(perawat(P)).nama_perawat == perawat)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void deleteFirstR(adr_dokter &D, adr_relasi &R)
{
    if (frelasi(D) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        R = frelasi(D);
        frelasi(D) = next(R);
        next(R) = NULL;
        prev(frelasi(D)) = NULL;
    }
}

void deleteLastR(adr_dokter D, adr_relasi &R)
{
    if (frelasi(D) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        adr_relasi Q = frelasi(D);
        adr_relasi P = frelasi(D);
        while (next(Q) != NULL)
        {
            P = Q;
            Q = next(Q);
        }
        R = Q;
        next(P) = NULL;
        prev(R) = NULL;
    }
}

void deleteAfterR(adr_dokter D, adr_relasi &R)
{
    adr_relasi prec = prev(R);
    if ((frelasi(D) != NULL) && (prec != NULL))
    {
        R = next(prec);
        next(prec) = next(R);
        prev(next(R)) = prec;
        next(R) = NULL;
        prev(R) = NULL;
    }
}

void delete1R(adr_dokter &D, adr_relasi &R)
{
    if (frelasi(D) == NULL)
    {
        cout << "list kosong" << endl;
    }
    else
    {
        R = frelasi(D);
        frelasi(D) = NULL;
        next(R) = NULL;
        prev(R) = NULL;
    }
}

void deleteR(adr_dokter &D, adr_relasi &R)
{
    adr_relasi x = frelasi(D);
    adr_relasi r = frelasi(D);
    adr_relasi lastr;
    while (next(r) != NULL)
    {
        r = next(r);
    }
    lastr = r;

    if (R == NULL)
    {
        cout << "tidak ada perawat" << endl;
    }
    else if (R == x)
    {
        deleteFirstR(D, R);
    }
    else if (next(x) == NULL)
    {
        delete1R(D, R);
    }
    else if (R == lastr)
    {
        deleteLastR(D, R);
    }
    else
    {
        deleteAfterR(D, R);
    }
}

void printAllData(list_dokter LD, list_perawat LP)
{
    adr_dokter d = first(LD);
    if (first(LD) == NULL)
    {
        cout << "List Kosong" << endl;
    }
    else
    {
        while (next(d) != first(LD))
        {
            cout << "Dokter " << info(d).nama_dr << " memiliki perawat : "<<endl;
            adr_relasi r = frelasi(d);
            while (r != NULL)
            {
                cout << info(perawat(r)).nama_perawat << endl;
                r = next(r);
            }
            d = next(d);
        }
        cout << "Dokter " << info(d).nama_dr << " memiliki perawat : "<<endl;
        adr_relasi r = frelasi(d);
        while (r != NULL)
        {
            cout << info(perawat(r)).nama_perawat << endl;
            r = next(r);
        }
    }
}

int hitungPr(adr_dokter d)
{
    int count = 0;
    adr_relasi P = frelasi(d);
    while (P != NULL)
    {
        count++;
        P = next(P);
    }
    return count;
}

void NilaiMax(list_dokter LD)
{
    int maks = 0;
    int x;
    adr_dokter d = first(LD);
    adr_dokter poli = NULL;
    while (next(d) != first(LD))
    {
        x = hitungPr(d);
        if (x > maks)
        {
            maks = x;
            poli = d;
        }
        d = next(d);
    }
    cout << "Poli yang paling banyak perawatnya adalah poli " << info(poli).poli_dr << " dengan jumlah perawat " << maks;
    cout << endl;
}
