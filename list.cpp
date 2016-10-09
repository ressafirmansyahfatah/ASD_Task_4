#include "list.h"

void createList(List &L)
{
    L.first =NULL;
    L.last = NULL;
}

address alokasi(infotype x)
{
    address P = new elmlist;
    Info(P)=x;
    Next(P)=NULL;
    Prev(P)= NULL;
    return P;
}

void dealokasi(address &P)
{
    delete (P);
}

void insertFirst(List &L, address P)
{
    if (L.first==NULL)
    {
        L.first = P;
        L.last = P;
        Next(P)=P;
        Prev(P)=P;
    }
    else
    {
        Next(P)=L.first;
        (L.first)->next=P;
        L.first = P;
        (L.last)->prev = P;
        P->prev = L.last;
    }
}

void insertLast(List &L, address P)
{
    if (L.first==NULL)
    {
        L.first = P;
        L.last = P;
        Next(P)=P;
        Prev(P)=P;
    }
    else
    {

        (L.first)->next=P;
        Next(P)=L.first;
        L.last = P;
        (L.first)->prev = P;
        P->prev = L.first;
    }
}

address findElm(List L, infotype x)
{
    address P;
    if(L.first!= NULL)
    {
        P=L.first;
        do
        {
            if(Info(P).ID ==x.ID)
            {
                return P;
            }
                   P=Next(P);
        }
        while(P!=L.first);
            return 0;
    }
    return P;
}

void deleteFirst(List &L, address &P)
{
    if (L.first != NULL)
    {
        P = First(L);
        if(L.first == L.last)
        {
            L.first = NULL;
            L.last = NULL;
        }
        else
        {
            First(L) = Next(P);
            (L.first)->prev = L.last;
            (L.last)->next = L.first;
            Next(P) = NULL;
            P->prev = NULL;
        }

    }
    else
        cout<<"List Kosong"<<endl;
}

void deleteLast(List &L, address &P)
{
    if (L.first != NULL)
    {
        P = First(L);
        if(L.first == L.last)
        {
            L.first = NULL;
            L.last = NULL;
        }
        else
        {
            Last(L) = Prev(P);
            (L.first)->prev = L.last;
            (L.last)->next = L.first;
            Next(P) = NULL;
            P->prev = NULL;
        }

    }
    else
        cout<<"List Kosong"<<endl;
}

void insertAfter(List &L,address Prec, address P)
{
    if(Prec != NULL)
    {
        Prev(P)=Prec;
        Next(P)=Next(Prec);
        Prev(Next(Prec))=P;
        Next(Prec)=P;
        if(Prec == L.last)
        {
            L.last = P;
        }
    }
}
void deleteAfter(List &L,address Prec, address &P)
{
    if(Prec != NULL)
    {

        P=Next(Prec);
        Next(Prec)=Next(P);
        Prev(Next(P))=Prec;
        Prev(P)=NULL;
        Next(P)=NULL;


        if(P == L.last)
        {
            L.last = Prec;
        }
    }
}

