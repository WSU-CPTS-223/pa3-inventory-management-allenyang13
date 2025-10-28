#include "Inventory.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Inventory::loadInventory(const std::string &fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "File open errors\n";
        return;
    }

    std::string line;
    getline(file, line);

    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string id, name, temp, categories;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, temp, ',');
        getline(ss, temp, ',');

        ss >> std::ws;
        if (ss.peek() == '"') 
        {
            ss.get(); 
            std::getline(ss, categories, '"'); 
            if (ss.peek() == ',') ss.get(); 
        } 
        else 
        {
        std::getline(ss, categories, ',');
        }


if (categories.empty()) categories = "NA";

        if(categories.empty())
            categories = "NA";

        Product product(id, name, categories);
        inventory.insert(id, product);
    }

    std::cout << "Loaded Inventory\n";
}

void Inventory::findItem(const std::string &uniqueID)
{
    Product* product = inventory.find(uniqueID);
    if (!product)
    {
        std::cout << "Product doesn't exist\n";
        return;
    }

    std::cout << "Product #" << product->id << '\n';
    std::cout << "Name: " << product->itemName << '\n';
    std::cout << "Categories: " << product->categories << '\n';
}

void Inventory::findByCategory(const std::string &category)
{
    bool itemFound = false;

    inventory.functionCallAll([&](const std::string &, const Product &product)
    {
        if (product.findCategory(category))
        {
            std::cout << "Product #" << product.id << " Item:" << product.itemName << '\n';
            itemFound = true;
        }
    });

    if (!itemFound)
    {
        std::cout << "No items in category " << category << "\n";
    }
}
