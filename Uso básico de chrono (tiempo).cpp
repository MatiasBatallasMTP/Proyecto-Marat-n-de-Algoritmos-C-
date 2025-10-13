#include <iostream>
#include <chrono>  // Necesario para usar chrono

int main() {
    // Usamos high_resolution_clock para obtener la mayor precisión
    auto start = std::chrono::high_resolution_clock::now();  // Captura el tiempo de inicio

    // Bloque de código cuyo tiempo queremos medir
    long long suma = 0;
    for (int i = 0; i < 1000000; ++i) {
        suma += i;  // Simple operación
    }

    auto end = std::chrono::high_resolution_clock::now();  // Captura el tiempo de finalización

    // Calculamos la duración
    std::chrono::duration<double> duration = end - start;  // La duración en segundos (double)

    // Mostramos el tiempo transcurrido
    std::cout << "El bloque de código tardó " << duration.count() << " segundos." << std::endl;

    return 0;
}
