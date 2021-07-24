/*
Implement a C++ Program to search for product details in a Product Database
Use applicable Object Oriented Practices

Classes:
========
Parent = Product
Child  = Food, Furniture

Searching Algorithm Used:
=========================
Simple Linear Search, O(n) time, O(1) space

Object Oriented Concepts Used:
==============================
* Classes
* Multiple Objects stored and accessed using Object Pointers
* Inheritance
* Virtual Functions
* Data Abstraction (with appropriate access specifiers)
* Default, Parameterized, Copy Constructors
* Const correctness in Getter Functions
* Destructors in Child Classes
* Virtual Destructor in Parent Class

*/

#include <iostream>

class Product {
private:
    std::string productName;
    int productBarCode;
    float productPrice;
        
public:
    // Default Constructor
    Product() : productName(""), productBarCode(0), productPrice(0) {}  

    // Parameterized Constructor
    Product( std::string productName, int productBarCode, float productPrice ) { 
        this->productName    = productName;
        this->productBarCode = productBarCode;
        this->productPrice   = productPrice;
    }

    // Copy Constructor
    Product( const Product& product ) {
        Product( product.productName, product.productBarCode, product.productPrice );
    }

    // Not really needed since we are not Dynamically Allocating Memory in the class
    virtual ~Product() {
        delete &productName;
        delete &productBarCode;
        delete &productPrice;
    }

    // Virtual Function to print generic details of the product
    virtual void displayDetails() const {
        std::cout << "Product Details:\n";
        std::cout << "================\n";

        std::cout << "Product Name: " << productName << "\n";
        std::cout << "Product Bar Code: " << productBarCode << "\n";
        std::cout << "Product Price: " << productPrice << "\n";

        std::cout << "----------------\n\n";
    }

    // Variable Getters and Setters
    void setName( std::string productName ) {
        this->productName = productName;
    }

    void setBarCode( int productBarCode ) {
        this->productBarCode = productBarCode;
    }

    void setPrice( int productPrice ) {
        this->productPrice = productPrice;
    }

    std::string getName() const {
        return productName;
    }

    int getBarCode() const {
        return productBarCode;
    }

    int getPrice() const {
        return productPrice;
    }

};


class Food : public Product {
private:
    std::string shelf_life;
    std::string date_of_production;
    std::string date_of_expiry;

    float calories_per_100_grams;

public:

    // Default Constructor
    Food() : shelf_life("0 years"), date_of_production("01-01-2001"), date_of_expiry("01-01-2001") {
        setName("");
        setBarCode(0);
        setPrice(0);
    }

    // Parameterized Constructor
    Food( std::string productName, int productBarCode, int productPrice,
          std::string shelf_life, std::string date_of_production, std::string date_of_expiry, 
          float calories_per_100_grams ) {
            
        // Setting parent variables
        setName( productName );
        setBarCode( productBarCode );
        setPrice( productPrice );

        // Setting class variables
        this->shelf_life = shelf_life;
        this->date_of_production = date_of_production;
        this->date_of_expiry = date_of_expiry;
        this->calories_per_100_grams = calories_per_100_grams;
    }

    // Copy Constructor
    Food( const Food& food ) {
        Food( food.getName(), food.getBarCode(), food.getPrice(), 
              food.shelf_life, food.date_of_production, food.date_of_expiry,
              food.calories_per_100_grams
            );
    }

    ~Food() {
        delete &shelf_life;
        delete &date_of_production;
        delete &date_of_expiry;
        delete &calories_per_100_grams;
    }

    // Overriden Virtual Function
    void displayDetails() const override {
        std::cout << "Product Details:\n";
        std::cout << "================\n";

        std::cout << "Product Name: " << getName() << "\n";
        std::cout << "Product Bar Code: " << getBarCode() << "\n";
        std::cout << "Product Price: " << getPrice() << "\n\n";
        
        std::cout << "Shelf Life: " << shelf_life << "\n";
        std::cout << "Date of Production: " << date_of_production << "\n";
        std::cout << "Date of Expiry: " << date_of_expiry << "\n";

        std::cout << "----------------\n\n";
    }

    // Setters and Getters:
    void setShelfLife( std::string shelf_life ) {
        this->shelf_life = shelf_life;
    }

    void setProductionDate( std::string date_of_production ) {
        this->date_of_production = date_of_production;
    }

    void setExpiryDate( std::string date_of_expiry ) {
        this->date_of_expiry = date_of_expiry;
    }

    void setCalories( float calories_per_100_grams ) {
        this->calories_per_100_grams = calories_per_100_grams;
    }

    std::string getShelfLife() const {
        return shelf_life;
    }

    std::string getProductionDate() const {
        return date_of_production;
    }

    std::string getExpiryDate() const {
        return date_of_expiry;
    }

    float getCalories() const {
        return calories_per_100_grams;
    }

};


class Furniture : public Product {
private:
    std::string furniture_type;
    std::string material;
    int strength_parameter;

public:
    // Default Constructor
    Furniture() {
        Product();
        furniture_type = "Coffee Table";
        material = "Wood";
        strength_parameter = 2;
    }

    // Parameterized Constructor
    Furniture( std::string productName, int productBarCode, int productPrice,
               std::string furniture_type, std::string material, int strength_parameter ) {
        
        setName( productName );
        setBarCode( productBarCode );
        setPrice( productPrice );
    
        this->furniture_type = furniture_type;
        this->material = material;
        this->strength_parameter = strength_parameter;
    }

