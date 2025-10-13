#include <iostream>
#include <vector>

using namespace std;

void convertirBinario(int numero) {
    vector<int> binario;

    // Si el número es 0, directamente mostramos 0
    if (numero == 0) {
        cout << "0";
        return;
    }

    // Mientras el número sea mayor que 0
    while (numero > 0) {
        // Guardamos el resto de la división por 2
        binario.push_back(numero % 2);
        // Dividimos el número entre 2
        numero = numero / 2;
    }

    // Imprimimos los restos en orden inverso (porque los calculamos de atrás hacia adelante)
    for (int i = binario.size() - 1; i >= 0; i--) {
        cout << binario[i];
    }
}

int main() {
    int numeroDecimal;

    cout << "Ingresa un número decimal: ";
    cin >> numeroDecimal;

    cout << "El número " << numeroDecimal << " en binario es: ";
    convertirBinario(numeroDecimal);
    cout << endl;

    return 0;
}
