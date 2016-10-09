#include "player.h"

List L;
address P;
infotype x;
int index_ID;

void menu();
void displayMenu();
void runMenu(int menu);

int main()
{
    index_ID = 0;
    createList(L);
    x.ID = 1;
    x.location = "";
    x.name = "clapping.wav";
    P = alokasi(x);
    insertFirst(L,P);

    x.ID = 2;
    x.location = "";
    x.name = "airpump2.wav";
    P = alokasi(x);
    insertFirst(L,P);

    menu();
    return 0;
}


void menu()
{
    int pil;
    do {
        displayMenu();
        cin>>pil;
        runMenu(pil);
    } while (pil!=5);
}


void displayMenu()
{
    cout<<"1.  Input new " << endl;
    cout<<"2.  View list" << endl;
    cout<<"3.  Play first song" << endl;
    cout<<"4.  Play next" << endl;
    cout<<"5.  Exit" << endl;
    cout<<"Pilih menu : ";
}

void runMenu(int menu)
{
    int pil,n;

    switch(menu)
    {
    case 1 :
        cout<<"Input new : "<<endl;
        x.ID = index_ID++;
        inputNewSong(x);

        P = alokasi(x);
        insertFirst(L,P);

        cout <<"Succes";
        break;

    case 2:
        printInfo(L);
        break;

    case 3 :
        P = First(L);
        playSong(P);
        break;

    case 4:
        playNext(P);
        break;

    case 5:
        cout << "Thank You" << endl;
        break;
    }
}
