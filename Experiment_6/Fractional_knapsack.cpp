// RIDWIK JAIN
// 25/DA/053
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by decreasing value/weight ratio
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;

    for (auto item : items) {
        if (W >= item.weight) {
            // Take the whole item
            W -= item.weight;
            maxValue += item.value;
        } 
        else {
            maxValue += ((double)item.value / item.weight) * W;
            break;
        }
    }

    return maxValue;
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    double result = fractionalKnapsack(W, items);

    cout << "Maximum value = " << result << endl;

    return 0;
}