#include "category.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

Category::Category(const std::string& name, const std::vector<std::string>& subcategories)
    : name(name), subcategories(subcategories) {}

const std::string& Category::getName() const {
    return name;
}

const std::vector<std::string>& Category::getSubcategories() const {
    return subcategories;
}

std::vector<Category> Category::loadCategories(const std::string& filepath) {
    std::vector<Category> categories;
    std::ifstream file(filepath);

    if (!file) {
        std::cerr << "Error: Unable to open file: " << filepath << std::endl;
        return categories;
    }

    std::string line;
    while(std::getline(file, line)) {
        std::istringstream ss(line);
        std::string name;
        std::getline(ss, name, '(');

        std::string subcategoriesStr;
        std::getline(ss, subcategoriesStr, ')');

        std::istringstream subcategoriesStream(subcategoriesStr);
        std::vector<std::string> subcategories;
        std::string sub;
        while(std::getline(subcategoriesStream, sub, '@')) {
            subcategories.push_back(sub);
        }

        categories.emplace_back(name, subcategories);
    }

    return categories;
}
