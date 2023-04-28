#include <iostream>
#include <iomanip>
#include <array>
#include "Cart.h"
using namespace std;


//*********************************************************
//                  Default Constructor
//*********************************************************
Cart::Cart(){ 
    cartTotal = 0.0f;
    cartSize = NUMITEMS;
    totalItems = 0;
    for(int i=0; i < NUMITEMS; i++){
        cart[i] = 0;
    }
}


//*********************************************************
//
//*********************************************************
void Cart::setCartArr(int a, int b, int c){
    //cout<<"\n\tHit setCarArr(a,b,c)\n";
    cart[0] = a;
    cart[1] = b;
    cart[2] = c;
}

 
//*********************************************************
//              Sets cart[] elements to random numbers
//*********************************************************
void Cart::setCartArr(){
    int num = 0;
    for(int i=0; i < NUMITEMS; i++){
        num = (rand()%3)+1;
        cart[i] = num;                         
    }
}


//*********************************************************
//
//*********************************************************  
void Cart::prntCart()const{       
    for(int i=0; i < NUMITEMS; i++){
        cout <<  cart[i] << " ";
    }
    cout << "]";
    //cout << setw(2)<< cartSize << " total cart."; 
}


