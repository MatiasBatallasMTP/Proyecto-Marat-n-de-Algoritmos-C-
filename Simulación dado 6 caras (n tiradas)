#include <iostream>
#include <random>
#include <vector>

void lanzarDado(int n) {
    // Semilla aleatoria basada en el reloj del sistema
    std::random_device rd;
    std::mt19937 gen(rd());  // Motor de Mersenne Twister

    // Distribución uniforme entre 1 y 6
    std::uniform_int_distribution<> distrib(1, 6);

    // Vector para contar la frecuencia de cada cara del dado
    std::vector<int> conteo(6, 0);  // Iniciamos un vector con 6 elementos, todos en 0

    // Realizamos n lanzamientos
    for (int i = 0; i < n; ++i) {
        int resultado = distrib(gen);  // Generamos un número entre 1 y 6
        conteo[resultado - 1]++;       // Incrementamos el contador correspondiente
    }

    // Mostramos el resultado de los lanzamientos
    std::cout << "Resultados de los lanzamientos de dado (" << n << " tiradas):" << std::endl;
    for (int i = 0; i < 6; ++i) {
        std::cout << "Cara " << i + 1 << ": " << conteo[i] << " veces" << std::endl;
    }
}

int main() {
    int n;

    std::cout << "Ingrese el número de lanzamient
