#include <iostream>

using namespace std;

// Función para contar los bits encendidos (popcount)
int contarBitsEncendidos(int numero) {
    int contador = 0;
    while (numero) {
        contador += numero & 1; // Si el bit menos significativo es 1, lo sumamos
        numero >>= 1;            // Desplazamos el número a la derecha
    }
    return contador;
}

int main() {
    int numero;

    cout << "Ingresa un número: ";
    cin >> numero;

    int bitsEncendidos = contarBitsEncendidos(numero);
    cout << "El número " << numero << " tiene " << bitsEncendidos << " bits encendidos." << endl;

    return 0;
}
