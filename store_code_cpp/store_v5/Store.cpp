#include "Store.h"
using namespace std;

//*********************************************************
//              Default Constructor
//*********************************************************
Store::Store(){    
    //cout<<"\n Hit Store Default Constructor\n";
    isTrue = false; 
    itemSize = NUMITEMS;
    
    item = new Item*[itemSize]; // Array of Items
    
    for(int i=0; i < itemSize; i++){        
        item[i] = new Item;
    }
    
    readItemFile(); // Read item and it's description from file
}

//*********************************************************
//              Destructor
//*********************************************************
Store::~Store(){
     //cout << "\n******Change Store Destructor*****\n";
    delete [] item;
}


//*********************************************************
//          Start survey
//*********************************************************
bool Store::start(User &user){
    
    //cout<<"\n\tgetCart=" << cart.getCart(3) << endl;
         
    int indx = 0, 
        quantity = 0, 
        totalItems = 0;
    int tempArr[NUMITEMS];
     
    // Print all items
    for(int i=0; i < NUMITEMS; i++){ 
        tempArr[i] = 0;
        cout << "\n\t" << i+1 << ". ";   
        item[i]->printItem(); // Print items     
    }
       
    // Get User's order
    cout << "\nEnter item number or 9 to checkout:   ";
    cin >> indx;   
    
    while ( !(indx==9) ){  // while not exit flag      
       
        --indx; // Decrement cause array range [0,2]
         
        if(!(indx >= 0 && indx < itemSize)) { cout<<"Invalid Item number. Try again...\n"; }
            
        else { // Read quantity of this item they want                       
           
            do { // validate quantity
                
                cout << "How many " << item[indx]->getItem(0) << " do you want? ";
                cin >> quantity;
                
                if(!(quantity >= 0 && quantity <= 100)){ cout<<"Invalid quantity. Try again...\n"; } 
                
            } while(!(quantity >= 0 && quantity <= 100));            
           
            tempArr[indx] = quantity;// set temp cart array          
        }        
        cout << "\nEnter item number or 9 to checkout:  ";
        cin >> indx; 
    } 
    
    
    // When user is finished selecting their items, then save their items to their cart.
    // Processing the tempArr outside of the input loops to fix  
    // BUG: Cart::cartTotal not adjusting total when item quantity is updated in survey.
    for(int i=0; i < NUMITEMS; i++){
       
        if(tempArr[i] > 0){          
            user.cart.setCartIndx(i,tempArr[i]);  // Reset cart object. 
            totalItems += tempArr[i];        
        } else { user.cart.setCartIndx(i,0); }  // Reset cart object.
    }
    
    // if cart is empty exit
    if(totalItems == 0){
        cout<<"\n\nYour order was not completed.\n"; 
        isTrue = false;
        return isTrue;        
    } 
    
    // Reset variable values in Cart class
    isTrue = true; // set flag       
   return isTrue; // return true and Admin will confirm files were rewritten 
}


//*********************************************************
//
//*********************************************************
void Store::readItemFile(){
    
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
void Store::pause(char ch) {
    
    string msg = ch=='r' ? "roll" : "continue";    
    cout<<endl<<setw(6)<<' '<<"Press enter to " << msg << ".";   
    cin.get();
}