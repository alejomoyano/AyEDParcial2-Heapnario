#ifndef ALGORITMOS_TP2_NODO_H
#define ALGORITMOS_TP2_NODO_H

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class NodoHeap {
private:
    int repeticiones=1; //cuenta cantidad de veces q se repite la palabra en el texto
    T dato;
    NodoHeap<T> *padre;
    vector<NodoHeap<T>*> hijos;

public:
    NodoHeap(T d);

    NodoHeap(const NodoHeap<T> &nh);

    void putHijo(NodoHeap<T> *nodo);

    int getCantidadHijos();

    T getDato();

    void sumarRepeticion();
};
/**
 *Constructor
*/
template<class T>
NodoHeap<T>::NodoHeap(T d) {
    dato = d;
    padre = nullptr;
}

/**
 *Constructor por copia
*/
template<class T>
NodoHeap<T>::NodoHeap(const NodoHeap<T> &nh) {
    repeticiones = nh.repeticiones;
    dato = nh.dato;
    padre = nh.padre;
    hijos = nh.hijos;
}

/**
 *Le agrega un hijo al nodo actual
*/
template<class T>
void NodoHeap<T>::putHijo(NodoHeap<T> *nodo) {
    hijos.push_back(nodo);
}

template<class T>
int NodoHeap<T>::getCantidadHijos() {
    return hijos.size();
}

template<class T>
T NodoHeap<T>::getDato() {
    return dato;
}

template<class T>
void NodoHeap<T>::sumarRepeticion() {
    repeticiones++;
}


#endif //ALGORITMOS_TP2_NODO_H