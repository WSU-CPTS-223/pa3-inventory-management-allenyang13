#pragma once
#include <string>


class Product
{
public:
    std::string id, itemName, categories;

    Product() = default;

    Product(const std::string &id, const std::string &itemName, const std::string &categories)
        : id(id), itemName(itemName), categories(categories) {};

    bool findCategory(const std::string& catName) const
    {
        std::string l_Categories = categories;
        std::string l_catName = catName;

        for (auto& c : l_Categories)
            c = std::tolower(c);

        for (auto& c : l_catName)
            c = std::tolower(c);

        return l_Categories.find(l_catName) != std::string::npos;
    }
};