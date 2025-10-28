#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>


std::unordered_map<int, Router*> routers;



int main() {

    // Ejemplo inicial de creación de routers y conexiones
    agregarRouter(routers, 0);
    agregarRouter(routers, 1);
    agregarRouter(routers, 2);
    agregarRouter(routers, 3);

    conectarRouters(routers, 0, 1, 2);
    conectarRouters(routers, 0, 2, 4);
    conectarRouters(routers, 1, 2, 1);
    conectarRouters(routers, 1, 3, 7);
    conectarRouters(routers, 2, 3, 3);

    std::string option;
    int id, id1, id2, costo;

    // Bucle del menú de opciones
    while (true) {
        std::cout << "\nMenu:\n1. Agregar Router\n2. Eliminar Router\n3. Conectar Routers\n4. Calcular distancia mas corta\n5. Mostrar camino\n6. Ver conexiones de un router\n7. Borrar y generar redes aleatorias\n8. Leer archivo y crear red\n9. Salir\n";
        std::cin >> option;

        if (option.length() != 1) {
            std::cout << "Opcion invalida." << std::endl;
            continue;
        }

        switch (option[0]) {
        case '1':
            std::cout << "Ingrese ID del nuevo Router: ";
            std::cin >> id;
            agregarRouter(routers, id);
            break;
        case '2':
            std::cout << "Ingrese ID del Router a eliminar: ";
            std::cin >> id;
            eliminarRouter(routers, id);
            break;
        case '3':
            std::cout << "Ingrese ID del Router de origen, ID del Router de destino y el costo: ";
            std::cin >> id1 >> id2 >> costo;
            conectarRouters(routers, id1, id2, costo);
            break;
        case '4':
            std::cout << "Ingrese ID del Router de origen e ID del Router de destino: ";
            std::cin >> id1 >> id2;
            calcularYMostrarCamino(routers, id1, id2);
            break;
        case '5':
            std::cout << "Ingrese ID del Router destino: ";
            std::cin >> id;
            mostrarCamino(routers[id]);
            break;
        case '6':
            std::cout << "Ingrese ID del Router para ver sus conexiones: ";
            std::cin >> id;
            if (routers.find(id) != routers.end()) {
                routers[id]->mostrarConexiones();
            } else {
                std::cout << "Router no encontrado." << std::endl;
            }
            break;
        case '7':
            generarRedesAleatorias(routers);
            break;
        case '8':
            leerArchivoYCrearRed(routers);
            break;
        case '9':
            borrarRedes(routers);
            return 0;
        default:
            std::cout << "Opcion invalida." << std::endl;
        }
    }

    return 0;



}
