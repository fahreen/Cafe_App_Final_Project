# APP Specifications


## Description
The goal of this project is to develop a software that manages a cafe.  The design will take into consideration the food they offer along with its prices, inventory, order history, transactions, till cash balance and employee information.  It will aid in managing the inventory, staff and transactions. 



## Features
Name          |Description
------------- | -------------
Food and drink offerings  |Stores the food and drink items that the restaurant offers.
Food and drink pricing |Stores the prices information about the food and drink items. Prices can also be updated based on promotions.
Stock |Keeps track of the inventory/stock of the items that the restaurant carries. Allows the user to see which items are currently in stock and which need to be reordered
Deals/coupons |Stores information about coupons and deals the restaurant is currently offering. Also allows deals/coupons to be applied to transactions
Initial stock and price setup with CSV file |  Simplify the initial setup of the system by letting the user input a CSV to automatically populate the system.
Order history of each product  |Allow the user to make orders for items out of stock and keep track of the order history for each item. Also keeps track of the items that have been received and items that are still waiting for shipment
Transactions and transaction history | Stores the transaction history of each item. This will allow the user to see how popular an item is in the restaurant. It can also keep track of the daily transactions made to understand profitability
Till cash balance |Keep track of the cash balance at each till in the restaurant. It will get updated based on the transactions done at that till
Different UI for different Users (employee, manager) | Have different interfaces for employees and managers to restrict access to certain information to employees
List of employees and managers in the system  | Store information about the current employees and managers of the restaurant



User Stories |
------------- | 
 As an administrator, I can input the product information and inventory to a CSV file so that I can setup the initial system. Test with a non-CSV file. Can view the details of items that were initially put in the system|
 As manager, I can add or remove a food/drink offering from the system, Add an item to the system and view the details of it, Remove an item from the system and make sure the details are not shown|
As a manager or employee, I can view the full list of items that are in stock to know when to reorder them, Inventory is updated after each transaction in the list, The details of an item that is in the system can be viewed from the csv file inputted |
As a manager or employee, I can search up a specific food or drink item to know if it is available and the price, View details about all items and it matches the CSV file, Employee/ manager looks up a food which doesn’t exist, Can get a list of food/drinks in the system |
As a manager, I can change the inventory information for each food/drink to update the stock information, After a new order arrives the inventory is updated, After an item removed from the system, the inventory is set to 0 | 
As a manager, I can change the price of the food or drink item, After manager changes price, system/menu is updated accordingly, Employee tries to change the price of a food item, Manager sets negative price, Tries to change the price of an item that doesn’t exist in stock |
As a manager or employee I can view the order history to know when which orders are pending, Place an order and view that it was added to the order history, Mark an order as received and view that the order history was updated, Cancel an order and view that the order history was update |
As a manager, I can reorder items that are out of/ low in stock, Employee tries to reorder an item, Manager tries to reorder an item that doesn’t exist in the database |
As a manager, I can view the transaction history of an item to know how well an item is doing, Order an item a few times and see that it shows in the transaction history | 
As a manager or employee, I can process transactions, Added to list of transaction history, Transaction is made with an invalid gift card or gift card with insufficient funds |
As an employee or manager, I can apply coupons to transactions, if invalid coupon is applied system must reject, Till does not display sale price of item |
As an employee or manager, I can view transaction history to monitor daily profits, A correct transaction history is returned, Complete a transaction and see that it was added to the transaction history |
As a manager or employee, I can view which items are currently on sale so that the price can be adjusted during checkout, Price of discounted item is the same price as one in CSV file, Coupon is applied and the transaction shows that the correct price was used, Manager or employee looks up an item that does not exist| 
As a manager, I can add or remove employees or managers, if employee tries to add or remove employee or manager they are denied access, If manager tries to remove employee/manager that does not exist in the system they are notified, If manager adds an employee/manager and this person appears in the list of employees/managers do not add them | 
As a manager or employee, I can see the cash balance of the till, I can complete a transaction at a till and view that the balance was updated |
As an employee, I can login to an interface that allows me to view food/drink offerings, prices, keep track of stock and process transactions, Correct password/username login by employee(pass), Wrong password/username login attempt(fail). The employee cannot view the order histories, transaction histories, list of employees/managers, current stock list |
As a manager, I can log into a special interface so that I can see the employee interface as well as stock, food/price offering, sales history per item, order history, transaction history and a list of employees/managers, Correct password/username login by employee(pass), Wrong password/username login attempt(fail), The employee interface can be viewed perform transactions, Can access special features (sales history, order history, transaction history and list of employees/managers) | 

# Instructions

