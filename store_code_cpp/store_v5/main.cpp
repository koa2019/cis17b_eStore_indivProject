/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 04-22-23 @9PM
 * Purpose: store_v5
  
 store_v5:
 * Refractored Survey class to Store.
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
        <<"4: View Purchase Stats\n"
        <<"5: Reset binary & text files\n"
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
               
                    
                    // Create new instance of NewClass class
                    Store store;
                                 
                    long recordLoc = admin.getBegnFile(indx);
                    
                    if(recordLoc<0){ cout << "\nError finding record location\n"; break; }
                    
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
                break;
            }             
            case 4: // View the Store's chart
            {          
                //cout<<"\tIn main()"; 
                admin.printItemStats();
                //User guest("Guest");                
                //Store sGuest;
                //if(sGuest.start(guest, 0)) { 
                        //cout<<"\n\ninside main() guest object looks like: ";
                        //guest.printUsrRec();   
                        //guest.getCheckout(); // Print checkout 
                //}
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
