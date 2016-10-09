#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "list.h"
#include <cstdlib>

void inputNewSong(infotype &x);
void printInfo(List L);
void playSong(address P);
void playNext(address &P);
void playPrev(address &P);
void shuffleList(List &L);
void sortList(List &L, int condition);
void playRepeat(List &L, int n);
void deleteSong(List &L);

#endif // PLAYER_H_INCLUDED
