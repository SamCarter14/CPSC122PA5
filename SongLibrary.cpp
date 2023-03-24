/*
Sam Carter
CPSC 122 spring 2023
Date: 3/23/23
Programming Assignment: PA5
Description: This program keeps track of a song library, where you can add, store, delete, edit, and load or push songs.
Notes: Learned out to use stoi() from freecodecamp
*/
#include "SongLibrary.h"

/*
Function: songLibrary
Date created: NA
Date modified: 3/21/23
Description: default value constructor for songLibrary
Input Param: NA
Returns: returns a default library
Pre: Nothing needed before
Post: Gives empty library
*/
SongLibrary::SongLibrary() {
	// initialize to empty list
	numSongs = 0;
  songs = NULL; 
}

/*
Function: ~SongLibrary
Date created:NA
Date modified: 3/21/23
Description: destructor for songLibrary
Input Param: NA
Returns: NA
Pre: Intend to have library made first
Post: Is a destructor, deletes.
*/
// TODO: finish SongLibrary destructor
SongLibrary::~SongLibrary() {
	delete [] songs;
  songs = NULL;
  numSongs = 0;
}
/*
Function: getNumSongs()
Date created: NA
Date modified: NA
Description: Gets the number of songs in a library
Input Param: NA
Returns: numSongs
Pre: Must have library
Post: gives number of songs in library
*/
int SongLibrary::getNumSongs() {
	return numSongs;
}
/*
Function: setNumSongs
Date created: NA
Date modified: NA
Description: Allows for a change in number of songs
Input Param: int newNumSongs
Returns: newNumSongs
Pre: Must have new number of songs 
Post: changes number of songs to new number
*/
void SongLibrary::setNumSongs(int newNumSongs) {
	numSongs = newNumSongs;
}
/*
Function: getSongsArray()
Date created: NA 
Date modified: NA
Description: This function gets the songs from an array of songs
Input Param: NA
Returns: songs
Pre: Must have array made
Post: returns songs
*/
Song * SongLibrary::getSongsArray() {
	return songs;
}
/*
Function: setSongsArray()
Date created: NA
Date modified: NA
Description: This function sets the songs to a song array
Input Param:
Returns: Song * newSongsArr
Pre: Must have song array
Post: returns filled array
*/
void SongLibrary::setSongsArray(Song * newSongsArr) {
	if (songs != NULL) {
		delete [] songs;
	}
	songs = newSongsArr;
}

/*
Function: displayLibrary()
Date created: NA
Date modified: 3/21/23
Description: This function displays the songs in a library
Input Param: NA
Returns: console log of library songs
Pre: Must have more than 0 songs
Post: console output about every song in library
*/
void SongLibrary::displayLibrary(){
   
  cout << endl << "********* Song Library *********" << endl << endl;
for(int i = 0; i < numSongs; i++){
cout << i + 1 << ". ";
songs[i].Song::displaySong();
}
  

}

/*
Function: performLoad()
Date created: NA
Date modified: 3/21/23
Description: This function loads the songs from a file into a new songs array
Input Param: string filename
Returns: a filled array of songs
Pre: Must have a filename with correct filepath
Post: Returns filled array of songs
*/
void SongLibrary::performLoad(string filename) {
  
    numSongs = 0;
    delete [] songs;
    songs = NULL;
   
   string title, artist, genre, trash;
   int rating;
   Song tempSong;
	 ifstream inFile;
   inFile.open(filename);
   while(!inFile.eof()){
     getline(inFile, title);
     getline(inFile, artist);
     getline(inFile, genre);
     inFile >> rating;
     getline(inFile, trash);
     getline(inFile, trash);
     
     if(title != ""){numSongs += 1;}
   }
  Song * newSongs = new Song[numSongs];
  inFile.clear();
  inFile.seekg(0);
  for (int i = 0; i < numSongs; i++){
     getline(inFile, title);
     getline(inFile, artist);
     getline(inFile, genre);
     inFile >> rating;
     getline(inFile, trash);
     getline(inFile, trash);
     if(title != ""){newSongs[i] = Song(title, artist, genre, rating);}
  }
  songs = newSongs;
  inFile.close();
}


