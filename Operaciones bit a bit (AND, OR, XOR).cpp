#include <iostream>

using namespace std;

void operacionesBitwise(int a, int b) {
    cout << "Primer número (a): " << a << endl;
    cout << "Segundo número (b): " << b << endl;

    // Operación AND
    int and_result = a & b;
    cout << "Resultado de a AND b: " << and_result << " (Binario: " << bitset<8>(and_result) << ")" << endl;

    // Operación OR
    int or_result = a | b;
    cout << "Resultado de a OR b: " << or_result << " (Binario: " << bitset<8>(or_result) << ")" << endl;

    // Operación XOR
    int xor_result = a ^ b;
    cout << "Resultado de a XOR b: " << xor_result << " (Binario: " << bitset<8>(xor_result) << ")" << endl;
}

int main() {
    int num1, num2;

    // Solicitar dos números al usuario
    cout << "Ingresa el primer número: ";
    cin >> num1;
    cout << "Ingresa el segundo número: ";
    cin >> num2;

    // Realizar las operaciones bitwise
    operacionesBitwise(num1, num2);

    return 0;
}
