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

class MusicPlaylist
{
    public:
    
    MusicPlaylist(); //constructor
    MusicPlaylist(const MuscPlaylist& otherMusicPlaylist); //copy constructor
    MusicPlaylist& operator=(const MusicPlaylist& otherMusicPlaylist); //overloaded assignment operator
    MusicPlaylist(MusicPlaylist&& otherMusicPlaylist) //move constructor
    MusicPlaylist& operator=(const MusicPlaylist&& otherMusicPlaylist); //move assignemnt operator
    
    ~MusicPlaylist(); //destructor
    
    
    
    
    
    private:
    std::string* playlist; //points to the dynamically allocated array
    int capacity; //How many elements the array can currently hold
    int size; //total # of elements stored
};


#endif /* MusicPlaylist_h */
