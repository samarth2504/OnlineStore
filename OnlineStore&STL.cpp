#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Product {
    int productID;
    string name;
    string category;
};
struct Order {
    int orderID;
    int productID;
    int quantity;
    string customerID;
    time_t orderDate;
};

int main() {
    vector<Product> products = {
        {101, "Laptop", "Electronics"},
        {102, "Smartphone", "Electronics"},
        {103, "CoffeeMaker", "Kitchen"},
        {104, "Blender", "Kitchen"},
        {105, "DeskLamp", "Home"}
    };

    deque<string> recentCustomers = {"C100", "C101", "C102"};

    recentCustomers.push_back("C103");
    recentCustomers.push_front("C104"); 

    list<Order> orderHistory;

    orderHistory.push_back({1, 101, 1, "C101", time(0)});
    orderHistory.push_back({2, 102, 2, "C102", time(0)});
    orderHistory.push_back({3, 103, 3, "C103", time(0)});

    set<string> categories;

    for (const auto& product : products) {
        categories.insert(product.category);
    }

    map<int, int> productStock = {
        {101, 10},
        {102, 20},
        {103, 15},
        {104, 12},
        {105, 14}
    };

    multimap<string, Order> customerOrders;
    for (const auto& order : orderHistory) {
        customerOrders.insert({order.customerID, order});
    }

    unordered_map<string, string> customerData = {
        {"C101", "Alice"},
        {"C102", "Bob"},
        {"C103", "Sam"},
        {"C104", "Coach"}
    };

    unordered_set<int> uniqueProductIDs;
    for (const auto& product : products) {
        uniqueProductIDs.insert(product.productID);
    }

    cout << "Recent Customers in Queue:\n";
    for (const auto& customer : recentCustomers) {
        cout << customer << " ";
    }
    cout << endl;

    cout << "\nProduct Categories:\n";
    for (const auto& category : categories) {
        cout << category << " ";
    }
    cout << endl;

    cout << "\nProduct Stock Levels:\n";
    for (const auto& stock : productStock) {
        cout << "ProductID: " << stock.first << ", Stock: " << stock.second << endl;
    }

    cout << "\nCustomer Orders:\n";
    for (const auto& entry : customerOrders) {
        cout << "CustomerID: " << entry.first 
             << ", OrderID: " << entry.second.orderID 
             << ", ProductID: " << entry.second.productID 
             << ", Quantity: " << entry.second.quantity << endl;
    }

    return 0;
}
