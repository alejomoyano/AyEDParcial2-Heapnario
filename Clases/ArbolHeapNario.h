#ifndef PARCIAL2_ARBOLYHEAPNARIO_ARBOLHEAPNARIO_H
#define PARCIAL2_ARBOLYHEAPNARIO_ARBOLHEAPNARIO_H

#include "NodoHeap.h"
#include "Cola.h"
#include "Pila.h"
#include <iostream>

using namespace std;

template<class T> class ArbolHeapNario {
    private:
        int n;
        NodoHeap<T> *raiz;
        Cola<NodoHeap<T>*> cola;
        Pila<NodoHeap<T>*> pila;
    public:
        ArbolHeapNario(int orden);
        void put(T dato);
};

template<class T>
ArbolHeapNario<T>::ArbolHeapNario(int orden) {
    n = orden;
    raiz = nullptr;
}

template<class T> void ArbolHeapNario<T>::put(T dato) {
    if (raiz == nullptr) {
        raiz = new NodoHeap<T>(dato);
        cola.encolar(raiz);
        pila.push(raiz);
    }
    else {
        NodoHeap<T> *aux = cola.verFrente();
        NodoHeap<T> *nodoNuevo = new NodoHeap<T>(dato);
        aux->putHijo(nodoNuevo);
        cola.encolar(nodoNuevo);
        pila.push(nodoNuevo);
        if(aux->getCantidadHijos() == n)
            cola.desencolar();
    }
}

#endif //PARCIAL2_ARBOLYHEAPNARIO_ARBOLHEAPNARIO_H
