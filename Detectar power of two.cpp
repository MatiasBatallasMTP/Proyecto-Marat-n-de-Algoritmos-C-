#include <iostream>
using namespace std;

bool isPowerOfTwo(long long n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

int main() {
    long long n;
    cout << "Ingrese un numero: ";
    cin >> n;
    cout << (isPowerOfTwo(n) ? "Es potencia de 2" : "No es potencia de 2") << endl;
}