## Compile the program using the command

	 g++ -o run main.cpp StockManager.cpp OrderManager.cpp Order.cpp User.cpp StaffManager.cpp FileLoader.cpp ItemLoader.cpp UserDataLoader.cpp InventoryManager.cpp Price.cpp MenuItem.cpp PromoLoader.cpp Coupon.cpp CouponManager.cpp

## Run the program using the command

	./run

## Enter commands

You will be promted to enter commands.

First command should be to initialize staff an inventory, enter the commands:

#### Initialize the staff information in the system with details provided from the csv (employees.csv). Note this sample csv is provided with some sample data. It can be updated to include more data or remove some data but should follow the same format.
	Initialize staff

#### Initialize the inventory information in the system with details provided from the csv (foodinventory.csv).Note this sample csv is provided with some sample data. It can be updated to include more data or remove some data but should follow the same format.
	Initialize inventory
    
#### Initialize the promo information in the system with details provided from the csv (promos.csv).Note this sample csv is provided with some sample data. It can be updated to include more data or remove some data but should follow the same format.
	Initialize promos
    
Then you may proceed to enter any valid commands (case sensitive) with the right amount of arguments.  Or exit to exit. 

## Valid Commands: 
	
#### Add a new item to the invetory by providing the name of the item, the id, the price, the current inventory being added, the minimum inventory to maintain and the list of ingredients(comma separated, no spaces)
	addNewItem arg1(string name) arg2(string id) arg3(double price) arg4(int currentInventory) arg5(int minimumInventory) arg6(string ingredients)
	example: addNewItem item1 123 2.00 12 1 egg	

#### Print the details of a specific menu item by providing the name
	printMenuItem arg1(string itemName)
	example: printMenuItem item1
    
#### Update the price of a specific menu item by providing the name and the new price
	updatePrice arg1(string itemName) arg2(double price)
	example: updatePrice item1 12.00

#### Print all the items with their details currently in the inventory (available in the menu)
	printMenu

#### Remove an item from the inventory by providing the name of the item
	removeItem arg1(string itemName)
	example: removeItem item1	

#### Print all the employees and managers currently registered in the system
	printAllStaff

#### Print all the managers currently registered in the system
	printManagers
    
#### Print all the employees currently registered in the system
	printEmployees

#### Add a new employee to the system by providing their id, firstname, lastname, type (either: "manager" or "employee") and their password
	addUser arg1(string id) arg2(string firstname) arg3(string lastname) arg4(string type) arg5(string password)
	example: addUser 200118 Peter Black employee whiskers

#### Remove a user from the system by providing their userId
	removeUser arg1(string userId)
	example: removeUser 200118

#### Print all the coupons currently in the system
	printAllCoupons
    
#### Print a coupon currently in the system by providing its code
	printCoupon arg1(string couponCode)
    example: printCoupon Coupon1

#### Add a new promo to the system by providing the desired name of the promo and the discount amount
	addNewPromo arg1(string couponCode, double discount)
    example: addNewPromo Coupon5 3.5

#### Remove a coupon from the system by providing its code
	removeCoupon arg1(string couponCode)
    example: removeCoupon Coupon1

#### Create an order by providing an item name and the quanitity for the order
	createOrder arg1(string itemName) arg2(int quantity)
    example: createOrder Tea 50

#### Mark and order as received by providing the order id
	receiveOrder arg1(int orderId)
    example: receiveOrder 0

#### Mark and order as cancelled by providing the order id
	cancelOrder arg1(int orderId)
    example: cancelOrder 0

#### Print a list of all the orders (pending, received and cancelled)
	printOrders
    example: printOrders

#### Print a list of all items that are in stock
	inStock
    example: inStock

#### Print a list of all items that are out of stock
	outOfStock
    example: outOfStock

#### Print a list of all items that are below threshold
	belowThresh
    example: belowThresh

#### Print if a specific item is in stock 
	itemInStock arg1(string itemName)
    example: itemInStock Tea

#### Print if a specific item is below the threshold 
	itemThresh arg1(string itemName)
    example: itemThresh Tea

#### Increase the inventory level of an item
	incStock arg1(string itemName) arg2(int quantityToIncreaseBy)
    example: incStock Tea 50

#### Decrease the inventory level of an item
	incStock arg1(string itemName) arg2(int quantityToDecreaseBy)
    example: decStock Tea 50
#### Retrieve a instance pointer
	instance()

#### This clears the old Tills then sets the Tills to the input
	setTills(vector <Till> tills)
    example: setTills tills
    
#### This prints all the tills
	printAllTills()
    
#### This prints a specific till based on ID
	printTill(string Id)
    example: printTill ID1
    
#### This adds a till by giving a till object
	addTill(Till till)
    example: addTill tillObject
    
#### This removes a specific till based on ID
	removeTill(std::string Id)
    example: removeTill ID1
    
