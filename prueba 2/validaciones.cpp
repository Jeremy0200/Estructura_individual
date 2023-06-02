#include "validaciones.h"
#include <cctype>

bool esNumero(const std::string& cadena) {
    for (char c : cadena) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool esOpcionValida(char opcion) {
    return (opcion == 's' || opcion == 'n' || opcion == 'S' || opcion == 'N');
}

//aqui se realizan las validaciones