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
    
    nPlayer = 2; 
    p1Winner = false;
    
    // Initialize dice array
    for(int i=0; i < NUM5; i++){
        diceArr[i] = 0;
    }   
    
    // Create array of index to keep track of each player
    indx = new int[nPlayer];
    
    // Initialize array
    for (int i=0; i < nPlayer; i++) {         
        indx[i] = i;
    }
  
    // creating double pointers. An array of Classes
    player = new User*[nPlayer]; 
    
    
    // Creating each individual player by calling User constructor 
    // Every player is initially set with a name of Player i
    // change player 1's name inside of play();    
    for (int i = 0; i < nPlayer; i++) {  
        
        int num = i+1;
        stringstream stream;  // convert int to string
        stream << num;
        string str2;
        stream >> str2;  // save converted int to a string variable
        string str1 = "Player " + str2;
        player[indx[i]] = new User(str1); 
    }
}

//**********************************************************
//                  Default Constructor
//**********************************************************
NewClass::~NewClass(){
    
    cout << "\n******Add code to Destroy **player in Yahtzee*****\n";
    
}
//**********************************************************
//              Setup NewClass here
//**********************************************************

bool NewClass::start(User &user){
    
    // Reset player 1's name with user's name
    player[indx[0]]->setName(user.getName());    
    
    // Create array for player's name
    string name[nPlayer] = {player[indx[0]]->getName(), player[indx[1]]->getName() };
   
    pause();          
  
    int randNum = (rand()%(0+101));             // random number between 0-100
    
    player[indx[0]]->setHiScore(randNum);   // Reset this object's member variable
    
      
    /* Player 1 represents the user object that passed in the function argument. 
       ONLY change user's values if player1 wins and has a higher score than user's hiScore. */
      
    if(user.isHiScore( player[indx[0]]->getHiScore() )){            
        
        p1Winner = true; // set flag
        
        // Reset user's hiSCore and update binary & text file            
        user.setHiScore( player[indx[0]]->getHiScore() );
        cout << "\n\tNew High Score of " << user.getHiScore() << "!\n";

        
        // Certain printout depending on if User is logged in or not
        if(user.getName() == "Guest"){ 
            
            //user.printUsr();
            cout<<"\n\tSign up or Login to save your score.\n"; 
        }
        else { cout << "\nUser is updating binary file...."; }
        
        return p1Winner; // return true player1 has new high score  

    } else { cout<<"\n\nNo new hiScore, so binary was not changed.\n"; }        
  
    
    return p1Winner; // p1Winner would be false here
}

//******************************************
//      pause screen before continuing
//******************************************
void NewClass::pause(char ch) {
    
    string msg = ch=='r' ? "roll" : "continue";    
    cout<<endl<<setw(6)<<' '<<"Press enter to " << msg << ".";   
    cin.get();
}
