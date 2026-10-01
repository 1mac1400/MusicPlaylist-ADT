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

using namespace std;

int main()
{
    MusicPlaylist popPlaylist;
    
    cout << "Append 3 songs to the Pop Playlist: ";
    popPlaylist.append("pop1");
    popPlaylist.append("pop2");
    popPlaylist.append("pop3");
    
    cout << popPlaylist << endl << endl;
    
    cout << "Insert a song to the front of the Pop Playlist and return number of songs in the Pop Playlist and display total number of songs in playlist\n";
    popPlaylist.insert("pop4", 0);
    cout << popPlaylist << endl << popPlaylist.getSize() << endl << endl;
    
    cout << "Remove the third song from the playlist and list total number of songs ";
    popPlaylist.remove(2);
    cout << popPlaylist << endl << popPlaylist.getSize() << endl << endl;
    
    cout << "Create a new copy of the Pop Playlist called Mixed Playlist and then empty out the pop Playlist";
    
    MusicPlaylist mixedPlaylist(popPlaylist);
    popPlaylist.clear();
    
    cout << "Mixed playlist: " << mixedPlaylist << endl << "Number of songs: " << popPlaylist.getSize() << endl << "Is Pop Playlist empty?: " << popPlaylist.isEmpty() << endl << endl;
    
    cout << "Copy back the songs in the Pop Playlist back";
    popPlaylist = mixedPlaylist;
    cout << "Pop Playlist: " << popPlaylist << endl << endl;
    
    cout << "Set rock2 as the first song in the mixed playlist replacing the first song \n";
    mixedPlaylist.set("rock2", 0);
    cout << "Mixed playlist: " << mixedPlaylist;

}
