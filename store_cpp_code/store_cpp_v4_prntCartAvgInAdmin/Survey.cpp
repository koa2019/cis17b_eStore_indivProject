#include <string>
#include <array>
#include <iostream> // cout
#include <fstream> // fstream
#include <iomanip> // setw()
#include "Survey.h"
#include "Item.h"
#include "Cart.h" 
using namespace std;

//*********************************************************
//              Default Constructor
//*********************************************************
Survey::Survey(){    
    //cout<<"\n Hit Survey Default Constructor\n";
    isTrue = false; 
    itemSize = NUMQQ;
    
    item = new Item*[itemSize]; // Array of Items
    
    for(int i=0; i < itemSize; i++){
        
        item[i] = new Item;
    }
    
    readItemFile();
}

//*********************************************************
//              Destructor
//*********************************************************
Survey::~Survey(){
     //cout << "\n******Change Survey Destructor*****\n";
    delete [] item;
    //delete [] cart;
}


//*********************************************************
//          Start survey
//*********************************************************
bool Survey::start(User &user, const long recordLoc){
    
    //cout<<"\n\tgetCart=" << cart.getCart(3) << endl;
         
    int indx = 0, 
        count = 0,
        num = 0, 
        totalItems = 0;
    float sum = 0.0f;
    
    // Loop through total number of items
    for(int i=0; i < NUMQQ; i++){ 
        cout << "\n\t" << i+1 << ". ";   
        item[i]->printItem(); // Print items     
    }
    
        
    cout << "\nEnter item number or 9 to checkout:   ";
    cin >> indx;   
    
    while ( !(indx==9) ){        
       
        --indx; // Decrement cause array range [0,2]
         
        if(! (indx >= 0 && indx < itemSize) ) {  
            
            cout<<"Invalid Item number. Try again...\n";
            
        } else { // Read quantity of this item they want                       
           
            do { // validate quantity
                
                cout << "How many " << item[indx]->getItem(0) << " do you want? ";
                cin >> num;
                
                if(!(num >= 0 && num <= 3)){ cout<<"Invalid quantity. Try again...\n"; } 
                
            } while(!(num >= 0 && num <= 3));
            
            // Reset cart object. Each indx represents their answer            
            user.cart.setCartIndx(indx,num);
            totalItems += num; 
            sum += (num * item[indx]->getPrice());
            //cout << "\tsum = " << sum << endl;
        }        
        cout << "\nEnter item number or 9 to checkout:  ";
        cin >> indx; 
    } 
        
    isTrue = true; // set flag
    user.cart.setCartSize(totalItems);
    user.cart.setCartTotal(sum);
    
    //   MOVE THIS TO getCheckout()
    cout << "\n\n\t***CHECKOUT***\n\n";
    cout << setw(30) << "Cart Size = " << user.cart.getCartSize() <<endl<<endl; 
    
    for(int i=0; i < NUMQQ; i++){
        
        int num = user.cart.getCartIndx(i);
        
        if(num > 0){
            cout << setw(19) << item[i]->getItem(0);
            cout << setw(3) << "$" << item[i]->getPrice() 
                 << " x " << num 
                 << " = " << (num*item[i]->getPrice()) << endl;
        }
    }
    cout << "-----------------------------------------\n";
    cout << setw(34) << "Total $" << user.cart.getCartTotal() << endl;


    if(!isTrue){ // if player 1 is NOT winner
        
        cout<<"\n\nYour order was not completed!\n"; 
        return false; 
    }
    else {       
        return isTrue; // return true and Admin will confirm files were rewritten
    }
}


//*********************************************************
//
//*********************************************************
void Survey::readItemFile(){
    
    //cout<<"\n Hit Question::readItemFile()\n";
    fstream in;
    in.open("surveyQA.txt", ios::in);
    if(in.fail()){ cout<<"\nError opening surveyQA.txt\n"; exit(0); }


    int i = 0;
    float cost = 0.0f;
    string str0 = "", str1 = "", str2 = "", str3 = "";
     
    
    while(!in.eof()){  // Read until end of file      
        
        getline(in,str0);
        getline(in,str1);
        getline(in,str2);
        in >> cost;
        in.ignore();
        item[i]->setItemArr(str0,str1,str2,cost);  // Reset item class object   
        //item[i].prntQA();
        i++;
    }    
    
    in.close();
}


//******************************************
//      pause screen before continuing
//******************************************
void Survey::pause(char ch) {
    
    string msg = ch=='r' ? "roll" : "continue";    
    cout<<endl<<setw(6)<<' '<<"Press enter to " << msg << ".";   
    cin.get();
}