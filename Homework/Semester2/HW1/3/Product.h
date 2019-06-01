//
//  Product.h
//  OnlineStore
//
//  Created by Zhivko Georgiev on 10.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Product_h
#define Product_h

//the product is guitar
class Product{
private:
    char* SKU; // id of the guitar
    char* brand; // brand guitar(Cort, Ibanez, Parker, Gibson, Fender)
    char* model; // model guitar(Cort - KX5, Fender Stratocaster)
    char* category; //acoustic, electric, ukulele etc.
    int price; // interval(100$ - 10000$)
    int count; // how many guitars of that type are int the store
public:
    Product(); //default
    Product(const char*, const char*, const char*, const char*, int, int); //all parameters
    Product(const Product&); //copy
    
    // getters and setters
    char* getSKU() const;
    void setSKU(const char*);
    char* getBrand() const;
    void setBrand(const char*);
    char* getModel() const;
    void setModel(const char*);
    char* getCategory() const;
    void setCategory(const char*);
    int getPrice() const;
    void setPrice(int);
    int getCount() const;
    void setCount(int);
    
    void printProduct() const;
    Product& operator=(const Product&); //operator
    friend std::istream& operator>>(std::istream&, Product&);
    friend class Store;
    ~Product(); //destructor
};
#endif /* Product_h */
