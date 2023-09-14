#include <iostream>
#include <string>

struct Nodo {
    int valor;
    Nodo* sig;

    Nodo(int val) : valor(val), sig(nullptr) {}
};

struct lcircular {
    Nodo* cabeza;

    lcircular() : cabeza(nullptr) {}

    void insertinicio(int valor) {
        Nodo* newNodo = new Nodo(valor);

        if (!cabeza) {
            newNodo->sig = newNodo; 
            cabeza = newNodo;
        } else {
            
            Nodo* ultimo = cabeza;
            while (ultimo->sig != cabeza) {
                ultimo = ultimo->sig;
            }

            int suma = ultimo->valor + valor;

            
            newNodo->valor = suma;
            newNodo->sig = cabeza;
            ultimo->sig = newNodo;
        }
    }

    void mostrar(int numNodos) {
        if (!cabeza) {
            std::cout << "La lista está vacía." << std::endl;
            return;
        }

        Nodo* actual = cabeza;
        for (int i = 0; i < numNodos; ++i) {
            std::cout << actual->valor << " ";
            actual = actual->sig;
        }
        std::cout << std::endl;
    }
};

int main() {
    lcircular listaCircular;

    int numNodos;
    std::cout << "Ingrese la cantidad de nodos que desea en la lista: ";
    std::cin >> numNodos;

    std::cout << "Ingrese los valores para la lista circular:" << std::endl;
    int valor;
    for (int i = 0; i < numNodos; ++i) {
        std::cin >> valor;
        listaCircular.insertinicio(valor);
    }

    std::cout << "Lista Circular con " << numNodos << " nodos:" << std::endl;
    listaCircular.mostrar(numNodos);

    return 0;
}
