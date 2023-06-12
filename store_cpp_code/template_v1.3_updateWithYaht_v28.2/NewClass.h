/* File:   NewClass.h
 * Author: DanYell
 * Created on April 16, 2023, 9:40 PM
*/

#ifndef NEWCLASS_H
#define NEWCLASS_H
#include "User.h"       // aggregates User class

const int NUM5 = 5; 
    
class NewClass {
    
private:
    bool isTrue;        // does user winner and have new high score   
    
public:
    NewClass(); // Default Constructor
    ~NewClass(); //Destructor
    
    // Mutators
    bool start(User &, const long);
    
    // Accessors
    void pause(char ch='c');
    void displayOptions(int &);
    
};

#endif /* NEWCLASS_H */

