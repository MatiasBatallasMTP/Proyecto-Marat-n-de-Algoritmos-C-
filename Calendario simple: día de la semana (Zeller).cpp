#include <iostream>
#include <cmath>

using namespace std;

string diaDeLaSemana(int dia, int mes, int anio) {
    // Si el mes es enero o febrero, ajustamos el mes y el año
    if (mes == 1 || mes == 2) {
        mes += 12;
        anio -= 1;
    }

    // Año dentro del siglo
    int K = anio % 100;
    // Siglo
    int J = anio / 100;

    // Fórmula de Zeller
    int h = (dia + (13 * (mes + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    // Array de días de la semana (0=sábado, 1=domingo, ..., 6=viernes)
    string dias[] = {"Sábado", "Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes"};

    return dias[h];
}

int main() {
    int dia, mes, anio;

    cout << "Ingresa el día (1-31): ";
    cin >> dia;
    cout << "Ingresa el mes (1-12): ";
    cin >> mes;
    cout << "Ingresa el año (YYYY): ";
    cin >> anio;

    string diaSemana = diaDeLaSemana(dia, mes, anio);

    cout << "El día de la semana es: " << diaSemana << endl;

    return 0;
}
