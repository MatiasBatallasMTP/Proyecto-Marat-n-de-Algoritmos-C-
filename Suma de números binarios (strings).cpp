#include <iostream>
#include <algorithm>

using namespace std;

string sumaBinarios(string bin1, string bin2) {
    // Asegurarse de que ambos números tengan la misma longitud, añadiendo ceros a la izquierda
    int n1 = bin1.length();
    int n2 = bin2.length();

    // Llenar con ceros a la izquierda si las longitudes no son iguales
    if (n1 < n2) {
        bin1.insert(0, n2 - n1, '0');
    } else if (n2 < n1) {
        bin2.insert(0, n1 - n2, '0');
    }

    string resultado = "";
    int acarreo = 0;

    // Empezamos desde el último bit hacia el primero
    for (int i = bin1.length() - 1; i >= 0; i--) {
        int bit1 = bin1[i] - '0'; // Convertir char a int
        int bit2 = bin2[i] - '0'; // Convertir char a int

        int suma = bit1 + bit2 + acarreo;

        // Si la suma es 2 o 3, necesitamos acarreo
        if (suma == 2) {
            resultado = '0' + resultado;
            acarreo = 1;
        } else if (suma == 3) {
            resultado = '1' + resultado;
            acarreo = 1;
        } else {
            resultado = (suma + '0') + resultado;
            acarreo = 0;
        }
    }

    // Si hay acarreo al final, lo añadimos
    if (acarreo == 1) {
        resultado = '1' + resultado;
    }

    return resultado;
}

int main() {
    string bin1, bin2;

    cout << "Ingresa el primer número binario: ";
    cin >> bin1;
    cout << "Ingresa el segundo número binario: ";
    cin >> bin2;

    string resultado = sumaBinarios(bin1, bin2);
    cout << "El resultado de la suma es: " << resultado << endl;

    return 0;
}
