/* File:   Cart.h
 * Author: DanYell
 * Created on April 14, 2023, 1:30 AM
*/

#ifndef CART_H
#define CART_H
#include <iostream>  // cout
#include <iomanip>  // setw()
using namespace std;

const int NUMQQ = 3;
const int CARTIZE = NUMQQ+1;

class Cart {    

    public:
    
    int cartSize;    // How many items are in the checkout cart
    int cart[NUMQQ]; // Array holds how many cart each option received
    float cartTotal;    
   
    Cart(); // Default constructor
    
    // Mutators
    void setCartSize(int s){ cartSize = s; }
    void setCartTotal(float t){ cartTotal = t; }
    void setCartIndx(int, int);
    void setCartArr();            // Sets cart elements to random #'s
    void setCartArr(int,int,int); // sets cart elements to these integers
    void increCartSize(){ cartSize++; }
    void increCart(int i){ cart[i]++; }    
    
    // Accessors
    int getCartIndx(int i) const { return cart[i]; }
    int getCartSize() const { return cartSize; }  
    float getCartTotal(){ return cartTotal; }
    void prntCart() const;
};
#endif /* CART_H */

