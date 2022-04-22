#include<iostream>
#include "StaffManager.h"

using namespace std;

/** This is a singleton object with the instance set to NULL */
StaffManager * StaffManager:: _instance=NULL;


/** Prevents copying or sharing but reducing these to nothing and not adding any info or an instance to be able to work with it */
StaffManager::StaffManager(StaffManager& other){
	;
}

/** Prevents copying or sharing but reducing these to nothing and not adding any info or an instance to be able to work with it */
StaffManager& StaffManager:: operator= (StaffManager other){
	;
}

/**
 * Protected Staff Manager constructor 
 * This is a singleton implementation (protected constructor) used to clear an instance of the staff manager, removes all inside  
 */
StaffManager::StaffManager(){
	this->staff.clear();
}

/**
 * Instance creator 
 * If the staff manager doesnt exist then it creates a new instance of the staff manager
 * then returns such instance in the form of a pointer
 * @return pointer of instance
 */
StaffManager & StaffManager:: instance(){
    if (_instance == NULL)
        _instance = new StaffManager();
    return *_instance;
}

/**
 * Staff manager destructor 
 * When the staff manager is no longer required this destructs the instance and clears the items
 */
StaffManager:: ~StaffManager(){
	;
}
		
/**
 * Staff getter method 
 * This returns the set of members which are in the current Staff
 * @return vector set of staff members
 */
std::vector<User> StaffManager:: getStaff(){
	return this->staff;
}

/**
 * Managers getter method 
 * Has a list of managers and if their Utype is a manager then push back into manager using the parameter of staff location
 * @return vector set of managers
 */
std::vector<User> StaffManager:: getManagers(){
	std::vector<User> managers;
    for (unsigned int i = 0; i < this->staff.size(); i++) {
        if(this->staff[i].getUType().compare("manager")==0){
			managers.push_back(staff[i]);
		}
    }
	return managers;
}

/**
 * Employees getter method 
 * Has a list of employees and if their Utype is a employee then push back into employee using the parameter of staff location
 * @return vector set of employees
 */
std::vector<User> StaffManager:: getEmployees(){
	std::vector<User> employees;
    for (unsigned int i = 0; i < this->staff.size(); i++) {
        if(this->staff[i].getUType().compare("employee")==0){
			employees.push_back(staff[i]);
		}
    }
	return employees;
}

/**
 * Add staff member method 
 * Tries to add a staff member to the list of all staff, if the name already exists in the list then it
 * comments saying you should remove the old one before adding a new item with the matching name
 * @param User new user to add
 */
int StaffManager:: addStaff (User newUser){
	for (unsigned int i = 0; i < staff.size(); i++) {
        if(staff[i].getUID().compare(newUser.getUID())==0){
            cout<<"the user with the id "+ staff[i].getUID()<<" already exists. Please remove this user first."<<endl;
            return -1; //fail
        }
    }
	staff.push_back(newUser);
	return 0; //pass
}

/**
 * Remove staff member method 
 * This method tries to remove a staff member by extracting its name then calling the remove by name method
 * @param User new user to remove
 */
int StaffManager:: removeStaff (User currUser){
	return removeStaff(currUser.getUID());
}

/**
 * Remove staff member method 
 * This method tries to remove a staff member by matching the name from the list of staff members, if the name does not exist
 * in the list then it comments saying that the staff member was not found
 * @param string user id to remove
 */
int StaffManager:: removeStaff (string userId){
	for (unsigned int i = 0; i < staff.size(); i++) {
        if(staff[i].getUID().compare(userId)==0){
			staff.erase(staff.begin()+i);
            return 0; //pass
        }
    }
	cout<<"the user with the id "+ userId<<" does not exists. Could not remove the user."<<endl;
	return -1; //fail
}

/**
 * Print all employees method 
 * Gets the full list of all employees then prints all employees off
 */
void StaffManager:: printAllEmployees(){
	cout<<endl<<endl<<"Printing Employees"<<endl<<endl;
	std::vector<User> employees = getEmployees();
	printStaff(employees);
}

/**
 * Print all managers method 
 * Gets the full list of all employees then prints all employees off
 */
void StaffManager:: printAllManagers(){
	cout<<endl<<endl<<"Printing Managers"<<endl<<endl;
	std::vector<User> managers = getManagers();
	printStaff(managers);
}

/**
 * Print all staff method 
 * Calls both print staff and print managers, this way printing off all staff members
 */
void StaffManager:: printAllStaff(){
	printAllManagers();
	printAllEmployees();
}

/**
 * Print given staff method 
 * For this list of staff members it will loop through and call the print username on each staff
 * @param vector of staff members
 */

void StaffManager:: printStaff(std::vector<User> staffMembers){
	for (unsigned int i = 0; i < staffMembers.size(); i++) {
        printUser(staffMembers[i].getUID());
    }
}
/**
 * Print user method 
 * This takes a singular staff ID and looks through the whole list until it finds it then 
 * displays all attributes to the screen, returns nothing
 * @param string user id
 */
void StaffManager:: printUser(string userId){
	cout<<endl;
	for (unsigned int i = 0; i < staff.size(); i++) {
        if(staff[i].getUID().compare(userId)==0){
			cout<<"UserId: "<<staff[i].getUID()<<endl;
			cout<<"Type: "<<staff[i].getUType()<<endl;
			cout<<"First Name: "<<staff[i].getUFName()<<endl;
			cout<<"Last Name: "<<staff[i].getULName()<<endl;
        }
    }
	return;
	cout<<"the user with the id "+ userId<<" does not exist in the system. Could not print the user info."<<endl;
}

