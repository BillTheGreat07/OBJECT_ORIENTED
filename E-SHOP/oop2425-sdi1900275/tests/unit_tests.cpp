#include "acutest.h" // Acutest testing framework
#include <iostream>
#include <string>

const std::string EXE_NAME = "./oop24";

void test_admin_insert(void) {
    std::string filename = "tests/admin_insert.txt";

    // Create a copy of the products so you don't mess with them
    system("cp ./files/products.txt ./files/products_copy.txt");

    // Try inserting
    std::string cmd = EXE_NAME + " files/categories.txt files/products_copy.txt files/users.txt < " + filename + " > /dev/null 2>&1";
    if (system(cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: ./oop24 failed to execute");
    }

    // Check if product was inserted
    std::string search_string = "Dummy Product @ Dummy Description @ Tech @ Laptop @ 500.00 @ Unit @ 1000";
    std::string grep_cmd = "grep -q \"" + search_string + "\" ./files/products_copy.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Product was not inserted");
    }

    // Delete copy
    system("rm -f ./files/products_copy.txt");
}

void test_admin_edit_title(void) {
    std::string filename = "tests/admin_edit_title.txt";

    // Create a copy of the products so you don't mess with them
    system("cp ./files/products.txt ./files/products_copy.txt");

    // Try editing title
    std::string cmd = EXE_NAME + " files/categories.txt files/products_copy.txt files/users.txt < " + filename + " > /dev/null 2>&1";
    if (system(cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: ./oop24 failed to execute");
    }

    // Check if product was edited
    std::string search_string = "Dummy Apple @ A healthy fruit @ Food @ Fruit @ 1.80 @ Kg @ 100";
    std::string grep_cmd = "grep -q \"" + search_string + "\" ./files/products_copy.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Product was not edited");
    }

    // Delete copy
    system("rm -f ./files/products_copy.txt");
}

void test_admin_edit_description(void) {
    std::string filename = "tests/admin_edit_description.txt";

    // Create a copy of the products so you don't mess with them
    system("cp ./files/products.txt ./files/products_copy.txt");

    // Try editing description
    std::string cmd = EXE_NAME + " files/categories.txt files/products_copy.txt files/users.txt < " + filename + " > /dev/null 2>&1";
    if (system(cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: ./oop24 failed to execute");
    }

    // Check if product was edited
    std::string search_string = "Apple @ A dummy healthy fruit @ Food @ Fruit @ 1.80 @ Kg @ 100";
    std::string grep_cmd = "grep -q \"" + search_string + "\" ./files/products_copy.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Product was not edited");
    }

    // Delete copy
    system("rm -f ./files/products_copy.txt");
}

void test_admin_edit_category_subcategory(void) {
    std::string filename = "tests/admin_edit_category_subcategory.txt";

    // Create a copy of the products so you don't mess with them
    system("cp ./files/products.txt ./files/products_copy.txt");

    // Try editing category and subcategory
    std::string cmd = EXE_NAME + " files/categories.txt files/products_copy.txt files/users.txt < " + filename + " > /dev/null 2>&1";
    if (system(cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: ./oop24 failed to execute");
    }

    // Check if product was edited
    std::string search_string = "Apple @ A healthy fruit @ Drink @ Tea @ 1.80 @ Kg @ 100";
    std::string grep_cmd = "grep -q \"" + search_string + "\" ./files/products_copy.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Product was not edited");
    }

    // Delete copy
    system("rm -f ./files/products_copy.txt");
}

void test_admin_edit_price(void) {
    std::string filename = "tests/admin_edit_price.txt";

    // Create a copy of the products so you don't mess with them
    system("cp ./files/products.txt ./files/products_copy.txt");

    // Try editing price
    std::string cmd = EXE_NAME + " files/categories.txt files/products_copy.txt files/users.txt < " + filename + " > /dev/null 2>&1";
    if (system(cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: ./oop24 failed to execute");
    }

    // Check if product was edited
    std::string search_string = "Apple @ A healthy fruit @ Food @ Fruit @ 99999.00 @ Kg @ 100";
    std::string grep_cmd = "grep -q \"" + search_string + "\" ./files/products_copy.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Product was not edited");
    }

    // Delete copy
    system("rm -f ./files/products_copy.txt");
}

void test_admin_edit_quantity(void) {
    std::string filename = "tests/admin_edit_quantity.txt";

    // Create a copy of the products so you don't mess with them
    system("cp ./files/products.txt ./files/products_copy.txt");

    // Try editing quantity
    std::string cmd = EXE_NAME + " files/categories.txt files/products_copy.txt files/users.txt < " + filename + " > /dev/null 2>&1";
    if (system(cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: ./oop24 failed to execute");
    }

    // Check if product was edited
    std::string search_string = "Apple @ A healthy fruit @ Food @ Fruit @ 1.80 @ Kg @ 12345";
    std::string grep_cmd = "grep -q \"" + search_string + "\" ./files/products_copy.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Product was not edited");
    }

    // Delete copy
    system("rm -f ./files/products_copy.txt");
}

