#include <iostream>
#include <limits>  // Para std::numeric_limits

int main() {
    int opcionJugador;
    
    // Bucle para validar la entrada hasta que sea correcta
    do {
        std::cout << "Elige una opción (1. Piedra, 2. Papel, 3. Tijera): ";
        std::cin >> opcionJugador;

        // Validamos que la entrada sea un número válido (int) y dentro del rango 1-3
        if (std::cin.fail() || opcionJugador < 1 || opcionJugador > 3) {
            std::cin.clear();  // Limpiamos el estado de error de std::cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignoramos la entrada incorrecta
            std::cout << "¡Entrada inválida! Por favor ingresa un número entre 1 y 3." << std::endl;
        }
    } while (opcionJugador < 1 || opcionJugador > 3);  // Condición de salida del bucle

    std::cout << "Has elegido la opción " << opcionJugador << std::endl;
    
    return 0;
}
