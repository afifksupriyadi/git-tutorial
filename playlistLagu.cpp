#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) (L).first
#define last(L) (L).last

struct playlist
{
    string band;
    string lagu;
};
typedef playlist infotype;

typedef struct element *adr;
struct element
{
    infotype info;
    adr next;
    adr prev;
};
struct List
{
    adr first;
    adr last;
};

void createList_1301223161(List &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

adr createNewElmt_1301223161(infotype x)
{
    adr p = new element;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;

    return p;
}

bool isEmpty_1301223161(List L)
{
    if (first(L) == NULL && last(L) == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void insertFirst_1301223161(List &L, adr p)
{
    if (first(L) == NULL & last(L) == NULL)
    {
        first(L) = p;
        last(L) = p;
    }
    else
    {
        next(p) = first(L);
        prev(next(p)) = p;
        first(L) = p;
    }
}

void insertLast_1301223161(List &L, adr p)
{
    if (first(L) == NULL && last(L) == NULL)
    {
        first(L) = p;
        last(L) = p;
    }
    else
    {
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}

void insertAfter_1301223161(List &L, adr prec, adr p)
{
    next(p) = next(prec);
    prev(p) = prec;
    prev(next(prec)) = p;
    next(prec) = p;
}

adr deleteFirst_1301223161(List &L)
{
    adr p;

    p = first(L);

    // jika list kosong
    if (isEmpty_1301223161(L) == true)
    {
        cout << "List Kosong" << endl;
        // jika list hanya 1 element
    }
    else if (first(L) == last(L))
    {
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        first(L) = next(p);
        prev(first(L)) = NULL;
        next(p) = NULL;
    }
    return p;
}

adr deleteLast_1301223161(List &L)
{
    adr p, q;

    // jika list kosong
    if (isEmpty_1301223161(L) == true)
    {
        cout << "List Kosong" << endl;
        // jika list hanya 1 element
    }
    else if (first(L) == last(L))
    {
        p = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        p = last(L);
        last(L) = prev(p);
        next(last(L)) = NULL;
        prev(p) = NULL;
    }
    return p;
}

adr deleteAfter_1301223161(List &L, adr prec)
{
    adr p;
    // geser prec ke satu elemen sebelumnya
    prec = prev(prec);

    p = next(prec);
    next(prec) = next(p);
    prev(next(p)) = prec;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}

List concat_1301223161(List L1, List L2)
{
    List L3;
    adr p;
    createList_1301223161(L3);
    L3 = L1;

    p = last(L3);
    next(p) = first(L2);
    prev(first(L2)) = p;
    last(L3) = last(L2);
    return L3;
}

adr findLagu_1301223161(string judul, List L)
{
    bool found = false;
    adr p, q;

    p = first(L);
    q = first(L);
    while (p != NULL)
    {
        if (info(p).lagu == judul)
        {
            found = true;
            q = p;
        }
        p = next(p);
    }

    if (found == true)
    {
        return q;
    }
    else
    {
        return NULL;
    }
}

void removeLagu_1301223161(string judul, List &L)
{
    adr p, cari;

    cari = findLagu_1301223161(judul, L);
    if (cari != NULL)
    {
        // jika list kosong
        if (isEmpty_1301223161(L) == true)
        {
            cout << "List Kosong" << endl;
            // jika list hanya 1 element
        }
        else if (first(L) == last(L))
        {
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
            cout << "***Lagu " << info(p).lagu << " TERHAPUS***" << endl;
            // jika judul ada pada elm pertama
        }
        else if (cari == first(L))
        {
            p = deleteFirst_1301223161(L);
            cout << "***Lagu " << info(p).lagu << " TERHAPUS***" << endl;
            // jika judul ada pada elm terakhir
        }
        else if (cari == last(L))
        {
            p = deleteLast_1301223161(L);
            cout << "***Lagu " << info(p).lagu << " TERHAPUS***" << endl;
            // jika judul berada ditengah
        }
        else
        {
            p = deleteAfter_1301223161(L, cari);
            cout << "***Lagu " << info(p).lagu << " TERHAPUS***" << endl;
        }
    }
    else
    {
        cout << "Lagu tidak ada dalam playlist" << endl;
    }
}

void show_1301223161(List L)
{
    if (first(L) != NULL)
    {
        adr p = first(L);
        while (p != NULL)
        {
            cout << info(p).lagu << " - " << info(p).band << endl;
            p = next(p);
        }
        cout << endl;
    }
    else
    {
        cout << "List Kosong" << endl;
    }
}

int main()
{
    List L;
    infotype laguFavorit;
    int jmlLagu;
    string xJudul;
    adr p, cek;

    // create List
    createList_1301223161(L);

    // Input data
    cout << "===== Input Data =====" << endl;
    cout << "Masukkan berapa banyak data: ";
    cin >> jmlLagu;
    for (int i = 0; i < jmlLagu; i++)
    {
        cin >> laguFavorit.lagu;
        cin >> laguFavorit.band;

        p = createNewElmt_1301223161(laguFavorit);
        insertLast_1301223161(L, p);
    }
    cout << endl;

    // show list
    cout << "===== Show Data =====" << endl;
    cout << "My playlist: " << endl;
    show_1301223161(L);

    // search lagu
    cout << "===== Search Data =====" << endl;
    cout << "Masukkan judul lagu yang dicari: ";
    cin >> xJudul;
    cek = findLagu_1301223161(xJudul, L);
    if (cek != NULL)
    {
        cout << "Lagu " << xJudul << " ada dalam list" << endl;
        if (cek == first(L))
        {
            cout << "Alamat lagu\t: " << cek << endl;
            cout << "Nama Lagu\t: " << info(cek).lagu << endl;
            cout << "Nama Musisi\t: " << info(cek).band << endl;
        }
        else
        {
            cout << "Alamat lagu\t: " << next(prev(cek)) << endl;
            cout << "Nama Lagu\t: " << info(cek).lagu << endl;
            cout << "Nama Musisi\t: " << info(cek).band << endl;
        }
    }
    else
    {
        cout << "Lagu " << xJudul << "tidak ada dalam list" << endl;
    }
    cout << endl;

    // Remove lagu
    cout << "===== Remove Data =====" << endl;
    cout << "Playlist sebelum diremove: " << endl;
    show_1301223161(L);

    cout << "Masukkan judul lagu yg akan dihapus: ";
    cin >> xJudul;
    cout << endl;
    removeLagu_1301223161(xJudul, L);
    cout << endl;
    cout << "Playlist setelah diremove: " << endl;
    show_1301223161(L);

    return 0;
}

// add new comment
