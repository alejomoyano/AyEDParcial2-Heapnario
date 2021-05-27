#ifndef PARCIAL2_ARBOLYHEAPNARIO_COLA_H
#define PARCIAL2_ARBOLYHEAPNARIO_COLA_H

#include "Nodo.h"

/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Cola {
private:
    Nodo<T> *frente;
    Nodo<T> *fondo;

public:
    Cola();
//    ~Cola();  El destructor genera problemas si no existe constructor por copia
    void encolar(T dato);
    T desencolar();
    bool esVacia();
    void vaciar();
    T verFrente();
};


/**
 * Constructor de la clase Cola
 * @tparam T
 */
template<class T>
Cola<T>::Cola() {
    fondo = frente = NULL;
}


///**
// * Destructor de la clase Cola, se encarga de liberar la memoria de todos los nodos
// * utilizados en la Cola
// * @tparam T
// */
//template<class T>
//Cola<T>::~Cola() {}


/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T>
void Cola<T>::encolar(T dato) {

    Nodo<T> *aux = new Nodo<T>(dato);
    // Si la cola esta vacia
    if (fondo == NULL && frente == NULL) {
        frente = fondo = aux;
    } else {
        fondo->setNext(aux);
        // fondo->setNext(new Nodo<T>(dato));
        fondo = aux;
    }
}


/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T>
T Cola<T>::desencolar() {

    if (esVacia()) throw 1;

    // si no es vacia.
    T tmp;
    Nodo<T> *aux = frente;

    frente = frente->getNext();
    tmp = aux->getDato();
    delete aux;
    if (frente == NULL)
        fondo = frente;

    return tmp;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T>
bool Cola<T>::esVacia() {
    return frente == NULL;
}


/**
 * Vaciamos y liberamos memoria.
 */
template<class T>
void Cola<T>::vaciar() {
    while(frente != NULL)
        desencolar();
}


/**
 * Mostrar el dato del frente
 */
template<class T>
T Cola<T>::verFrente() {
    if(esVacia()) throw 404;
    return frente->getDato();
}

#endif //PARCIAL2_ARBOLYHEAPNARIO_COLA_H