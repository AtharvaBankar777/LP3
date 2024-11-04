#include <iostream>
#include <vector>

using namespace std;

int stepCountRecursive = 0; // Global variable to count recursive steps

// Recursive function to calculate Fibonacci numbers with step count
int fibonacciRecursive(int n)
{
    stepCountRecursive++;
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative function to calculate Fibonacci numbers with step count
int fibonacciIterative(int n, int &stepCountIterative)
{
    if (n <= 1)
        return n;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        stepCountIterative++; // Increment step count for each addition
    }
    return b;
}

int main()
{
    int n;
    cout << "Enter the Fibonacci term you want to calculate: ";
    cin >> n;

    // Recursive approach
    int resultRecursive = fibonacciRecursive(n);
    cout << "Fibonacci (Recursive) of " << n << " is: " << resultRecursive << endl;
    cout << "Step count (Recursive): " << stepCountRecursive << endl;

    // Iterative approach
    int stepCountIterative = 0;
    int resultIterative = fibonacciIterative(n, stepCountIterative);
    cout << "Fibonacci (Iterative) of " << n << " is: " << resultIterative << endl;
    cout << "Step count (Iterative): " << stepCountIterative << endl;

    return 0;
}
