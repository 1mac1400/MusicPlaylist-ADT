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
    MusicPlaylist musicPlaylist2;

    musicPlaylist1.append("Death of You");
    musicPlaylist1.append("Don't Stop The Music");

    musicPlaylist2 = musicPlaylist1;


    musicPlaylist1.insert("Closer", 2); 
    //musicPlaylist1.remove(1);
    std::cout << musicPlaylist1.get(1) << std::endl;

    musicPlaylist1.set("We Fell In Love", 1);

    //std::cout << musicPlaylist1.isEmpty() << std::endl;
    
    std::cout << musicPlaylist1 << "musicPlaylist1" << std::endl;
    std::cout << musicPlaylist1.getSize() << std::endl;

    MusicPlaylist musicPlaylist3 = musicPlaylist1;
    musicPlaylist1.clear();

    std::cout << musicPlaylist1 << std::endl;
    std::cout << musicPlaylist1.getSize() << "\n" << std::endl;

    std::cout << musicPlaylist2 << std::endl;
    std::cout << musicPlaylist2.getSize() << "\n" << std::endl;

    std::cout << musicPlaylist3 << std::endl;
    std::cout << musicPlaylist3.getSize() << "\n" << std::endl;
    
    return 0;
}
