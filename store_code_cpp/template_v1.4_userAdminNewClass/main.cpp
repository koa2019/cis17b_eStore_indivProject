/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 04-16-23 @10 PM
 * Purpose:  template_adminUserClass_aggregates. v1.4
 * 
Comments: 
 * If it's your first time running this code, select 5 from the menu
   that runs in main(). This reset's the code by resetting the User's binary file, 
   userdata.dat. This way you can start with fresh code that I haven't tested on.
 
 * The commented out couts and print() are kept in here, so you can see what 
   the code is doing at that point for debugging purposes.

 * CAUCTION! if you rewrite anything other than hiScore, then 
   it will effect wrtTxt() and reWrtTxt(). If name was 8 bits, but you change
   name to 7 or 9 bits, then it messes the text file up.
 
 * bool start(User user, long recordLoc) accepts a User object from main() 
   and this record's bit location in the binary file, userData.dat. 
   start() resets hiScore in user's object and rewrites its record 
   in the binary & text files.
 
 * If start() returns true to main(), then Admin will confirm the record has
   been updated and print the updated record.
 
 * This is meant to be a template. Replace NewClass with whatever Class you're creating
   that needs User & Admin classes.
 
 * NewClass is meant to show you how'd you rewrite a integer variable, hiScore in
   binary & text files. You can change hiScore or any User member variable as you see fit.
 
 * This was created on a PC. If you're running it on a mac, then
   delete the build and dist folders before running it. If that doesn't work, then
   you'll have to copy and paste each file into a new project in your netbeans

 
 v1.1:
 * This is based off of yahtzee_v24_moveDice2SC.

 v1.3:
 * Merged yahtzee_v28.2's Admin & User Classes with store_v1.2
 
 Admin/User To Do:   
 * Make User::readInputFile() read inputs from file again. isStrEqual() returns false. 
 * Add a bool variable to Admin as a flag for deleted records? 
 * DRY. Clean up repetitive code.
 * Have ~User do something other than cout a message. Program fails without it.
 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <string>  //string
#include <cstring> //c-strings
#include <cctype> // tolower()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "User.h"
#include "Admin.h"
#include "NewClass.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));

    int choice = 0;
    Admin admin;
    User user; 
    
    
    cout<<"\n\n\tMenu\n"
        <<"1: Admin Login\n"
        <<"2: Sign Up\n"
        <<"3: User Login\n"
        <<"4: Start NewClass as a guest\n"
        <<"5: ReadInputFile()\n"
        <<"9: Exit\n"
        <<"Enter a number: ";
        cin>>choice;
        cin.ignore();
        
        switch(choice){
            
            case 1: // Admin login
            {               
                admin.adminLogin();
                break;
            } 
            case 2: // User sign up for new account
            {
               
                user.signUp();
                //cout<<"\ninside main() after signUp() object looks like: ";
                //user.printUsr();
                break;
            }
            case 3:  // User login. If successful, then play game          
            {       
                //Admin admin1;
                int indx = admin.isUsrLogin();
                if(!(indx == -66)){
                    
                    cout<<"\n\nUser login was successful.\n"; 
                    cout<<"\ninside main() admin1 object looks like: ";
                    admin.printAdUsr(indx);                    
                    
                    
                    // Create new User & copy admin values to user                    
                    admin.copy2Usr(user,indx);    
                    cout << "\nWelcome " << user.getName();
                    user.printUsr(); 
                    
                    // Create new instance of NewClass class
                    NewClass yourClass;
                                 
                    long recordLoc = admin.getBegnFile(indx);
                    
                    if(recordLoc<0){ cout << "\nError finding record location\n"; break; }
                    
                    // if user is winner & has new hiScore, then print their update record
                    if(yourClass.start(user, recordLoc)) {                         
                        
                        //cout<<"\n\ninside main() user object looks like: ";
                        //user.printUsr();                       
                          
                        // rewrite this record in binary & text files  
                        user.reWrtBin(recordLoc); 
                        admin.readAllUsrs();
                        cout << "\nAdmin is reading updated binary file....\n";
                        admin.printAdUsr(user.getNumRec());   
                    }                                                    
                }
                break;
            }             
            case 4: // Play NewClass as a guest
            {          
                User guest("Guest"); 
                //cout<<"\ninside main() guest user object looks like: ";
                guest.printUsr();
                NewClass game2;                                                  
                game2.start(guest,0);
                break;
            }
            case 5:   // Reset files by erasing binary & text file, then creates records in 
            {        // User binary with records. Use after testing & altering records.    
                user.readInputFile(); 
                break;
            }
            default: 
            {
                cout<<"\nGood Bye.\n";                
                exit(0);
            }
        }    
    return 0;
}