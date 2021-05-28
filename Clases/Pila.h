#ifndef PARCIAL2_ARBOLYHEAPNARIO_PILA_H
#define PARCIAL2_ARBOLYHEAPNARIO_PILA_H

#include "Nodo.h"

/**
 * Clase que implementa una Pila generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T> class Pila {
    private:
        Nodo<T> *inicio;
    public:
        Pila();
        Pila(Nodo<T>* n) { inicio = n; };
    //    ~Pila();  El destructor genera problemas si no existe un constructor por copia
        void push(T dato);
        T pop();
        bool esVacia();
        T peek();
        int size();
        Pila<T>* resto();
        T esta(T d);

};


/**
 * Constructor de la clase Pila
 * @tparam T
 */
template<class T> Pila<T>::Pila() {
    inicio = NULL;
}

///**
// * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
// * utilizados en la lista
// * @tparam T
// */
//template<class T>
//Pila<T>::~Pila() {
//   while (!esVacia()) {
//       pop();
//   }
//}

/**
 * Inserta un dato en la pila
 * @tparam T
 * @param dato  dato a insertar
 */
template<class T> void Pila<T>::push(T dato) {
    auto *aux = new Nodo<T>(dato, inicio);
    inicio = aux;
//    inicio = new Nodo(dato,inicio);
}

/**
 * Obtener el dato de la pila
 * @tparam T
 * @return dato almacenado en el nodo
 */
template<class T> T Pila<T>::pop() {
    if (esVacia()) throw 1;

    T dato = inicio->getDato();
    Nodo<T> *aux = inicio;

    inicio = inicio->getNext();
    delete aux;

    return dato;
}

/**
 * Responde si la pila se encuentra Vacía
 * @tparam T
 * @return
 */
template<class T> bool Pila<T>::esVacia() {
    return inicio == NULL;
}

template<class T> T Pila<T>::peek() {
    if (esVacia()) throw 1;

    return inicio->getDato();
}

template<class T> int Pila<T>::size() {
    if(esVacia()){return 0;}
    Nodo<T> *aux = inicio;
    int cont = 0;

    while (aux != NULL) {
        cont++;
        aux = aux->getNext();
    }

    return cont;
}

template<class T>
Pila<T>* Pila<T>::resto() {
    Pila* copia = new Pila<T>(inicio->getNext());
    return copia;
}

template<class T>
T Pila<T>::esta(T d) {
    if(!esVacia()){
        if(inicio->getDato()== d){ //acá está el error
            return inicio->getDato();
        } else{
            return this->resto()->esta(d);
        }
    }
    return nullptr;
}


#endif //PARCIAL2_ARBOLYHEAPNARIO_PILA_H