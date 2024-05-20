#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Class to represent a menu item
class MenuItem {
private:
    string name;
    double price;

public:
    MenuItem(string name, double price) : name(name), price(price) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};

// Class to represent a table
class Table {
private:
    int tableNumber;
    bool isAvailable;

public:
    Table(int tableNumber) : tableNumber(tableNumber), isAvailable(true) {}

    int getTableNumber() const {
        return tableNumber;
    }

    bool isAvailable() const {
        return isAvailable;
    }

    void setAvailable(bool available) {
        isAvailable = available;
    }
};

// Main class for the restaurant management system
class RestaurantManagementSystem {
private:
    unordered_map<string, MenuItem> menu;
    unordered_map<int, Table> tables;

public:
    // Function to add a new menu item
    void addMenuItem(const string& name, double price) {
        menu[name] = MenuItem(name, price);
    }

    // Function to remove a menu item
    void removeMenuItem(const string& name) {
        menu.erase(name);
    }

    // Function to display the menu
    void displayMenu() const {
        cout << "Menu:" << endl;
        for (const auto& item : menu) {
            cout << item.second.getName() << " - $" << item.second.getPrice() << endl;
        }
    }

    // Function to add a new table
    void addTable(int tableNumber) {
        tables[tableNumber] = Table(tableNumber);
    }

    // Function to remove a table
    void removeTable(int tableNumber) {
        tables.erase(tableNumber);
    }

    // Function to display available tables
    void displayAvailableTables() const {
        cout << "Available Tables:" << endl;
        for (const auto& table : tables) {
            if (table.second.isAvailable()) {
                cout << "Table " << table.second.getTableNumber() << endl;
            }
        }
    }
};

int main() {
    RestaurantManagementSystem restaurant;

    // Adding menu items
    restaurant.addMenuItem("Burger", 10.99);
    restaurant.addMenuItem("Pizza", 12.99);
    restaurant.addMenuItem("Salad", 8.99);

    // Adding tables
    restaurant.addTable(1);
    restaurant.addTable(2);
    restaurant.addTable(3);

    // Displaying menu and available tables
    restaurant.displayMenu();
    restaurant.displayAvailableTables();

    return 0;
}
