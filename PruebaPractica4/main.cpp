#include <iostream>
#include <map>

int main() {
    // Declaración e inicialización
    std::map<std::string, int> resultados;

    // Insertar llaves-valores
    resultados["Alice"] = 85;
    resultados["Bob"] = 92;
    resultados["Charlie"] = 78;

    // Access values using keys
    std::cout << "Resultado de Bob: " << resultados["Bob"] << std::endl;

    // Revisar si una llave existe
    if (resultados.find("David") != resultados.end()) {
        std::cout << "Resultados David: " << resultados["David"] << std::endl;
    } else {
        std::cout << "No hay coincidencias." << std::endl;
    }


    std::cout << "Resultados: ";
    for (const auto& par : resultados) { //Se utiliza para deducir el tipo de dato  Despues de los dos puntos me dice qué voy a recorrer
        std::cout << par.first << ": " << par.second << ", "; //llave y valor
    }
    std::cout << std::endl;

    // Remoción
    resultados.erase("Charlie");

    if (resultados.empty()) {
        std::cout << "Map vac" << std::endl;
    } else {
        std::cout << "Map no vac." << std::endl;
    }

    return 0;
}
