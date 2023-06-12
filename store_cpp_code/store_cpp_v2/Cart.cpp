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
    cartSize = 0;
    for(int i=0; i < NUMQQ; i++){
        cart[i] = 0;
    }
}


//*********************************************************
//              Set a cart array element
//*********************************************************
void Cart::setCartIndx(int i, int value){ 
    cart[i] = value; 
    increCartSize();
}


//*********************************************************
//
//*********************************************************
void Cart::setCartArr(int a, int b, int c){
    //cout<<"\n\tHit setVotArr()\n";
    cart[0] = a;
    cart[1] = b;
    cart[2] = c;
    increCartSize();
    increCartSize();
    increCartSize();
}

 
//*********************************************************
//              Sets cart[] elements to random numbers
//*********************************************************
void Cart::setCartArr(){
    int num = 0;
    for(int i=0; i < NUMQQ; i++){
        num = (rand()%3)+1;
        cart[i] = num;
        increCartSize();                           
    }
}


//*********************************************************
//
//*********************************************************  
void Cart::prntCart()const{       
    for(int i=0; i < NUMQQ; i++){
        cout <<  cart[i] << " ";
    }
    cout << "]";
    //cout << setw(2)<< cartSize << " total cart."; 
}


