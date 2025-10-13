#include <iostream>
#include <fstream>
#include <iomanip>  // Para manipulación de formato (setprecision, fixed)
#include <string>
#include <vector>

struct Persona {
    std::string nombre;
    int edad;
    float altura;
    bool empleado;
    double salario;
};

// Función para escribir los datos de las personas en un archivo CSV
void escribirCSV(const std::string& archivo, const std::vector<Persona>& personas) {
    std::ofstream file(archivo);

    if (!file.is_open()) {  // Comprobamos si el archivo se abre correctamente
        std::cerr << "No se pudo abrir el archivo " << archivo << std::endl;
        return;
    }

    // Escribimos el encabezado (
