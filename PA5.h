/*
Sam Carter
CPSC 122 spring 2023
Date: 3/23/23
Programming Assignment: PA5
Description: This program keeps track of a song library, where you can add, store, delete, edit, and load or push songs.
Notes: Learned out to use stoi() from freecodecamp
*/
#ifndef PA5_H
#define PA5_H

#include <iostream>
#include <fstream>
#include <string>
#include "Song.h"
#include "SongLibrary.h"

using namespace std;

const int QUIT_OPTION = 9;
const int FIRST_OPTION = 1;
const int LAST_OPTION = QUIT_OPTION;

void displayMenu();
int getValidChoice();
void executeUserChoice(int, SongLibrary&);
void runMusicManager();

#endif
