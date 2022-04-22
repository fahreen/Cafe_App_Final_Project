
#include "FileLoader.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "ItemLoader.h"
#include "UserDataLoader.h"
#include "PromoLoader.h"

/**
  * File loader class
  * 
  * Loads the file based on the charater type that was passed along with it
  * This one at moment has 2 possible types, this loads in the users with the
  * file name as a parameter
  */

 /**
   * Default constructor
   * Creates a new file loader object
   */
FileLoader :: FileLoader(){};

/**
  * Constructor that takes in a file
  * Loads a csv file given a file name and type, which will either be users or menu items
  * @param string file name
  * @param char file type
  */
FileLoader :: FileLoader(std :: string fileName, char type){
	if (type =='A'){ /** depending on the type load users or menu items */
		UserDataLoader users(fileName); /** load users from file */
	}
	else if (type == 'B'){
		ItemLoader items(fileName); /** load menu items from file */
	}
  	else if (type == 'C'){
    PromoLoader promos(fileName);
  }
};

 /**
   * File loader deconstructor
   * Destroys the file loader object when no longer needed
   */
FileLoader::~FileLoader(){};

/*
int main(){
	FileLoader f1("foodinventory.csv", 'B');
	FileLoader f2("employees.csv", 'A');
	return 0;
	};*/
