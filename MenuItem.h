#ifndef MENUITEM_H_
#define MENUITEM_H_

#include <string>
#include "Price.h"

/** Sets the definitions of the functions in terms of arguement length and type */
class MenuItem{
    private:
        std::string name; 
        std::string id;
        double currentPrice;
        Price price;
        int currentInventory;
        int minimumInventory;
        std::string ingredients;
        void setInvalidItem();

    public:
        /** constructor to initilize what a menu item is composed of */
        MenuItem();
        MenuItem (std::string name, std::string id, double price, int currentInventory, int minimumInventory, std::string ingredients);
        MenuItem (std::string name, std::string id, Price price, int currentInventory, int minimumInventory, std::string ingredients);
	    
        /** destructor method */
	    ~MenuItem();
        
        /** get info methods */
        std::string getName();
        std::string getId();
        double getCurrentPrice();
        double getSalePrice();
        bool getOnSale();
        double getCurrentInventory();
        double getMinimumInventory();
        std::string getIngredients();

        /** set attribute methods */
        void setName(std::string name);
        void setPrice(double price);
        void setCurrentInventory(int inventory);
        void setMinimumInventory(int minimumInventory);
        void setIngredients(std::string ingredients);

        /** sale functions */
        void putItemOnSale();
        void putItemOnSale(double price);
        void takeItemOffSale();
};

#endif /* MENUITEM_H_ */
