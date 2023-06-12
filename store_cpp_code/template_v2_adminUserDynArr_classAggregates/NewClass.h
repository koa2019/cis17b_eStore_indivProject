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
    bool p1Winner;        // does user winner and have new high score
    int nPlayer;         // Player inputs how many players
    int *indx = nullptr;
    int diceArr[NUM5] = {};
    User **player = nullptr;   // Aggregates instance of User Class. Array of User's
    
public:
    NewClass(); // Default Constructor
    ~NewClass(); //Destructor
    
    // Mutators
    bool start(User &);
    
    // Accessors
    void pause(char ch='c');
    void displayOptions(int &);
    
};

#endif /* NEWCLASS_H */

