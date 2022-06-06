#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "song.h"
#include "musicplayer.h"

//new music player is created
//with an empty queue and current song pointing to null
player* createMusicPlayer()
{
    player* new = (player*) malloc(sizeof(player));
    assert(new!= NULL);
    new->Current = NULL;
    new->Queue = makeSong(" "," ",0);
    new->size = 0;
    return new;
}

// This function checks whether the song is present in the queue or not
int Check(player* player,char* name)
{
    if (player == NULL)
        return -1;
    
    SSong* trav = player->Queue;
    int count = 0;
    while(trav->next != NULL)
    {
        if(trav->name == name)
            return count-1;
        count++;
        trav = trav->next;
    }
}

// This function adds Song to queue at the end.
int addSongToQueue(player* player, SSong* song)
{   
    SSong* trav = (SSong*) malloc(sizeof(SSong));
    trav = player->Queue;
    while(trav->next != NULL)
        trav = trav->next;

    SSong* temp = (SSong*) malloc(sizeof(SSong));
    temp=song;
    trav->next= temp;
    player->size += 1;
    
    return 0;
}

//This function removes song at a specified location (zero index)
int removeSongFromQueue(player* player, int pos)
{
    if (player == NULL)
        return 1;
    if (pos >= player->size)
        return 1;
    
    SSong* trav = makeSong(" "," ",0);
    trav = player->Queue;
    for (int i = 0;i<(pos);i++)
    {
        trav = trav->next;
    }
    SSong* temp = makeSong(" "," ",0);
    temp = trav->next;
    trav->next = trav->next->next;
    
    player->size -= 1;

    return 0;
}

//This function plays song by transfering it to current and removing it from queue
int playSong(player* player)
{
    if (player->Queue->next == NULL)
        return 1;
    
    player->Current = player->Queue->next;
    removeSongFromQueue(player,0);
    return 0;
}

//Returns Current Song being played
SSong* getCurrentSong(player* player)
{
    return player->Current;
}

//prints the queue onto the terminal
int print(player* player)
{
    if (player == NULL)
        return 1;
    
    SSong* trav = makeSong(" "," ",0);
    trav = player->Queue->next;

    while(trav != NULL)
    {
        printf("%s\n", trav->name);
        printf("%s\n",trav->artist);
        printf("%lf\n", trav->duration);
        printf("****************\n");
        trav = trav->next;
    }

    return 0;
}