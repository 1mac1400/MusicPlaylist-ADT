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
	MusicPlaylist metal;
	cout << metal<<"\n";

	metal.append("Master of Puppets");
	metal.append("Ace of Spades");
	metal.append("War Pigs");
	cout <<"\nMETAL PLAYLIST : \n" << metal << "\n";
	metal.insert("Breaking the Law",1);
	cout <<"\nMETAL PLAYLIST : \n" << metal << "\n";
	metal.remove(10);
	metal.remove(0);
	cout <<"\nMETAL PLAYLIST : \n" << metal<<"\n";
	cout<<metal.get(2)<<"\n";
	metal.set("Monkey Rocks",2);
	cout <<"\nMETAL PLAYLIST : \n" << metal<<"\n";
	metal.set("Monkey Balls",7);
	cout <<"\nMETAL PLAYLIST : \n" << metal<<"\n";
	cout<<metal.get(2)<<"\n";
	cout<<metal.get(9)<<"\n";
	cout <<"\nMETAL PLAYLIST : \n" << metal<<"\n";	
	cout << metal.getSize() << endl;

	metal.isEmpty();

	metal.clear();
	cout << metal;
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
	cout << "\nMETAL PLAYLIST : \n" << metal << "\n\n";

	MusicPlaylist cyber(metal);

	cout << "\nCYBER PLAYLIST : \n" << cyber << "\n";
	cyber.remove(10);
	cyber.remove(0);
	cout <<"\nCYBER PLAYLIST : \n"<< cyber << "\n";

	MusicPlaylist rock;
	rock = cyber;
	cout << "\nROCK PLAYLIST : \n" <<rock << "\n";

	//move constructor
	MusicPlaylist alternative = move(rock);
	cout << "\nALTERNATIVE PLAYLIST : \n" << alternative << "\n";

	//move assignment operator
	MusicPlaylist punk = move(metal);
	cout << "\nPUNK PLAYLIST : \n" << punk << "\n";

	cout << "\nMETAL PLAYLIST" << metal << "\n";

}
