#ifndef STOCKMANAGER_H_
#define STOCKMANAGER_H_

#include <string>
#include <vector>
#include "MenuItem.h"
#include "InventoryManager.h"
#include "OrderManager.h"

/** Sets the definitions of the functions in terms of arguement length and type */
class StockManager{
    private:
        /** constructor to initilize what a menu item is composed of */

        static StockManager *_instance; /** The class only allows one instance of the inventory manager */
        StockManager(StockManager& other);
        StockManager& operator= (StockManager other);

    protected:
        StockManager(); /** Prevents instantiation of the of the inventory manager by making a protected class */

    public:
	    
        static StockManager& instance();
        virtual ~StockManager();
        
        //return current stock if successful, return -1 if unsuccessful
        int addStock(std::string itemName, int increaseBy); 

        //return current stock if successful, return -1 if unsuccessful
        //print a warning if it goes below the threshold
        int removeStock(std::string itemName, int decreaseBy);

        bool isInStock(std::string itemName);
        bool isBelowThreshold(std::string itemName);

        std::vector<MenuItem> getListOfItemsInStock();
        std::vector<MenuItem> getListOfItemsOutOfStock();
        std::vector<MenuItem> getListOfItemsBelowThreshold();

        void printItemsInStock();
        void printItemsOutOfStock();
        void printItemsBelowThreshold();
};

#endif /* STOCKMANAGER_H_ */
