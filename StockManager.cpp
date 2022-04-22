#include <iostream>
#include<string>
#include <vector>
#include "StockManager.h"
#include "MenuItem.h"
#include "InventoryManager.h"
#include "OrderManager.h"

using namespace std;

StockManager * StockManager:: _instance=NULL; 

StockManager::StockManager(StockManager& other){
    ;
}

StockManager& StockManager:: operator= (StockManager other){
    ;
}

StockManager::StockManager(){
    ;
}

StockManager &StockManager::instance()
{
    if (_instance == NULL){
        _instance = new StockManager();
    }
    return *_instance;
}

StockManager:: ~StockManager(){
    ;
}

//return current stock if successful, return -1 if unsuccessful
int StockManager::addStock(string itemName, int increaseBy){
    MenuItem *item;
    item = InventoryManager::instance().findMenuItem(itemName);
    if((item->getId()).compare("-1") ==0){
        cout <<"The item does not exist, therefore its stock level couldn't be increased."<<endl;
        delete item;
        return -1; //return -1 if the items stock couldnt be updated
    }else{
        int currInventory=item->getCurrentInventory();
        int newInventory = currInventory + increaseBy;
        item->setCurrentInventory(newInventory);
        cout <<"Inventory for "<<itemName<<" updated:"<<endl;
        cout <<"Initial Inventory: "<<currInventory<<endl;
        cout <<"Increased By: "<<increaseBy<<endl;
        cout <<"New Inventory: "<<newInventory<<endl;
        return item->getCurrentInventory();
    }
}

//return current stock if successful, return -1 if unsuccessful
//print a warning if it goes below the threshold
int StockManager::removeStock(string itemName, int decreaseBy){
    MenuItem *item;
    item = InventoryManager::instance().findMenuItem(itemName);
    if((item->getId()).compare("-1") ==0){
        cout <<"The item does not exist, therefore its stock level couldn't be decreased."<<endl;
        delete item;
        return -1; //return -1 if the items stock couldnt be updated
    }else{
        int currInventory=item->getCurrentInventory();
        int newInventory = currInventory - decreaseBy;
        if(newInventory<0){
            cout <<"Not enough inventory to perform action for: "<< itemName<<endl;
            cout <<"Initial Inventory: "<<currInventory<<endl;
            cout <<"Cannot Decrease By: "<<decreaseBy<<endl;
            return -1;
        }else{
            item->setCurrentInventory(newInventory);
            cout <<"Inventory for "<<itemName<<" updated:"<<endl;
            cout <<"Initial Inventory: "<<currInventory<<endl;
            cout <<"Decreased By: "<<decreaseBy<<endl;
            cout <<"New Inventory: "<<newInventory<<endl;
            if (newInventory<(item->getMinimumInventory())){
                cout << "WARNING: Inventory has fallen below the minimum threshold: "<<item->getMinimumInventory()<<endl;
            }
            return item->getCurrentInventory();
        }
    }
}

bool StockManager::isInStock(string itemName){
    MenuItem *item;
    item = InventoryManager::instance().findMenuItem(itemName);
    if((item->getId()).compare("-1") ==0){
        cout <<"The item does not exist, therefore its not in stock."<<endl;
        delete item;
        return false; //return -1 if the items stock couldnt be checked
    }else{
        int currInventory=item->getCurrentInventory();
        if(currInventory<=0){
            return false;
        }
        return true;
    }
}

bool StockManager::isBelowThreshold(string itemName){
    MenuItem *item;
    item = InventoryManager::instance().findMenuItem(itemName);
    if((item->getId()).compare("-1") ==0){
        cout <<"The item does not exist, therefore its not in stock."<<endl;
        delete item;
        return true; //return -1 if the items stock couldnt be checked
    }else{
        int currInventory=item->getCurrentInventory();
        if(currInventory<(item->getMinimumInventory())){
            return true;
        }else{
            return false;
        }
    }
}

vector<MenuItem> StockManager::getListOfItemsInStock(){
    vector<MenuItem> allItems = InventoryManager::instance().getMenuItems();
    vector<MenuItem> inStock;
    for (unsigned int i = 0; i < allItems.size(); i++) {
        if(isInStock(allItems[i].getName())){
            inStock.push_back(allItems[i]);
        }
    }
    return inStock;
}

vector<MenuItem> StockManager::getListOfItemsOutOfStock(){
    vector<MenuItem> allItems = InventoryManager::instance().getMenuItems();
    vector<MenuItem> outOfStock;
    for (unsigned int i = 0; i < allItems.size(); i++) {
        if(!isInStock(allItems[i].getName())){
            outOfStock.push_back(allItems[i]);
        }
    }
    return outOfStock;
}

vector<MenuItem> StockManager::getListOfItemsBelowThreshold(){
    vector<MenuItem> allItems = InventoryManager::instance().getMenuItems();
    vector<MenuItem> belowThreshold;
    for (unsigned int i = 0; i < allItems.size(); i++) {
        if(isBelowThreshold(allItems[i].getName())){
            belowThreshold.push_back(allItems[i]);
        }
    }
    return belowThreshold;
}

void StockManager::printItemsInStock(){
    cout <<"PRINTING IN STOCK ITEMS"<<endl;
    vector<MenuItem> itemsInStock = getListOfItemsInStock();
    for (unsigned int i = 0; i < itemsInStock.size(); i++) {
        InventoryManager::instance().printMenuItem(itemsInStock[i].getName());
    }
}

void StockManager::printItemsOutOfStock(){
    cout <<"PRINTING OUT OF STOCK ITEMS"<<endl;
    vector<MenuItem> itemsOutOfStock = getListOfItemsOutOfStock();
    for (unsigned int i = 0; i < itemsOutOfStock.size(); i++) {
        InventoryManager::instance().printMenuItem(itemsOutOfStock[i].getName());
    }
}

void StockManager::printItemsBelowThreshold(){
    cout <<"PRINTING ITEMS THATS ARE BELOW THRESHOLD"<<endl;
    vector<MenuItem> itemsBelowThresh = getListOfItemsBelowThreshold();
    for (unsigned int i = 0; i < itemsBelowThresh.size(); i++) {
        InventoryManager::instance().printMenuItem(itemsBelowThresh[i].getName());
    }

}