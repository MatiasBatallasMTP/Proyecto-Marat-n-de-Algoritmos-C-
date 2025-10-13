#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string convertirHexadecimal(int numero) {
    if (numero == 0) return "0"; // Si el número es 0, retornamos 0 directamente.

    string hex = "";
    char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    // Mientras el número sea mayor que 0
    while (numero > 0) {
        // Guardamos el carácter hexadecimal correspondiente al resto de la división por 16
        hex.push_back(hexDigits[numero % 16]);
        // Dividimos el número por 16
        numero = numero / 16;
    }

    // Como hemos obtenido los dígitos de atrás hacia adelante, invertimos la cadena
    reverse(hex.begin(), hex.end());
    return hex;
}

int main() {
    int numeroDecimal;

    cout << "Ingresa un número decimal: ";
    cin >> numeroDecimal;

    string hexadecimal = convertirHexadecimal(numeroDecimal);
    cout << "El número " << numeroDecimal << " en hexadecimal es: " << hexadecimal << endl;

    return 0;
}
