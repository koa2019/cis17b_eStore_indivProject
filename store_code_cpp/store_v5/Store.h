/* File:   Cart.h
 * Author: DanYell
 * Created on April 14, 2023, 1:30 AM
*/

#ifndef STORE_H
#define STORE_H
#include <fstream> // fstream
#include "Item.h"
#include "Cart.h"
#include "User.h"
using namespace std;

class Store {
     
public:
    
    bool isTrue;    
    int itemSize;
    Item **item = nullptr;
    
    Store(); // Default Constructor
    ~Store(); // Destructor

    // Mutators
    bool start(User &); 
    void readItemFile();
    
    // Accessor
    void pause(char ch='c');
};
#endif /* STORE_H */