    // Copy Constructor
    Furniture( const Furniture& furniture ) {
        Furniture( furniture.getName(), furniture.getBarCode(), furniture.getPrice(),
                   furniture.furniture_type, furniture.material, furniture.strength_parameter );
    }

    ~Furniture() {
        delete &furniture_type;
        delete &material;
        delete &strength_parameter;
    }

    // Overriden Virtual Function
    void displayDetails() const override {
        std::cout << "Product Details:\n";
        std::cout << "================\n";

        std::cout << "Product Name: " << getName() << "\n";
        std::cout << "Product Bar Code: " << getBarCode() << "\n";
        std::cout << "Product Price: " << getPrice() << "\n\n";
        
        std::cout << "Furniture Type: " << furniture_type << "\n";
        std::cout << "Material: " << material << "\n";
        std::cout << "Strenght Parameter: " << strength_parameter << "\n";

        std::cout << "----------------\n\n";
    }

    // Setters and Getters
    void setType( std::string furniture_type ) {
        this->furniture_type = furniture_type;
    }

    void setMaterial( std::string material ) {
        this->material = material;
    }

    void setStrengthParameter( int strength_parameter ) {
        this->strength_parameter = strength_parameter;
    }

    std::string getType() const {
        return furniture_type;
    }

    std::string getMaterial() const {
        return material;
    }

    int getStrengthParameter() const {
        return strength_parameter;
    }
};

bool search_product_by_name( Product **products , std::string name, int number_of_products ) {
    std::cout << "Searching Product by Name...\n";

    for ( int i = 0; i < number_of_products; i++ ) {

        if ( products[i]->getName() == name ) {
            std::cout << "Product Found!\n\n";
            products[i]->displayDetails();

            return true;
        }
    }

    return false;
}


bool search_product_by_bar_code( Product **products, int bar_code, int number_of_products ) {
    std::cout << "Searching Product by Bar Code...\n";

    for ( int i = 0; i < number_of_products; i++ ) {

        if ( products[i]->getBarCode() == bar_code ) {
            std::cout << "Product Found!\n\n";
            products[i]->displayDetails();

            return true;
        }
    }

    return false;
}


int main() {

    std::cout << "Welcome to the Product Management System!\n";

    int number_of_products;
    std::cout << "\nEnter number of products: ";
    std::cin >> number_of_products;

    std::cout << "\n";

    Product* products[number_of_products];

    for ( int i = 0; i < number_of_products; i++ ) {
        int product_type;

        std::cout << "Enter Product Type:\n";
        std::cout << "1 - Food Product\n";
        std::cout << "2 - Furniture Product\n";

        std::cin >> product_type;

        std::cout << "\n";

        if ( product_type == 1 ) {

            std::string name, shelf_life, date_production, date_expiry;
            int bar_code, price;
            float calories;

            std::cout << "Enter Name: ";
            std::cin >> name;
            std::cout << "Enter Bar Code: ";
            std::cin >> bar_code;
            std::cout << "Enter Price: ";
            std::cin >> price;
            std::cout << "Enter Shelf Life: ";
            std::cin >> shelf_life;
            std::cout << "Enter Production Date: ";
            std::cin >> date_production;
            std::cout << "Enter Expiry Date: ";
            std::cin >> date_expiry;
            std::cout << "Enter Calories: ";
            std::cin >> calories;

            std::cout << "\n";

            // Product *product = new Food( name, bar_code, price, shelf_life, 
            //                              date_production, date_expiry, calories );

            // products[i] = *product;
            products[i] = new Food( name, bar_code, price, shelf_life, 
                                    date_production, date_expiry, calories );

        }

        else if ( product_type == 2 ) {
        
            std::string name, furniture_type, material;
            int bar_code, price, strength;

            std::cout << "Enter Name: ";
            std::cin >> name;

            std::cout << "Enter Bar Code: ";
            std::cin >> bar_code;

            std::cout << "Enter Price: ";
            std::cin >> price;

            std::cout << "Enter Furniture Type: ";
            std::cin >> furniture_type;

            std::cout << "Enter Material: ";
            std::cin >> material;

            std::cout << "Enter Strength Parameter: ";
            std::cin >> strength;

            std::cout << "\n";

            Product *product = new Furniture(name, bar_code, price, furniture_type,
                                             material, strength);
            // products[i] = *product;
            products[i] = new Furniture( name, bar_code, price, furniture_type,
                                         material, strength);

            delete product;
        }

        else {
            std::cout << "Invalid Input!\n";
        }
    }


    std::string search_name;
    int search_bar_code;

    std::cout << "\nSearching for a Product:\n";

    std::cout << "Search by Name: ";
    std::cin >> search_name;

    std::cout << "\n";

    bool found_by_name = search_product_by_name( products, search_name, number_of_products );

    if ( !found_by_name ) {
        std::cout << "Could not locate Item!\n";
    }

    std::cout << "Search by Bar Code: ";
    std::cin >> search_bar_code;

    bool found_by_bar_code = search_product_by_bar_code( products, search_bar_code, number_of_products );

    if ( !found_by_bar_code ) {
        std::cout << "Could not locate Item!\n";
    }

    std::cout << "\n\nThank you for using the program!\n\n";
    return 0;
}