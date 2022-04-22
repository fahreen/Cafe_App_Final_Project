#include <string>
#include <iostream>
#include "Coupon.h"

using namespace std;

/**
 * Coupon class
 * Creates a new coupon object given a coupon code and its discount amount
 * 
 * */

/**
 * Set Invalid Coupon method
 * Creates an empty/invalid coupon object which resets the attributes of a coupon
 * */
void Coupon:: setInvalidCoupon(){
    this->couponCode = "";
    this->discount = 0;
}

/**
 * Unparameterized Couponn constructor
 * Calls the invalid coupon method if a coupon object is created with no parameters
 * */
Coupon::Coupon(){
	setInvalidCoupon();
}

/**
 * Parameterized coupon constructor
 * @param string couponCode identifier of coupon object
 * @param double discout amount of coupon
 * */
Coupon::Coupon(string couponCode, double discount){

    //If the code is am empty string, set coupon as invalid and print error message
	if(couponCode.compare("")==0){
        setInvalidCoupon();
        cout<<"The coupon code entered was not valid. Please make sure it is not blank. Coupon not created."<<endl;
    }

    //If the discount is less than 0 (invalid) set coupon as invalid and print error message
    else if(discount <0) {
        setInvalidCoupon();
        cout<<"The discount entered was not valid. Coupon not created."<<endl;
    }

    //If coupon is valid, set its attributes
    else {
        this->couponCode = couponCode;
        this->discount = discount;
    }

}

/**
 * Coupon deconstuctor 
 * */
Coupon::~Coupon(){
    ;
}

/**
 * Accessor method for the code of the Coupon object
 * @return string couponCode
 * */
string Coupon::getCouponCode(){
    return this->couponCode;
}

/**
 * Accessor method for the discount of the Coupon object
 * @return double doscount amount
 * */
double Coupon::getDiscount(){
    return this->discount;
}