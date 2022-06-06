#ifndef __MUSIC_PLAYER_H
#define __MUSIC_PLAYER_H

#include "song.h"

//Generates new musicplayer
typedef struct MusicPlayer{
    SSong* Current;
    SSong* Queue;
    int size;
}player;

player* createMusicPlayer();
int addSongToQueue(player* player, SSong* song);
int removeSongFromQueue(player* player, int pos);
int playSong(player* player);
SSong* getCurrentSong(player* player);
int print(player* player);
int Check(player* player,char* name);

#endif