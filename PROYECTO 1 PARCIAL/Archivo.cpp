#include "archivo.h"
#include <fstream>

std::unordered_map<std::string, int> contarRegistrosPorProvincia(const std::string& Personas) {
    std::unordered_map<std::string, int> registrosPorProvincia;
    for (const auto& par : provincias) {
        registrosPorProvincia[par.second] = 0;
    }
    std::ifstream archivo(Personas);
    if (archivo.is_open()) {
        std::string linea;
        while (getline(archivo, linea)) {
            std::string cedula = linea.substr(0, 2);
            if (provincias.find(cedula) != provincias.end()) {
                std::string provincia = provincias[cedula];
                registrosPorProvincia[provincia]++;
            }
        }
        archivo.close();
    }
    return registrosPorProvincia;
}