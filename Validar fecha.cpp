#include <iostream>
#include <limits>

bool esBisiesto(int año) {
    // Un año es bisiesto si es divisible por 4, pero no por 100, a menos que también sea divisible por 400
    return (año % 4 == 0 && (año % 100 != 0 || año % 400 == 0));
}

bool esFechaValida(int dia, int mes, int año) {
    // Validamos que el mes esté en el rango 1-12
    if (mes < 1 || mes > 12) {
        return false;
    }

    // Definimos el número de días por mes, considerando años bisiestos para febrero
    int diasPorMes[] = {31, 28 + esBisiesto(año), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Validamos que el día esté dentro del rango adecuado para el mes dado
    if (dia < 1 || dia > diasPorMes[mes - 1]) {
        return false;
    }

    return true;
}

int main() {
    int dia, mes, año;

    // Bucle para