/*
Function: performSave()
Date created: NA
Date modified: 3/21/23
Description: This function saves the songs from a songs array to a new file
Input Param: string filename
Returns:returns an outfile
Pre:Must have outfile name and a songs array
Post: output file created and filled with songs
*/
void SongLibrary::performSave(string filename) {
	ofstream outFile;
  outFile.open(filename);
for(int i = 0; i < numSongs; i++){
  outFile << songs[i].getTitle() << endl;
  outFile << songs[i].getArtist() << endl;
  outFile << songs[i].getGenre() << endl;
  outFile << songs[i].getRating() << endl << endl;
}
  
  outFile.close();
}

/*
Function: performSort()
Date created: NA
Date modified: 3/21/23
Description: This function sorts songs based on the attribute the user chooses
Input Param: string attribute
Returns: sorted array of songs
Pre: must have an array of songs, must have attribute to sort by
Post: Sorts a sorted or unsorted array of songs
*/
void SongLibrary::performSort(string attribute) {
  Song tempSong;
  int i = 0, j = 0;
	if(attribute == "title"){
    for(j = 0; j < numSongs; j++){
    for (i = 0; i < numSongs - 1; i++){
     if(songs[i].getStringAttributeValue("title") > 
      songs[i + 1].getStringAttributeValue("title")){
      tempSong = songs[i + 1];
      songs[i + 1] = songs[i];
      songs[i] = tempSong;
  }
  }
  }
  }

   else if(attribute == "artist"){
    for(j = 0; j < numSongs; j++){
    for (i = 0; i < numSongs - 1; i++){
     if(songs[i].getStringAttributeValue("artist") > 
      songs[i + 1].getStringAttributeValue("artist")){
      tempSong = songs[i + 1];
      songs[i + 1] = songs[i];
      songs[i] = tempSong;
  }
  }
  }
  }

  else if(attribute == "genre"){
    for(j = 0; j < numSongs; j++){
    for (i = 0; i < numSongs - 1; i++){
     if(songs[i].getStringAttributeValue("genre") > 
      songs[i + 1].getStringAttributeValue("genre")){
      tempSong = songs[i + 1];
      songs[i + 1] = songs[i];
      songs[i] = tempSong;
  }
  }
  }
  }


  	else if(attribute == "rating"){
    for(j = 0; j < numSongs; j++){
    for (i = 0; i < numSongs - 1; i++){
     if(songs[i].getStringAttributeValue("rating") > 
      songs[i + 1].getStringAttributeValue("rating")){
      tempSong = songs[i + 1];
      songs[i + 1] = songs[i];
      songs[i] = tempSong;
  }
  }
  }
  }
  else{cout << "Invalid input" << endl;}
  }

/*
Function: performSearch()
Date created: NA
Date modified: 3/23/23
Description: This function searches for a song based on the attribute of the users choice.
Input Param: string searchAttribute, string searchAttributeValue, Song * foundSong, int * index
Returns: true or false if song was found, and cout statement about song information
Pre: Must have index or attribute from user
Post: Tells user whether or not it could find song in console
*/
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
  int num;
  if(searchAttribute != "index"){
  for(int i = 0; i < numSongs; i++){
    if(songs[i].getStringAttributeValue(searchAttribute) == searchAttributeValue){
     *index = i;
     *foundSong = songs[i];
    cout << *index + 1 << ". ";
    songs[*index].Song::displaySong();
    }
  }}
  else{
    num = stoi(searchAttributeValue);
    if(num <= numSongs){
    songs[num - 1].Song::displaySong();
    *index = num - 1;
    }
  }
	if(*index < 0 ){
  return false;
}
  else{
	return true;
}}

