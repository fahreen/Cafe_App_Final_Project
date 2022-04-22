#ifndef ORDERMANAGER_H_
#define ORDERMANAGER_H_

#include <string>
#include <vector>
#include "Order.h"

/** Sets the definitions of the functions in terms of arguement length and type */
class OrderManager{
    private:
        int totalOrders;
        /** constructor to initilize what a menu item is composed of */
        static OrderManager *_instance; /** The class only allows one instance of the inventory manager */
        std::vector<Order> allOrders; /** keeps track of all orders*/
        std::vector<Order> ordersPending; /** keeps tack of order made and pending */
        std::vector<Order> ordersReceived; /** keeps tack of orders made and received */
        std::vector<Order> orderCancelled;  /** keeps tack of orders made and cancelled */

        OrderManager(OrderManager& other);
        OrderManager& operator= (OrderManager other);

        void printOrderList(std::vector<Order> orderList); //helper method to print orderlists
        void printOrder(Order order); //helper method to print an order

    protected:
        OrderManager(); /** Prevents instantiation of the of the inventory manager by making a protected class */

    public:
	    
        static OrderManager& instance();

        virtual ~OrderManager();

        /** get info methods */
        std::vector<Order> getOrdersPending();
        std::vector<Order> getOrdersReceived();
        std::vector<Order> getOrdersCancelled();

        /** other methods **/
        //returns the order id if successful, returns -1 if unsuccessful
        int createOrder(std::string itemName, int quantity); 
        //returns the order id if successful, returns -1 if unsuccessful
        int cancelOrder(int orderId);
        //return the order id if successful, returns -1 if unsuccessful
        int markOrderReceived(int orderId);

        Order * findOrderById(int orderId); //helper method to print an order

        void printAllOrdersPending();
        void printAllOrdersReceived();
        void printAllOrdersCancelled();
        void printAllOrders();
};

#endif /* ORDERMANAGER_H_ */
