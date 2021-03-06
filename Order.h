#ifndef ORDER_H_
#define ORDER_H_

#include <string>
#include "MenuItem.h"

//This class will hold a the information for a single order made 
class Order{

    private:
        int orderId; //the unique id of the order
        MenuItem itemOrdered; //the item that was ordered
        bool orderRecieved; //whether or not the order was received
        int quantity; //the total amount that was ordered
    
    public:
        //constructor to create the order
        Order();
        Order(MenuItem item, int orderId, int quantity);

        //destructor 
        ~Order();

        //getters for order information
        int getOrderId();
        MenuItem getMenuItemOrdered();
        bool isOrderReceived();
        int getQuantityOrdered();

        //no other setters, order should be cancelled and remade if you want to make changes

        //other functions
        int markOrderReceived(); //mark that the order has been received
        std::string getMenuItemOrderedName(); //get the name of the item that was ordered
        std::string getMenuItemOrderedId(); //get the id of the menuitem that was ordered
};

#endif /* ORDER_H_ */
