#pragma once
#include "Product.h"
#include "Hash.h"
#include <string>

class Inventory
{
private:
    HashTable<std::string, Product> inventory;

public:
    void loadInventory(const std::string &fileName);
    void findItem(const std::string &uniqueID);
    void findByCategory(const std::string &category);

};