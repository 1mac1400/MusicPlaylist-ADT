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

#include "MusicPlaylist.h"
#include <iostream>

MusicPlaylist::MusicPlaylist()
{
    capacity = 10; //default number of spaces avaliable
    size = 0;
    playlist = new std::string[capacity];
    
    if (playlist == nullptr)
    {
        std::cout << "ERROR: Memory Allocation Failed In Constructor\n\n";
        exit(1);
    }
}


MusicPlaylist::MusicPlaylist(const MusicPlaylist& otherMusicPlaylist)
{
    capacity = otherMusicPlaylist.capacity;
    size = otherMusicPlaylist.size;
    
    playlist = new std::string[capacity];
    
    if (playlist == nullptr)
    {
        std::cout << "ERROR: Memory Allocation Failed In copy constructor\n\n";
        exit(1);
    }
    
    for (int i = 0; i < capacity; i++)
    {
        playlist[i] = otherMusicPlaylist.playlist[i]; //assigns elements to the new playlist
    }
    
    
}

MusicPlaylist& MusicPlaylist::operator=(const MusicPlaylist& otherMusicPlaylist)
{
    if (this == &otherMusicPlaylist) //checks self assignment
    {
        return *this;
    }
    
    delete[] playlist;
    
    size = otherMusicPlaylist.size;
    capacity = otherMusicPlaylist.capacity;
    
    playlist = new std::string[capacity];
    
    if (playlist == nullptr)
    {
        std::cout << "ERROR: Memory Allocation Failed In overloaded assignment operator\n\n";
        exit(1);
    }
    
    for (int i = 0; i < capacity; i++)
    {
        playlist[i] = otherMusicPlaylist.playlist[i]; //assigns elements to the new playlist
    }
    
    return *this;
    
}

MusicPlaylist::MusicPlaylist(MusicPlaylist&& otherMusicPlaylist)
{
    capacity = otherMusicPlaylist.capacity;
    size = otherMusicPlaylist.size;
    
    playlist = otherMusicPlaylist.playlist; //transfers ownership of the array from otherMusicPlaylist to playlist
    otherMusicPlaylist.playlist = nullptr; //prevents accidential deletion of playlist array
    
}

MusicPlaylist& MusicPlaylist::operator=(MusicPlaylist&& otherMusicPlaylist)
{
    if (this == &otherMusicPlaylist) //checks self assignment
    {
        return *this;
    }
    
    delete[] playlist;
    capacity = otherMusicPlaylist.capacity;
    size = otherMusicPlaylist.size;
    
    playlist = otherMusicPlaylist.playlist; //transfers ownership of the array from otherMusicPlaylist to playlist
    otherMusicPlaylist.playlist = nullptr; //prevents accidential deletion of playlist array
    
    return *this;
}


MusicPlaylist::~MusicPlaylist()
{
    delete[] playlist;
    playlist = nullptr; //prevent dangling point 
    
}

void MusicPlaylist::append(const std::string& song)
{
 if(size==capacity)
 {
  doubleCapacity();
 }
 playList[size]=song;
 size++;
}

std::ostream& operator<<(std::ostream& out, const MusicPlaylist& printPlaylist)
{
    out << "(";
    for (int i = 0; i < printPlaylist.size; i++)
    {
        out << printPlaylist.playlist[i] << " "; //prints out each song in playlist
        
    }
    out << ")";
    
    return out;
}


void MusicPlaylist::doubleCapacity()
{
    int newCapacity = capacity * 2; 
    
    std::string* temp; //will point to the address of the new doubled array list
    temp = new std::string[newCapacity];
    
    for (int i = 0; i < size; i++)
    {
        temp[i] = playlist[i]; //copy elements to the doubled array list
    }
    
    delete[] playlist; //deletes the initial array list
    
    playlist = temp; //playlist now points to the address of the new doubled array list
    capacity = newCapacity;
    
}
