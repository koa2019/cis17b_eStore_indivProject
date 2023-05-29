const ITEM_SIZE = 3;


//*********************************************************
//              Default Constructor
//*********************************************************
function Item() {
    
    console.log("Hit Item Constructor");
    
//    var menu = [
//        {name: 'Rainbow Roll',
//            inDescrpt: 'imi. crabmeat, cucumber, avocado',
//            outDescrpt: 'Tuna, salmon, white fish, shrimp, albacore, avocado',
//            price: 11.95},
//        {name: 'Hot Night Roll',
//            inDescrpt: 'shrimp, tempura, imi. crabmeat, cucumer, avocado',
//            outDescrpt: 'spicy tuna',
//            price: 12.95},
//        {name: 'Baked Lobster Roll',
//            inDescrpt: 'imi. crabmeat, cucumber, avocado',
//            outDescrpt: 'Baked crawfish',
//            price: 12.95}
//    ];
    
    var menuSize = this.setMenuSize(menu.length);
    //console.log('Item() getMenuSize = ' + this.getMenuSize());
    
    var i = 0;
    var name = this.setItemName(i, "Roll");
    var inside = this.setInside(i,"inside roll");
    var outside = this.setOutside(i,"outside roll");
    var price = this.setPrice(i,0.01);
    //this.consoleItemMembers();

    //i = 1;
//    var item = {this.setItemName(i, "Roll"),
//                this.setInside(i,"inside roll"),
//                this.setOutside(i,"outside roll"), 
//                this.setPrice(i,0.01)};
                
    var item = {name: this.getItemName(), inside: this.getInside(),
                outside: this.getOutside(), price: this.getPrice()};
    //console.log('item.name = ' + item.name);
    //console.log(this.getName());
    //this.consoleItem();

   // for (var i = 0; i < this.menuSize; i++) {
        
        
//        item[i].name = 'Item ' + i;
//        item[i].inDescrpt = 'inside roll description  ' + i;
//        item[i].outDescrpt = 'outside roll descrption  ' + i;
//        item[i].price = (1.00 + i);
//        item[i] = {name: 'Item ' + i,
//                        inDescript: 'inside roll description ' + i,
//                        outDescript: 'outside roll descrption ' + i,
//                        price: (1.00 + i)};
        
        //this.consoleItem(i);
        //console.log(item[i].name);
        //console.log(item[i].inDescript);
        //console.log(item[i].outDescript);
        //console.log('Price: ' + item[i].price);
        //console.log(" ");
    //}

}

//*********************************************************
//                      Mutators
//*********************************************************
Item.prototype.setMenuSize = function (n) {
    this.menuSize = n;
};
Item.prototype.setItemName = function (i, str) {
    this.name = str + i;  //this.item[i].name = str;
};
Item.prototype.setInside = function (i, str) {
    this.inside = str + i;  //this.item[i].name = str;
};
Item.prototype.setOutside = function (i, str) {
    this.outside = str + i;  //this.item[i].name = str;
};
Item.prototype.setPrice = function (i,p) {
    this.price = p;
};


//*********************************************************
//                      ACCESSOR FUNCTIONS
//*********************************************************


Item.prototype.getMenuSize = function () {
    return this.menuSize;
};

Item.prototype.getItemName = function (i) {
    return this.name;//this.item[i].name;
};

Item.prototype.getInside = function (i, str) {
    return this.inside;
};

Item.prototype.getOutside = function (i, str) {
    return this.outside;
};

Item.prototype.getPrice = function () {
    return this.price;
};


//****************************************
//     Get 
//****************************************
Item.prototype.consoleItemMembers = function () {
    console.log('getItemName = ' + this.getItemName());
    console.log('getInside   = '   + this.getInside());
    console.log('getOutside  = '  + this.getOutside());
    console.log('getPrice    = '   + this.getPrice());
    console.log(" ");
};

Item.prototype.consoleItem = function () {
    console.log(this.item.name);
    console.log(this.item.inside);
    console.log(this.item.outside);
    console.log(this.item.price);
};

Item.prototype.printItem = function (divName) {

//    var menuDiv = document.getElementById('menuDiv');
//    var p = document.createElement('p');
//    p.setAttribute('name', 'item-name');
//    p.innerHTML = (i + 1) + ". " + menu[i].name + "\n";
//    menuDiv.appendChild(p);
};