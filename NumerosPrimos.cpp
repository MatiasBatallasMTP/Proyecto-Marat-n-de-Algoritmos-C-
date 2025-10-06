#include <iostream>
using namespace std;

bool esPrimo(int n) {
    if (n <= 1) return false;  // Los números menores o iguales a 1 no son primos
    for (int i = 2; i * i <= n; i++) {  // Solo verificamos hasta la raíz cuadrada de n
        if (n % i == 0) return false;  // Si n es divisible por i, no es primo
    }
    return true;  // Si no encontró divisores, es primo
}

int main() {
    int numero;
    cout << "Introduce un número: ";
    cin >> numero;
    
    if (esPrimo(numero)) {
        cout << numero << " es un número primo." << endl;
    } else {
        cout << numero << " no es un número primo." << endl;
    }

    return 0;
}
