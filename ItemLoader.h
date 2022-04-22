#ifndef ITEMLOAD_H_
#define ITEMLOAD_H_

#include "FileLoader.h"

/**
 * Item Loader header file 
 * This is the item loader class, as its name might suggest it loads items.
 * The constructor reads in from the input filestream with the parameters being the fileName
 * then opens the file and reads in various pieces of information to help understand.
 * Next line by line in loop reads in from the file and adds it to the array where it can be used later
 * Then the array is used to send to addnewitem where it can be added
 * Finally all items read in are printed then the file is closed
*/
class ItemLoader : public FileLoader{
public:
/**
 * Item Loader method 
 * For the bulk loading of all the items in a file
 * The method requires a filename from which import items
 * @param string file name
 */
	ItemLoader(std :: string fileName);
private:
  
/**
 * Add new item method
 * Method for the creation of new menu items
 * The items are individually added to the set, where it will be used to create a new menu item
 * @param string name of item
 * @param string id of item
 * @param double price of item
 * @param int current inventory amount of item
 * @param int minimum inventory amount of item
 * @param string ingredients in item
 */
	void addNewItem(std:: string name, std:: string id, double price, int currentInventory, int minimumInventory, std:: string ingredients);
};
#endif
