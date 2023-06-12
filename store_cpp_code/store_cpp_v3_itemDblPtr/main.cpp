/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 04-13-23 @8PM
 * Purpose: store_v3_itemDblPtr
  
 store_v3_itemDblPtr:
 *  Made Survey::Item item[] **item;
 * Printed checkout totals in Survey::start()
  
 To Do: 
 * Print Cart averages in Admin
 * BUG: Cart::cartTotal not adjusting total when item quantity is updated in survey.
 * Put checkout in a function instead of inside Survey::start()
 * Move **item from Survey class to Item class.
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
#include "Survey.h"

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
        <<"4: View Survey Chart\n"
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
                    //admin.printAdUsr(indx);                    
                    
                    
                    // Create new User & copy admin values to user                    
                    admin.copy2Usr(user,indx);    
                    cout << "\nWelcome " << user.getName();
                    //user.printUsr(); 
                    admin.printAdUsr(user.getNumRec()); 
               
                    
                    // Create new instance of NewClass class
                    Survey survey;
                                 
                    long recordLoc = admin.getBegnFile(indx);
                    
                    if(recordLoc<0){ cout << "\nError finding record location\n"; break; }
                    
                    // if user is winner & has new hiScore, then print their update record
                    if(survey.start(user, recordLoc)) {                         
                        
                        cout<<"\n\ninside main() user object looks like: ";
                        user.printUsrRec();                       
                        admin.printAdUsr(user.getNumRec());   
                          
                        //rewrite this record in binary & text files  
                        user.reWrtBin(recordLoc); 
                        cout << "\nUser is updating binary file....";         
                        admin.readBin_setArray();
                        cout << "\nAdmin is reading updated binary file....\n";
                        admin.printAdUsr(user.getNumRec());
                        cout << "Survey Results\n";
                        admin.getPrntCart();
                    }                                                    
                }
                break;
            }             
            case 4: // View the Survey's chart
            {          
                //cout<<"\tIn main()"; 
                //admin.printtCart();
                User guest("Guest");
                
                Survey sGuest;
                if(sGuest.start(guest, 0)) {                         
                        
                        cout<<"\n\ninside main() guest object looks like: ";
                        guest.printUsrRec();   
                        //guest.getCheckout(); // Print checkout 
                }
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