/*
Function: performAddSong()
Date created: NA
Date modified: 3/22/23
Description: This function adds a song to the array of songs
Input Param: Song newSong
Returns: An array with one more song than before
Pre: Must have a song to add to array
Post: An array with at least one song is given
*/
void SongLibrary::performAddSong(Song newSong) {
   numSongs += 1;
   Song * newSongsList = new Song[numSongs];
  
  if(numSongs > 1){
    for(int i = 0; i < (numSongs - 1); i++){
      newSongsList[i] = songs[i];
    }
    newSongsList[numSongs - 1] = newSong;
    delete [] songs;
    songs = NULL;
    songs = newSongsList;
  }
  else{
    newSongsList[0] = newSong;
    songs = newSongsList;
  }
}

/*
Function: performRemoveSong()
Date created: NA
Date modified: 3/23/23
Description: This function removes a song from an array of songs
Input Param: int indexToRemove
Returns: An Array of songs with one less song than before
Pre: Must have an array of at least one song
Post: Gives an array minus one song of the users choice
*/
void SongLibrary::performRemoveSong(int indexToRemove) {
numSongs -= 1;
  int j = 0;
	Song * deleteItemSongsList = new Song[numSongs];
  songs[indexToRemove].setTitle("");
  for(int i = 0; i < numSongs + 1; i++){
    if(songs[i].getTitle() != ""){
      deleteItemSongsList[j] = songs[i];
        j++;
    }
  }
  delete [] songs;
  songs = NULL;
  if(numSongs > 0){
  songs = deleteItemSongsList;
  }
}

/*
Function: performEditSong()
Date created: NA 
Date modified: 3/22/23
Description: This function allows a user to edit an attribute of a song
Input Param: int indexToEdit, string attribute, string newAttributeValue
Returns: A song within an array with a changed attribute
Pre: Must have a song within an array to change, and know what to change about the song
Post: Gives the same array back with a song edited in one attribute
*/
void SongLibrary::performEditSong(int indexToEdit, string attribute, string newAttributeValue) {	
  int num;
   if(attribute == "title"){
     songs[indexToEdit].setTitle(newAttributeValue);
   }
    else if(attribute == "artist"){
     songs[indexToEdit].setArtist(newAttributeValue);
   }
    else if(attribute == "genre"){
     songs[indexToEdit].setGenre(newAttributeValue);
   }
    else if(attribute == "rating"){
      num = stoi(newAttributeValue);
     songs[indexToEdit].setRating(num);
   }
    }
  


/*
Function: addSongToLibrary()
Date created: 3/22/23
Date modified: 3/22/23
Description: This function gets the attributes for a new song to be added and calls addSong();
Input Param: NA
Returns: An array with one more song
Pre: NA
Post: Gives an array with one more song than it had before
*/
 void SongLibrary::addSongToLibrary(){
   string artist, title, genre;
   int rating;
   cout << "Please enter the name of the song:" << endl;
   cin >> title;
   cout << "Please enter the name of the artist:" << endl;
   cin >> artist;
   cout << "Please enter the name of the genre:" << endl;
   cin >> genre;
   cout << "Please enter the rating:" << endl;
   cin >> rating;
   Song addSong(title, artist, genre, rating);
   performAddSong(addSong);
 }
/*
Function: loadLibrary()
Date created: 3/22/23
Date modified:3/22/23
Description: This function gets the name of a file a user wants to upload songs from, calls performLoad()
Input Param: NA
Returns: A filled array of songs from a file
Pre: NA
Post: Gives filled array of songs
*/
 void SongLibrary::loadLibrary(){
   string fileName;
   cout << "Enter file name" << endl;
   cin >> fileName;
   performLoad(fileName);
 }
/*
Function: saveLibrary()
Date created: 3/22/23
Date modified: 3/22/23
Description: This function asks for the name of a file you want to upload songs to from your array, and calls performSave()
Input Param: NA
Returns: Filled output file of songs from your array
Pre:NA 
Post: Gives a filled output file based on user input
*/
void SongLibrary::saveLibrary(){
  string filename;
  cout << "Enter the name of file you wish to save songs:" << endl;
  cin >> filename;
  performSave(filename);
    }
