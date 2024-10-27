#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int profit;
    int weight;
};

bool compare(Item a, Item b) {
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;

    for (const auto& item : items) {
        if (capacity >= item.weight) {
            totalValue += item.profit;
            capacity -= item.weight;
        } else {
            totalValue += item.profit * ((double)capacity / item.weight);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);

    for (int i = 0; i < n; ++i) {
        cout << "Enter profit of item " << (i + 1) << ": ";
        cin >> items[i].profit;
        cout << "Enter weight of item " << (i + 1) << ": ";
        cin >> items[i].weight;
    }

    int capacity;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;
    cout << "Maximum value in knapsack: " << fractionalKnapsack(capacity, items) << endl;

    return 0;
}

//  Sample Input and Output

//  3
//  60
//  10
//  100
//  20
//  120
//  30
//  50

//  Output: Maximum value in knapsack: 240.0