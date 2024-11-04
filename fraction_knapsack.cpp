#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with value and weight
struct Item
{
  int value, weight;

  // Constructor for ease of initialization
  Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items by value-to-weight ratio
bool compare(Item a, Item b)
{
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int capacity, vector<Item> &items)
{
  // Sort items by their value-to-weight ratio in descending order
  sort(items.begin(), items.end(), compare);

  double maxValue = 0.0; // Total maximum value that can be carried
  for (const auto &item : items)
  {
    // If the item can fit entirely in the knapsack, take it
    if (capacity >= item.weight)
    {
      capacity -= item.weight;
      maxValue += item.value;
    }
    // Otherwise, take the fractional part of the item
    else
    {
      maxValue += item.value * ((double)capacity / item.weight);
      break; // Knapsack is full
    }
  }

  return maxValue;
}

int main()
{
  int n, capacity;
  cout << "Enter the number of items: ";
  cin >> n;
  cout << "Enter the capacity of the knapsack: ";
  cin >> capacity;

  vector<Item> items;
  cout << "Enter value and weight of each item:\n";
  for (int i = 0; i < n; i++)
  {
    int value, weight;
    cin >> value >> weight;
    items.push_back(Item(value, weight));
  }

  double maxValue = fractionalKnapsack(capacity, items);
  cout << "Maximum value in knapsack = " << maxValue << endl;

  return 0;
}
