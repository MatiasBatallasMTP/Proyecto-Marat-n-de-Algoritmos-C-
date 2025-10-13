#include <iostream>
using namespace std;

int swapBits(int numero, int i, int j) {
    // Obtener los bits i y j
    int bitI = (numero >> i) & 1;
    int bitJ = (numero >> j) & 1;

    // Si los bits son diferentes, se intercambian
    if (bitI != bitJ) {
        numero ^= (1 << i);  // Invertir bit en la posición i
        numero ^= (1 << j);  // Invertir bit en la posición j
    }
    return numero;
}

int main() {
    int numero, i, j;
    cout << "Ingresa un número: ";
    cin >> numero;
    cout << "Ingresa la posición del primer bit (i): ";
    cin >> i;
    cout << "Ingresa la posición del segundo bit (j): ";
    cin >> j;

    numero = swapBits(numero, i, j);
    cout << "Número después del intercambio: " << numero << endl;

    return 0;
}
