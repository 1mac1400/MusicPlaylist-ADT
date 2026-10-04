/*
 Muhammad Jafri
 Lauriano Zamora
 Brandon Morgado De La Rosa
 CMPR 131 - FALL 2026
 October 4 2026
 
 Group Project #1
 
 Collaborations: Muhammad Jafri, Lauriano Zamora, Brandon Morgado De La Rosa
 Resources/AI Tools used: Claude help in identifying some of the edge cases we glanced over at first also some minor logic and error fixes in some of the functions like doubleCapacity and copy constructor. Gemini was also used for the special character ♫ printing code
     Used C++ Programming, Program Design Including Data Structures" by D.S Malik as a reference for the remove and insert functions
        
 */

#include "MusicPlaylist.h"
#include <iostream>

MusicPlaylist::MusicPlaylist()
{
    capacity = 10; //default number of spaces avaliable
    size = 0;
    playlist = new (std::nothrow) std::string[capacity];
    
    if (playlist == nullptr)
    {
        std::cout << "ERROR: Memory Allocation Failed In Constructor\n\n";
        size = 0;
        capacity = 0;
        return;
    }
}


MusicPlaylist::MusicPlaylist(const MusicPlaylist& otherMusicPlaylist)
{

    
    playlist = new (std::nothrow) std::string[otherMusicPlaylist.capacity];
    
    if (playlist == nullptr)
    {
        std::cout << "ERROR: Memory Allocation Failed In copy constructor\n\n";
        size = 0;
        capacity = 0;
        return;
    }
    
    capacity = otherMusicPlaylist.capacity;
    size = otherMusicPlaylist.size;
    
    for (int i = 0; i < size; i++)
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
    
    playlist = new (std::nothrow) std::string[otherMusicPlaylist.capacity];
    
    if (playlist == nullptr)
    {
        std::cout << "ERROR: Memory Allocation Failed In overloaded assignment operator\n\n";
        return *this;
    }
    
    size = otherMusicPlaylist.size;
    capacity = otherMusicPlaylist.capacity;
    
    for (int i = 0; i < size; i++)
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
    otherMusicPlaylist.size = 0;
    otherMusicPlaylist.capacity = 0;
    
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
    otherMusicPlaylist.size = 0;
    otherMusicPlaylist.capacity = 0;
    
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

  if (size == capacity)//checks to see if allocation failed in doubleCapacity.
  {
      return;
  }
 }
 playlist[size]=song;
 size++;
}


std::string MusicPlaylist::get(int idx) const
{
        //checking index bounds
    if (idx >= 0 && idx < size)
    {
    return playlist[idx];
    }else
    {
        return "ERROR: Invalid Index";
    }
}

int MusicPlaylist::getSize() const
{
    return size;
}

bool MusicPlaylist::isEmpty() const
{
    return size==0;
}

void MusicPlaylist::clear()
{
    size=0;
}

void MusicPlaylist::set(const std::string& song, int idx)
{
        //checking index bounds
    if (idx >= 0 && idx < size)
    {
    playlist[idx]=song;
    }else
    {
        std::cout << "ERROR: Invalid Index \n\n";
    }
}


void MusicPlaylist::insert(const std::string& song, int idx)
{
    //checking index bounds
    if (idx >= 0 && idx <= size)
    {
        //resize the array if needed
        if (size == capacity)
        {
            doubleCapacity();
            if (size == capacity)//checks to see if allocation failed in doubleCapacity.
            {
                return;
            }
            
        }
        //shift elements to the right but start at last element to make sure
        //the elements get copied in the correct order without overriding a value before it was shifted
        for (int i = size; i >idx; i--)
        {
            playlist[i] = playlist[i-1];
        }
        //inserting value at correct index
        playlist[idx] = song;
    }
    else {
        std::cout << "ERROR: Invalid Index \n\n";
        return;
    }
    size++;
}


void MusicPlaylist::remove(int idx)
{
    //checking index bounds
    if (idx >= 0 && idx < size)
    {
        //shift elements to the left starting  from the idx location
        //note for the edge cases when we are removing the only element or the last element,
        //the loop won't run but size data memeber will still be updated in this function
        //which will make the element no longer accessible and essentially removed from the list
        //as all other operations involving indexing are controlled by the 'size' variable.
        //the element will still sit in memory but it will be overwritten next time the list grows
        //and size updates.
        for (int i = idx; i <size-1; i++)
        {
            playlist[i] = playlist[i+1];
        }
    }
    else {
        std::cout << "ERROR: Invalid Index\n";
        return;
    }
    size--;
}


std::ostream& operator<<(std::ostream& out, const MusicPlaylist& printPlaylist)
{
    out << "( ";
    for (int i = 0; i < printPlaylist.size; i++)
    {
        out << printPlaylist.playlist[i]; //prints out each song in playlist
        
        if (i < printPlaylist.size - 1)
        {
            out << ", ";
        }
        
    }
    out << ")";
    
    return out;
}


void MusicPlaylist::doubleCapacity()
{
    int newCapacity = capacity * 2;
    
    if (newCapacity == 0) //accounts for the capacity if it is 0
    {
        newCapacity = 1;
    }
    
    std::string* temp; //will point to the address of the new doubled array list
    temp = new (std::nothrow) std::string[newCapacity];
    
    if (temp == nullptr)
    {
        std::cout << "ERROR: Memory Allocation Failed In doubleCapacity\n\n";
        return;
    }
    
    for (int i = 0; i < size; i++)
    {
        temp[i] = playlist[i]; //copy elements to the doubled array list
    }
    
    delete[] playlist; //deletes the initial array list
    
    playlist = temp; //playlist now points to the address of the new doubled array list
    capacity = newCapacity;
}
