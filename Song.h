/*
Sam Carter
CPSC 122 spring 2023
Date: 3/23/23
Programming Assignment: PA5
Description: This program keeps track of a song library, where you can add, store, delete, edit, and load or push songs.
Notes: Learned out to use stoi() from freecodecamp
*/
#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cctype>

using namespace std;

const int MIN_RATING = 1;
const int MAX_RATING = 5;

string convertToLowercase(string);

class Song {
	private:
		string title;
		string artist;
		string genre;
		int rating;
	public:
		Song();
		Song(string, string, string, int);
		string getTitle();
		void setTitle(string);
		
		string getArtist();
		void setArtist(string);
		
		string getGenre();
		void setGenre(string);
		
		int getRating();
		void setRating(int);

		void displaySong();
		string getStringAttributeValue(string);
};

#endif
