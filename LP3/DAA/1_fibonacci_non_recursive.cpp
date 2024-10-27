#include <iostream>
using namespace std;

int fib(int n, int &steps) {
    int a = 0, b = 1, c;
    if (n == 0) return a;
    for (int i = 2; i <= n; i++) {
        steps++;
        c = a + b;
        a = b;
        b = c;
    }
    steps++;
    return b;
}

int main() {
    int n, steps = 0;
    cin >> n;
    cout << "Fibonacci(" << n << ") = " << fib(n, steps) << endl;
    cout << "Steps: " << steps << endl;
    return 0;
}