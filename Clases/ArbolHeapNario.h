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
        bool palabraRepetida(NodoHeap<T>* dato, Pila<NodoHeap<T>*> aux);
};

template<class T>
ArbolHeapNario<T>::ArbolHeapNario(int orden) {
    n = orden;
    raiz = nullptr;
}

template<class T> bool ArbolHeapNario<T>::palabraRepetida(NodoHeap<T>* dato, Pila<NodoHeap<T>*> aux) {
    NodoHeap<T>* result = aux.esta(dato);
    if(result!= nullptr) {
        result->sumarCont();
        return true;
    } else{
        return false;
    }
}



template<class T> void ArbolHeapNario<T>::put(T dato) {
    if (raiz == nullptr) {
        raiz = new NodoHeap<T>(dato);
        cola.encolar(raiz);
        pila.push(raiz);
        cout << dato <<endl; //para ver raíz
        cout << endl <<endl;
    }
    else {
        NodoHeap<T> *nodoNuevo = new NodoHeap<T>(dato);
        if (!(palabraRepetida(nodoNuevo, pila))) {
        NodoHeap<T> *aux = cola.verFrente();
        aux->putHijo(nodoNuevo);
        cola.encolar(nodoNuevo);
        pila.push(nodoNuevo);
        cout << dato << endl;
            if (aux->getCantidadHijos() == n) {
                cola.desencolar();
                cout << endl << endl; //para probar cuando desencola
            }
        }
    }
}




#endif //PARCIAL2_ARBOLYHEAPNARIO_ARBOLHEAPNARIO_H
