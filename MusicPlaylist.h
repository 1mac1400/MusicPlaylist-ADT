/*
 -
 -
 -
 -
 CMPR 131 - FALL 2026
 October 4 2026
 
 Group Project #1
 
 Collaborations:None
 
 Resources/AI Tools used:
 */


#ifndef MUSICPLAYLIST_H
#define MUSICPLAYLIST_H
#include <iostream>

using namespace std;

template<class ItemType>
class MusicPlaylist
{
    public:
    
    MusicPlaylist(); //constructor
    MusicPlaylist(const MusicPlaylist<ItemType>& otherMusicPlaylist); //copy constructor
    MusicPlaylist& operator=(const MusicPlaylist<ItemType>& otherMusicPlaylist); //overloaded assignment operator
    MusicPlaylist(MusicPlaylist<ItemType>&& otherMusicPlaylist) //move constructor
    MusicPlaylist& operator=(const MusicPlaylist<ItemType>&& otherMusicPlaylist); //move assignemnt operator
    
    ~MusicPlaylist(); //destructor
    
    
    
    
    
    private:
    ItemType* playlist; //points to the dynamically allocated array
    int capacity; //How many elements the array can currently hold
    int numOfSongs; //total # of elements stored
};


#endif /* MusicPlaylist_h */
