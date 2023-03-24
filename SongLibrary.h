/*
Sam Carter
CPSC 122 spring 2023
Date: 3/23/23
Programming Assignment: PA5
Description: This program keeps track of a song library, where you can add, store, delete, edit, and load or push songs.
Notes: Learned out to use stoi() from freecodecamp
*/
#ifndef SONG_LIBRARY_H
#define SONG_LIBRARY_H

#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std;

class SongLibrary {
	private:
		int numSongs;
		Song * songs;
		
		// TODO: add your additional private member functions here
	public:
		SongLibrary();
		~SongLibrary();
		int getNumSongs();
		void setNumSongs(int);
		Song * getSongsArray();
		void setSongsArray(Song *);

		void displayLibrary();
		void performLoad(string);
		void performSave(string);
		void performSort(string);
		bool performSearch(string, string, Song *, int *);
		void performAddSong(Song);
		void performRemoveSong(int);
		void performEditSong(int, string, string);

		// TODO: add your additional public member functions here
    
    void addSongToLibrary();
    void loadLibrary();
    void saveLibrary();
    void sortLibrary();
    void editSongInLibrary();
    void searchLibrary();
    void removeSongFromLibrary();

};

#endif
