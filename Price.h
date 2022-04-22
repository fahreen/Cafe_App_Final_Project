#ifndef PRICE_H_
#define PRICE_H_

/** sets all the types for all the variable types */
class Price{
    private:
        double price;
        double salePrice;
        bool onSale;

    public:
        /** Construct the objects */
        Price ();
        Price (double price);
        Price (double price, double salePrice);

        /** Destroy the object */
        ~Price();

        /** Return the attributes */
        double getPrice();
        double getSalePrice();
        bool getIsOnSale();

        /** Set the attributes */
        void setPrice(double price);
        void setSalePrice(double salePrice);
        void setIsOnSale(bool onSale);
};

#endif /* PRICE_H_ */
