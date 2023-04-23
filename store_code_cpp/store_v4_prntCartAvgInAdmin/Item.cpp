#include <string>
#include <array>
#include <iostream> // cout
#include <fstream> // fstream
#include <iomanip> // setw()
#include "Item.h"
#include "Cart.h"
#include "User.h"
using namespace std;


//*********************************************************
//              Default Constructor
//*********************************************************
Item::Item(){
    
    //cout<<"\n Hit Item Default Constructor\n";    
    stringSize = ITEMSIZE;
    price = 0.0f;
    
    for(int i = 0; i < stringSize; i ++){
        item[i]  = "";        
    }
}


//*********************************************************
//      Try overloaded + operator function
//*********************************************************
void addStringSize(int n){
    
//    int numItems = stringSize + n;
//    setStringSize(numItems);
}

//*********************************************************
//              Reset each item with this string
//*********************************************************

void Item::setItemArr(string q, string a, string b, float p){    
    setItem(0,q);
    setItem(1,a);
    setItem(2,b);
    price = p;
    //setItem(3,c);
}

//*********************************************************
//
//*********************************************************
void Item::printItem(){   
    cout << item[0] << "\n";    
    cout << "\t   Inside : " << item[1] << "\n";
    cout << "\t   Outside: " << item[2] << "\n";
    cout << "\t   $" << fixed << setprecision(2) << price << endl;
}
