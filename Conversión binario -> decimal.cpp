#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int convertirDecimal(string binario) {
    int decimal = 0;

    // Recorremos el número binario de izquierda a derecha
    int longitud = binario.length();

    for (int i = 0; i < longitud; i++) {
        // Convertimos cada carácter del string a un valor numérico (0 o 1)
        if (binario[i] == '1') {
            // Calculamos su valor decimal, considerando la posición del bit
            decimal += pow(2, longitud - 1 - i);
        }
    }

    return decimal;
}

int main() {
    string numeroBinario;

    cout << "Ingresa un número binario: ";
    cin >> numeroBinario;

    // Convertimos el número binario a decimal
    int decimal = convertirDecimal(numeroBinario);

    cout << "El número binario " << numeroBinario << " en decimal es: " << decimal << endl;

    return 0;
}