#### This removes a specific till based on till object
	removeTill(Till till)
    example: removeTill tillObject
    
#### This finds a specific till based on ID
	findTill(std::string id)
    example: removeTill ID1
    
#### This creates a till based on ID and balance
	Till (string id, double cashBalance)
    example: Till ID1 0
    
#### This returns the ID of a till
	getId()
    
#### This returns the balance of a till
    getCashBalance()
    
#### This sets the balance of a till
	setCashBalance(double balance)
    example: setCashBalance 0
    
#### This returns a instance of a sales manager
	instance()
    
#### This creates list of all on sales objects
	getSaleItems()
    
#### This prints off all on sale objects
	printAllSaleItems()
    
#### This prints off a specific sales object based on item name
	printSaleItem(string itemName)
    example: printSaleItem gouda
    
#### This finds a specific on sale item based on its name
	findSaleItem(string name)
    example: findSaleItem gouda

## Example
The following is a sequence of working commands. An example use of the interface is given. The following commands can be copied into the terminal after running `./run` one line at a time.


    Initialize staff
    Initialize inventory
    Initialize promos
    addNewItem item1 123 2.00 12 1 egg
    printMenu	
    printMenuItem item1
    updatePrice item1 12.00
    printMenuItem item1
    removeItem item1
    printMenuItem item1
    printMenu
    printAllStaff
    printManagers
    printEmployees
    addUser 200118 Peter Black employee whiskers
    printEmployees
    removeUser 200118
    printEmployees
    printAllCoupons
    printCoupon Coupon1
    addNewPromo Coupon5 3.5
    removeCoupon Coupon5
    exit
## User stories

## 1) As a manager, I am provided with a sample CSV file that can be used to populate the inventory
## 2)As an administrator, I can input the product information and inventory to a CSV file so that I can setup the initial system
Acceptance Tests: 
1)When "Initialize Inventory" is called all items file are read succesfully without segementation faults or type mismatch(pass) --> no segemntation errors occured, no type mismatch
2)Can view the details of items that were initially put in the system (pass) --> all menu items printed succesfully from the inventory manager

	Initialize inventory
    
## 3) As a manager, I am provided with a sample CSV file that can be used to populate the staff list
## 4)As an administrator, I can input the staff information and inventory to a CSV file so that I can setup the initial system
Acceptance Tests: 
1)When "Initialize staff" is called all items file are read succesfully without segementation faults or type mismatch(pass) --> no segemntation errors occured, no type mismatch
2)Can view the details of items that were initially put in the system (pass) --> all staff information is printed succesfully from the inventory manager

	Initialize staff

## 5) As manager, I can add or remove a food/drink offering from the system
Acceptance Tests: 
5.1)Add an item to the system and view the details of it (pass)
5.2) add pre-esisting item (fail)
5.3)Remove an item from the system and make sure the details are not shown (pass)

	addNewItem item2 124 3.00 17 1 egg	
    addNewItem item2 124 3.00 17 1 egg
    removeItem item2
    printMenuItem item2
    printMenu
    

## 6) As a manager or employee, I can search up a specific food or drink item to know if it is available and the price 
Acceptance Tests: 
6.1)View details about all items and it matches the CSV file(pass) --> all items created mach those entered in CSV file
6.2) Employee/ manager looks up a food which doesn’t exist (fail) --> user is notified food doesnt exit
6.3) Can get a list of food/drinks in the system (pass)--> prints a list of the menu
	
    addNewItem item3 125 3.00 17 1 egg
    printMenuItem item3
    printMenuItem fakeitem
    

## 7) As a manager, I can change the price of the food or drink item
Acceptance Tests: 
After manager changes price, system/menu is updated accordingly(pass) --> item appears on menu with new price
	
    addNewItem item4 125 3.00 2 1 egg
    printMenuItem item4
    updatePrice item4 12.00
    

## 8 ) As a manager or employee I can see a full list of inventory items
Acceptance Tests: 1) List of items are formatted correctly and mamcth csv file, and includes any additional items(pass)​--> yes

     printMenu
     
     
## 9) As a manager, I can add or remove employees or managers
9.1) User adds employee and can see it in the list of employees(pass)
9.2) User tries to add an employee with an existing ID but sees an error message (fail)
9.3) User removes employee and can see that the employee is removed when printing the list of employees (pass)
9.4) User tries to remove an employee thats not in the system but sees an error message(fail)
    
    addUser 200119 Charlie Black employee whiskers
    printEmployees
   	addUser 200119 Charlie Black employee whiskers
    removeUser 200119
    printEmployees
    removeUser 200119 

