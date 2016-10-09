#include "player.h"


void inputNewSong(infotype &x)
{
    cout << "Input nama lagu (.wav) : ";
    cin >> x.name;
    cout << "Masukkan lokasi simpan " << endl << "(write - for default location) :";
    cin >> x.location;
    if(x.location=="-"){
        x.location="";
    }
}


void printInfo(List L)
{
    address Q = First(L);
    do
    {
        cout<<"Nama     : "<<Info(Q).name << endl;
        cout<<"ID       : "<<Info(Q).ID << endl;
        cout<<"Lokasi   : "<<Info(Q).location << endl;
        Q = Next(Q);
    }while(Q != L.first);
}


void playSong(address P)
{
    string filename = Info(P).location+Info(P).name;
    cout << "playing " << filename << endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(1000); //delay 1 second
}


void playNext(address &P)
{
    P = Next(P);
    playSong(P);
}


void playPrev(address &P)
{
P = Prev(P);
    playSong(P);
}

void shuffleList(List &L)
{
    List L2;
    int i;
    createList(L2);
    while(L.first != NULL){
        address p = L.first;
        address q =L.first;
        int nPlayer;
        do
        {
            nPlayer;
            q = Next(q);
        }
        while(q != L.first);
        for(int i=0; i<= rand() % nPlayer;i++){
            p = Next(p);
        }
        if(p == L.first){
            deleteFirst(L,p);
            insertLast(L2,p);
        }else if(p == L.last)
        {
            deleteLast(L,p);
            insertLast(L2,p);
        }else
        {
            deleteAfter(L,Prev(p),p);
            insertLast(L2,p);
        }
        L=L2;

    }
}

void sortList(List &L, int condition)
{
	/**
	* PR : mengurutkan isi (elemen) dari list L berdasarkan kondisi
	* FS : isi (elemen) dari list L terurut
	*      jika kondisi = 1, sort by ID
	*      jika kondisi = 2, sort by nama
	*/
	//-------------your code here-------------


    //----------------------------------------

}

void playRepeat(List &L, int n)
{
    address P=L.first;
    for (int i=0;i<n;i++){
        playSong;
        do{
            playNext;
        }while(P!=L.first);
    }
}

void deleteSong(List &L){
	/**
	* IS : list L mungkin kosong
	* PR : menerima input user untuk ID lagu yang ingin dihapus
	*      jika ID lagu ditemukan, hapus (dealokasi) lagu dari list
	* FS : elemen dengan ID yang dicari didealokasi
	*/
	//-------------your code here-------------


    //----------------------------------------

}
