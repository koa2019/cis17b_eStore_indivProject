
var menu = [
    {name: 'Rainbow Roll',
        inside: 'Imitation crabmeat, cucumber, avocado<br>',
        outside: 'Tuna, salmon, white fish, shrimp, albacore, avocado',
        price: 11.95},
    {name: 'Hot Night Roll',
        inside: 'Shrimp, tempura, imi. crabmeat, cucumer, avocado<br>',
        outside: 'Spicy tuna',
        price: 12.95},
    {name: 'Baked Lobster Roll',
        inside: 'Imitation crabmeat, cucumber, avocado<br>',
        outside: 'Baked crawfish<br>',
        price: 12.95}
];
var menuSize = menu.length;
 
 
//*********************************************************
//              Default Constructor
//*********************************************************
function Store(user) {
   
    console.log("Hit Store Default Constructor");
    this.isComplete = false;
    this.showMenu(user);
    document.getElementById('header').innerHTML = "OISHII SUSHI & TERIYAKI";
    document.getElementById('message-div').innerHTML = 'Welcome ' + user.getName();
    //document.getElementById('submit-cart').addEventListener('click', this.tallyCart);
    
    //user.printUser(); 
}


//*********************************************************
//              Checkout of Store
//*********************************************************
Store.prototype.checkout = function() {
    //console.log("Hit checkout()");
    console.log('Hit checkout().  basket = ' + this.getBasket());    
    console.log('Hit checkout().  totalBasketIems = ' + this.getTotalBasketIems() );   
};


//*********************************************************               
//          Event handler for submit button
//          getElementsByName will not return a value!
//*********************************************************
Store.prototype.tallyCart=function(user){    
    
    console.log("Hit tallyCart()");
    //user.printUser();    
    
    var value = 0;
    var cartTotalCost = 0.0;
    var item0 = document.getElementById('0');
    var item1 = document.getElementById('1');
    var item2 = document.getElementById('2');
    
    // if checkbox is checked on html, then set these variables
    if(item0.checked){
        user.cart.increTotItm();
        value = item0.value *1;
        //console.log('item0.value = ' + value0);
        cartTotalCost += value;
        user.cart.setCartIndx(0,1);
    }
    if(item1.checked){
        user.cart.increTotItm();
        value = item1.value  *1;
        //console.log('item1.value = ' + value1);
        cartTotalCost += value;
        user.cart.setCartIndx(1,1);
    }
    if(item2.checked){
        user.cart.increTotItm();
        value = item2.value  *1;        
        //console.log('item2.value = ' + value2);
        cartTotalCost += value;
        user.cart.setCartIndx(2,1);
    }
    
    //          CHECKOUT
    document.getElementById('submit-cart').style.display = 'none';
    
    // if cart is empty on submit
    if(user.cart.getTotalItems() === 0){
        alert("Your order was not completed."); 
        console.log("Your order was not completed."); 
        this.isComplete = false;
        return this.isComplete;     
    } 
    user.cart.setCartTotalCost(cartTotalCost);
    user.printUser();
    this.isComplete = true; // set flag       
    return this.isComplete; // return true and Admin will confirm files were rewritten 
};


//                 Mutators
//Store.prototype.setBasketIndex = function(i, val) {
//    this.basket[i] = val;
//};
//Store.prototype.setTotalBasketIems = function(num) {
//    this.totalBasketIems = num;
//};

//               Accessors
Store.prototype.getIsComplete = function() {
    return this.isComplete;
};
//Store.prototype.getTotalBasketIems = function() {
//    return this.totalBasketIems;
//};
//Store.prototype.getBasketIndex = function(i) {
//    return this.basket[i];
//};
//Store.prototype.getBasket = function(i) {
//    return this.basket;
//};


//*********************************************************
//               Write menu items to HTML
//*********************************************************
Store.prototype.showMenu=function(user) {

    console.log("Hit showMenu()");
    var div = document.getElementById("menu-Div");
    var form = document.createElement('form');
    form.setAttribute('action', ' ');
    form.setAttribute('id', 'store-Form');
    div.appendChild(form);


    // Write each item and its descriptions to its own html div
    for (var x = 0; x < menuSize; x++) {

        // Create a div to group each question's answers together
        var divItem = document.createElement('div');
        divItem.setAttribute('id', 'item' + x+'-div');
        //divQQ.setAttribute('name','q' + x);
        form.appendChild(divItem);
        
        
        // checkbox for this menu item
        var radio = [menuSize];
        var cost  = menu[x].price;
        radio[x] = this.makeRadio('checkbox', cost, x);
        divItem.append(radio[x]);
        
        var img = document.createElement('img');
        img.setAttribute('src', './assets/img/roll'+x+'.jpg');
        img.setAttribute('width','300px');
        img.setAttribute('height','300px');
        img.setAttribute('alt',menu[x].name);
        divItem.append(img);
        
        // Create h2 element for each question & append node to HTML by div id  
        var h2 = document.createElement('h2');
        h2.innerHTML = (x+1) + '. ' + menu[x].name;
        divItem.append(h2);     
        //console.log(h2);
        
        // Create a label and input for each menu item
        var inside  = menu[x].inside; 
        var outside = menu[x].outside;        
        var label_in;
        var label_out;
        var label_price;
        
        // Append nodes to HTML by appending variable data value to div id 
        label_in = this.makeLabel(inside, x);
        divItem.append(label_in);
        label_out = this.makeLabel(outside, x);
        divItem.append(label_out);
        label_price = this.makeLabel(cost, x);
        divItem.append(label_price);   
    }

    // Create & append a submit button
    var surveyBtn = this.makeBtn('button', 'submit', 'submit-cart',user);
    form.append(surveyBtn);    
};


//*********************************************************
//              Make a submit button   
//*********************************************************
Store.prototype.makeBtn=function(type, val, id,user) {
    var input = document.createElement('button');
    input.setAttribute('type', type);
    input.setAttribute('id', id);
    input.setAttribute('value', val);
    input.setAttribute('onclick', 'store.tallyCart(user)');
    input.innerHTML = val;
    return input;
};


//*********************************************************
//              Make radio input 
//*********************************************************
Store.prototype.makeRadio=function(type, val, itemIndex) {

    var input = document.createElement('input');
    input.setAttribute('type', type);
    input.setAttribute('class', ('item' + itemIndex)); // name attr groups inputs & allows one radio to be selected
    input.setAttribute('id', (itemIndex ));
    input.setAttribute('value', val);
    return input;
};


//*********************************************************
//                 Make label for input     
//*********************************************************
Store.prototype.makeLabel=function(text, ItemIndex) { //create label html element
    var label = document.createElement('label');
    label.setAttribute('for', "q" + ItemIndex);
    label.innerHTML = text;
    return label;
};