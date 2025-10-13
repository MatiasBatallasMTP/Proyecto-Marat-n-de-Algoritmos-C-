#include <iostream>
using namespace std;

bool obtenerBitIesimo(int numero, int i) {
    return (numero >> i) & 1; // Desplaza y evalúa el bit
}

int main() {
    int numero, i;
    cout << "Ingresa un número: ";
    cin >> numero;
    cout << "Ingresa la posición del bit a obtener (0-indexed): ";
    cin >> i;

    bool bit = obtenerBitIesimo(numero, i);
    cout << "El bit en la posición " << i << " es: " << bit << endl;

    return 0;
}
