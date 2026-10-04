/*
 Muhammad Jafri
 Lauriano Zamora
 Brandon Morgado De La Rosa
 CMPR 131 - FALL 2026
 October 4 2026
 
 Group Project #1
 
 Resources/AI Tools used: Claude help in identifying some of the edge cases we glanced over at first and some logic errors in our edge cases. Help with some of the logic and error fixes in some of the functions like doubleCapacity and copy constructor. Gemini was also used for the special character ♫  code printing.
     Used C++ Programming, Program Design Including Data Structures" by D.S Malik as a reference for the remove and insert functions
 */

#include "MusicPlaylist.h"
#include <iostream>

using namespace std;

//this block is so that we can safely print the music symbol ♫ without causing a compilation failure if someone runs the code in a non-windows system like macOS or Linux
//the WIN32_LEAN_AND_MEAN is used to avoid an error where 'byte' is data type name in STD library but 'byte' is also a type inside windows.h
//which causes compiler to be confused which 'byte' are we referring to. Thus, this command tells the compiler to strip its old "byte" data type from windows.h
// and avoid the compiler confusion
//windows.h is need so that the output console command can work below
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

int main()
{
    //this is safety feature if running windows then symbol will be correct music symbol
    //if this program is run on Linux or MacOS then this line of code won't run and its not needed
    //because per Google, the Linux & macOS terminals use UTF-8 encoding by default
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif
    
    cout << "-------------Default Constructor test---------------\n\nCreate a METAL PLAYLIST using the default constructor then print\nMETAL PLAYLIST:  ";
    MusicPlaylist metal;
    cout << metal<<"\n";

    
    cout << "\n\n-------------APPEND, INSERT, REMOVE, GET, AND SET TEST---------------\n\n";
    cout << "Add songs to the METAL PLAYLIST then print";
    metal.append("Master of Puppets");
    metal.append("Ace of Spades");
    metal.append("War Pigs");
    metal.append("Pain Killer");
    metal.append("Holy Wars");
    metal.append("War Pigs");
    cout <<"\nMETAL PLAYLIST: " << metal << "\n";
    
    cout << "\n\nInsert Breaking the Law as the second song in the METAL PLAYLIST then print";
    metal.insert("Breaking the Law",1);
    cout <<"\nMETAL PLAYLIST : " << metal << "\n";
    
    cout << "\n\nTry using remove by trying to remove the 10th song and printing, then remove the first, middle, and last song in the METAL PLAYLIST and print\n";
    metal.remove(10);
    metal.remove(0);
    metal.remove(2);
    metal.remove(4);
    
    cout <<"\nMETAL PLAYLIST after removing from the front, middle, and end: " << metal<<"\n";

     
    cout << "\nPrint out the 3rd song in the playlist, then search for the 8th song in the playlist to see if there is one\n";
    cout << "Third song in METAL PLAYLIST:" <<metal.get(2)<<"\n";
    cout <<metal.get(7) << "\n\n";
    
    cout << "Set Monkey Rocks as the third song in METAL PLAYLIST and then try to set Monkey Balls as the 8th song in METAL PLAYLIST";
    metal.set("Monkey Rocks",2);
    cout <<"\nMETAL PLAYLIST: " << metal<<"\n";
    metal.set("Monkey Balls",7);

    cout << "Print the 3rd song in METAL PLAYLIST and try to print out the 10th song in METAL PLAYLIST\n";
    cout << "Third song in METAL PLAYLIST: "<<metal.get(2)<<"\n";
    cout<< "10th song in METAL PLAYLIST: " << metal.get(9) << "\n\n";
    
    cout << "-------------isEmpty,clear, copy constructor test, and overloaded assignment operator---------------\n\n";
    cout <<"\nMETAL PLAYLIST: \n" << metal<<"\n";
    cout << "METAL PLAYLIST SIZE:"<< metal.getSize() << endl << endl;
    cout << "Use the isEmpty function to see if METAL PLAYLIST is empty\n";
    cout << "Is the METAL PLAYLIST empty: " << metal.isEmpty();

    cout << "\n\nNow clear the Metal Playlist\n";
    metal.clear();
    cout << "METAL PLAYLIST: "<< metal << endl << endl;
    
    cout << "Add new songs to the METAL PLAYLIST\n";
    metal.append("Master of Puppets");
    metal.append("Ace of Spades");
    metal.append("War Pigs");
    metal.append("Crazy Train");
    metal.append("Pain Killer");
    metal.append("Holy Wars");
    metal.append("Paranoid");
    metal.append("Mast of Puppets");
    metal.append("War Pigs");
    metal.append("Hallowed");
    metal.append("Ace of Spades");
    metal.append("War Pigs");
    cout << "METAL PLAYLIST: " << metal << endl << endl;
    
    cout << "Now insert a song to the front, middle, and end of the METAL PLAYLIST\n";
    metal.insert("The Trooper",0);
    metal.insert("Run to the Hills", metal.getSize());
    metal.insert("Walk", 7);
    cout << "METAL PLAYLIST: " << metal << endl << endl;
    
     
    
    cout << "\n\nCreate a CYBER PLAYLIST and copy the songs in METAL PLAYLIST to it\n";

    MusicPlaylist cyber(metal);

    cout << "CYBER PLAYLIST: " << cyber << endl << endl;
    
    cout << "Remove the first 3 songs from the CYBER PLAYLIST and then print both PLAYLISTS\n";
    cyber.remove(0);
    cyber.remove(0);
    cyber.remove(0);
    cout << "CYBER PLAYLIST: " << cyber << endl;
    cout << "Number of songs in CYBER PLAYLIST: " << cyber.getSize() << endl;
    cout << "METAL PLAYLIST: " << metal << endl;
    cout << "Number of songs in METAL PLAYLIST: " << metal.getSize() << endl << endl << "Create a PERSONAL PLAYLIST and add 2 songs to it\n";
    MusicPlaylist personal;
    personal.append("Ace of spades");
    personal.append("Trim");
    cout << "PERSONAL PLAYLIST: " << personal << endl << endl;
    
    cout << "Now copy over the songs in CYBER PLAYLIST to PERSONAL PLAYLIST\n";
    
    personal = cyber;
    
    cout << "PERSONAL PLAYLIST: " << personal << endl;
    cout << "CYBER PLAYLIST: " << cyber << endl << endl;
    
    cout << "ADD 2 songs to PERSONAL PLAYLIST and then print both PERSONAL PLAYLIST AND CYBER PLAYLIST\n";
    personal.append("Chop Suey");
    personal.append("Duality");
    cout << "PERSONAL PLAYLIST: " << personal << endl;
    cout << "CYBER PLAYLIST: " << cyber << endl;
    
    
    cout << "Check for self assignment now by assigning PERSONAL PLAYLIST to PERSONAL PLAYLIST\nPERSONAL PLAYLIST: ";
    
    personal = personal;
    
    cout << personal << endl << endl;
    
    cout << "-------------Move constructor and move assignment operator---------------\n\n";
    
    cout << "Move the songs from the PERSONAL PLAYLIST to a new PLAYLIST called TOP SONGS PLAYLIST\n";
    
    MusicPlaylist topS = std::move(personal);
    cout << "TOP SONGS PLAYLIST: " << topS << endl;
    cout << "TOP SONGS PLAYLIST SIZE: " << topS.getSize() << endl << endl;
    cout << "PERSONAL PLAYLIST: " << personal << endl;
    cout << "PERSONAL PLAYLIST SIZE: " << personal.getSize() << endl;
  
    cout << "\n\nNow move the songs from the CYBER PLAYLIST to the TOP SONGS PLAYLIST\n";
    
    topS = std::move(cyber);
    cout << "TOP SONGS PLAYLIST: " << topS << endl;
    cout << "TOP SONGS PLAYLIST SIZE: " << topS.getSize() << endl << endl;
    cout << "CYBER PLAYLIST: " << cyber << endl;
    cout << "CYBER PLAYLIST SIZE: " << cyber.getSize() << endl << endl;

    return 0;
}
