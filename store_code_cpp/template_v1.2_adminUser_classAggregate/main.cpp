/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 04-16-23 @10 PM
 * Purpose:  template_adminUserClass_aggregates. v1.1
 * 
Comments: 
 * If it's your first time running this code, select 5 from the menu
   that runs in main(). This reset's the code by resetting the User's binary file, 
   userdata.dat. This way you can start with fresh code that I haven't tested on.

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
 * CAUCTION! if you chance anything other than hiScore, then 
   it will effect wrtTxt() and reWrtTxt(). If name was 8 bits, but you change
  name to 7 or 9 bits, then it messes the text file up.
 
 v1.1:
 * This is based off of yahtzee_v24_moveDice2SC.

 
 
 Admin/User To Do:  
 * Make getAllUsr() print outside of its function  
 * Destroy double ptr in NewClass class & in Admin class? 
 * Add a bool variable to Admin as a flag for deleted records? 
 * DRY. Clean up repetitive code.
 * Have destructors do something other than cout a message. Program fails without them.

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
                Admin admin;
                admin.adminLogin();
                break;
            } 
            case 2: // User sign up for new account
            {
                User user1;
                user1.signUp();
                cout<<"\ninside main() user1 object looks like: ";
                user1.printUsr();
                break;
            }
            case 3:  // User login. If successful, then start()          
            {       
                Admin admin1;
                
                if(admin1.isUsrLogin()){
                    
                    cout<<"\nUser login was successful.\n"; 
                    //cout<<"\ninside main() admin1 object looks like: ";
                    //admin1.printAdUsr();                    
                    
                    
                    // Create new User & copy admin values to user
                    User user2;
                    admin1.copy2Usr(user2);    
                    cout << "\nWelcome " << user2.getName();
                    user2.printUsr(); 
                    
                    // Create new instance of NewClass class
                    NewClass yourClass1;
                                 
                    long recordLoc = admin1.getBegnFile();   
                    
                    // if true, then print this objects updated record from binary
                    if(yourClass1.start(user2, recordLoc )) {                         
                        
                        //cout<<"\n\ninside main() updated user2 object looks like: ";
                        //user2.printUsr();
                         
                        cout << "\nAdmin is reading binary file....\n";
                        admin1.findByIndx(user2.getNumRec());
                        admin1.printAdUsr();   
                    }                                                    
                }
                break;
            }             
            case 4: // Play NewClass as a guest
            {          
                User guest("Guest"); 
                cout<<"\ninside main() guest user object looks like: ";
                guest.printUsr();
                NewClass yourClass2;                                                  
                yourClass2.start(guest,0);
                break;
            }
            case 5: // Reset files by erasing binary & text file, then creates records in 
            {        // User binary with records. Use after testing & altering records.
            
                User user5;
                user5.readInputFile(); 
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