/*
Sam Carter
CPSC 122 spring 2023
Date: 3/23/23
Programming Assignment: PA5
Description: This program keeps track of a song library, where you can add, store, delete, edit, and load or push songs.
Notes: Learned out to use stoi() from freecodecamp
*/
#include "PA5.h"
/*
Function: displayMenu()
Date created: NA
Date modified: NA
Description: This function displays the entire menu of options to choose from
Input Param: NA
Returns: returns console oupput about menu
Pre: Nothing required before
Post: Gives output about menu options
*/
void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Display library" << endl;
	cout << "2) Load library" << endl;
	cout << "3) Store library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Add song to library" << endl;
	cout << "7) Remove song from library" << endl;
	cout << "8) Edit song in library" << endl;
	cout << "9) Quit" << endl;
}
/*
Function: getValidchoice()
Date created: NA
Date modified: NA
Description: Determines whether or not user input is a valid input
Input Param: NA
Returns: Returns cout statement if input is invalid.
Pre: Must have user input about option
Post: returns user choice if it is acceptable
*/
int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}
/*
Function: executeUserChoice()
Date created: NA
Date modified: 3/23/23
Description: This code calls lib functions in order to execute the users decision
Input Param: int choice, SongLibrary& lib
Returns: Either ends program or runs user option
Pre: Must have user input
Post: Execute users wishes about songs
*/
void executeUserChoice(int choice, SongLibrary& lib) {
  Song songNew = Song("hello", "hey", "wassup", 1);
	switch (choice) {
		case 1:
			lib.displayLibrary();
			break;
		case 2:
    lib.loadLibrary();
			// TODO: call a helper member function, something like lib.loadLibrary();
			break;
		case 3: 
			// TODO: call a helper member function, something like lib.saveLibrary();
      lib.saveLibrary();
			break;
		case 4:
			// TODO: call a helper member function, something like lib.sortLibrary();
      lib.sortLibrary();
			break;
		case 5:
      lib.searchLibrary();
			// TODO: call a helper member function, something like lib.searchLibrary();
			break;
		case 6:
      lib.addSongToLibrary();
		 	// TODO: call a helper member function, something like lib.addSongToLibrary();
		 	break;
		case 7:
			// TODO: call a helper member function, something like lib.removeSongFromLibrary();
      lib.removeSongFromLibrary();
			break;
		case 8:
      lib.editSongInLibrary();
			// TODO: call a helper member function, something like lib.editSongInLibrary();
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}
/*
Function: runMusicManager()
Date created: NA
Date modified: NA
Description: This function executes userchoice if their decision is valid
Input Param: NA
Returns: Executes user choice or console statement thanking user
Pre: The user must have given a VALID choice
Post: The program either executes user choice or thanks them for using program
*/
void runMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the CPSC 122 Music Manager!!" << endl;
}
