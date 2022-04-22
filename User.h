
#ifndef User_H
#define User_H

#include <string>
#include <vector>

/**
 * User.h header file
 * Sets all the permissions for the different types and differnet methods 
 */

class User{
	
	private:
	
		std::string uID;
		std::string uFName;
		std::string uLName;
		std::string uType;
		std::string uPass;
		std::vector <std::string> commandsvec;
		std::vector <std::string> selectvec;

	public:
		
		/** Constructor, one with taking attributes and one not to build a user */
		User();
		User(std::string uID, std::string uFName, std::string uLName, std::string uType, std::string uPass);
		
		
		/** This method destructs the object */
		~User();

		/** Each of these methods get the type held in the name and return it */
		std::string getUID();
		std::string getUFName();
		std::string getULName();
		std::string getUType();
		std::string getUPass();
		
		/** Each of these methods set the type held in the name to the instance */
		void setUID(std::string uid);
		void setUFName(std::string userfirstName);
		void setULName(std::string userlastName);
		void setUType(std::string uType);
		void setUPass(std::string uPass);
	
		/** Here are some additional methods to help maintain the data structure */
		bool checkCommand(std::string command);
		std::vector <std::string> returnAllCommands();
		std::vector <std::string> returnSelectCommands();
		void printAllCommands();
		void printSelectCommands();

};

#endif
