#include <iostream>  // cout
#include <iomanip>  // setw()
#include <vector>  // vector
#include <bits/stdc++.h>  // vectors pc
#include "NewClass.h"
#include "User.h"       // aggregates instance of User class
using namespace std;

//**********************************************************
//                  Default Constructor
//**********************************************************
NewClass::NewClass(){ 
    isTrue = false;    
}

//**********************************************************
//                  Default Constructor
//**********************************************************
NewClass::~NewClass(){
    
    cout << "\n******Change NewClass Destructor*****\n";
    
}
//**********************************************************
//              Setup NewClass here
//  reset user's hiScore and return true to main()
//  if true, then Admin will confirm the rewritten record in main()
//**********************************************************

bool NewClass::start(User &user, const long recordLoc){
  
    pause();          
  
    int randNum = (rand()%(0+101));             // random number between 0-100
              
        
    isTrue = true; // set flag

    // Reset user's hiSCore and update binary & text file            
    user.setHiScore(randNum);
    
    cout << "\n\tNew High Score of " << user.getHiScore() << "!\n";

     if(!isTrue){ // if player 1 is NOT winner
        
        cout<<"\n\nHiScore was NOT updated!\n"; 
        return false; 
    }
    else { 
        
//        // rewrite this record in binary & text files  
//        user.reWrtBin(recordLoc); 
        cout << "\nUser is updating binary file...."; 
        return isTrue; // return true and Admin will confirm files were rewritten
    }
}

//******************************************
//      pause screen before continuing
//******************************************
void NewClass::pause(char ch) {
    
    string msg = ch=='r' ? "roll" : "continue";    
    cout<<endl<<setw(6)<<' '<<"Press enter to " << msg << ".";   
    cin.get();
}
