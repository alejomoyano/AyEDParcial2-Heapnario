#ifndef PARCIAL2_ARBOLYHEAPNARIO_NODOHEAP_H
#define PARCIAL2_ARBOLYHEAPNARIO_NODOHEAP_H

#include <iostream>
#include <vector>

using namespace std;

template<class T> class NodoHeap {
private:
    int contador=1;
    T dato;
    NodoHeap<T> *padre;
    vector<NodoHeap<T>*> hijos;

public:
    NodoHeap(T d);

    NodoHeap(const NodoHeap<T> &nh);

    void putHijo(NodoHeap<T> *nodo);

    int getCantidadHijos();
};

template<class T> NodoHeap<T>::NodoHeap(T d) {
    dato = d;
    padre = nullptr;
}

template<class T> NodoHeap<T>::NodoHeap(const NodoHeap<T> &nh) {
    contador = nh.contador;
    dato = nh.dato;
    padre = nh.padre;
    hijos = nh.hijos;
}

template<class T> void NodoHeap<T>::putHijo(NodoHeap<T> *nodo) {
    hijos.push_back(nodo);
}

template<class T> int NodoHeap<T>::getCantidadHijos() {
    return hijos.size();
}

#endif //PARCIAL2_ARBOLYHEAPNARIO_NODOHEAP_H