/*
Function: sortLibrary()
Date created: 3/21/23
Date modified: 3/22/23
Description: This song asks for how a user would like to sort their library
Input Param: NA
Returns: returns a sorted array of songs, calls performSort()
Pre: NA
Post: returns a sorted array based on user input
*/
void SongLibrary::sortLibrary(){
   string libSort;
  if(numSongs < 1){
    cout << "No songs to sort." << endl;
  }
  else{
  cout << "How would you like to sort your library?" << endl;
  cout << "You can do so by title, artist, genre or rating:" << endl;
  cin >> libSort;
  performSort(libSort);
}
}
/*
Function: editSongInLibrary()
Date created: 3/21/23
Date modified: 3/22/23
Description: This function asks a user how they would like to edit a song and which song to search for, calls performEditSong()
Input Param: NA
Returns: Returns an edited song from array
Pre: NA
Post: Edits a song based on user input
*/
void SongLibrary::editSongInLibrary(){
int index = 0;
string attribute = "", newAttributeName = "", searchAttribute = "", searchAttributeName = "";
cout << "Which song attribute would you like to search by? (title, artist, genre, rating or index)" << endl;
cin >> searchAttribute;
cout << "And what " << attribute << " would you like to search for?" << endl;
if(searchAttribute == "index"){
  cin >> index;
  index -= 1;
}
  else{
  getline(cin, searchAttributeName);
  getline(cin, searchAttributeName);
  for(int i = 0; i < numSongs; i++){
    if(songs[i].getStringAttributeValue(searchAttribute) == searchAttributeName){
      index = i;
      break;
    }
  }
  }
  
  cout << "Which attribute would you like to change?" << endl;
  cin >> attribute;
  cout << "What would you like to change the " << attribute << " to?" << endl;
  getline(cin, newAttributeName);
  getline(cin, newAttributeName);

performEditSong(index, attribute, newAttributeName);
}

/*
Function: searchLibrary()
Date created: 3/23/23
Date modified:3/23/23
Description: This function asks the user how they would like to search for a song, calls performSearch()
Input Param: NA
Returns: Returns console output on either song information or on how the function could not find song
Pre: NA
Post: Gives console output to user
*/
void SongLibrary::searchLibrary(){
string searchAttributeValue, searchAttribute;
int num;
int index = -1;
  Song foundSong;
  bool check = false;
  cout << "What song attribute would you like to search by? (title, artist, genre, rating or index)" << endl;
  cin >> searchAttribute;
 cout << "And what " << searchAttribute << " would you like to search for?" << endl;
  if(searchAttribute == "rating" || searchAttribute == "index"){
    cin >> num;
    searchAttributeValue = to_string(num);
  }
  else{getline(cin, searchAttributeValue);
      getline(cin, searchAttributeValue);};
  
check = performSearch(searchAttribute, searchAttributeValue, &foundSong, &index);
  if(check == false){
    cout << "Could not find song." << endl;
  }
  
  
}
/*
Function: removeSongFromLibrary()
Date created: 3/23/23
Date modified:3/23/23
Description: This function asks a user how they would like to delete a song, calls for performRemoveSong()
Input Param: NA
Returns: An array of songs with one less song
Pre:
Post: Returns array of songs with one less song if it had songs to begin with.
*/
void SongLibrary::removeSongFromLibrary(){
  string songAttribute, attributeValue;
  int index;
  if(numSongs > 0){
  cout << "Which song attribute would you like to search by?" << endl;
  cin >> songAttribute;
  cout << "And what " << songAttribute << " would you like to search by?" << endl;
  getline(cin, attributeValue);
  getline(cin, attributeValue);

  if(songAttribute != "index"){
    for(int i = 0; i < numSongs; i++){
      if(songs[i].getStringAttributeValue(songAttribute) == attributeValue){
        index = i;
      }
    }
      }
  else{
    index = stoi(attributeValue);
    index -= 1;
  }
  performRemoveSong(index);}
  else{cout << "Not enough Songs" << endl;}
}