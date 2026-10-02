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

int main()
{
    MusicPlaylist musicPlaylist1;
    std::cout << "Playlist 1 has been created" << std::endl;
    MusicPlaylist musicPlaylist2;
    std::cout << "Playlist 2 has been created" << std::endl;

    std::cout << std::endl;
    
    musicPlaylist1.append("Death of You");
    std::cout << "Added \"Death of You\" to track #1 for Playlist 1" << std::endl;
    musicPlaylist1.append("Don't Stop The Music");
    std::cout << "Added \"Don't Stop The Music\" to track #2 for Playlist 1" << std::endl;
    musicPlaylist1.append("More");
    std::cout << "Added \"More\" to track #3 for Playlist 1" << std::endl;

    std::cout << std::endl;

    musicPlaylist2 = musicPlaylist1;
    std::cout << "Copied all Playlist 1 tracks to Playlist 2" << std::endl;

    std::cout << std::endl;

    musicPlaylist1.insert("Closer", 2);
    std::cout << "Adding \"Closer\" at track #3 for Playlist 1" << std::endl;
   
    std::cout << "Removing song \"Don't Stop The Music\" at track #2 for Playlist 1" << std::endl;
    musicPlaylist1.remove(1);

    std::cout << "Displaying track #2 from Playlist 1: ";
    std::cout << musicPlaylist1.get(1) << std::endl;

    std::cout << std::endl;

    std::cout << "Replacing song \"Closer\" with the song \"We Fell In Love\" at track #2 for Playlist 1" << std::endl;
    musicPlaylist1.set("We Fell In Love", 1);
    
    //std::cout << musicPlaylist1.isEmpty() << std::endl;
    
    std::cout << "Displaying Playlist 1:\n" << musicPlaylist1 << std::endl;
    std::cout << "Playlist 1 has: " << musicPlaylist1.getSize() << " tracks" << std::endl;

    std::cout << std::endl;

    MusicPlaylist musicPlaylist3 = musicPlaylist1;
    std::cout << "Playlist 3 has been created and has copied all tracks from Playlist 1" << std::endl;
    std::cout << std::endl;
    std::cout << "Clearing all tracks from Playlist 1" << std::endl;
    musicPlaylist1.clear();

    musicPlaylist2.append("4eva");
    std::cout << "Added \"4eva\" to track #4 for Playlist 2" << std::endl;

    std::cout << "Displaying Playlist 1:\n" << musicPlaylist1 << std::endl;
    std::cout << "Playlist 1 has: " << musicPlaylist1.getSize() << " tracks" << std::endl;

    std::cout << "Displaying Playlist 2:\n" << musicPlaylist2 << std::endl;
    std::cout << "Playlist 2 has: " << musicPlaylist2.getSize() << " tracks" << std::endl;

    std::cout << "Displaying Playlist 3:\n" << musicPlaylist3 << std::endl;
    std::cout << "Playlist 3 has: " << musicPlaylist3.getSize() << " tracks" << std::endl;
    
    return 0;
}
