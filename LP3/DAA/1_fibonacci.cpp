#include <iostream>
using namespace std;

int fib(int n, int &steps) {
    steps++;
    if (n <= 1) return n;
    return fib(n - 1, steps) + fib(n - 2, steps);
}

int main() {
    int n, steps = 0;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fib(n, steps) << endl;
    cout << "Steps: " << steps << endl;
    return 0;
}