void test_admin_remove(void) {
    std::string filename = "tests/admin_remove.txt";

    // Create a copy of the products so you don't mess with them
    system("cp ./files/products.txt ./files/products_copy.txt");

    // Try removing
    std::string cmd = EXE_NAME + " files/categories.txt files/products_copy.txt files/users.txt < " + filename + " > /dev/null 2>&1";
    if (system(cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: ./oop24 failed to execute");
    }

    // Check if product was removed
    std::string search_string = "Tomato @ A healthy vegetable @ Food @ Vegetable @ 2.00 @ Kg @ 100";
    std::string grep_cmd = "grep -q \"" + search_string + "\" ./files/products_copy.txt";
    if (system(grep_cmd.c_str()) == 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Product was not removed");
    }

    // Delete copy
    system("rm -f ./files/products_copy.txt");
}

// Customer Tests

void test_customer_insert(void) {
    std::string filename = "tests/customer_insert.txt";

    // Create a copy of the products so you don't mess with them
    system("cp ./files/products.txt ./files/products_copy.txt");
    system("cp ./files/users.txt ./files/users_copy.txt");

    // Try inserting
    std::string cmd = EXE_NAME + " files/categories.txt files/products_copy.txt files/users_copy.txt < " + filename + " > /dev/null 2>&1";
    if (system(cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: ./oop24 failed to execute");
    }

    std::string grep_cmd;

    // Check that all products are in the order history
    grep_cmd = "grep -q \"2 Tomato\" files/order_history/_user__history.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Incorrect value of \"Tomato\"");
    }
    grep_cmd = "grep -q \"3 Bottle of Beer\" files/order_history/_user__history.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Incorrect value of \"Bottle of Beer\"");
    }
    grep_cmd = "grep -q \"1 Romantic Saga\" files/order_history/_user__history.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Incorrect value of \"Romantic Saga\"");
    }

    // Check total cost
    grep_cmd = "grep -q \"Total Cost: 21.49\" files/order_history/_user__history.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Incorrect Total Cost. Correct is 21.49");
    }

    // Delete copy
    system("rm -f ./files/products_copy.txt");
    system("rm -f ./files/order_history/_user__history.txt");

    system("rm -f ./files/users_copy.txt");
}

void test_customer_update(void) {
    std::string filename = "tests/customer_update.txt";

    // Create a copy of the products so you don't mess with them
    system("cp ./files/products.txt ./files/products_copy.txt");
    system("cp ./files/users.txt ./files/users_copy.txt");

    // Try inserting
    std::string cmd = EXE_NAME + " files/categories.txt files/products_copy.txt files/users_copy.txt < " + filename + " > /dev/null 2>&1";
    if (system(cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: ./oop24 failed to execute");
    }

    std::string grep_cmd;

    // Check that all products are in the ordder history
    grep_cmd = "grep -q \"8 Apple\" files/order_history/_user__history.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Incorrect value of \"Apple\"");
    }
    grep_cmd = "grep -q \"2 Chicken Breast\" files/order_history/_user__history.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Incorrect value of \"Chicken Breast\"");
    }

    // Check total cost
    grep_cmd = "grep -q \"Total Cost: 25.4\" files/order_history/_user__history.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Incorrect Total Cost. Correct is 25.4");
    }

    // Delete copy
    system("rm -f ./files/products_copy.txt");
    system("rm -f ./files/order_history/_user__history.txt");

    system("rm -f ./files/users_copy.txt");
}

void test_customer_remove(void) {
    std::string filename = "tests/customer_remove.txt";

    // Create a copy of the products so you don't mess with them
    system("cp ./files/products.txt ./files/products_copy.txt");
    system("cp ./files/users.txt ./files/users_copy.txt");

    // Try inserting
    std::string cmd = EXE_NAME + " files/categories.txt files/products_copy.txt files/users_copy.txt < " + filename + " > /dev/null 2>&1";
    if (system(cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: ./oop24 failed to execute");
    }

    std::string grep_cmd;

    // Check that all products are in the ordder history
    grep_cmd = "grep -q \"1 Latte Beans\" files/order_history/_user__history.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Incorrect value of \"Latte Beans\"");
    }
    grep_cmd = "grep -q \"T-Shirt\" files/order_history/_user__history.txt";
    if (system(grep_cmd.c_str()) == 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: T-Shirt is present in the order-history file\"");
    }

    // Check total cost
    grep_cmd = "grep -q \"Total Cost: 4\" files/order_history/_user__history.txt";
    if (system(grep_cmd.c_str()) != 0) {
        TEST_CHECK(false);
        TEST_MSG("What failed: Incorrect Total Cost. Correct is 4");
    }

    // Delete copy
    system("rm -f ./files/products_copy.txt");
    system("rm -f ./files/order_history/_user__history.txt");

    system("rm -f ./files/users_copy.txt");
}

// List of test functions for the test runner
TEST_LIST = {
    { "Admin Insert", test_admin_insert },
    { "Admin Edit Title", test_admin_edit_title },
    { "Admin Edit Description", test_admin_edit_description },
    { "Admin Edit Category-Subcategory", test_admin_edit_category_subcategory },
    { "Admin Edit Price", test_admin_edit_price },
    { "Admin Edit Quantity", test_admin_edit_quantity },
    { "Admin Edit Remove", test_admin_remove },
    { "Customer Insert", test_customer_insert },
    { "Customer Update", test_customer_update },
    { "Customer Remove", test_customer_remove },
    { NULL, NULL } 
};