#ifndef __SONG_H
#define __SONG_H

//Basic structure of a song
typedef struct Song{
    char* name;
    // must be initialized 
    char* artist;
    double duration;
    struct Song* next;
} SSong;

SSong* makeSong(char* name, char* artist, double duration);

#endif