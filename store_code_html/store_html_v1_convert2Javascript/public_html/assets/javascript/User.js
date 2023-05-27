/* 
 
*/
// Item Variables
const SIZE = 3;


// Default constructor  Called in Yahtzee.html
function User(){   
    console.log("Hit User Default constructor");
    this.numRec = 0;
    this.name="Guest";
    this.email="email@email.com";
    this.password="password";  
    this.cartSize=SIZE;    
    
    // Create new Cart Object
    this.cart = new Array();
    this.cart = new Cart();
    //this.cart.printCart();
}

//To String function of the ScoreCard Class
User.prototype.printUser=function(){
    console.log("numRec   = " + this.getNumRec());
    console.log("name     = " + this.getName());
    console.log("email    = " + this.getEmail());
    console.log("password = " + this.getPassword());
    console.log("cartSize = " + this.getCartSize());
    this.cart.printCart();
};



//*****************************************************
//                      Mutators
//*****************************************************
User.prototype.setNumRec=function(num) { 
    this.numRec = num; 
};

User.prototype.setName=function(str){
    this.name = str;
};

User.prototype.setEmail=function(str){
    this.email = str;
};

User.prototype.setPassword=function(str){
    this.password = str;
};

User.prototype.setCartSize=function(s) {
    this.cartSize = s; 
};


//*****************************************************
//                      Accessors
//*****************************************************
User.prototype.getNumRec=function(){
    return this.numRec;
};

User.prototype.getName=function(){
    return this.name;
};

User.prototype.getEmail=function(){
    return this.email;
};

User.prototype.getPassword=function(){
    return this.name;
};

User.prototype.getCartSize=function(){
    return this.cartSize;
};


/******************************************************************/              
//                  REWRITE 1 RECORD TO BINARY FILE     
/*****************************************************************/

User.prototype.reWrtRecord=function(){
    console.log("Hit reWrtRecord()");
};