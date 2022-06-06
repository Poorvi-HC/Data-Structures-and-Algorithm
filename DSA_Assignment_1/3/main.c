#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "song.h"
#include "musicplayer.h"

int main()
{
    printf("Commands for the Music player is as follows:\n");
    printf("To Add new song to player = ADD <Name> <Artist> <Duration>\n");
    printf("To Insert a song to the queue = INSERT <song name>\n");
    printf("To Remove a song from the list = REMOVE <position of the song>\n");
    printf("To play song = PLAY\n");
    printf("To print queue = PRINT\n");
    printf("To display the current song thats playing = GET\n");
    typedef struct MusicPlayer musicPlayer;
    typedef struct Song song;

    musicPlayer* mp = createMusicPlayer();
    song** songs = (song**) malloc(1000*sizeof(song*));

    int numSongs = 0;
    char command[100];

    begin:
    scanf(" %s",command);
    
    if (strcmp(command,"QUIT") != 0)
    {
        if(strcmp(command,"ADD") == 0)
        {
            char* name = (char*) malloc(100*sizeof(char));
            char* artist = (char*) malloc(100*sizeof(char));
            double dur;
            scanf("%s %s %lf",name,artist,&dur);
            songs[numSongs++] = makeSong(name,artist,dur);
            printf("Song %s by artist %s and duration %lf is created.\n",name,artist,dur);
        }

        else if(strcmp(command,"INSERT") == 0)
        {
            char name[100];
            scanf(" %s",name);
            int flag = -1;

            for (int a = 0;a < numSongs;a++)
                if(strcmp(name,songs[a]->name) == 0)
                    flag = a;
            
            if (flag == -1)
            {
                printf("No song found with name %s\n",name);
                goto cont;
            }
            SSong* add;
            if(Check(mp,name) != -1)
            {
                SSong* temp = makeSong(songs[flag]->name,songs[flag]->artist,songs[flag]->duration);
                add = temp;
            }
            else
                add = songs[flag];

            if(addSongToQueue(mp,add) == 1)
                printf("Song %s couldn't be added to the musicplayer\n",name);
            else
                printf("Song %s added successfully\n",name);
        }
        
        else if(strcmp(command,"PLAY") == 0)
        {
            if(playSong(mp) == 0)
                printf("Playing song\n");
            else
                printf("Couldn't play song\n");
        }

        else if(strcmp(command,"GET") == 0)
        {
            song* s = getCurrentSong(mp);
            if(s == NULL)
                printf("No song playing\n");
            else
                printf("Song %s is playing right now\n",s->name);          
        }

        else if(strcmp(command,"PRINT") == 0)
        {
            print(mp);
        }

        else if(strcmp(command,"REMOVE") == 0)
        {
            int pos;
            scanf("%d",&pos);
            if(removeSongFromQueue(mp, pos) == 1)
                printf("Song at index %d couldn't be removed\n", pos);
            else
                printf("Song at index %d removed successfully\n", pos);
        }

        else
        {
            printf("Invalid Command\n");
        }

        cont:
        goto begin;
    }

    return 0;
}