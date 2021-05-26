#ifndef ALGORITMOS_TP2_NODO_H
#define ALGORITMOS_TP2_NODO_H

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class NodoHeap {
private:
    int contador=1;
    T dato;
    NodoHeap<T> *padre;
    vector<NodoHeap<T>*> *hijos;

public:
    NodoHeap(){
        padre= nullptr;
    };

    NodoHeap(T dato, NodoHeap<T>* padre) : dato(dato), padre(padre){}

    T getDato() const {
        return dato;
    }

    void setDato(T dato) {
        NodoHeap::dato = dato;
    }

    NodoHeap<T> *getPadre() const {
        return padre;
    }

    vector<NodoHeap<T>*>* getHijos() const {
        return hijos;
    }


    void setHijo(NodoHeap<T> *hijo) {
        NodoHeap::hijos->push_back(*hijo);
    }


};

#endif //ALGORITMOS_TP2_NODO_H
