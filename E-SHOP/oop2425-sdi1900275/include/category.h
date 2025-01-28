#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>
#include <vector>

class Category {
private:
    std::string name;
    std::vector<std::string> subcategories;

public:
    Category(const std::string& name, const std::vector<std::string>& subcategories);
    const std::string& getName() const;
    const std::vector<std::string>& getSubcategories() const;
    static std::vector<Category> loadCategories(const std::string& filepath);
};

#endif
