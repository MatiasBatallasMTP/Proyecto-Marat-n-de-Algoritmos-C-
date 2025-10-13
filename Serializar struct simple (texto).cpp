#include <iostream>
#include <sstream>
#include <string>

struct Persona {
    std::string nombre;
    int edad;
    float altura;
};

std::string serializar(const Persona& p) {
    std::ostringstream oss;  // Usamos ostringstream para construir la cadena
    oss << "Nombre: " << p.nombre << "\n"
        << "Edad: " << p.edad << "\n"
        << "Altura: " << p.altura << "\n";
    return oss.str();  // Devuelve la cadena serializada
}

int main() {
    Persona persona = {"Juan", 30, 1.75};  // Creación de una instancia de Persona

    // Serialización
    std::string datos_serializados = serializar(persona);

    // Mostrar los datos serializados
    std::cout << "Datos serializados:\n" << datos_serializados;

    return 0;
}
