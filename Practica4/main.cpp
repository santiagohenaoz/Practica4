#include "redmanager.h"

int main() {
    RedManager red;
    std::string option;
    int id, id1, id2, costo;

    std::cout << "============================================" << std::endl;
    std::cout << "        SIMULADOR DE REDES - UDEA" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "\nRed inicial tipo arbol + anillo + conexiones extra (8 routers):\n" << std::endl;

    // Crear routers
    for (int i = 0; i <= 7; ++i) {
        red.agregarRouter(i);
    }

    // Conexiones tipo árbol
    red.conectarRouters(0, 1, 2);
    red.conectarRouters(0, 2, 4);
    red.conectarRouters(1, 3, 3);
    red.conectarRouters(1, 4, 5);

    // Conexión tipo anillo
    red.conectarRouters(4, 0, 6);

    // Nuevas conexiones con router 2
    red.conectarRouters(2, 5, 2);
    red.conectarRouters(2, 6, 3);

    // Router 7 conectado a 3, 4, 5, 6
    red.conectarRouters(7, 3, 4);
    red.conectarRouters(7, 4, 4);
    red.conectarRouters(7, 5, 5);
    red.conectarRouters(7, 6, 5);

    // Mostrar routers y conexiones al inicio
    std::cout << "\nRouters existentes y sus conexiones:\n" << std::endl;
    for (int i = 0; i <= 7; ++i) {
        red.mostrarConexionesDeRouter(i);
    }

    while (true) {
        std::cout << "\nMenu:\n"
                  << "1. Agregar Router\n"
                  << "2. Eliminar Router\n"
                  << "3. Conectar Routers\n"
                  << "4. Calcular distancia mas corta\n"
                  << "5. Mostrar camino\n"
                  << "6. Ver conexiones de un router\n"
                  << "7. Borrar y generar redes aleatorias\n"
                  << "8. Leer archivo y crear red\n"
                  << "9. Salir\n";
        std::cin >> option;

        if (option.length() != 1) {
            std::cout << "Opcion invalida." << std::endl;
            continue;
        }

        switch (option[0]) {
        case '1':
            std::cout << "Ingrese ID del nuevo Router: ";
            std::cin >> id;
            red.agregarRouter(id);
            break;
        case '2':
            std::cout << "Ingrese ID del Router a eliminar: ";
            std::cin >> id;
            red.eliminarRouter(id);
            break;
        case '3':
            std::cout << "Ingrese ID del Router de origen, ID del Router de destino y el costo: ";
            std::cin >> id1 >> id2 >> costo;
            red.conectarRouters(id1, id2, costo);
            break;
        case '4':
            std::cout << "Ingrese ID del Router de origen e ID del Router de destino: ";
            std::cin >> id1 >> id2;
            red.calcularYMostrarCamino(id1, id2);
            break;
        case '5':
            std::cout << "Ingrese ID del Router destino: ";
            std::cin >> id;
            red.mostrarConexionesDeRouter(id);
            break;
        case '6':
            std::cout << "Ingrese ID del Router para ver sus conexiones: ";
            std::cin >> id;
            red.mostrarConexionesDeRouter(id);
            break;
        case '7':
            red.generarRedesAleatorias();
            break;
        case '8':
            red.leerArchivoYCrearRed();
            break;
        case '9':
            red.borrarRedes();
            return 0;
        default:
            std::cout << "Opcion invalida." << std::endl;
        }
    }
}
