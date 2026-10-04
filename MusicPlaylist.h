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


#ifndef MUSICPLAYLIST_H
#define MUSICPLAYLIST_H
#include <iostream>

class MusicPlaylist
{
    public:
    
    MusicPlaylist(); //constructor
    MusicPlaylist(const MusicPlaylist& otherMusicPlaylist); //copy constructor
    MusicPlaylist& operator=(const MusicPlaylist& otherMusicPlaylist); //overloaded assignment operator
    MusicPlaylist(MusicPlaylist&& otherMusicPlaylist); //move constructor
    MusicPlaylist& operator=(MusicPlaylist&& otherMusicPlaylist); //move assignemnt operator
    
    ~MusicPlaylist(); //destructor
    
    
    friend std::ostream& operator<<(std::ostream& out, const MusicPlaylist& printPlaylist); //overloaded isnertion operator
    
    
    void append(const std::string& song); //adds  new element in array at next avaliable space

    void insert(const std::string& song, int idx); //add new element at a specific index

    void remove(int idx); //remove a element at a specific index

    std::string get(int idx) const; //Returns element at index
    
    void set(const std::string& song, int idx); //replaces element at index

    int getSize() const; //Returns size/Number of elements in list
    
    bool isEmpty() const; //Returns true if empty false if not
    
    void clear(); //clears array by setting size to 0

    
    
    private:
    std::string* playlist; //points to the dynamically allocated array
    int capacity; //How many elements the array can currently hold
    int size; //total # of elements stored
    
    void doubleCapacity(); //HELPER FUNCTION (doubles the capacity whenever array is full)
};


#endif /* MusicPlaylist_h */