## 10) As a manager or employee I can view the list of orders 
Acceptance Tests: 
10.1) Without placing an order, see that there are 3 empty lists displayed - pending orders, received orders and cancelled orders (pass)
10.2) Place an order and view that it was added to the list of orders as pending (pass)

    Initialize inventory
    printOrders
    createOrder Tea 10
    printOrders

## 11) As a manager, I can place orders for items in the inventory to refill the stock
Acceptance Tests: 
11.1) Order an existing item with a positive quantity (pass)
11.2) Order an existing item with a negative or zero quantity (fail)
11.3) Order an item  that does not exist (fail)

    Initialize inventory
    createOrder Tea 10
    printOrders
    createOrder Tea -100
    createOrder TeaInvalid 100

## 12) As a manger, I can mark orders as received to keep track of what has arrived in store and update the inventory
Acceptance Tests: 
12.1) Place an order, mark it as received and view that it was placed in the order received list (pass)
12.2) Place an order, mark it as received and view that inventory amount was increased (pass)
12.3) Mark an order as received after it was already received or cancelled (fail)
12.4) Mark an order with an invalid order ID as received (fail)
    Initialize inventory
    createOrder Tea 10
    receiveOrder 0
    printOrders
    createOrder Tea 100
    receiveOrder 0
    receiveOrder 1
    receiveOrder 10

## 13) As a manger, I can mark orders as cancelled to keep track of order that will not arrive at the store
Acceptance Tests: 
13.1) Place an order, mark it as cancelled and view that it was placed in the order cancelled list (pass)
13.2) Mark an order as cancelled after it was already received or cancelled (fail)
13.3) Mark an order with an invalid order ID as cancelled (fail)
    Initialize inventory
    createOrder Tea 10
    cancelOrder 0
    printOrders
    createOrder Tea 100
    cancelOrder 0
    cancelOrder 1
    cancelOrder 10

## 14) As a manager I can see a warning when an items inventory falls below its minimum threshold during regular operation
Acceptance Tests: 
14.1) Decrease the inventory of an item to a value below the threshold (pass)
14.2) Decrease the inventory of an item to a value above the threshold (fail)
    Initialize inventory
    decStock Tea 10
    decStock Tea 400

## 15) As a manager, I can update the inventory level for each food/drink to keep track of the stock
Acceptance Tests: 
15.1) Increase the inventory amount of an item and see that its updated (pass)
15.2) Decrease the inventory amount of an item and see that its updated (pass)
    Initialize inventory
    decStock Tea 10
    incStock Tea 100

## 16) As a manager, I can verify if a specific item isbelow the minimum threshold to know if I should re-order it
Acceptance Tests: 
16.1) Check if an invalid item is in stock then verify that an error is shown and it is displayed as below the threshold (fail)
16.2) Check if a valid item is in stock then verify that it displayed as above the minimum threshold (pass)
16.3) Reduce the inventory of a valid item to below a minimum threshold, then verify that it displayed as below the threshold (fail)
    Initialize inventory
    itemThresh invalidItem
    itemThresh Tea
    decStock Tea 450
    itemThresh Tea

## 17) As a manager, I can verify if a specific item is in stock to know if I should re-order it
Acceptance Tests: 
17.1) Check if an invalid item is in stock then verify that an error is shown and it is displayed as out of stock (fail)
17.2) Check if a valid item is in stock then verify that it displayed as in stock (pass)
17.3) Reduce the inventory of a valid item to 0, then check if it is in stock then verify that it displayed as out of stock (fail)
    Initialize inventory
    itemInStock invalidItem
    itemInStock Tea
    decStock Tea 500
    itemInStock Tea

## 18) As a manager, I can see a list of items that are in Stock, out of Stock and below a minimum Threshold to determine if I should order more inventory
17.1) Fill in the inventory with items that are in stock, then print an view that all items are in stock, none of the items are out of stock and no items are below threshold (pass)
17.2) Reduce the inventory of a valid item to 0 and see that it only appears in the out of stock and below threshold lists (pass)
17.3) Reduce the inventory of a valid item to below the minimum threshold and see that it only appears in the in stock and below threshold lists(pass)
    Initialize inventory
    inStock
    outOfStock
    belowThresh
    decStock Tea 500
    inStock
    outOfStock
    belowThresh
    incStock Tea 50
    inStock
    outOfStock
    belowThresh

## 19) As a user, I can interact with the system through a command line inteface
Acceptance Tests: 

    Initialize staff
    Initialize inventory
    addNewItem item1 123 2.00 12 1 egg
    printMenu	
    printMenuItem item1
    updatePrice item1 12.00
    printMenuItem item1
    removeItem item1
    printMenuItem item1
    printMenu
    printAllStaff
    printManagers
    printEmployees
    addUser 200118 Peter Black employee whiskers
    printEmployees
    removeUser 200118
    printEmployees
    exit
