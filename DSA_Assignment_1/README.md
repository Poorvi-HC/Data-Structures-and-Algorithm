
# ASSIGNMENT 1

## Problem Statement 1
### Create a Doubly Linked List and include the following functions:

<br/>

#### 1. insert(list, x): Insert a node containing data x at the end of the linked list (i.e. list which should be of type my dll).
#### 2. insert at(list, x, i): Insert a node containing data x at position i (zero-indexed) in the given list.
#### 3. delete(list, i): Delete the node at position i of the given list.
#### 4. find(list, x): Return the position of the first occurrence of x, if x is not present in the list return -1. Return type should be int.
#### 5. prune(list): Delete all nodes at odd indexes in the given linked list.
#### 6. print(list): Print all the elements of the given linked list starting from index 0.
#### 7. print reverse(list): Print all the elements of the given linked list in reverse order.
#### 8. get size(list): Return the current size of the linked list. Return type should be int.

<br/>

### Run the code as:-
``` 
    $ make q1 
    $ ./q1.out 
```
### The rest of the implementation is self explanatory.

<br/>

## Problem Statement 2
### Create a program that generates complex numbers and conducts the following operations on it:
<br/>

#### 1. Addition add(a, b): Given 2 complex numbers a and b, return a complex number c which is sum of the two.
#### 2. Subtract sub(a, b): Given 2 complex numbers a and b, return a complex number c which is the difference of the two.
#### 3. Mod mod(a): Given a complex number a, return a float x which equals to the sqrt of the sum of all the squares of the numbers within a complex number.
#### 4. Dot product dot(a, b): Given 2 complex numbers a and b, return a float x which is dot product of the 2 numbers
#### 5.  Given 2 complex numbers a and b, return a float x which equals to dot(a,b)/mod(a)*mod(b).

<br/>

### Run the code as:-
``` 
    $ make q2
    $ ./q2.out 
```

### The rest of the implementation is self explanatory.

<br/>

## Problem Statement 3
### Create a musicplayer which can generate new songs and control the queue of songs by doing the following operations in them:- (without Bonus)
<br/>

#### makeSong - generates new song with information stored such as song name, artist, duration of song.
#### createMusicPlayer - generates a fresh music player
#### addSongToQueue - Adds song to end of queue of the music player
#### removeSongFromQueue - Remove song at a given index from the queue
#### playSong - Plays the top-most song in the playlist and removes it from queue
#### getCurrentSong - Get the current song thats playing
#### Check - which checks whether a song is present in the queue already
#### Print - Which prints the queue under musicplayer


<br/>

### Run the code as:-
``` 
    $ make q3
    $ ./q3.out 
```

### The rest of the implementation is self explanatory.

<br/>

### This operation clears the file
```
    $make clean
```
