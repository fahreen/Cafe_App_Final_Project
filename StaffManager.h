
#ifndef StaffManager_H
#define StaffManager_H

#include <string>
#include <vector>
#include "User.h"
#include "User.h"

/**
 * Staff Manager class 
 * This class allows you to create instances of a staff and has several
 * funtions to be able to manuplulate the data, such as getters, setters and deletes
 */
class StaffManager{
	
    private:
        static StaffManager *_instance; /** The class only allows one instance of the inventory manager */
        std::vector<User> staff; /** The class allows one menu list per instance manager reference */

		/**
         * By setting these private it prevents copying and assignment to other class as they should not be accessing this
         */
        StaffManager(StaffManager& other);
        StaffManager& operator= (StaffManager other);


		
		/**
         * Prevents instantiation of the of the inventory manager by making a protected class
         */
    protected:
        StaffManager();

	public:
		/** There is no public constructor (singleton) but instead an instance method to get the singleton object */
        static StaffManager & instance();

		/** This is a virtual method that is meant to be a destructor of an instance that is no longer required */
		virtual ~StaffManager();
		
		/** This is a get method that gets the set of staff members and returns them */
		std::vector<User> getStaff();

		/** Here are some additional methods to help maintain the data structure */
		std::vector<User> getManagers();
		std::vector<User> getEmployees();
		int addStaff (User newUser);
		int removeStaff (User currUser);
		int removeStaff (std:: string userId);
		void printAllEmployees();
		void printAllManagers();
		void printAllStaff();
		void printStaff(std::vector<User> staffMembers);
		void printUser(std:: string userId);
};

#endif
