#include <iostream>
using namespace std;

// Función para intercambiar los bits en posiciones p1 y p2 de un número n
unsigned int swapBits(unsigned int n, unsigned int p1, unsigned int p2) {
    // Obtener los bits en las posiciones dadas
    unsigned int bit1 = (n >> p1) & 1;
    unsigned int bit2 = (n >> p2) & 1;

    // Si los bits son iguales, no hay nada que intercambiar
    if (bit1 == bit2)
        return n;

    // Crear una máscara con 1s en las posiciones p1 y p2
    unsigned int mask = (1U << p1) | (1U << p2);

    // Usar XOR con la máscara para intercambiar los bits
    n ^= mask;

    return n;
}

int main() {
    unsigned int num, p1, p2;

    cout << "Ingrese un numero: ";
    cin >> num;

    cout << "Ingrese la posicion del primer bit: ";
    cin >> p1;

    cout << "Ingrese la posicion del segundo bit: ";
    cin >> p2;

    cout << "\nNumero original: " << num << endl;
    cout << "Numero despues del swap: " << swapBits(num, p1, p2) << endl;

    return 0;
}
