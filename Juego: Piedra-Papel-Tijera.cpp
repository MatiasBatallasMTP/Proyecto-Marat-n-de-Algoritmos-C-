#include <iostream>
#include <random>
#include <string>

// Función para convertir el número en la jugada correspondiente
std::string obtenerJugada(int opcion) {
    switch (opcion) {
        case 1: return "Piedra";
        case 2: return "Papel";
        case 3: return "Tijera";
        default: return "Opción inválida";
    }
}

// Función para determinar el ganador
std::string determinarGanador(const std::string& jugador, const std::string& ia) {
    if (jugador == ia) {
        return "¡Es un empate!";
    }
    
    if ((jugador == "Piedra" && ia == "Tijera") || 
        (jugador == "Tijera" && ia == "Papel") || 
        (jugador == "Papel" && ia == "Piedra")) {
        return "¡Ganaste!";
    }
    
    return "¡La IA ganó!";
}

int main() {
    // Semilla aleatoria basada en el reloj del sistema
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 3); // Generamos números aleatorios entre 1 y 3 (Piedra, Papel, Tijera)

    // Opciones del jugador
    int opcionJugador;
    std::cout << "¡Bienvenido al juego Piedra-Papel-Tijera!" << std::endl;
    std::cout << "Elige una opción:" << std::endl;
    std::cout << "1. Piedra" << std::endl;
    std::cout << "2. Papel" << std::endl;
    std::cout << "3. Tijera" << std::endl;
    std::cout << "Tu elección: ";
    std::cin >> opcionJugador;

    // Validación de la opción
    if (opcionJugador < 1 || opcionJugador > 3) {
        std::cout << "Opción inválida. El juego terminar
