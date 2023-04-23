/* File:   Cart.h
 * Author: DanYell
 * Created on April 14, 2023, 1:30 AM
*/

#ifndef SURVEY_H
#define SURVEY_H
#include <string>
#include <array>
#include "Item.h"
#include "Cart.h"
#include "User.h"
using namespace std;

class Survey {
    
//protected: 
public:
    
    bool isTrue;    
    int itemSize;
    Item **item = nullptr;
    
    Survey(); // Default Constructor
    ~Survey(); // Destructor

    // Mutators
    bool start(User &, const long); 
    void readItemFile();
    
    // Accessor
    //void getCheckout()const;
    void pause(char ch='c');
};
#endif /* SURVEY_H */

