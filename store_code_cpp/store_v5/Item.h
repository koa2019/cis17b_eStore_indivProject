/* File:   Item.h
 * Author: DanYell
 * Created on April 13, 2023, 6:55 PM
*/

#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iomanip> // setprecision()
using namespace std;

const int ITEMSIZE = 3;

class Item {   
    
protected: 
    int stringSize;  // number of rolls
    string item[ITEMSIZE]; //[item, insideRollDescrip,outside roll]
    float price; // price of roll
    
public:
    
    Item(); // Default Constructor
    Item(int);
    //~Item(){ delete [] item; }  // Destructor
    
    // Mutator
    void setStringSize(int n) { stringSize = n; }
    void addStringSize(int);
    void setItem(int i, string str){ item[i] = str; }
    void setPrice(float p) { price = p; }
    void setItemArr(string,string,string,float);   
    //void readItemFile();
    
    // Accessors
    int getStringSize() const { return stringSize; }
    string getItem(int i){ return item[i]; }
    float getPrice() const { return price; }
    void printItem();
};
#endif /* ITEM_H */

