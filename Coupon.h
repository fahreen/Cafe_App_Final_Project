#ifndef COUPON_H_
#define COUPON_H_

#include <string>
/**
 * Coupon header file
 * */
class Coupon{
	/**
	 * Declare private methods/attributes
	 * */
	private:
		//Code attribute of coupon, allows the coupon to be identified in the system
		std::string couponCode;
		//Discount amount attribute of the coupon
		double discount;
		//Sets an invalid coupon object
        void setInvalidCoupon();
		
	public:
		//Parameterized and unparameterized constructors and destructors
		Coupon();
        ~Coupon();
		Coupon(std::string couponCode, double discount);
		//Accesses code attribute of given coupon
		std::string getCouponCode();
		//Access discount attribute of given coupon
		double getDiscount();
};
#endif /*COUPON_H_ */