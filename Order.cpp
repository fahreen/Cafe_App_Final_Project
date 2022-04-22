
#include <string>
#include <iostream>
#include "Order.h"
#include "MenuItem.h"

using namespace std;

//This class will hold a the information for a single order made
/**
 *      std::string orderId; //the unique id of the order
        MenuItem itemOrdered; //the item that was ordered
        bool orderRecieved; //whether or not the order was received
        int quantity; //the total amount that was ordered
*/

//constructor to create the order

//default constructor will create an invalid menu item
Order::Order(){
    this->orderId = -1;
    MenuItem item;
    this->itemOrdered = item;
    this->orderRecieved= false;
    this->quantity=-1;
}

Order::Order(MenuItem item, int orderId, int quantity){
    this->orderId = orderId;
    this->itemOrdered = item;
    this->orderRecieved= false;
    this->quantity=quantity;
}

//destructor
Order::~Order(){
    ;
}

//getters for order information
int Order::getOrderId(){
    return this->orderId;
}

MenuItem Order::getMenuItemOrdered(){
    return this->itemOrdered;
}

bool Order::isOrderReceived(){
    return this->orderRecieved;
}

int Order::getQuantityOrdered(){
    return this->quantity;
}

//no other setters, order should be cancelled and remade if you want to make changes

//other functions
//mark that the order has been received
int Order:: markOrderReceived(){
    if(this->orderRecieved==true){
        cout<< "Error: The order was already recieved. Could not mark as received" <<endl;
        return -1; //return -1 if the order was already received
    }else{
        this->orderRecieved=true;
        return 0; //return 0 if the marking was successful
    }
}           
//get the name of the item that was ordered
string Order::getMenuItemOrderedName(){
    return (this->itemOrdered).getName();
}

//get the id of the item that was ordered
string Order::getMenuItemOrderedId(){
    return (this->itemOrdered).getId();
}
