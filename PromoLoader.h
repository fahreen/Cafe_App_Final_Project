#ifndef PROMOLOADER_H_
#define PROMOLOADER_H_

#include "FileLoader.h"

/**
 * Promo Loader header file 
 * The constructor reads in from the input filestream with the parameters being the fileName
 * then opens the file and reads in various pieces of information to help understand.
 * Next line by line in loop reads in from the file and adds it to the array where it can be used later
 * Then the array is used to send to addnewpromo where it can be added
 * Finally all items read in are printed then the file is closed
*/
class PromoLoader : public FileLoader{
public:
/**
 * Promo Loader method 
 * For the bulk loading of all the items in a file
 * The method requires a filename from which import items
 * @param string file name
 */
	PromoLoader(std :: string fileName);
private:
  
/**
 * Add new promo method
 * Method for the creation of new promos
 * The items are individually added to the set, where it will be used to create a new menu item
 * @param string promo code
 * @param double discount amount
 */
	void addNewPromo(std::string coupon_code, double discount);
};
#endif
 
