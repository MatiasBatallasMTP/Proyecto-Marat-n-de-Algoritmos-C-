#include <iostream>
using namespace std;

bool esPotenciaDe2(int numero) {
    return (numero > 0) && (numero & (numero - 1)) == 0;
}

int main() {
    int numero;
    cout << "Ingresa un número: ";
    cin >> numero;

    if (esPotenciaDe2(numero)) {
        cout << numero << " es una potencia de 2." << endl;
    } else {
        cout << numero << " no es una potencia de 2." << endl;
    }

    return 0;
}
