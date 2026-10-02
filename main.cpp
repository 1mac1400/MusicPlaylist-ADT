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
    //default constructor test
    cout << "-------------Default Construtor test---------------\nCreate a METAL PLAYLIST using the defauly constructor then print\nMETAL PLAYLIST:  ";
    MusicPlaylist metal;
    cout << metal<<"\n";

    
    cout << "\n\n-------------APPEND, INSERT, REMOVE, GET, AND SET TEST---------------\n";
    cout << "Add songs to the METAL PLAYLIST then print";
    metal.append("Master of Puppets");
    metal.append("Ace of Spades");
    metal.append("War Pigs");
    cout <<"\nMETAL PLAYLIST: " << metal << "\n";
    
    cout << "\n\nInsert Breaking the Law as the second song in the METAL PLAYLIST then print";
    metal.insert("Breaking the Law",1);
    cout <<"\nMETAL PLAYLIST : " << metal << "\n";
    
    cout << "\n\nTry using remove by trying to remove the 10th song and printing, then remove the first song in the METAL PLAYLIST and print\n";
    metal.remove(10);
    metal.remove(0);
    cout <<"METAL PLAYLIST: " << metal<<"\n";
    
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
    
    cout << "-------------isEmpty, isEmpty,clear, copy constructor test, and overloaded assignment operator---------------\n";
    cout <<"\nMETAL PLAYLIST: \n" << metal<<"\n";
    cout << "METAL PLAYLIST SIZE:"<< metal.getSize() << endl << endl;
    cout << "Use the isEmpty function to see if METAL PLAYLIST is empty\n";
    cout << "Is the METAL PLAYLIST empty: " << metal.isEmpty();

    cout << "\n\nNow clear the Metal Playlist\nMetal Playlist: ";
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
    cout << "METAL PLAYLIST: " << metal;
    
    cout << "\n\nCreate a CYBER PLAYLIST and copy the songs in METAL PLAYLIST to it\n";

    MusicPlaylist cyber(metal);

    cout << "CYBER PLAYLIST: " << cyber << endl << endl;
    
    cout << "Remove the first 3 songs from the CYBER PLAYLIST and then print\n";
    cyber.remove(0);
    cyber.remove(0);
    cyber.remove(0);
    cout << "CYBER PLAYLIST: " << cyber << endl << endl << "Create a PERSONAL PLAYLIST and add 2 songs to it\n";
    MusicPlaylist personal;
    personal.append("Ace of spades");
    personal.append("Trim");
    cout << "PERSONAL PLAYLIST: " << personal << endl << endl;
    
    cout << "Now copy over the songs in CYBER PLAYLIST to PERSONAL PLAYLIST\n";
    
    personal = cyber;
    
    cout << "PERSONAL PALYLIST: " << personal << endl << endl;
    
    
    
    
    
    

  

}
