#ifndef DATA_H_
#define DATA_H_

#include "FileLoader.h"

/**
 * File loader header file
 * 
 * This is the header file for the user data loader class, as its name might suggest it loads users.
 * The constructor reads in from the input filestream with the parameters being the fileName
 * then opens the file and reads in various pieces of information to help understand.
 * Next line by line in loop reads in from the file and adds it to the array where it can be used later
 * Then the array is used to send to addUser where it can be added
 */

class UserDataLoader: public FileLoader{
public:
  
	/** UserDataLoader method for the bulk loading of all the users in a file */
	UserDataLoader(std :: string fileName);
  
private:
  
	/** addUser method for the creation of new user profiles */
	/** The users are individually added to the set, where it will be used to perform authentication and authorization */
	void addUser(std:: string id, std:: string fname, std:: string lname, std:: string type, std:: string password);
};
#endif
