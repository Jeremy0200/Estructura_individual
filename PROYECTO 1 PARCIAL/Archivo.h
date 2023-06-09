#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> provincias = {
    {"01", "Azuay"}, {"02", "Bolívar"}, {"03", "Cañar"}, {"04", "Carchi"}, {"05", "Cotopaxi"},
    {"06", "Chimborazo"}, {"07", "El Oro"}, {"08", "Esmeraldas"}, {"09", "Guayas"}, {"10", "Imbabura"},
    {"11", "Loja"}, {"12", "Los Ríos"}, {"13", "Manabí"}, {"14", "Morona Santiago"}, {"15", "Napo"},
    {"16", "Pastaza"}, {"17", "Pichincha"}, {"18", "Tungurahua"}, {"19", "Zamora Chinchipe"},
    {"20", "Galápagos"}, {"21", "Sucumbíos"}, {"22", "Orellana"}, {"23", "Santo Domingo de los Tsáchilas"},
    {"24", "Santa Elena"}
};

std::unordered_map<std::string, int> contarRegistrosPorProvincia(const std::string& Personas);
#endif
