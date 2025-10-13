#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Persona {
    std::string nombre;
    int edad;
    float altura;
    bool empleado;
    double salario;
};

// Función para leer el archivo CSV
std::vector<Persona> leerCSV(const std::string& archivo) {
    std::vector<Persona> personas;  // Vector para almacenar las personas
    std::ifstream file(archivo);     // Abrimos el archivo

    if (!file.is_open()) {          // Si no se puede abrir el archivo
        std::cerr << "No se pudo abrir el archivo " << archivo << std::endl;
        return personas;
    }

    std::string linea;
    while (std::getline(file, linea)) {
        std::istringstream ss(linea);  // Convertimos la línea en un stream
        Persona persona;
        
        // Leemos los valores separados por coma
        std::getline(ss, persona.nombre, ',');
        ss >> persona.edad; ss.ignore();  // Leemos la edad (y saltamos la coma)
        ss >> persona.altura; ss.ignore();  // Leemos la altura (y saltamos la coma)
        
        int empleadoInt;
        ss >> empleadoInt; ss.ignore();  // Leemos el valor de "empleado" y saltamos la coma
        persona.empleado = (empleadoInt == 1);  // Convertimos 1/0 a true/false

        ss >> persona.salario;  // Leemos el salario

        personas.push_back(persona);  // Añadimos la persona al vector
    }

    file.close();  // Cerramos el archivo
    return personas;
}

int main() {
    std::string archivo = "personas.csv";  // Ruta del archivo CSV

    // Leemos los datos del archivo CSV
    std::vector<Persona> personas = leerCSV(archivo);

    // Mostramos los datos leídos
    std::cout << "Personas leídas desde el CSV:" << std::endl;
    for (const auto& persona : personas) {
        std::cout << "Nombre: " << persona.nombre << ", Edad: " << persona.edad
                  << ", Altura: " << persona.altura << ", Empleado: " << (persona.empleado ? "Sí" : "No")
                  << ", Salario: " << persona.salario << std::endl;
    }

    return 0;
}
