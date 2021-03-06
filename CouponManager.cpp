#include <iostream>
#include <iomanip>
#include "CouponManager.h"

using namespace std;

/**
 * CouponManager class
 * Manages the list of Coupons in the system
 * 
 * */

/**
  * Coupon Manager instance
  * Starts a instance as NULL allowing it to be start getting written to
  */ 
CouponManager * CouponManager:: _instance=NULL;

/**
   * Coupon Manager constructor
   * Prevents copying or sharing but reducing these to nothing and not adding any info or an instance to be able to work with it
   * @param CouponManager& other
   */
CouponManager::CouponManager(CouponManager& other){
    ;
}

CouponManager& CouponManager:: operator= (CouponManager other){
    ;
}

/**
 * Coupon Manager unparamaterized constructor
 * Resets the current list of coupons in the system
 * */
CouponManager::CouponManager(){
    this->listOfCoupons.clear();
}

/**
   * Coupon Manager constructor
   * If the coupon manager doesnt exist then it creates a new instance of the inventory manager
   * then returns such instance in the form of a pointer
   * @return a pointer to the instance
   */
CouponManager& CouponManager::instance(){
    if (_instance == NULL)
        _instance = new CouponManager();
    return *_instance;
}

/**
 * Coupon Manager deconstructor
 * Resets the list of coupons in the system
 * */
CouponManager:: ~CouponManager(){
    this->listOfCoupons.clear();
}

/**
 * Accessor method to retrieve the list of all coupons currently being managed
 * @return vector<Coupon> listOfCoupons
 * */
vector<Coupon> CouponManager:: getCoupons(){
    return this->listOfCoupons;
}

/**
 * Coupon list setter method
 * Adds a given list of coupons to the maintained coupon list
 * @param vector<Coupon> listOfCoupons
 * */
void CouponManager::setCoupons(vector<Coupon> listOfCoupons){
    //Clear the current list of coupons
    this->listOfCoupons.clear();
    //Loop through the given list and add them one by one using the addCoupon method
    for (unsigned int i = 0; i < listOfCoupons.size(); i++){
        addCoupon(listOfCoupons[i]);
    }
}

/**
 * Prints the list of coupons in the system
 * */
void CouponManager::printAllCoupons(){
    cout<<endl<<"All coupons listed:"<<endl<<endl;
    //Loop through coupon list and call printCoupon method on each one
    for(unsigned int i = 0; i <listOfCoupons.size(); i++){
        printCoupon(listOfCoupons[i].getCouponCode());
    }
}

/**
 * Prints an individual coupon object with its code and discount attributes
 * @param string couponCode of coupon to be printed
 * */
void CouponManager::printCoupon(string couponCode){
    cout<<endl;
    //Loops through list of coupons until one has a code matching the given code
    for (unsigned int i = 0; i < listOfCoupons.size(); i++){
        if (couponCode.compare(listOfCoupons[i].getCouponCode()) == 0){
            //Print out its attributes
            cout<<"Coupon Code: "<<listOfCoupons[i].getCouponCode()<<endl;
            cout<<"Discount: "<<listOfCoupons[i].getDiscount()<<endl;
            return;
        }
    }
    //Print error message if coupon was not found
    cout << "Item was not found" << endl;
}

/**
 * Adds a given coupon to the system
 * @param Coupon coupon to be added
 * 
 * */
void CouponManager::addCoupon(Coupon coupon){
    //Loop through list of coupons to see if one has a code matching the code of the given Coupon
    for (unsigned int i = 0; i<listOfCoupons.size(); i++){
        if (coupon.getCouponCode().compare(listOfCoupons[i].getCouponCode()) == 0){
            //Print an error message if coupon is found in system
            cout << "The coupon already exists" << endl;
            return;
        }
    }
    //Print error if Coupon has an invalid discont amount or empty coupon code
    if (coupon.getDiscount() == -1){
        cout << "Invalid coupon discount - could not be added to the system" << endl;
    }
    else if (coupon.getCouponCode() == ""){
        cout << "Invalid coupon code - could not be added to the system" << endl;
    }
    //Add coupon to the list if it is valid
    else{
        listOfCoupons.push_back(coupon);
        cout << "The coupon with the code " + coupon.getCouponCode() << " was added to the system" << endl;
    }
}

/**
 * Removes a given coupon from the system given its code
 * @param string couponCode of coupon to be removed
 * */
void CouponManager::removeCoupon(std::string couponCode){
    //Loop through list of coupons until coupon with the given code has been found
    for (unsigned int i = 0; i < listOfCoupons.size(); i++){
        if (couponCode.compare(listOfCoupons[i].getCouponCode()) ==0){
            //Once found, remove the coupon from the list
            listOfCoupons.erase(listOfCoupons.begin()+i);
            cout << "The coupon with the code " + couponCode << " has been removed" << endl;
            return;
        
        }
    }
    //If not found in the system, print error message
    cout << "The coupon with the code " + couponCode << " does not exist in the system" << endl;
}

/**
 * Removes a given coupon from the list 
 * @param Coupon coupon to be removed
 * */
void CouponManager::removeCoupon(Coupon coupon){
    //Retrieve the coupon's code and call the removeCoupon method above
    removeCoupon(coupon.getCouponCode());
}

/**
 * Find a coupon in the system given its code
 * @param string couponCode
 * @return Coupon* pointer to coupon object
 * 
 * */
Coupon * CouponManager::findCoupon(string couponCode){
    //Loop through list to find coupon with the given code
    for (unsigned int i = 0; i <listOfCoupons.size(); i++){
        if (couponCode.compare(listOfCoupons[i].getCouponCode()) == 0){
            //If found, return the Coupon object assicoated with that code
            return &listOfCoupons[i];
        }
    }
    //If coupon is not found, print error message
    cout << "The coupon with the code " + couponCode << " does not exist in the system" << endl;
}







