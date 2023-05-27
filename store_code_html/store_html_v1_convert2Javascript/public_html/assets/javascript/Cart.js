const CSIZE = 3;

//*********************************************************
//                  Default Constructor
//*********************************************************
function Cart(){ 
    console.log("Hit Cart Default Constructor");
    this.setCartSize(CSIZE);//this.cartSize = CSIZE;
    this.setTotalItems(0);
    this.cart = [CSIZE];
    for(var i=0; i < CSIZE; i++){
        this.cart[i] = 0;
    }
    this.setCartTotalCost(0.0);
    //this.printCart();
}

 // Mutators
Cart.prototype.setCartSize=function(s){ this.cartSize = s; };
Cart.prototype.setCartTotalCost=function(t){ this.cartTotalCost = t; };
Cart.prototype.setTotalItems=function(n) { this.totalItems = n; };
Cart.prototype.setCartIndx=function(i, value){ this.cart[i] = value; };
Cart.prototype.setCartArr=function(){};            // Sets cart elements to random #'s
Cart.prototype.setCartArr=function(a,b,c){}; // sets cart elements to these integers
Cart.prototype.increTotItm=function(){ this.totalItems++; };
    
    
// Accessors
Cart.prototype.getCart=function() { return this.cart; };
Cart.prototype.getCartIndx=function(i) { return this.cart[i]; };
Cart.prototype.getCartSize=function() { return this.cartSize; }; 
Cart.prototype.getTotalItems=function() { return this.totalItems; };
Cart.prototype.getCartTotalCost=function(){ return this.cartTotalCost.toFixed(2); };
Cart.prototype.printCart=function(){
    //console.log('cart[0] = ' + this.getCartIndx(0));
    //console.log('cart[1] = ' + this.getCartIndx(1));
    //console.log('cart[2] = ' + this.getCartIndx(2));
    console.log('cart[ ' + this.getCart() + " ]\n"
    + 'getCartSize = ' + this.getCartSize() 
    + '\ngetTotalItems = ' + this.getTotalItems()
    + '\ngetCartTotalCost  $' + this.getCartTotalCost());
};