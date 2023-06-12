/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 04-22-23 @9PM
 * Purpose: store_v5
  
 Comments to User:
 * For ease of use, when you login in as a user or admin I have printed 
   their login info to the screen. Type it in when prompted.  
 * If it's your first time running this code, select 6 from the menu
   that runs in main(). This reset's the code by resetting the User's binary file 
   to 9 records. This way you can start with fresh code that I haven't tested on.
 
 
 store_v5:
 * Refractor-ed Survey class to Store.
 * copy2Usr() saved cart[] elements to user2.
 * Added getCheckout() in Admin. It prints the user's order.
 * Fixed BUG: Cart::cartTotal not adjusting total when item quantity is updated in store,
   by creating temp integer array to temporarily saves the user's order until they're
   ready to checkout.
 * Added Cart::totalItems.
 * Set each player's totalItems and cartTotal after binary file is read. Inside of Admin::setItemStats().
 * Prints percentages in printItemStats().
  
 To Do:  
 * Move printItemStats() from main() to adminPortal().
 * Move **item from Store class to Item class.
 * Make readInput() read inputs from file again 
 * Add a bool isDeleted[totalRec] to Admin as a flag for deleted records? 
 * DRY. Clean up repetitive code.
*/

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> // setw()
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <string> //string
#include <cstring> //c-strings
#include <cctype>  // toupper()
#include <fstream> // fstream
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "User.h"
#include "Admin.h"
#include "Store.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

// Function prototypes
void getUsrLogin();

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));

    int choice = 0;
    User user; 
    Admin admin;   
   
    cout<<"\n\n\tMenu\n"
        <<"1: Admin Login\n"
        <<"2: Sign Up\n"
        <<"3: User Login\n"
        <<"4: Shop as Guest\n"
        <<"5: View Purchased Stats\n"
        <<"6: Reset binary & text files\n"
        <<"9: Exit\n"
        <<"Enter a number: ";
        cin>>choice;
        
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
                getUsrLogin();
                break;
            }   
            case 4: // View the Store's chart
            {          
                //cout<<"\tIn main()"; 
                User guest("Guest");                
                Store sGuest;
                if(sGuest.start(guest)) { 
                        cout<<"\n\ninside main() guest object looks like: ";
                        guest.printUsrRec();   
                        //guest.getCheckout(); // Print checkout 
                }
                break;
            }
            case 5: // View the Store's chart
            {          
                //cout<<"\tIn main()"; 
                admin.printItemStats();
                break;
            }
            case 6:   // Reset files by erasing binary & text file, then creates records in 
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

//**************FUNCTION DEFINTITIONS********************************
void getUsrLogin(){
        
    User user; 
    Admin admin; 
    
    int indx = admin.isUsrLogin();
     
    if(!(indx == -66)){

        cout<<"\nUser login was successful.\n"; 
        //cout<<"\ninside main() admin1 object looks like: ";
        admin.printAdUsr(indx);                    


        // Create new User & copy admin values to user                    
        admin.copy2Usr(user,indx);    
        cout << "\nWelcome " << user.getName();
        user.printUsr(); 
        admin.printAdUsr(user.getNumRec()); 

        // Create new instance of Store class
        Store store;

        long recordLoc = admin.getBegnFile(indx);

        if(recordLoc<0){ cout << "\nError finding record location\n"; return; }

        // if user is winner & has new hiScore, then print their update record
        if(store.start(user)) {                         

            //cout<<"\n\ninside main() user object looks like: ";
            //user.printUsrRec();                       
            //admin.printAdUsr(user.getNumRec());   

            //rewrite this record in binary & text files  
            user.reWrtBin(recordLoc); 
            cout << "\nUser is updating binary file....";         
            admin.readBin_setArray();
            cout << "\nAdmin is reading updated binary file....\n";
            admin.printAdUsr(user.getNumRec());                       
            admin.getCheckout(indx);                        
        } 
    }
}