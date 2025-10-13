
#include <iostream>
using namespace std;

int main() {
    int numero;

    // Pedir al usuario que ingrese un número
    cout << "Ingresa un número: ";
    cin >> numero;

    // Verificar si el número es par o impar
    if (numero % 2 == 0) {
        cout << "El número " << numero << " es par." << endl;
    } else {
        cout << "El número " << numero << " es impar." << endl;
    }

    return 0;
}
