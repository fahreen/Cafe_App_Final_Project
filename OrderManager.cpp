
#include <iostream>
#include<string>
#include "OrderManager.h"
#include "InventoryManager.h"
#include "StockManager.h"


using namespace std;

OrderManager * OrderManager:: _instance=NULL; 

OrderManager& OrderManager:: operator= (OrderManager other){
    ;
}
void OrderManager:: printOrderList(vector<Order> orderList){
    for (unsigned int i = 0; i < orderList.size(); i++){
        printOrder(orderList[i]);
    }
}

void OrderManager::printOrder(Order order){
    cout<<"Item Name: "<<order.getMenuItemOrderedName()<<endl;
    cout<<"Item Id: "<<order.getMenuItemOrderedId()<<endl;
    cout<<"Order Id: "<<order.getOrderId()<<endl;
    cout<<"Quantity Ordered: "<<order.getQuantityOrdered()<<endl;
    cout<<"Order Received: "<<(order.isOrderReceived()?"True":"False")<<endl<<endl;
}

OrderManager::OrderManager(){
    ;
}

OrderManager &OrderManager::instance()
{
    if (_instance == NULL){
        _instance = new OrderManager();
        _instance->totalOrders = 0;
    }
    return *_instance;
}

OrderManager::OrderManager(OrderManager& other){
    ;
}

OrderManager:: ~OrderManager(){
    ;
}

vector<Order> OrderManager:: getOrdersPending(){
    return this->ordersPending;
}

vector<Order> OrderManager:: getOrdersReceived(){
    return this->ordersReceived;
}

vector<Order> OrderManager::getOrdersCancelled(){
    return this->orderCancelled;
}

/** other methods **/
//returns the order id if successful, returns -1 if unsuccessful
int OrderManager::createOrder(string itemName, int quantity){
    MenuItem *item;
    item = InventoryManager::instance().findMenuItem(itemName);
    if((item->getId()).compare("-1") ==0){
        cout <<"The item does not exist, therefore could not be ordered"<<endl;
        delete item;
        return -1; //return -1 if the item could not be successfully ordered
    }else if (quantity<1){
        cout <<"Invalid order quantity, the quantity should be greater than 0"<<endl;
        return -1;
    }
    else{
        //order the item
        Order order(*item, totalOrders++, quantity);
        this->allOrders.push_back(order); //add the item to all order
        this->ordersPending.push_back(order); //add the item to pending orders
        return order.getOrderId();

    }
}

//returns the order id if successful, returns -1 if unsuccessful
int OrderManager::cancelOrder(int orderId){
    Order *order;
    order = findOrderById(orderId);
    if((order->getOrderId())==-1){
        cout <<"The order does not exist, therefore could not be cancelled."<<endl;
        delete order;
        return -1; //return -1 if the item could not be successfully cancelled
    }else{
        //cancel the order
        for (unsigned int i = 0; i < (this->ordersPending).size(); i++){
            if(orderId==ordersPending[i].getOrderId()){
                this->ordersPending.erase(ordersPending.begin()+i); //remove the order from the pending list
                this->orderCancelled.push_back(*order); //add the item to pending orders
                return order->getOrderId();
            }
        }
        //if the order was not found in pending list, then it is either already received or cancelled
        cout <<"The order was already cancelled or received. Could not cancel the order."<<endl;
        return -1; //return -1 if the item could not be successfully cancelled
    }
}

//return the order id if successful, returns -1 if unsuccessful
int OrderManager::markOrderReceived(int orderId){
    Order *order = findOrderById(orderId);
    if((order->getOrderId())==-1){
        cout <<"The order does not exist, therefore could not be marked as received"<<endl;
        delete order;
        return -1; //return -1 if the item could not be successfully cancelled
    }else{
        //cancel the order
        for (unsigned int i = 0; i < (this->ordersPending).size(); i++){
            if(orderId==ordersPending[i].getOrderId()){
                this->ordersPending.erase(ordersPending.begin()+i); //remove the order from the pending list
                order->markOrderReceived();
                this->ordersReceived.push_back(*order); //add the item to received orders
                //update stockmanager after receiving an order
                StockManager::instance().addStock(order->getMenuItemOrderedName(), order->getQuantityOrdered());
                return order->getOrderId();
            }
        }
        //if the order was not found in pending list, then it is either already received or cancelled
        cout <<"The order was already cancelled or received. Could not mark the order as received."<<endl;
        return -1; //return -1 if the item could not be successfully cancelled
    }
}

Order * OrderManager::findOrderById(int orderId){
    //look for the order id and return the object if found
    for (unsigned int i = 0; i < (this->allOrders).size(); i++){
        if(orderId==allOrders[i].getOrderId()){
            return &allOrders[i];
        }
    }
    cout <<"The order with the id: " << orderId <<" does not exits in the system"<<endl;
    return new Order();//return an invalid order object
}


void OrderManager::printAllOrdersPending(){
    cout<<"ORDERS PENDING:"<<endl<<endl;
    printOrderList(this->ordersPending);
    cout<<endl<<endl;
}
void OrderManager::printAllOrdersReceived(){
    cout<<"ORDERS RECEIVED:"<<endl<<endl;
    printOrderList(this->ordersReceived);
    cout<<endl<<endl;
}
void OrderManager::printAllOrdersCancelled(){
    cout<<"ORDERS CANCELLED:"<<endl<<endl;
    printOrderList(this->orderCancelled);
    cout<<endl<<endl;
}
void OrderManager::printAllOrders(){
    printAllOrdersPending();
    printAllOrdersReceived();
    printAllOrdersCancelled();
}