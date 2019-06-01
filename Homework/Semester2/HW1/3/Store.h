//
//  Store.h
//  OnlineStore
//
//  Created by Zhivko Georgiev on 12.04.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef Store_h
#define Store_h

#include "Product.h"
// store for selling guitars
class Store{
private:
    Product* products;
    int productsCnt;
    int capacity;
public:
    Store(); //default
    Store(const Store&); //copy
    void resize();
    void addProduct(const Product&);
    void deleteProduct(int pos);
    void changeProduct(int pos, const Product&);
    void displayProducts() const;
    Store& operator=(const Store&); //operator
    ~Store(); //destructor
};
#endif /* Store_h */
