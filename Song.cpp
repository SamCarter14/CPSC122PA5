/*
Sam Carter
CPSC 122 spring 2023
Date: 3/23/23
Programming Assignment: PA5
Description: This program keeps track of a song library, where you can add, store, delete, edit, and load or push songs.
Notes: Learned out to use stoi() from freecodecamp
*/
#include "Song.h"

/*
Function: convertToLowerCase
Date created: NA
Date modified: 3/20/23
Description: This function converts words to lower string
Input Param: string s
Returns: string a
Pre: Must have a string inputed to be converted
Post: Returns a string in lower case
*/
string convertToLowercase(string s) {
string a = s;
  for(int i = 0; i < a.size(); i++){
  a.at(i) = tolower(a.at(i));
  }
	return a;
}

/*
Function: song()
Date created: NA
Date modified: 3/20/23
Description: This function creates a default value constructor for songs
Input Param: NA
Returns: A default song
Pre: Must need to make a song
Post: Returns a default made song
*/
Song::Song() {
  title = "";
  artist = "";
  genre = "";
  rating = 1;
}

/*
Function: song()
Date created: NA
Date modified: 3/20/23
Description: This function creates a explicit value constructor for songs
Input Param: string titleParam, string artistParam, string genreParam, int ratingParam
Returns: A song made with input parameters
Pre: Must have input parameters for song attributes
Post: Creates a new song with its own values
*/
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
  title = titleParam;
  artist = artistParam;
  genre = genreParam;
  rating = ratingParam;
  setRating(rating);
}
/*
Function: getTitle()
Date created: NA 
Date modified: 3/20/23
Description: Gets the title of a song
Input Param: NA
Returns: title
Pre: Must have a song made to get title
Post: gets title of song
*/
string Song::getTitle() {
	return title;
}
/*
Function: setTitle()
Date created: NA 
Date modified: 3/20/23
Description: changes the title for a song
Input Param: string newTitle()
Returns: newTitle
Pre: must have a title to change and a new title name
Post: changes the title of song
*/
void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}
/*
Function: getArtist()
Date created: NA
Date modified: 3/20/23
Description: gets the artist of a song
Input Param: NA
Returns: artist
Pre: must have a song to get artist
Post: returns song artist
*/
string Song::getArtist() {
	return artist;
}
/*
Function: setArtist()
Date created: NA
Date modified: 3/20/23
Description: This function changes the artist of a song
Input Param: string newArtist
Returns: newArtist
Pre: Must have song made and a new artist name
Post: changes artist name
*/
void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}
/*
Function: getGenre()
Date created: NA
Date modified: 3/20/23
Description: gets the genre of a song
Input Param: NA
Returns: genre
Pre: must have a song to get genre
Post: returns song genre
*/
string Song::getGenre() {
	return genre;
}
/*
Function: setGenre()
Date created: NA
Date modified: 3/20/23
Description: This function changes the genre of a song
Input Param: string newGenre
Returns: newGenre
Pre: Must have song made and a new genre name
Post: changes genre name
*/
void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}
/*
Function: getRating()
Date created: NA
Date modified: 3/20/23
Description: gets the rating of a song
Input Param: NA
Returns: rating
Pre: must have a song to get rating
Post: returns song rating
*/
int Song::getRating() {
	return rating;
}
/*
Function: setRating()
Date created: NA
Date modified: 3/20/23
Description: This function changes the rating of a song and checks if it is in the right range
Input Param: int newRating
Returns: newRating
Pre: Must have song made and a new rating
Post: changes ratu\ing
*/
void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}

/*
Function: displaySong()
Date created: NA
Date modified: 3/20/23
Description: This function couts a song and its information
Input Param: NA
Returns: console output
Pre: Must have a song made
Post: Gives console description about song
*/
void Song::displaySong() {
cout << "Title: " << title << endl << "   Sang by: " << artist << endl << "   Genre: " << genre << endl << "   Rating: " << rating << endl;
}

/*
Function: getStringAttributeValue()
Date created: NA
Date modified: 3/22/23
Description: This function gets the string of a songs attribute
Input Param: string attribute
Returns: a songs attribute (the one requested)
Pre: Must have song made and an attribute
Post: returns an attribute as a string
*/
string Song::getStringAttributeValue(string attribute) {
  string rating = "";
  int i;
  
	if(attribute == "title"){
    return getTitle();
  }
  else if(attribute == "artist"){
    return getArtist();
  }
  else if(attribute == "genre"){
    return getGenre();
  }
  else if(attribute == "rating"){
    rating = to_string(getRating());
    return rating;
  }
	return "";
}