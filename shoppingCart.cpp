#include "item.cpp"
#include <algorithm>
#include <vector>
using namespace std;
class ShoppingCart {
private:
    std::vector<Item> items;

public:
    ShoppingCart() = default;

    void addItem(const Item& item) {
        items.push_back(item);
    }

    void removeItem(const Item& item) {
        // Remove item by matching name and price
        auto it = std::find_if(items.begin(), items.end(), [&item](const Item& i) {
            return i.getName() == item.getName() && i.getPrice() == item.getPrice();
        });

        if (it != items.end()) {
            items.erase(it);
        }
    }

    void clearCart() {
        items.clear();
    }

    int getItemCount() const {
        return items.size();
    }

    double getTotalPrice() const {
        double totalPrice = 0.0;
        for (const auto& item : items) {
            totalPrice += item.getPrice();
        }
        return totalPrice;
    }

    std::vector<Item> getItems() const {
        return items;
    }
};