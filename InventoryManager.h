#ifndef INVENTORYMANAGER_H_
#define INVENTORYMANAGER_H_
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "MenuItem.h"

/**
 * Inventory Manager header file
 * 
 * This class allows you to create instances of a inventory and has several
 * funtions to be able to manuplulate the data, such as getters, setters and deletes
 * 
 */
class InventoryManager{
    private:
        static InventoryManager *_instance; /** The class only allows one instance of the inventory manager */
        std::vector<MenuItem> items; /** The class allows one menu list per instance manager reference */

      /**
        * Inventory manager constructor
        * By setting these private it prevents copying and assignment to other class as they should
        * not be accessing this
        * @param InventoryManager& other
        */ 
        InventoryManager(InventoryManager& other);
      /**
        * Inventory manager constructor
        * By setting these private it prevents copying and assignment to other class as they should
        * not be accessing this
        * @param InventoryManager other
        */ 
        InventoryManager& operator= (InventoryManager other);

    protected:
        InventoryManager(); /** Prevents instantiation of the of the inventory manager by making a protected class */


    public:
       /**
         * Instance method
         * There is no public constructor (singleton) but instead an instance method to get the singleton object 
         */
        static InventoryManager & instance();

       /**
         * Inventory manager destructor
         * This is a virtual method that is meant to be a destructor of an instance that is no longer required 
         */
        virtual ~InventoryManager(); 

       /**
         * Menu items getter method
         * This is a get method that gets the set of menu items and returns them
         * @return vector set of menu items
         */
        std::vector <MenuItem> getMenuItems();

       /**
         * Menu items setter method
         * This is a set method that takes a set of menu items and replaces the current set with such
         * @param vector set of menu items
         */
        void setMenuItems(std::vector <MenuItem> items);
        
       /**
         * Here are some additional methods to help maintain the data structure
         */
        void printAllMenuItems();   
        void printMenuItem(std::string itemName);    
        int addMenuItem(MenuItem item);   
        int removeMenuItem(std::string itemName); 
        int removeMenuItem(MenuItem item);
        MenuItem * findMenuItem(std::string name);
};

#endif 
/*INVENTORYMANAGER_H_*/
