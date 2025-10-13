#include <iostream>
#include <ctime>

using namespace std;

int calcularEdad(int diaNacimiento, int mesNacimiento, int anioNacimiento) {
    // Obtener la fecha actual
    time_t t = time(0);
    struct tm* ahora = localtime(&t);

    // Obtener la fecha actual
    int diaHoy = ahora->tm_mday;
    int mesHoy = ahora->tm_mon + 1; // tm_mon va de 0 a 11, por eso sumamos 1
    int anioHoy = ahora->tm_year + 1900; // tm_year da el número de años desde 1900

    // Calcular la edad
    int edad = anioHoy - anioNacimiento;

    // Ajustar si el cumpleaños no ha pasado este año
    if (mesHoy < mesNacimiento || (mesHoy == mesNacimiento && diaHoy < diaNacimiento)) {
        edad--;
    }

    return edad;
}

int main() {
    int diaNacimiento, mesNacimiento, anioNacimiento;

    // Solicitar al usuario su fecha de nacimiento
    cout << "Ingresa tu dia de nacimiento (dd): ";
    cin >> diaNacimiento;
    cout << "Ingresa tu mes de nacimiento (mm): ";
    cin >> mesNacimiento;
    cout << "Ingresa tu año de nacimiento (yyyy): ";
    cin >> anioNacimiento;

    // Calcular y mostrar la edad
    int edad = calcularEdad(diaNacimiento, mesNacimiento, anioNacimiento);
    cout << "Tu edad es: " << edad << " años." << endl;

    return 0;
}
