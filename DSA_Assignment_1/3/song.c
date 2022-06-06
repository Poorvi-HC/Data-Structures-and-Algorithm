#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "song.h"

//This function creates a new song to add to the list
SSong* makeSong(char* name, char* artist, double duration)
{
    SSong* song;
    song = (SSong*) malloc(sizeof(SSong));
    assert(song != NULL);

    song->name = name;
    song->artist = artist;
    song->duration = duration;
    song->next = NULL;
    
    return song;
}

