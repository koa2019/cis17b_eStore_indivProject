/* File:   Cart.h
 * Author: DanYell
 * Created on April 14, 2023, 1:30 AM
*/

#ifndef CART_H
#define CART_H
#include <iostream>  // cout
#include <iomanip>  // setw()
using namespace std;

const int NUMITEMS = 3;

class Cart {    

    public:
    
    int cartSize;    // How many items are in the checkout cart
    int cart[NUMITEMS]; // Array holds how many cart each option received
    int totalItems;
    float cartTotal;    
   
    Cart(); // Default constructor
    
    // Mutators
    void setCartSize(int s){ cartSize = s; }
    void setCartTotal(float t){ cartTotal = t; }
    void setTotItm(int n) { totalItems = n; }
    void setCartIndx(int i, int value){ cart[i] = value; }
    void setCartArr();            // Sets cart elements to random #'s
    void setCartArr(int,int,int); // sets cart elements to these integers
    void increTotItm(){ cartSize++; }
    //void increCart(int i){ cart[i]++; }    
    
    // Accessors
    int getCartIndx(int i) const { return cart[i]; }
    int getCartSize() const { return cartSize; }  
    int getTotItm() const { return totalItems; }
    float getCartTotal(){ return cartTotal; }
    void prntCart() const;
};
#endif /* CART_H */

